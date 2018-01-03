/********************************************************************************
** Form generated from reading UI file 'engine.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENGINE_H
#define UI_ENGINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EngineClass
{
public:
    QAction *actionNew_scene;
    QAction *actionOpen_Scene;
    QAction *actionSave_current_Scene;
    QAction *actionSave_all_Scenes;
    QWidget *centralWidget;
    QPushButton *exitBtn;
    QTabWidget *sceneTab;
    QWidget *tab;
    QOpenGLWidget *sceneRender1;
    QWidget *tab_2;
    QOpenGLWidget *sceneRender2;
    QPushButton *rotateBtn;
    QPushButton *scaleBtn;
    QPushButton *translateBtn;
    QTreeView *treeView;
    QLabel *gameObjectList;
    QLabel *label;
    QToolBox *toolBox;
    QWidget *page;
    QWidget *page_2;
    QComboBox *selectComponent;
    QMenuBar *menuBar;
    QMenu *fileMenu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EngineClass)
    {
        if (EngineClass->objectName().isEmpty())
            EngineClass->setObjectName(QStringLiteral("EngineClass"));
        EngineClass->setWindowModality(Qt::NonModal);
        EngineClass->resize(1123, 716);
        actionNew_scene = new QAction(EngineClass);
        actionNew_scene->setObjectName(QStringLiteral("actionNew_scene"));
        actionOpen_Scene = new QAction(EngineClass);
        actionOpen_Scene->setObjectName(QStringLiteral("actionOpen_Scene"));
        actionSave_current_Scene = new QAction(EngineClass);
        actionSave_current_Scene->setObjectName(QStringLiteral("actionSave_current_Scene"));
        actionSave_all_Scenes = new QAction(EngineClass);
        actionSave_all_Scenes->setObjectName(QStringLiteral("actionSave_all_Scenes"));
        centralWidget = new QWidget(EngineClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        exitBtn = new QPushButton(centralWidget);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        exitBtn->setGeometry(QRect(1020, 630, 75, 23));
        sceneTab = new QTabWidget(centralWidget);
        sceneTab->setObjectName(QStringLiteral("sceneTab"));
        sceneTab->setGeometry(QRect(160, 0, 851, 661));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        sceneRender1 = new QOpenGLWidget(tab);
        sceneRender1->setObjectName(QStringLiteral("sceneRender1"));
        sceneRender1->setGeometry(QRect(0, 0, 991, 641));
        sceneTab->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        sceneRender2 = new QOpenGLWidget(tab_2);
        sceneRender2->setObjectName(QStringLiteral("sceneRender2"));
        sceneRender2->setGeometry(QRect(0, 0, 851, 641));
        sceneTab->addTab(tab_2, QString());
        rotateBtn = new QPushButton(centralWidget);
        rotateBtn->setObjectName(QStringLiteral("rotateBtn"));
        rotateBtn->setGeometry(QRect(1020, 40, 91, 23));
        scaleBtn = new QPushButton(centralWidget);
        scaleBtn->setObjectName(QStringLiteral("scaleBtn"));
        scaleBtn->setGeometry(QRect(1020, 60, 91, 23));
        translateBtn = new QPushButton(centralWidget);
        translateBtn->setObjectName(QStringLiteral("translateBtn"));
        translateBtn->setGeometry(QRect(1020, 20, 91, 23));
        treeView = new QTreeView(centralWidget);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setGeometry(QRect(0, 20, 161, 301));
        gameObjectList = new QLabel(centralWidget);
        gameObjectList->setObjectName(QStringLiteral("gameObjectList"));
        gameObjectList->setGeometry(QRect(10, 0, 111, 16));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 340, 111, 16));
        toolBox = new QToolBox(centralWidget);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(0, 360, 151, 291));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 151, 229));
        toolBox->addItem(page, QStringLiteral("Page 1"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 151, 229));
        selectComponent = new QComboBox(page_2);
        selectComponent->setObjectName(QStringLiteral("selectComponent"));
        selectComponent->setGeometry(QRect(0, 0, 151, 22));
        selectComponent->setEditable(false);
        toolBox->addItem(page_2, QStringLiteral("Page 2"));
        EngineClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(EngineClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1123, 26));
        fileMenu = new QMenu(menuBar);
        fileMenu->setObjectName(QStringLiteral("fileMenu"));
        EngineClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(EngineClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        EngineClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(EngineClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        EngineClass->setStatusBar(statusBar);

        menuBar->addAction(fileMenu->menuAction());
        fileMenu->addAction(actionNew_scene);
        fileMenu->addAction(actionOpen_Scene);
        fileMenu->addAction(actionSave_current_Scene);
        fileMenu->addAction(actionSave_all_Scenes);

        retranslateUi(EngineClass);

        sceneTab->setCurrentIndex(0);
        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(EngineClass);
    } // setupUi

    void retranslateUi(QMainWindow *EngineClass)
    {
        EngineClass->setWindowTitle(QApplication::translate("EngineClass", "Engine", Q_NULLPTR));
        actionNew_scene->setText(QApplication::translate("EngineClass", "New scene", Q_NULLPTR));
        actionOpen_Scene->setText(QApplication::translate("EngineClass", "Open Scene", Q_NULLPTR));
        actionSave_current_Scene->setText(QApplication::translate("EngineClass", "Save current Scene", Q_NULLPTR));
        actionSave_all_Scenes->setText(QApplication::translate("EngineClass", "Save all Scenes", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("EngineClass", "Exit", Q_NULLPTR));
        sceneTab->setTabText(sceneTab->indexOf(tab), QApplication::translate("EngineClass", "Tab 1", Q_NULLPTR));
        sceneTab->setTabText(sceneTab->indexOf(tab_2), QApplication::translate("EngineClass", "Tab 2", Q_NULLPTR));
        rotateBtn->setText(QApplication::translate("EngineClass", "Rotate", Q_NULLPTR));
        scaleBtn->setText(QApplication::translate("EngineClass", "Scale", Q_NULLPTR));
        translateBtn->setText(QApplication::translate("EngineClass", "Translate", Q_NULLPTR));
        gameObjectList->setText(QApplication::translate("EngineClass", "GameObject List :", Q_NULLPTR));
        label->setText(QApplication::translate("EngineClass", "Selected GameObject :", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("EngineClass", "Page 1", Q_NULLPTR));
        selectComponent->setCurrentText(QString());
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("EngineClass", "Page 2", Q_NULLPTR));
        fileMenu->setTitle(QApplication::translate("EngineClass", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EngineClass: public Ui_EngineClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENGINE_H
