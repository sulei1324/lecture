/****************************************************************************
** Meta object code from reading C++ file 'lecture.h'
**
** Created: Thu Jan 7 09:56:07 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lecture.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lecture.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_lecture[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x0a,
      28,    8,    8,    8, 0x0a,
      47,    8,    8,    8, 0x0a,
      66,    8,    8,    8, 0x0a,
      85,    8,    8,    8, 0x0a,
     104,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_lecture[] = {
    "lecture\0\0button1OnClicked()\0"
    "button2OnClicked()\0button3OnClicked()\0"
    "button4OnClicked()\0button5OnClicked()\0"
    "button6OnClicked()\0"
};

void lecture::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        lecture *_t = static_cast<lecture *>(_o);
        switch (_id) {
        case 0: _t->button1OnClicked(); break;
        case 1: _t->button2OnClicked(); break;
        case 2: _t->button3OnClicked(); break;
        case 3: _t->button4OnClicked(); break;
        case 4: _t->button5OnClicked(); break;
        case 5: _t->button6OnClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData lecture::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject lecture::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_lecture,
      qt_meta_data_lecture, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &lecture::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *lecture::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *lecture::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_lecture))
        return static_cast<void*>(const_cast< lecture*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int lecture::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
