/****************************************************************************
** Meta object code from reading C++ file 'pidcontroller.h'
**
** Created: Fri Oct 3 01:27:27 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "pidcontroller.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pidcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PIDController[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   53,  121,  121, 0x0a,
     122,  142,  121,  121, 0x0a,
     159,  184,  121,  121, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PIDController[] = {
    "PIDController\0PIDInit(float,float,float,float,float)\0"
    "P_Param,I_Param,D_Param,IntegralTreshold_Param,DriveThreshold_Param\0"
    "\0PIDTask(float,bool)\0tempValue,status\0"
    "setSetTemperature(float)\0temperature\0"
};

void PIDController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PIDController *_t = static_cast<PIDController *>(_o);
        switch (_id) {
        case 0: _t->PIDInit((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5]))); break;
        case 1: _t->PIDTask((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->setSetTemperature((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PIDController::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PIDController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PIDController,
      qt_meta_data_PIDController, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PIDController::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PIDController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PIDController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PIDController))
        return static_cast<void*>(const_cast< PIDController*>(this));
    return QObject::qt_metacast(_clname);
}

int PIDController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
