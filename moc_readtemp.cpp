/****************************************************************************
** Meta object code from reading C++ file 'readtemp.h'
**
** Created: Fri Oct 3 01:27:44 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "readtemp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'readtemp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ReadTemp[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,   35,   47,   47, 0x05,

 // slots: signature, parameters, type, tag, flags
      48,   63,   47,   47, 0x0a,
      75,   47,   47,   47, 0x0a,
      86,   47,   47,   47, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ReadTemp[] = {
    "ReadTemp\0ReadDataReady(float,bool)\0"
    "value,error\0\0ReadStart(int)\0msecPerioud\0"
    "ReadStop()\0sampleTimerEvent()\0"
};

void ReadTemp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ReadTemp *_t = static_cast<ReadTemp *>(_o);
        switch (_id) {
        case 0: _t->ReadDataReady((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->ReadStart((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->ReadStop(); break;
        case 3: _t->sampleTimerEvent(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ReadTemp::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ReadTemp::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ReadTemp,
      qt_meta_data_ReadTemp, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ReadTemp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ReadTemp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ReadTemp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ReadTemp))
        return static_cast<void*>(const_cast< ReadTemp*>(this));
    return QObject::qt_metacast(_clname);
}

int ReadTemp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ReadTemp::ReadDataReady(float _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
