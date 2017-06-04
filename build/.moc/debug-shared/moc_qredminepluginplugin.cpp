/****************************************************************************
** Meta object code from reading C++ file 'qredminepluginplugin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../qredmineplugin/qredminepluginplugin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qredminepluginplugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QRedminePlugin__Internal__QRedminePluginPlugin_t {
    QByteArrayData data[1];
    char stringdata0[47];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QRedminePlugin__Internal__QRedminePluginPlugin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QRedminePlugin__Internal__QRedminePluginPlugin_t qt_meta_stringdata_QRedminePlugin__Internal__QRedminePluginPlugin = {
    {
QT_MOC_LITERAL(0, 0, 46) // "QRedminePlugin::Internal::QRe..."

    },
    "QRedminePlugin::Internal::QRedminePluginPlugin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QRedminePlugin__Internal__QRedminePluginPlugin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void QRedminePlugin::Internal::QRedminePluginPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject QRedminePlugin::Internal::QRedminePluginPlugin::staticMetaObject = {
    { &ExtensionSystem::IPlugin::staticMetaObject, qt_meta_stringdata_QRedminePlugin__Internal__QRedminePluginPlugin.data,
      qt_meta_data_QRedminePlugin__Internal__QRedminePluginPlugin,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QRedminePlugin::Internal::QRedminePluginPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QRedminePlugin::Internal::QRedminePluginPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QRedminePlugin__Internal__QRedminePluginPlugin.stringdata0))
        return static_cast<void*>(const_cast< QRedminePluginPlugin*>(this));
    return ExtensionSystem::IPlugin::qt_metacast(_clname);
}

int QRedminePlugin::Internal::QRedminePluginPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ExtensionSystem::IPlugin::qt_metacall(_c, _id, _a);
    return _id;
}

QT_PLUGIN_METADATA_SECTION const uint qt_section_alignment_dummy = 42;

#ifdef QT_NO_DEBUG

QT_PLUGIN_METADATA_SECTION
static const unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', ' ',
    'q',  'b',  'j',  's',  0x01, 0x00, 0x00, 0x00,
    'T',  0x02, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
    '@',  0x02, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x03, 0x00, 'I',  'I',  'D',  0x00, 0x00, 0x00,
    '!',  0x00, 'o',  'r',  'g',  '.',  'q',  't', 
    '-',  'p',  'r',  'o',  'j',  'e',  'c',  't', 
    '.',  'Q',  't',  '.',  'Q',  't',  'C',  'r', 
    'e',  'a',  't',  'o',  'r',  'P',  'l',  'u', 
    'g',  'i',  'n',  0x00, 0x9b, 0x09, 0x00, 0x00,
    0x09, 0x00, 'c',  'l',  'a',  's',  's',  'N', 
    'a',  'm',  'e',  0x00, 0x14, 0x00, 'Q',  'R', 
    'e',  'd',  'm',  'i',  'n',  'e',  'P',  'l', 
    'u',  'g',  'i',  'n',  'P',  'l',  'u',  'g', 
    'i',  'n',  0x00, 0x00, 0x1a, ' ',  0xa1, 0x00,
    0x07, 0x00, 'v',  'e',  'r',  's',  'i',  'o', 
    'n',  0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00,
    0x05, 0x00, 'd',  'e',  'b',  'u',  'g',  0x00,
    0x15, 0x12, 0x00, 0x00, 0x08, 0x00, 'M',  'e', 
    't',  'a',  'D',  'a',  't',  'a',  0x00, 0x00,
    0xb0, 0x01, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00,
    0x8c, 0x01, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x04, 0x00, 'N',  'a',  'm',  'e',  0x00, 0x00,
    0x0e, 0x00, 'Q',  'R',  'e',  'd',  'm',  'i', 
    'n',  'e',  'P',  'l',  'u',  'g',  'i',  'n', 
    0x1b, 0x07, 0x00, 0x00, 0x07, 0x00, 'V',  'e', 
    'r',  's',  'i',  'o',  'n',  0x00, 0x00, 0x00,
    0x05, 0x00, '0',  '.',  '0',  '.',  '1',  0x00,
    0x9b, 0x0a, 0x00, 0x00, 0x0d, 0x00, 'C',  'o', 
    'm',  'p',  'a',  't',  'V',  'e',  'r',  's', 
    'i',  'o',  'n',  0x00, 0x05, 0x00, '0',  '.', 
    '0',  '.',  '1',  0x00, 0x1b, 0x0d, 0x00, 0x00,
    0x06, 0x00, 'V',  'e',  'n',  'd',  'o',  'r', 
    0x0a, 0x00, 'O',  'p',  'e',  'n',  's',  'o', 
    'u',  'r',  'c',  'e',  0x9b, 0x10, 0x00, 0x00,
    0x09, 0x00, 'C',  'o',  'p',  'y',  'r',  'i', 
    'g',  'h',  't',  0x00, 0x0d, 0x00, '(',  'C', 
    ')',  ' ',  'M',  'y',  'C',  'o',  'm',  'p', 
    'a',  'n',  'y',  0x00, 0x9b, 0x14, 0x00, 0x00,
    0x07, 0x00, 'L',  'i',  'c',  'e',  'n',  's', 
    'e',  0x00, 0x00, 0x00, ' ',  0x00, 'G',  'N', 
    'U',  ' ',  'G',  'e',  'n',  'e',  'r',  'a', 
    'l',  ' ',  'P',  'u',  'b',  'l',  'i',  'c', 
    ' ',  'L',  'i',  'c',  'e',  'n',  's',  'e', 
    ' ',  '(',  'G',  'P',  'L',  ')',  0x00, 0x00,
    0x9b, 0x1b, 0x00, 0x00, 0x0b, 0x00, 'D',  'e', 
    's',  'c',  'r',  'i',  'p',  't',  'i',  'o', 
    'n',  0x00, 0x00, 0x00, 0x1d, 0x00, 'R',  'e', 
    'd',  'm',  'i',  'n',  'e',  ' ',  'c',  'l', 
    'i',  'e',  'n',  't',  ' ',  'f',  'o',  'r', 
    ' ',  'q',  't',  ' ',  'c',  'r',  'e',  'a', 
    't',  'o',  'r',  0x00, 0x1b, '!',  0x00, 0x00,
    0x03, 0x00, 'U',  'r',  'l',  0x00, 0x00, 0x00,
    0x1c, 0x00, 'h',  't',  't',  'p',  's',  ':', 
    '/',  '/',  'g',  'i',  't',  'h',  'u',  'b', 
    '.',  'c',  'o',  'm',  '/',  'b',  'a',  'b', 
    'a',  'k',  '-',  'a',  'b',  '/',  0x00, 0x00,
    0x94, '\'', 0x00, 0x00, 0x0c, 0x00, 'D',  'e', 
    'p',  'e',  'n',  'd',  'e',  'n',  'c',  'i', 
    'e',  's',  0x00, 0x00, 'P',  0x00, 0x00, 0x00,
    0x02, 0x00, 0x00, 0x00, 'L',  0x00, 0x00, 0x00,
    '@',  0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00,
    '8',  0x00, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x04, 0x00, 'N',  'a',  'm',  'e',  0x00, 0x00,
    0x04, 0x00, 'C',  'o',  'r',  'e',  0x00, 0x00,
    0x1b, 0x06, 0x00, 0x00, 0x07, 0x00, 'V',  'e', 
    'r',  's',  'i',  'o',  'n',  0x00, 0x00, 0x00,
    0x05, 0x00, '4',  '.',  '3',  '.',  '0',  0x00,
    0x0c, 0x00, 0x00, 0x00, ' ',  0x00, 0x00, 0x00,
    0x85, 0x01, 0x00, 0x00, '@',  0x00, 0x00, 0x00,
    't',  0x00, 0x00, 0x00, '(',  0x01, 0x00, 0x00,
    0xc8, 0x00, 0x00, 0x00, 0x94, 0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00,
    '\\', 0x00, 0x00, 0x00, '(',  0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00,
    '<',  0x00, 0x00, 0x00, 't',  0x00, 0x00, 0x00,
    'd',  0x00, 0x00, 0x00
};

#else // QT_NO_DEBUG

QT_PLUGIN_METADATA_SECTION
static const unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', ' ',
    'q',  'b',  'j',  's',  0x01, 0x00, 0x00, 0x00,
    'T',  0x02, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
    '@',  0x02, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x03, 0x00, 'I',  'I',  'D',  0x00, 0x00, 0x00,
    '!',  0x00, 'o',  'r',  'g',  '.',  'q',  't', 
    '-',  'p',  'r',  'o',  'j',  'e',  'c',  't', 
    '.',  'Q',  't',  '.',  'Q',  't',  'C',  'r', 
    'e',  'a',  't',  'o',  'r',  'P',  'l',  'u', 
    'g',  'i',  'n',  0x00, 0x95, 0x09, 0x00, 0x00,
    0x08, 0x00, 'M',  'e',  't',  'a',  'D',  'a', 
    't',  'a',  0x00, 0x00, 0xb0, 0x01, 0x00, 0x00,
    0x13, 0x00, 0x00, 0x00, 0x8c, 0x01, 0x00, 0x00,
    0x1b, 0x03, 0x00, 0x00, 0x04, 0x00, 'N',  'a', 
    'm',  'e',  0x00, 0x00, 0x0e, 0x00, 'Q',  'R', 
    'e',  'd',  'm',  'i',  'n',  'e',  'P',  'l', 
    'u',  'g',  'i',  'n',  0x1b, 0x07, 0x00, 0x00,
    0x07, 0x00, 'V',  'e',  'r',  's',  'i',  'o', 
    'n',  0x00, 0x00, 0x00, 0x05, 0x00, '0',  '.', 
    '0',  '.',  '1',  0x00, 0x9b, 0x0a, 0x00, 0x00,
    0x0d, 0x00, 'C',  'o',  'm',  'p',  'a',  't', 
    'V',  'e',  'r',  's',  'i',  'o',  'n',  0x00,
    0x05, 0x00, '0',  '.',  '0',  '.',  '1',  0x00,
    0x1b, 0x0d, 0x00, 0x00, 0x06, 0x00, 'V',  'e', 
    'n',  'd',  'o',  'r',  0x0a, 0x00, 'O',  'p', 
    'e',  'n',  's',  'o',  'u',  'r',  'c',  'e', 
    0x9b, 0x10, 0x00, 0x00, 0x09, 0x00, 'C',  'o', 
    'p',  'y',  'r',  'i',  'g',  'h',  't',  0x00,
    0x0d, 0x00, '(',  'C',  ')',  ' ',  'M',  'y', 
    'C',  'o',  'm',  'p',  'a',  'n',  'y',  0x00,
    0x9b, 0x14, 0x00, 0x00, 0x07, 0x00, 'L',  'i', 
    'c',  'e',  'n',  's',  'e',  0x00, 0x00, 0x00,
    ' ',  0x00, 'G',  'N',  'U',  ' ',  'G',  'e', 
    'n',  'e',  'r',  'a',  'l',  ' ',  'P',  'u', 
    'b',  'l',  'i',  'c',  ' ',  'L',  'i',  'c', 
    'e',  'n',  's',  'e',  ' ',  '(',  'G',  'P', 
    'L',  ')',  0x00, 0x00, 0x9b, 0x1b, 0x00, 0x00,
    0x0b, 0x00, 'D',  'e',  's',  'c',  'r',  'i', 
    'p',  't',  'i',  'o',  'n',  0x00, 0x00, 0x00,
    0x1d, 0x00, 'R',  'e',  'd',  'm',  'i',  'n', 
    'e',  ' ',  'c',  'l',  'i',  'e',  'n',  't', 
    ' ',  'f',  'o',  'r',  ' ',  'q',  't',  ' ', 
    'c',  'r',  'e',  'a',  't',  'o',  'r',  0x00,
    0x1b, '!',  0x00, 0x00, 0x03, 0x00, 'U',  'r', 
    'l',  0x00, 0x00, 0x00, 0x1c, 0x00, 'h',  't', 
    't',  'p',  's',  ':',  '/',  '/',  'g',  'i', 
    't',  'h',  'u',  'b',  '.',  'c',  'o',  'm', 
    '/',  'b',  'a',  'b',  'a',  'k',  '-',  'a', 
    'b',  '/',  0x00, 0x00, 0x94, '\'', 0x00, 0x00,
    0x0c, 0x00, 'D',  'e',  'p',  'e',  'n',  'd', 
    'e',  'n',  'c',  'i',  'e',  's',  0x00, 0x00,
    'P',  0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
    'L',  0x00, 0x00, 0x00, '@',  0x00, 0x00, 0x00,
    0x05, 0x00, 0x00, 0x00, '8',  0x00, 0x00, 0x00,
    0x1b, 0x03, 0x00, 0x00, 0x04, 0x00, 'N',  'a', 
    'm',  'e',  0x00, 0x00, 0x04, 0x00, 'C',  'o', 
    'r',  'e',  0x00, 0x00, 0x1b, 0x06, 0x00, 0x00,
    0x07, 0x00, 'V',  'e',  'r',  's',  'i',  'o', 
    'n',  0x00, 0x00, 0x00, 0x05, 0x00, '4',  '.', 
    '3',  '.',  '0',  0x00, 0x0c, 0x00, 0x00, 0x00,
    ' ',  0x00, 0x00, 0x00, 0x85, 0x01, 0x00, 0x00,
    '@',  0x00, 0x00, 0x00, 't',  0x00, 0x00, 0x00,
    '(',  0x01, 0x00, 0x00, 0xc8, 0x00, 0x00, 0x00,
    0x94, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    0xfc, 0x00, 0x00, 0x00, '\\', 0x00, 0x00, 0x00,
    '(',  0x00, 0x00, 0x00, 0x9b, 'A',  0x00, 0x00,
    0x09, 0x00, 'c',  'l',  'a',  's',  's',  'N', 
    'a',  'm',  'e',  0x00, 0x14, 0x00, 'Q',  'R', 
    'e',  'd',  'm',  'i',  'n',  'e',  'P',  'l', 
    'u',  'g',  'i',  'n',  'P',  'l',  'u',  'g', 
    'i',  'n',  0x00, 0x00, '1',  0x00, 0x00, 0x00,
    0x05, 0x00, 'd',  'e',  'b',  'u',  'g',  0x00,
    0x1a, ' ',  0xa1, 0x00, 0x07, 0x00, 'v',  'e', 
    'r',  's',  'i',  'o',  'n',  0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, '<',  0x00, 0x00, 0x00,
    0xfc, 0x01, 0x00, 0x00, '$',  0x02, 0x00, 0x00,
    '0',  0x02, 0x00, 0x00
};
#endif // QT_NO_DEBUG

using namespace QRedminePlugin;
using namespace QRedminePlugin::Internal;
QT_MOC_EXPORT_PLUGIN(QRedminePlugin::Internal::QRedminePluginPlugin, QRedminePluginPlugin)

QT_WARNING_POP
QT_END_MOC_NAMESPACE
