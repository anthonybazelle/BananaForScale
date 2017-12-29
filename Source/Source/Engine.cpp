#include "engine.h"

Engine::Engine(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.exitButton, SIGNAL(clicked()), this, SLOT(ExitApplication()));
}

Engine::~Engine()
{

}

void Engine::ExitApplication()
{
	QApplication::exit();
}