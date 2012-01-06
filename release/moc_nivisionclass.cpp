/****************************************************************************
** Meta object code from reading C++ file 'nivisionclass.h'
**
** Created: Tue Jan 3 15:25:33 2012
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../nivisionclass.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nivisionclass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NIVisionClass[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      27,   15,   14,   14, 0x05,
      68,   63,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     102,   14,   14,   14, 0x0a,
     120,   14,   14,   14, 0x0a,
     139,   14,   14,   14, 0x0a,
     182,  158,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_NIVisionClass[] = {
    "NIVisionClass\0\0niVisionVar\0"
    "NIVisionVarsChanged(NIVisionClass*)\0"
    "rect\0NIVisionPointToolClickEvent(Rect)\0"
    "slotToggleTools()\0slotToggleImage1()\0"
    "slotToggleImage2()\0displayWinNum,numX,numY\0"
    "slotUpdateVisionWindows(int,int,int)\0"
};

const QMetaObject NIVisionClass::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_NIVisionClass,
      qt_meta_data_NIVisionClass, 0 }
};

const QMetaObject *NIVisionClass::metaObject() const
{
    return &staticMetaObject;
}

void *NIVisionClass::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NIVisionClass))
        return static_cast<void*>(const_cast< NIVisionClass*>(this));
    return QObject::qt_metacast(_clname);
}

int NIVisionClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: NIVisionVarsChanged((*reinterpret_cast< NIVisionClass*(*)>(_a[1]))); break;
        case 1: NIVisionPointToolClickEvent((*reinterpret_cast< Rect(*)>(_a[1]))); break;
        case 2: slotToggleTools(); break;
        case 3: slotToggleImage1(); break;
        case 4: slotToggleImage2(); break;
        case 5: slotUpdateVisionWindows((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void NIVisionClass::NIVisionVarsChanged(NIVisionClass * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NIVisionClass::NIVisionPointToolClickEvent(Rect _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
