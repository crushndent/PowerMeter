//Basic energy monitoring sketch
//Authors: Trystan Lea, Eric Sandeen

//Licenced under GNU General Public Licence more details here
// openenergymonitor.org

//Sketch measures voltage and current. 
//and then calculates useful values like real power,
//apparent power, powerfactor, Vrms, Irms.

//Setup variables
int numberOfSamples = 3000;

//Set Voltage and current input pins
int inPinV = 1;
int inPinI = 0;
int inPinI2 = 2;

//Sanity check calibration method thanks to Eric Sandeen http://sandeen.net/wordpress
//See discussion here: http://openenergymonitor.org/emon/node/59
//Enter the values of your setup below 

// Voltage is reduced both by wall xfmr & voltage divider
#define AC_WALL_VOLTAGE        120
#define AC_ADAPTER_VOLTAGE     16	//TC
// Ratio of the voltage divider in the circuit
#define AC_VOLTAGE_DIV_RATIO   13	//TC = 130/10
// CT: Voltage depends on current, burden resistor, and turns
#define CT_BURDEN_RESISTOR    100
#define CT_TURNS              2000 //TC - TRUE - was 3030
//5ma for 10A current - approximately
//CT_TURNS = ratio = 2000

//Calibration coeficients
//These need to be set in order to obtain accurate results
//Set the above values first and then calibrate futher using normal calibration method described on how to build it page.
double VCAL = 0.939;
double ICAL = 0.954;
double ICAL2 = 0.940;
double PHASECAL = 1.0; //Was 2.4

#define Vcc 5.0
// Initial gueses for ratios, modified by VCAL/ICAL tweaks
#define AC_ADAPTER_RATIO       (AC_WALL_VOLTAGE / AC_ADAPTER_VOLTAGE)
double V_RATIO = AC_ADAPTER_RATIO * AC_VOLTAGE_DIV_RATIO * Vcc / 1024 * VCAL;
double I_RATIO = (long double)CT_TURNS / CT_BURDEN_RESISTOR * Vcc / 1024 * ICAL;
double I_RATIO2 = (long double)CT_TURNS / CT_BURDEN_RESISTOR * Vcc / 1024 * ICAL2;

//Sample variables
int lastSampleV,lastSampleI,sampleV,sampleI;
int lastSampleI2,sampleI2;

//Filter variables
double lastFilteredV, lastFilteredI, filteredV, filteredI, lastFilteredI2, filteredI2;
double filterTemp;

//Stores the phase calibrated instantaneous voltage.
double shiftedV;

//Power calculation variables
double sqI,sqI2,sqV,instP,sumI,sumI2,sumV,sumP;

//Useful value variables
double realPower,
       apparentPower,
       powerFactor,
       Vrms,
       Irms,
       Irms2;

int ledPin =  13;    // LED connected to digital pin 13
int blink = 0;

void setup()
{
   Serial.begin(19200); 
   pinMode(ledPin, OUTPUT);     
   
   Serial.print("realPower");
   Serial.print(',');
   Serial.print("apparentPower");
   Serial.print(',');
   Serial.print("powerFactor");
   Serial.print(',');
   Serial.print("Vrms");
   Serial.print(",");
   Serial.print("Irms");
   Serial.print(',');
   Serial.println("Irms2");
   
}

void loop()
{ 
	for (int n=0; n<numberOfSamples; n++)
	{

		//Used for offset removal
		lastSampleV=sampleV;
		lastSampleI=sampleI;
		lastSampleI2=sampleI2;

		//Read in voltage and current samples.   
		sampleV = analogRead(inPinV);
		sampleI = analogRead(inPinI);
		sampleI2 = analogRead(inPinI2);

		//Used for offset removal
		lastFilteredV = filteredV;
		lastFilteredI = filteredI;
		lastFilteredI2 = filteredI2;

		//Digital high pass filters to remove 2.5V DC offset.
		filteredV = 0.996*(lastFilteredV+(sampleV-lastSampleV));
		filteredI = 0.996*(lastFilteredI+sampleI-lastSampleI);
		filteredI2 = 0.996*(lastFilteredI2+sampleI2-lastSampleI2);

		//Phase calibration goes here.
		shiftedV = lastFilteredV + PHASECAL * (filteredV - lastFilteredV);

		//Root-mean-square method voltage
		//1) square voltage values
		sqV= filteredV * filteredV;
		//2) sum
		sumV += sqV;

		//Root-mean-square method current
		//1) square current values
		sqI = filteredI * filteredI;
		sqI2 = filteredI2 * filteredI2;
		//2) sum 
		sumI += sqI;
		sumI2 += sqI2;

		//Instantaneous Power
		instP = shiftedV * (filteredI+filteredI2);
		//Sum
		sumP +=instP;
	}

	//Calculation of the root of the mean of the voltage and current squared (rms)
	//Calibration coeficients applied. 
	Vrms = V_RATIO*sqrt(sumV / numberOfSamples); 
	Irms = I_RATIO*sqrt(sumI / numberOfSamples); 
	Irms2 = I_RATIO2*sqrt(sumI2 / numberOfSamples); 

	//Calculation power values
	realPower = V_RATIO*I_RATIO*I_RATIO2*sumP / numberOfSamples;
	apparentPower = Vrms * (Irms+Irms2);
	powerFactor = realPower / apparentPower;

	//Output to serial
//	Serial.print(sumP);
//	Serial.print(',');

//	Serial.print(realPower);
//	Serial.print(',');
	Serial.print(apparentPower);
	Serial.print(',');
//	Serial.print(powerFactor);
//	Serial.print(',');
	Serial.print(Vrms);
	Serial.print(",");
	Serial.print(Irms);
	Serial.print(',');
	Serial.println(Irms2);

	//Reset accumulators
	sumV = 0;
	sumI = 0;
	sumI2 = 0;
	sumP = 0;

        if (blink == 0)
        {
          blink = 1;
          digitalWrite(ledPin, HIGH);
        }
        else
        {
          blink = 0;
          digitalWrite(ledPin, LOW);
        }
}
