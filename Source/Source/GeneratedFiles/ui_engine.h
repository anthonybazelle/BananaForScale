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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EngineClass
{
public:
    QWidget *centralWidget;
    QOpenGLWidget *openGLWidget;
    QPushButton *exitButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EngineClass)
    {
        if (EngineClass->objectName().isEmpty())
            EngineClass->setObjectName(QStringLiteral("EngineClass"));
        EngineClass->resize(600, 400);
        centralWidget = new QWidget(EngineClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        openGLWidget = new QOpenGLWidget(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setGeometry(QRect(0, 0, 511, 351));
        exitButton = new QPushButton(centralWidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(520, 20, 75, 23));
        EngineClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(EngineClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        EngineClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(EngineClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        EngineClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(EngineClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        EngineClass->setStatusBar(statusBar);

        retranslateUi(EngineClass);

        QMetaObject::connectSlotsByName(EngineClass);
    } // setupUi

    void retranslateUi(QMainWindow *EngineClass)
    {
        EngineClass->setWindowTitle(QApplication::translate("EngineClass", "Engine", Q_NULLPTR));
        exitButton->setText(QApplication::translate("EngineClass", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EngineClass: public Ui_EngineClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENGINE_H
