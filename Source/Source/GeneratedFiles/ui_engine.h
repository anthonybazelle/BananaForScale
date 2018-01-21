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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>
#include "Render.h"

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
    QWidget *Scene1;
    QWidget *tab_2;
    QOpenGLWidget *sceneRender2;
    QTreeView *GOTreeView;
    QLabel *labelGOList;
    QLabel *labelComponent;
    QToolBox *componentToolBox;
    QWidget *page;
    QWidget *page_2;
    Render *renderer;
    QLabel *title;
    QLabel *imageTitle;
    QMenuBar *menuBar;
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
        exitBtn->setGeometry(QRect(1040, 640, 75, 23));
        sceneTab = new QTabWidget(centralWidget);
        sceneTab->setObjectName(QStringLiteral("sceneTab"));
        sceneTab->setGeometry(QRect(160, 0, 851, 21));
        Scene1 = new QWidget();
        Scene1->setObjectName(QStringLiteral("Scene1"));
        sceneTab->addTab(Scene1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        sceneRender2 = new QOpenGLWidget(tab_2);
        sceneRender2->setObjectName(QStringLiteral("sceneRender2"));
        sceneRender2->setGeometry(QRect(0, 0, 851, 641));
        sceneTab->addTab(tab_2, QString());
        GOTreeView = new QTreeView(centralWidget);
        GOTreeView->setObjectName(QStringLiteral("GOTreeView"));
        GOTreeView->setGeometry(QRect(0, 20, 161, 301));
        labelGOList = new QLabel(centralWidget);
        labelGOList->setObjectName(QStringLiteral("labelGOList"));
        labelGOList->setGeometry(QRect(10, 0, 111, 16));
        labelComponent = new QLabel(centralWidget);
        labelComponent->setObjectName(QStringLiteral("labelComponent"));
        labelComponent->setGeometry(QRect(10, 340, 111, 16));
        componentToolBox = new QToolBox(centralWidget);
        componentToolBox->setObjectName(QStringLiteral("componentToolBox"));
        componentToolBox->setEnabled(true);
        componentToolBox->setGeometry(QRect(0, 360, 151, 291));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 151, 237));
        componentToolBox->addItem(page, QStringLiteral("Page 1"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 151, 237));
        componentToolBox->addItem(page_2, QStringLiteral("Page 2"));
        renderer = new Render(centralWidget);
        renderer->setObjectName(QStringLiteral("renderer"));
        renderer->setGeometry(QRect(160, 20, 951, 611));
        title = new QLabel(centralWidget);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(330, 70, 531, 101));
        QFont font;
        font.setFamily(QStringLiteral("Segoe Print"));
        font.setPointSize(28);
        title->setFont(font);
        title->setMouseTracking(false);
        title->setAutoFillBackground(false);
        imageTitle = new QLabel(centralWidget);
        imageTitle->setObjectName(QStringLiteral("imageTitle"));
        imageTitle->setGeometry(QRect(450, 260, 271, 371));
        EngineClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(EngineClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1123, 21));
        EngineClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(EngineClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        EngineClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(EngineClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        EngineClass->setStatusBar(statusBar);

        retranslateUi(EngineClass);

        sceneTab->setCurrentIndex(0);
        componentToolBox->setCurrentIndex(1);


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
        sceneTab->setTabText(sceneTab->indexOf(Scene1), QApplication::translate("EngineClass", "Tab 1", Q_NULLPTR));
        sceneTab->setTabText(sceneTab->indexOf(tab_2), QApplication::translate("EngineClass", "Tab 2", Q_NULLPTR));
        labelGOList->setText(QApplication::translate("EngineClass", "GameObject List :", Q_NULLPTR));
        labelComponent->setText(QApplication::translate("EngineClass", "Component :", Q_NULLPTR));
        componentToolBox->setItemText(componentToolBox->indexOf(page), QApplication::translate("EngineClass", "Page 1", Q_NULLPTR));
        componentToolBox->setItemText(componentToolBox->indexOf(page_2), QApplication::translate("EngineClass", "Page 2", Q_NULLPTR));
        title->setText(QApplication::translate("EngineClass", "Welcome in BananaForScale", Q_NULLPTR));
        imageTitle->setText(QApplication::translate("EngineClass", "<html><head/><body><p><br/></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EngineClass: public Ui_EngineClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENGINE_H
