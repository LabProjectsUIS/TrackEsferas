/****************************************************************************
** Meta object code from reading C++ file 'GUIUpdater.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GUIUpdater.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUIUpdater.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GUIUpdater_t {
    QByteArrayData data[9];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GUIUpdater_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GUIUpdater_t qt_meta_stringdata_GUIUpdater = {
    {
QT_MOC_LITERAL(0, 0, 10), // "GUIUpdater"
QT_MOC_LITERAL(1, 11, 16), // "updateLeftCamera"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 17), // "updateRightCamera"
QT_MOC_LITERAL(4, 47, 7), // "doFlash"
QT_MOC_LITERAL(5, 55, 16), // "startCalibration"
QT_MOC_LITERAL(6, 72, 11), // "startServer"
QT_MOC_LITERAL(7, 84, 15), // "pointerDetected"
QT_MOC_LITERAL(8, 100, 18) // "pointerNotDetected"

    },
    "GUIUpdater\0updateLeftCamera\0\0"
    "updateRightCamera\0doFlash\0startCalibration\0"
    "startServer\0pointerDetected\0"
    "pointerNotDetected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GUIUpdater[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    1,   52,    2, 0x06 /* Public */,
       4,    0,   55,    2, 0x06 /* Public */,
       5,    0,   56,    2, 0x06 /* Public */,
       6,    0,   57,    2, 0x06 /* Public */,
       7,    0,   58,    2, 0x06 /* Public */,
       8,    0,   59,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GUIUpdater::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GUIUpdater *_t = static_cast<GUIUpdater *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateLeftCamera((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 1: _t->updateRightCamera((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 2: _t->doFlash(); break;
        case 3: _t->startCalibration(); break;
        case 4: _t->startServer(); break;
        case 5: _t->pointerDetected(); break;
        case 6: _t->pointerNotDetected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GUIUpdater::*_t)(const QImage & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GUIUpdater::updateLeftCamera)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GUIUpdater::*_t)(const QImage & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GUIUpdater::updateRightCamera)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (GUIUpdater::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GUIUpdater::doFlash)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (GUIUpdater::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GUIUpdater::startCalibration)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (GUIUpdater::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GUIUpdater::startServer)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (GUIUpdater::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GUIUpdater::pointerDetected)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (GUIUpdater::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GUIUpdater::pointerNotDetected)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject GUIUpdater::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GUIUpdater.data,
      qt_meta_data_GUIUpdater,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GUIUpdater::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GUIUpdater::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GUIUpdater.stringdata0))
        return static_cast<void*>(const_cast< GUIUpdater*>(this));
    return QObject::qt_metacast(_clname);
}

int GUIUpdater::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void GUIUpdater::updateLeftCamera(const QImage & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GUIUpdater::updateRightCamera(const QImage & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GUIUpdater::doFlash()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void GUIUpdater::startCalibration()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void GUIUpdater::startServer()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void GUIUpdater::pointerDetected()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void GUIUpdater::pointerNotDetected()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
