/****************************************************************************
** Meta object code from reading C++ file 'hawk.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../hawk.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hawk.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Hawk_t {
    QByteArrayData data[8];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Hawk_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Hawk_t qt_meta_stringdata_Hawk = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Hawk"
QT_MOC_LITERAL(1, 5, 17), // "subjectListChange"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 16), // "addButtonHandler"
QT_MOC_LITERAL(4, 41, 26), // "increaseHoursButtonHandler"
QT_MOC_LITERAL(5, 68, 19), // "popOutButtonHandler"
QT_MOC_LITERAL(6, 88, 12), // "populateList"
QT_MOC_LITERAL(7, 101, 13) // "removeHandler"

    },
    "Hawk\0subjectListChange\0\0addButtonHandler\0"
    "increaseHoursButtonHandler\0"
    "popOutButtonHandler\0populateList\0"
    "removeHandler"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Hawk[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   45,    2, 0x0a /* Public */,
       4,    0,   46,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x0a /* Public */,
       7,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Hawk::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Hawk *_t = static_cast<Hawk *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->subjectListChange(); break;
        case 1: _t->addButtonHandler(); break;
        case 2: _t->increaseHoursButtonHandler(); break;
        case 3: _t->popOutButtonHandler(); break;
        case 4: _t->populateList(); break;
        case 5: _t->removeHandler(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Hawk::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Hawk::subjectListChange)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Hawk::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Hawk.data,
      qt_meta_data_Hawk,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Hawk::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Hawk::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Hawk.stringdata0))
        return static_cast<void*>(const_cast< Hawk*>(this));
    return QWidget::qt_metacast(_clname);
}

int Hawk::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Hawk::subjectListChange()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
