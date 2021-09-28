/****************************************************************************
** Meta object code from reading C++ file 'ProgramLauncher.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "ProgramLauncher.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ProgramLauncher.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProgramLauncher_t {
    QByteArrayData data[15];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProgramLauncher_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProgramLauncher_t qt_meta_stringdata_ProgramLauncher = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ProgramLauncher"
QT_MOC_LITERAL(1, 16, 15), // "programsChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 15), // "finishedChanged"
QT_MOC_LITERAL(4, 49, 8), // "settings"
QT_MOC_LITERAL(5, 58, 3), // "str"
QT_MOC_LITERAL(6, 62, 4), // "eval"
QT_MOC_LITERAL(7, 67, 4), // "page"
QT_MOC_LITERAL(8, 72, 3), // "arg"
QT_MOC_LITERAL(9, 76, 7), // "process"
QT_MOC_LITERAL(10, 84, 4), // "name"
QT_MOC_LITERAL(11, 89, 8), // "fileName"
QT_MOC_LITERAL(12, 98, 11), // "startupApps"
QT_MOC_LITERAL(13, 110, 8), // "programs"
QT_MOC_LITERAL(14, 119, 6) // "finish"

    },
    "ProgramLauncher\0programsChanged\0\0"
    "finishedChanged\0settings\0str\0eval\0"
    "page\0arg\0process\0name\0fileName\0"
    "startupApps\0programs\0finish"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProgramLauncher[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       2,   62, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   46,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       6,    2,   49,    2, 0x02 /* Public */,
       6,    3,   54,    2, 0x02 /* Public */,
      12,    0,   61,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    7,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    9,   10,   11,
    QMetaType::Void,

 // properties: name, type, flags
      13, QMetaType::QVariantList, 0x00495103,
      14, QMetaType::Bool, 0x00495003,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void ProgramLauncher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProgramLauncher *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->programsChanged(); break;
        case 1: _t->finishedChanged(); break;
        case 2: _t->settings((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->eval((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->eval((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 5: _t->startupApps(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ProgramLauncher::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProgramLauncher::programsChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ProgramLauncher::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProgramLauncher::finishedChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ProgramLauncher *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QVariantList*>(_v) = _t->programs(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->finish(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ProgramLauncher *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setPrograms(*reinterpret_cast< QVariantList*>(_v)); break;
        case 1: _t->isFinished(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject ProgramLauncher::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ProgramLauncher.data,
    qt_meta_data_ProgramLauncher,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ProgramLauncher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProgramLauncher::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProgramLauncher.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ProgramLauncher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ProgramLauncher::programsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ProgramLauncher::finishedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
