#ifndef ENGINE_H
#define ENGINE_H

#include <QtWidgets/QMainWindow>
#include "ui_engine.h"

class Engine : public QMainWindow
{
	Q_OBJECT

public:
	Engine(QWidget *parent = 0);
	~Engine();

private:
	Ui::EngineClass ui;
	void ExitApplication();
};

#endif // ENGINE_H
