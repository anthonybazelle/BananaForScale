#include "engine.h"

Engine::Engine(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	const QString qtVersion = QLatin1String("Close");
	ui.exitBtn->setText(qtVersion);
	ui.selectComponent->addItem("Cube");
	ui.selectComponent->addItem("Sphere");
	connect(ui.exitBtn, SIGNAL(clicked()), this, SLOT(ExitApplication()));
}

Engine::~Engine()
{

}

void Engine::ExitApplication()
{
	QApplication::exit();
}