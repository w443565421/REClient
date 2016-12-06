/****************************************************************************
** Meta object code from reading C++ file 'modifyDialogThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../modifyDialogThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modifyDialogThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ModifyDialogThread_t {
    QByteArrayData data[3];
    char stringdata0[53];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModifyDialogThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModifyDialogThread_t qt_meta_stringdata_ModifyDialogThread = {
    {
QT_MOC_LITERAL(0, 0, 18), // "ModifyDialogThread"
QT_MOC_LITERAL(1, 19, 32), // "stopdocker_process_finished_slot"
QT_MOC_LITERAL(2, 52, 0) // ""

    },
    "ModifyDialogThread\0stopdocker_process_finished_slot\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModifyDialogThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void ModifyDialogThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ModifyDialogThread *_t = static_cast<ModifyDialogThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stopdocker_process_finished_slot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ModifyDialogThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ModifyDialogThread.data,
      qt_meta_data_ModifyDialogThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ModifyDialogThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModifyDialogThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ModifyDialogThread.stringdata0))
        return static_cast<void*>(const_cast< ModifyDialogThread*>(this));
    return QThread::qt_metacast(_clname);
}

int ModifyDialogThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
