/****************************************************************************
** Meta object code from reading C++ file 'captureimage.h'
**
** Created: Thu Oct 6 13:05:54 2016
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "captureimage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'captureimage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_captureimage[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      34,   14,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_captureimage[] = {
    "captureimage\0\0exitCode,exitStatus\0"
    "imageSent(int,QProcess::ExitStatus)\0"
};

const QMetaObject captureimage::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_captureimage,
      qt_meta_data_captureimage, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &captureimage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *captureimage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *captureimage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_captureimage))
        return static_cast<void*>(const_cast< captureimage*>(this));
    return QObject::qt_metacast(_clname);
}

int captureimage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: imageSent((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
