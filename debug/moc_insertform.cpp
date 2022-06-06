/****************************************************************************
** Meta object code from reading C++ file 'insertform.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../insertform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'insertform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_insertform_t {
    const uint offsetsAndSize[14];
    char stringdata0[78];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_insertform_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_insertform_t qt_meta_stringdata_insertform = {
    {
QT_MOC_LITERAL(0, 10), // "insertform"
QT_MOC_LITERAL(11, 12), // "refreshTable"
QT_MOC_LITERAL(24, 0), // ""
QT_MOC_LITERAL(25, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(47, 11), // "recieveData"
QT_MOC_LITERAL(59, 5), // "index"
QT_MOC_LITERAL(65, 12) // "clearWidgets"

    },
    "insertform\0refreshTable\0\0on_pushButton_clicked\0"
    "recieveData\0index\0clearWidgets"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_insertform[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   39,    2, 0x08,    2 /* Private */,
       4,    1,   40,    2, 0x08,    3 /* Private */,
       6,    0,   43,    2, 0x08,    5 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,

       0        // eod
};

void insertform::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<insertform *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->refreshTable(); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->recieveData((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->clearWidgets(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (insertform::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&insertform::refreshTable)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject insertform::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_insertform.offsetsAndSize,
    qt_meta_data_insertform,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_insertform_t
, QtPrivate::TypeAndForceComplete<insertform, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *insertform::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *insertform::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_insertform.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int insertform::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void insertform::refreshTable()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
