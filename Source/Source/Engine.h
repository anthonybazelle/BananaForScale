#ifndef ENGINE_H
#define ENGINE_H

#include <QtWidgets/QMainWindow>
#include <QtCore>
#include <qpushbutton.h>
#include "ui_engine.h"

class Engine : public QMainWindow
{
	Q_OBJECT

public:
	explicit Engine(QWidget *parent = 0);
	~Engine();

private:
	Ui::EngineClass ui;
	

	// C'est tr�s particulier comme syntax C++ mais c'est propre � Qt
	private slots:
	void ExitApplication();
};

#endif // ENGINE_H
