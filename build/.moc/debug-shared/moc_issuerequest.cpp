/****************************************************************************
** Meta object code from reading C++ file 'issuerequest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../RedminePlugin/redmineclinet/issue/issuerequest.h"
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
    QByteArrayData data[6];
    char stringdata0[55];
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
QT_MOC_LITERAL(3, 28, 11), // "ReplayError"
QT_MOC_LITERAL(4, 40, 3), // "err"
QT_MOC_LITERAL(5, 44, 10) // "sigReplyOk"

    },
    "IssueRequest\0sigReplyError\0\0ReplayError\0"
    "err\0sigReplyOk"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IssueRequest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       5,    0,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

       0        // eod
};

void IssueRequest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IssueRequest *_t = static_cast<IssueRequest *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigReplyError((*reinterpret_cast< ReplayError(*)>(_a[1]))); break;
        case 1: _t->sigReplyOk(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IssueRequest::*_t)(ReplayError );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IssueRequest::sigReplyError)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (IssueRequest::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IssueRequest::sigReplyOk)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject IssueRequest::staticMetaObject = {
    { &IManager::staticMetaObject, qt_meta_stringdata_IssueRequest.data,
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
    return IManager::qt_metacast(_clname);
}

int IssueRequest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void IssueRequest::sigReplyError(ReplayError _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void IssueRequest::sigReplyOk()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
