/****************************************************************************
** Meta object code from reading C++ file 'ibase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../RedminePlugin/redmineclinet/ibase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ibase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IBase_t {
    QByteArrayData data[9];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IBase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IBase_t qt_meta_stringdata_IBase = {
    {
QT_MOC_LITERAL(0, 0, 5), // "IBase"
QT_MOC_LITERAL(1, 6, 13), // "sigReplyError"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 11), // "ReplayError"
QT_MOC_LITERAL(4, 33, 3), // "err"
QT_MOC_LITERAL(5, 37, 10), // "sigReplyOk"
QT_MOC_LITERAL(6, 48, 16), // "sltReplyFinished"
QT_MOC_LITERAL(7, 65, 14), // "QNetworkReply*"
QT_MOC_LITERAL(8, 80, 5) // "reply"

    },
    "IBase\0sigReplyError\0\0ReplayError\0err\0"
    "sigReplyOk\0sltReplyFinished\0QNetworkReply*\0"
    "reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IBase[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       5,    0,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void IBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IBase *_t = static_cast<IBase *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigReplyError((*reinterpret_cast< ReplayError(*)>(_a[1]))); break;
        case 1: _t->sigReplyOk(); break;
        case 2: _t->sltReplyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IBase::*_t)(ReplayError );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IBase::sigReplyError)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (IBase::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IBase::sigReplyOk)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject IBase::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_IBase.data,
      qt_meta_data_IBase,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *IBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IBase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IBase.stringdata0))
        return static_cast<void*>(const_cast< IBase*>(this));
    return QObject::qt_metacast(_clname);
}

int IBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
