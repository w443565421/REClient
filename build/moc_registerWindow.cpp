/****************************************************************************
** Meta object code from reading C++ file 'registerWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../registerWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'registerWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_registerWindow_t {
    QByteArrayData data[15];
    char stringdata0[342];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_registerWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_registerWindow_t qt_meta_stringdata_registerWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "registerWindow"
QT_MOC_LITERAL(1, 15, 33), // "newdocker_process_finished_si..."
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 34), // "stopdocker_process_finished_s..."
QT_MOC_LITERAL(4, 85, 17), // "after_send_failed"
QT_MOC_LITERAL(5, 103, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(6, 125, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(7, 149, 25), // "newdocker_process_started"
QT_MOC_LITERAL(8, 175, 26), // "newdocker_process_finished"
QT_MOC_LITERAL(9, 202, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(10, 223, 26), // "stopdocker_process_started"
QT_MOC_LITERAL(11, 250, 27), // "stopdocker_process_finished"
QT_MOC_LITERAL(12, 278, 18), // "ready_to_newdocker"
QT_MOC_LITERAL(13, 297, 24), // "content_from_send_thread"
QT_MOC_LITERAL(14, 322, 19) // "ready_to_stopdocker"

    },
    "registerWindow\0newdocker_process_finished_signal\0"
    "\0stopdocker_process_finished_signal\0"
    "after_send_failed\0on_pushButton_clicked\0"
    "on_pushButton_2_clicked\0"
    "newdocker_process_started\0"
    "newdocker_process_finished\0"
    "QProcess::ExitStatus\0stopdocker_process_started\0"
    "stopdocker_process_finished\0"
    "ready_to_newdocker\0content_from_send_thread\0"
    "ready_to_stopdocker"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_registerWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    2,   75,    2, 0x08 /* Private */,
      10,    0,   80,    2, 0x08 /* Private */,
      11,    2,   81,    2, 0x08 /* Private */,
      12,    1,   86,    2, 0x08 /* Private */,
      14,    0,   89,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 9,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 9,    2,    2,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void,

       0        // eod
};

void registerWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        registerWindow *_t = static_cast<registerWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newdocker_process_finished_signal(); break;
        case 1: _t->stopdocker_process_finished_signal(); break;
        case 2: _t->after_send_failed(); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_pushButton_2_clicked(); break;
        case 5: _t->newdocker_process_started(); break;
        case 6: _t->newdocker_process_finished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 7: _t->stopdocker_process_started(); break;
        case 8: _t->stopdocker_process_finished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 9: _t->ready_to_newdocker((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->ready_to_stopdocker(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (registerWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&registerWindow::newdocker_process_finished_signal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (registerWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&registerWindow::stopdocker_process_finished_signal)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject registerWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_registerWindow.data,
      qt_meta_data_registerWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *registerWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *registerWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_registerWindow.stringdata0))
        return static_cast<void*>(const_cast< registerWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int registerWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void registerWindow::newdocker_process_finished_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void registerWindow::stopdocker_process_finished_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
