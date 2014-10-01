/****************************************************************************
** Meta object code from reading C++ file 'qcppdialogimpl.h'
**
** Created: Sat Nov 19 17:17:53 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qcppdialogimpl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qcppdialogimpl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QCPPDialogImpl[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x09,
      29,   26,   15,   15, 0x09,
      43,   15,   15,   15, 0x09,
      54,   15,   15,   15, 0x09,
      74,   69,   15,   15, 0x09,
     106,   15,   15,   15, 0x09,
     121,   15,   15,   15, 0x09,
     138,   15,   15,   15, 0x09,
     155,   15,   15,   15, 0x09,
     166,   15,   15,   15, 0x09,
     179,   15,   15,   15, 0x09,
     195,   15,   15,   15, 0x09,
     211,  204,   15,   15, 0x09,
     238,   15,   15,   15, 0x09,
     249,   15,   15,   15, 0x09,
     262,  259,   15,   15, 0x09,
     285,  259,   15,   15, 0x09,
     305,   15,   15,   15, 0x09,
     321,   15,   15,   15, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_QCPPDialogImpl[] = {
    "QCPPDialogImpl\0\0execCmd()\0fd\0readData(int)\0"
    "sendFile()\0showAboutMsg()\0item\0"
    "oldCmdClicked(QListWidgetItem*)\0"
    "saveSettings()\0readFromStdout()\0"
    "readFromStderr()\0sendDone()\0connectTTY()\0"
    "disconnectTTY()\0killSz()\0enable\0"
    "enableSettingWidgets(bool)\0doOutput()\0"
    "sendKey()\0on\0hexOutputClicked(bool)\0"
    "enableLogging(bool)\0chooseLogFile()\0"
    "clearOutput()\0"
};

const QMetaObject QCPPDialogImpl::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QCPPDialogImpl,
      qt_meta_data_QCPPDialogImpl, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QCPPDialogImpl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QCPPDialogImpl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QCPPDialogImpl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QCPPDialogImpl))
        return static_cast<void*>(const_cast< QCPPDialogImpl*>(this));
    if (!strcmp(_clname, "Ui::CuteCommDlg"))
        return static_cast< Ui::CuteCommDlg*>(const_cast< QCPPDialogImpl*>(this));
    return QWidget::qt_metacast(_clname);
}

int QCPPDialogImpl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: execCmd(); break;
        case 1: readData((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: sendFile(); break;
        case 3: showAboutMsg(); break;
        case 4: oldCmdClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: saveSettings(); break;
        case 6: readFromStdout(); break;
        case 7: readFromStderr(); break;
        case 8: sendDone(); break;
        case 9: connectTTY(); break;
        case 10: disconnectTTY(); break;
        case 11: killSz(); break;
        case 12: enableSettingWidgets((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: doOutput(); break;
        case 14: sendKey(); break;
        case 15: hexOutputClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: enableLogging((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: chooseLogFile(); break;
        case 18: clearOutput(); break;
        default: ;
        }
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
