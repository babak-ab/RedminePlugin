/****************************************************************************
** Meta object code from reading C++ file 'qrest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qrest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qrest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QRest_t {
    QByteArrayData data[17];
    char stringdata0[214];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QRest_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QRest_t qt_meta_stringdata_QRest = {
    {
QT_MOC_LITERAL(0, 0, 5), // "QRest"
QT_MOC_LITERAL(1, 6, 10), // "replyError"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 14), // "QNetworkReply*"
QT_MOC_LITERAL(4, 33, 5), // "reply"
QT_MOC_LITERAL(5, 39, 27), // "QNetworkReply::NetworkError"
QT_MOC_LITERAL(6, 67, 5), // "error"
QT_MOC_LITERAL(7, 73, 11), // "errorString"
QT_MOC_LITERAL(8, 85, 16), // "sltReplyFinished"
QT_MOC_LITERAL(9, 102, 12), // "sltSslErrors"
QT_MOC_LITERAL(10, 115, 16), // "QList<QSslError>"
QT_MOC_LITERAL(11, 132, 3), // "err"
QT_MOC_LITERAL(12, 136, 24), // "sltAuthenticationRequest"
QT_MOC_LITERAL(13, 161, 15), // "QAuthenticator*"
QT_MOC_LITERAL(14, 177, 4), // "auth"
QT_MOC_LITERAL(15, 182, 13), // "sltReplyError"
QT_MOC_LITERAL(16, 196, 17) // "sltReplyReadyRead"

    },
    "QRest\0replyError\0\0QNetworkReply*\0reply\0"
    "QNetworkReply::NetworkError\0error\0"
    "errorString\0sltReplyFinished\0sltSslErrors\0"
    "QList<QSslError>\0err\0sltAuthenticationRequest\0"
    "QAuthenticator*\0auth\0sltReplyError\0"
    "sltReplyReadyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QRest[] = {

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
       1,    3,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   51,    2, 0x08 /* Private */,
       9,    1,   54,    2, 0x08 /* Private */,
      12,    2,   57,    2, 0x08 /* Private */,
      15,    1,   62,    2, 0x08 /* Private */,
      16,    0,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::QString,    4,    6,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 13,    4,   14,
    QMetaType::Void, 0x80000000 | 5,   11,
    QMetaType::Void,

       0        // eod
};

void QRest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QRest *_t = static_cast<QRest *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->replyError((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->sltReplyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: _t->sltSslErrors((*reinterpret_cast< const QList<QSslError>(*)>(_a[1]))); break;
        case 3: _t->sltAuthenticationRequest((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< QAuthenticator*(*)>(_a[2]))); break;
        case 4: _t->sltReplyError((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 5: _t->sltReplyReadyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QSslError> >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QRest::*_t)(QNetworkReply * , QNetworkReply::NetworkError , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QRest::replyError)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject QRest::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QRest.data,
      qt_meta_data_QRest,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QRest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QRest::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QRest.stringdata0))
        return static_cast<void*>(const_cast< QRest*>(this));
    return QObject::qt_metacast(_clname);
}

int QRest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void QRest::replyError(QNetworkReply * _t1, QNetworkReply::NetworkError _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
