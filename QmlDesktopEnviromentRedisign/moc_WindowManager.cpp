/****************************************************************************
** Meta object code from reading C++ file 'WindowManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "WindowManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WindowManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WindowManager_t {
    QByteArrayData data[16];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WindowManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WindowManager_t qt_meta_stringdata_WindowManager = {
    {
QT_MOC_LITERAL(0, 0, 13), // "WindowManager"
QT_MOC_LITERAL(1, 14, 17), // "dataWindowChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 6), // "reload"
QT_MOC_LITERAL(4, 40, 8), // "minimize"
QT_MOC_LITERAL(5, 49, 4), // "back"
QT_MOC_LITERAL(6, 54, 13), // "restoreWindow"
QT_MOC_LITERAL(7, 68, 2), // "id"
QT_MOC_LITERAL(8, 71, 5), // "index"
QT_MOC_LITERAL(9, 77, 10), // "killWindow"
QT_MOC_LITERAL(10, 88, 14), // "killAllWindows"
QT_MOC_LITERAL(11, 103, 15), // "setAllwaysOnTop"
QT_MOC_LITERAL(12, 119, 12), // "allwaysOnTop"
QT_MOC_LITERAL(13, 132, 8), // "setOnTop"
QT_MOC_LITERAL(14, 141, 5), // "onTop"
QT_MOC_LITERAL(15, 147, 4) // "data"

    },
    "WindowManager\0dataWindowChanged\0\0"
    "reload\0minimize\0back\0restoreWindow\0"
    "id\0index\0killWindow\0killAllWindows\0"
    "setAllwaysOnTop\0allwaysOnTop\0setOnTop\0"
    "onTop\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WindowManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       1,   78, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       3,    0,   60,    2, 0x00 /* Private */,
       4,    0,   61,    2, 0x02 /* Public */,
       5,    0,   62,    2, 0x02 /* Public */,
       6,    2,   63,    2, 0x02 /* Public */,
       9,    1,   68,    2, 0x02 /* Public */,
      10,    0,   71,    2, 0x02 /* Public */,
      11,    1,   72,    2, 0x02 /* Public */,
      13,    1,   75,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Long, QMetaType::Int,    7,    8,
    QMetaType::Void, QMetaType::Long,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   14,

 // properties: name, type, flags
      15, QMetaType::QVariantList, 0x00495103,

 // properties: notify_signal_id
       0,

       0        // eod
};

void WindowManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WindowManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataWindowChanged(); break;
        case 1: _t->reload(); break;
        case 2: _t->minimize(); break;
        case 3: _t->back(); break;
        case 4: _t->restoreWindow((*reinterpret_cast< long(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->killWindow((*reinterpret_cast< long(*)>(_a[1]))); break;
        case 6: _t->killAllWindows(); break;
        case 7: _t->setAllwaysOnTop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setOnTop((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WindowManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WindowManager::dataWindowChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<WindowManager *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QVariantList*>(_v) = _t->data(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<WindowManager *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setData(*reinterpret_cast< QVariantList*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject WindowManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_WindowManager.data,
    qt_meta_data_WindowManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WindowManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WindowManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WindowManager.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int WindowManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void WindowManager::dataWindowChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
