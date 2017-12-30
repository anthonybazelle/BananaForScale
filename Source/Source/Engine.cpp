#include "engine.h"

Engine::Engine(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	const QString qtVersion = QLatin1String("Close");
	ui.exitButton->setText(qtVersion);
	
	connect(ui.exitButton, SIGNAL(clicked()), this, SLOT(ExitApplication()));
}

Engine::~Engine()
{

}

void Engine::ExitApplication()
{
	QApplication::exit();
}