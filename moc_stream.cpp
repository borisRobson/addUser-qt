/****************************************************************************
** Meta object code from reading C++ file 'stream.h'
**
** Created: Thu Oct 6 15:10:40 2016
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stream.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stream.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_stream[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x0a,
      20,    7,    7,    7, 0x0a,
      33,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_stream[] = {
    "stream\0\0printtext()\0capTimeOut()\0"
    "updateWindow()\0"
};

const QMetaObject stream::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_stream,
      qt_meta_data_stream, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &stream::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *stream::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *stream::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_stream))
        return static_cast<void*>(const_cast< stream*>(this));
    return QObject::qt_metacast(_clname);
}

int stream::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: printtext(); break;
        case 1: capTimeOut(); break;
        case 2: updateWindow(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
