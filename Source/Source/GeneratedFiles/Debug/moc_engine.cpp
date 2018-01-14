/****************************************************************************
** Meta object code from reading C++ file 'engine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../engine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'engine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Engine_t {
    QByteArrayData data[17];
    char stringdata0[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Engine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Engine_t qt_meta_stringdata_Engine = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Engine"
QT_MOC_LITERAL(1, 7, 15), // "ExitApplication"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 14), // "CreateNewScene"
QT_MOC_LITERAL(4, 39, 6), // "Rotate"
QT_MOC_LITERAL(5, 46, 9), // "OpenScene"
QT_MOC_LITERAL(6, 56, 16), // "SaveCurrentScene"
QT_MOC_LITERAL(7, 73, 13), // "SaveAllScenes"
QT_MOC_LITERAL(8, 87, 12), // "GetListScene"
QT_MOC_LITERAL(9, 100, 19), // "std::vector<Scene*>"
QT_MOC_LITERAL(10, 120, 14), // "GetSceneByName"
QT_MOC_LITERAL(11, 135, 6), // "Scene*"
QT_MOC_LITERAL(12, 142, 12), // "std::string&"
QT_MOC_LITERAL(13, 155, 4), // "name"
QT_MOC_LITERAL(14, 160, 14), // "GetActiveScene"
QT_MOC_LITERAL(15, 175, 5), // "GetUI"
QT_MOC_LITERAL(16, 181, 16) // "Ui::EngineClass*"

    },
    "Engine\0ExitApplication\0\0CreateNewScene\0"
    "Rotate\0OpenScene\0SaveCurrentScene\0"
    "SaveAllScenes\0GetListScene\0"
    "std::vector<Scene*>\0GetSceneByName\0"
    "Scene*\0std::string&\0name\0GetActiveScene\0"
    "GetUI\0Ui::EngineClass*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Engine[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
      10,    1,   71,    2, 0x08 /* Private */,
      14,    0,   74,    2, 0x08 /* Private */,
      15,    0,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 9,
    0x80000000 | 11, 0x80000000 | 12,   13,
    0x80000000 | 11,
    0x80000000 | 16,

       0        // eod
};

void Engine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Engine *_t = static_cast<Engine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ExitApplication(); break;
        case 1: _t->CreateNewScene(); break;
        case 2: _t->Rotate(); break;
        case 3: _t->OpenScene(); break;
        case 4: _t->SaveCurrentScene(); break;
        case 5: _t->SaveAllScenes(); break;
        case 6: { std::vector<Scene*> _r = _t->GetListScene();
            if (_a[0]) *reinterpret_cast< std::vector<Scene*>*>(_a[0]) = _r; }  break;
        case 7: { Scene* _r = _t->GetSceneByName((*reinterpret_cast< std::string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Scene**>(_a[0]) = _r; }  break;
        case 8: { Scene* _r = _t->GetActiveScene();
            if (_a[0]) *reinterpret_cast< Scene**>(_a[0]) = _r; }  break;
        case 9: { Ui::EngineClass* _r = _t->GetUI();
            if (_a[0]) *reinterpret_cast< Ui::EngineClass**>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject Engine::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Engine.data,
      qt_meta_data_Engine,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Engine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Engine::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Engine.stringdata0))
        return static_cast<void*>(const_cast< Engine*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Engine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
