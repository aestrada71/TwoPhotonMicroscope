/****************************************************************************
** Meta object code from reading C++ file 'AcqThread.h'
**
** Created: Tue Jan 3 15:25:32 2012
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AcqThread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AcqThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AcqThread[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      34,   25,   10,   10, 0x05,
      60,   55,   10,   10, 0x05,
      93,   82,   10,   10, 0x05,
     132,  121,   10,   10, 0x05,
     167,  160,   10,   10, 0x05,
     195,  188,   10,   10, 0x05,
     230,  216,   10,   10, 0x05,
     281,  267,   10,   10, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_AcqThread[] = {
    "AcqThread\0\0acqFinished()\0progress\0"
    "sendProgress(double)\0zPos\0"
    "sigZPosChange(double)\0imageData1\0"
    "imageData1Change(RGBValue*)\0imageData2\0"
    "imageData2Change(RGBValue*)\0image1\0"
    "image1Change(Image*)\0image2\0"
    "image2Change(Image*)\0title,message\0"
    "sendMessageForPopup(QString,QString)\0"
    "win,numx,numy\0sigUdateVisionWindows(int,int,int)\0"
};

const QMetaObject AcqThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_AcqThread,
      qt_meta_data_AcqThread, 0 }
};

const QMetaObject *AcqThread::metaObject() const
{
    return &staticMetaObject;
}

void *AcqThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AcqThread))
        return static_cast<void*>(const_cast< AcqThread*>(this));
    return QThread::qt_metacast(_clname);
}

int AcqThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: acqFinished(); break;
        case 1: sendProgress((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: sigZPosChange((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: imageData1Change((*reinterpret_cast< RGBValue*(*)>(_a[1]))); break;
        case 4: imageData2Change((*reinterpret_cast< RGBValue*(*)>(_a[1]))); break;
        case 5: image1Change((*reinterpret_cast< Image*(*)>(_a[1]))); break;
        case 6: image2Change((*reinterpret_cast< Image*(*)>(_a[1]))); break;
        case 7: sendMessageForPopup((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: sigUdateVisionWindows((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void AcqThread::acqFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void AcqThread::sendProgress(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AcqThread::sigZPosChange(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AcqThread::imageData1Change(RGBValue * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void AcqThread::imageData2Change(RGBValue * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void AcqThread::image1Change(Image * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void AcqThread::image2Change(Image * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void AcqThread::sendMessageForPopup(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void AcqThread::sigUdateVisionWindows(int _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
