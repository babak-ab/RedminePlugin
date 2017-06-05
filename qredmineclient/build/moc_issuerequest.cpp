/****************************************************************************
** Meta object code from reading C++ file 'issuerequest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../issuerequest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'issuerequest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IssueRequest_t {
    QByteArrayData data[9];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IssueRequest_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IssueRequest_t qt_meta_stringdata_IssueRequest = {
    {
QT_MOC_LITERAL(0, 0, 12), // "IssueRequest"
QT_MOC_LITERAL(1, 13, 13), // "sigReplyError"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 15), // "ConnectionError"
QT_MOC_LITERAL(4, 44, 3), // "err"
QT_MOC_LITERAL(5, 48, 15), // "sigRecvResponse"
QT_MOC_LITERAL(6, 64, 16), // "sltReplyFinished"
QT_MOC_LITERAL(7, 81, 14), // "QNetworkReply*"
QT_MOC_LITERAL(8, 96, 5) // "reply"

    },
    "IssueRequest\0sigReplyError\0\0ConnectionError\0"
    "err\0sigRecvResponse\0sltReplyFinished\0"
    "QNetworkReply*\0reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IssueRequest[] = {

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

void IssueRequest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IssueRequest *_t = static_cast<IssueRequest *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigReplyError((*reinterpret_cast< ConnectionError(*)>(_a[1]))); break;
        case 1: _t->sigRecvResponse(); break;
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
            typedef void (IssueRequest::*_t)(ConnectionError );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IssueRequest::sigReplyError)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (IssueRequest::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IssueRequest::sigRecvResponse)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject IssueRequest::staticMetaObject = {
    { &IBase::staticMetaObject, qt_meta_stringdata_IssueRequest.data,
      qt_meta_data_IssueRequest,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *IssueRequest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IssueRequest::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IssueRequest.stringdata0))
        return static_cast<void*>(const_cast< IssueRequest*>(this));
    return IBase::qt_metacast(_clname);
}

int IssueRequest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IBase::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void IssueRequest::sigReplyError(ConnectionError _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void IssueRequest::sigRecvResponse()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
