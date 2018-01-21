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
    QByteArrayData data[21];
    char stringdata0[274];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Engine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Engine_t qt_meta_stringdata_Engine = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Engine"
QT_MOC_LITERAL(1, 7, 16), // "AddNewGameObject"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 15), // "AddNewComponent"
QT_MOC_LITERAL(4, 41, 16), // "RemoveGameObject"
QT_MOC_LITERAL(5, 58, 15), // "RemoveComponent"
QT_MOC_LITERAL(6, 74, 17), // "ComponentSelected"
QT_MOC_LITERAL(7, 92, 21), // "ShowContextMenuGOList"
QT_MOC_LITERAL(8, 114, 3), // "pos"
QT_MOC_LITERAL(9, 118, 24), // "ShowContextMenuComponent"
QT_MOC_LITERAL(10, 143, 15), // "ExitApplication"
QT_MOC_LITERAL(11, 159, 14), // "CreateNewScene"
QT_MOC_LITERAL(12, 174, 6), // "Rotate"
QT_MOC_LITERAL(13, 181, 9), // "OpenScene"
QT_MOC_LITERAL(14, 191, 16), // "SaveCurrentScene"
QT_MOC_LITERAL(15, 208, 13), // "SaveAllScenes"
QT_MOC_LITERAL(16, 222, 11), // "SceneSwitch"
QT_MOC_LITERAL(17, 234, 10), // "GOSelected"
QT_MOC_LITERAL(18, 245, 5), // "index"
QT_MOC_LITERAL(19, 251, 5), // "GetUI"
QT_MOC_LITERAL(20, 257, 16) // "Ui::EngineClass*"

    },
    "Engine\0AddNewGameObject\0\0AddNewComponent\0"
    "RemoveGameObject\0RemoveComponent\0"
    "ComponentSelected\0ShowContextMenuGOList\0"
    "pos\0ShowContextMenuComponent\0"
    "ExitApplication\0CreateNewScene\0Rotate\0"
    "OpenScene\0SaveCurrentScene\0SaveAllScenes\0"
    "SceneSwitch\0GOSelected\0index\0GetUI\0"
    "Ui::EngineClass*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Engine[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    1,   98,    2, 0x08 /* Private */,
       7,    1,  101,    2, 0x08 /* Private */,
       9,    1,  104,    2, 0x08 /* Private */,
      10,    0,  107,    2, 0x08 /* Private */,
      11,    0,  108,    2, 0x08 /* Private */,
      12,    0,  109,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    0,  111,    2, 0x08 /* Private */,
      15,    0,  112,    2, 0x08 /* Private */,
      16,    0,  113,    2, 0x08 /* Private */,
      17,    1,  114,    2, 0x08 /* Private */,
      19,    0,  117,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QPoint,    8,
    QMetaType::Void, QMetaType::QPoint,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   18,
    0x80000000 | 20,

       0        // eod
};

void Engine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Engine *_t = static_cast<Engine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->AddNewGameObject(); break;
        case 1: _t->AddNewComponent(); break;
        case 2: _t->RemoveGameObject(); break;
        case 3: _t->RemoveComponent(); break;
        case 4: _t->ComponentSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->ShowContextMenuGOList((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 6: _t->ShowContextMenuComponent((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 7: _t->ExitApplication(); break;
        case 8: _t->CreateNewScene(); break;
        case 9: _t->Rotate(); break;
        case 10: _t->OpenScene(); break;
        case 11: _t->SaveCurrentScene(); break;
        case 12: _t->SaveAllScenes(); break;
        case 13: _t->SceneSwitch(); break;
        case 14: _t->GOSelected((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 15: { Ui::EngineClass* _r = _t->GetUI();
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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
