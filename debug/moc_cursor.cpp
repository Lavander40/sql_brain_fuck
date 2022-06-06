/****************************************************************************
** Meta object code from reading C++ file 'cursor.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../cursor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cursor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cursor_t {
    const uint offsetsAndSize[26];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_cursor_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_cursor_t qt_meta_stringdata_cursor = {
    {
QT_MOC_LITERAL(0, 6), // "cursor"
QT_MOC_LITERAL(7, 12), // "refreshTable"
QT_MOC_LITERAL(20, 0), // ""
QT_MOC_LITERAL(21, 5), // "index"
QT_MOC_LITERAL(27, 11), // "recieveData"
QT_MOC_LITERAL(39, 5), // "table"
QT_MOC_LITERAL(45, 12), // "clearWidgets"
QT_MOC_LITERAL(58, 9), // "fill_from"
QT_MOC_LITERAL(68, 8), // "movement"
QT_MOC_LITERAL(77, 23), // "on_updateButton_clicked"
QT_MOC_LITERAL(101, 21), // "on_prevButton_clicked"
QT_MOC_LITERAL(123, 21), // "on_nextButton_clicked"
QT_MOC_LITERAL(145, 23) // "on_cancelButton_clicked"

    },
    "cursor\0refreshTable\0\0index\0recieveData\0"
    "table\0clearWidgets\0fill_from\0movement\0"
    "on_updateButton_clicked\0on_prevButton_clicked\0"
    "on_nextButton_clicked\0on_cancelButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cursor[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   65,    2, 0x08,    3 /* Private */,
       6,    0,   68,    2, 0x08,    5 /* Private */,
       7,    2,   69,    2, 0x08,    6 /* Private */,
       9,    0,   74,    2, 0x08,    9 /* Private */,
      10,    0,   75,    2, 0x08,   10 /* Private */,
      11,    0,   76,    2, 0x08,   11 /* Private */,
      12,    0,   77,    2, 0x08,   12 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void cursor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<cursor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->refreshTable((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->recieveData((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->clearWidgets(); break;
        case 3: _t->fill_from((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->on_updateButton_clicked(); break;
        case 5: _t->on_prevButton_clicked(); break;
        case 6: _t->on_nextButton_clicked(); break;
        case 7: _t->on_cancelButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (cursor::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&cursor::refreshTable)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject cursor::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_cursor.offsetsAndSize,
    qt_meta_data_cursor,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_cursor_t
, QtPrivate::TypeAndForceComplete<cursor, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *cursor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cursor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cursor.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int cursor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void cursor::refreshTable(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
