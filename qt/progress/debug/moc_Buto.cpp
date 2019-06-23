/****************************************************************************
** Meta object code from reading C++ file 'Buto.h'
**
** Created: Tue May 21 15:57:19 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Buto.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Buto.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Buto[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x08,
      18,    5,    5,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Buto[] = {
    "Buto\0\0doProcess()\0partialWorkCompleted()\0"
};

void Buto::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Buto *_t = static_cast<Buto *>(_o);
        switch (_id) {
        case 0: _t->doProcess(); break;
        case 1: _t->partialWorkCompleted(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Buto::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Buto::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_Buto,
      qt_meta_data_Buto, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Buto::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Buto::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Buto::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Buto))
        return static_cast<void*>(const_cast< Buto*>(this));
    return QPushButton::qt_metacast(_clname);
}

int Buto::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
