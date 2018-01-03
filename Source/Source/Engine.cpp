#include "engine.h"


Engine* Engine::instance = 0;

Engine::Engine(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->listScene = std::vector<Scene*>();

	const QString qtVersion = QLatin1String("Close");
	ui.exitBtn->setText(qtVersion);
	ui.selectComponent->addItem("Cube");
	ui.selectComponent->addItem("Sphere");
	connect(ui.exitBtn, SIGNAL(clicked()), this, SLOT(ExitApplication()));
	//ui.
	//connect(ui.menuBar->adda)
}

Engine::~Engine()
{

}

void Engine::ExitApplication()
{
	QApplication::exit();
}

void Engine::CreateNewScene()
{
	// TODO : Creer un fichier XML associe a la scene | Afficher la scene associe au nouveau XML dans le Render
	// Mettre a jour la liste du GameObject associe a la scene (normalement vide dans le cas du createScene)
}

Engine* Engine::getInstance()
{
	if (this->instance == NULL)
	{
		instance = new Engine();
	}

	return this->instance;
}

void Engine::OpenScene()
{
	// TODO : Traiter le XML associe a la Scene ouverte, et l'afficher dans le Render
	// On ne le fera certainement pas car trop long et dur a traiter (cote openGL)
	// Mettre a jour la liste du GameObject associe a la scene
}

void Engine::SaveCurrentScene()
{
	// TODO : Serialiser dans un XML les gameObjects de la Scene affiche dans le Render de l'engine, ainsi que leur position (du point de pivot deja)
}

void Engine::SaveAllScenes()
{
	// TODO : Serialiser dans un XML les gameObjects des Scenes ouvertes dans l'engine, ainsi que leur position (du point de pivot deja)
}

std::vector<Scene*> Engine::GetListScene()
{
	return this->listScene;
}

Scene* Engine::GetSceneByName(std::string& name)
{
	for (auto it = this->listScene.begin(); it != this->listScene.end(); ++it)
	{
		if ((*it)->GetName().compare(name) == 0)
		{
			return (*it);
		}
	}

	std::cout << "No Scene found with this name : '" << name << "'." << std::endl;

	return NULL;
}

Scene* Engine::GetActiveScene()
{
	// Recuperer le nom de la tab visible (le nom de la scene donc)
	QString nameCurrentTab = ui.sceneTab->tabText(ui.sceneTab->currentIndex());
	return GetSceneByName(nameCurrentTab.toStdString());
}

Ui::EngineClass* Engine::GetUI()
{
	return &ui;
}