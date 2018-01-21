#include "engine.h"


Engine* Engine::instance = 0;

Engine::Engine(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->listScene = std::vector<Scene*>();

	const QString qtVersion = QLatin1String("Close");
	ui.exitBtn->setText(qtVersion);

	ui.componentToolBox->removeItem(1);
	ui.componentToolBox->removeItem(0);

	ui.sceneTab->removeTab(1);
	ui.sceneTab->removeTab(0);

	// TODO : IMAGE A CORRIGER !
	//QPixmap pixMap(":C:/Users/User/Documents/GitHub/Moteur C++/Source/Source/Resources/imgTitle.png");
	//ui.imageTitle->setPixmap(pixMap);
	//ui.imageTitle->setMask(pixMap.mask());
	//ui.imageTitle->show();
	this->model = new QStandardItemModel(0, 1);
	this->goSelected = NULL;
	ui.GOTreeView->setContextMenuPolicy(Qt::CustomContextMenu);
	ui.componentToolBox->setContextMenuPolicy(Qt::CustomContextMenu);

	connect(ui.exitBtn, SIGNAL(clicked()), this, SLOT(ExitApplication()));
	connect(ui.sceneTab, SIGNAL(currentChanged(int)), this, SLOT(SceneSwitch()));
	connect(ui.GOTreeView, SIGNAL(clicked(QModelIndex)), this, SLOT(GOSelected(QModelIndex)));
	connect(ui.GOTreeView, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(ShowContextMenuGOList(const QPoint &)));
	connect(ui.componentToolBox, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(ShowContextMenuComponent(const QPoint &)));
	connect(ui.componentToolBox, SIGNAL(currentChanged(int)), this, SLOT(ComponentSelected(int)));

	CreateMenuBar();

	// Pour les tests et présentation p-e, on load une scene à l'ouverture
	//Scene* defaultScene = new Scene();
	//defaultScene->SetName("DefaultSceneBFS");
	//this->listScene.push_back(defaultScene);
	//this->activeScene = defaultScene;	
	HideEditWindow();
	//Render::getInstance()->SetCurrentSceneRendered(defaultScene);
}

Engine::~Engine()
{
	// TODO : Penser à vider la mémoire 
}

void Engine::contextMenuEvent(QContextMenuEvent *event)
{
	//this->menuFile = new QMenu(this);
	//CreateMenuBar();
	//this->menuFile->exec(event->globalPos());
}


void Engine::ExitApplication()
{
	QApplication::exit();
}

void Engine::HideStartingWindow()
{
	this->ui.title->hide();
	this->ui.imageTitle->hide();

	this->ui.labelComponent->show();
	this->ui.labelGOList->show();
	this->ui.renderer->show();
	this->ui.sceneTab->show();
	this->ui.GOTreeView->show();
	this->ui.componentToolBox->show();
}

void Engine::HideEditWindow()
{
	this->ui.labelComponent->hide();
	this->ui.labelGOList->hide();
	this->ui.renderer->hide();
	this->ui.sceneTab->hide();
	this->ui.GOTreeView->hide();
	this->ui.componentToolBox->hide();
}

void Engine::ComponentSelected(int index)
{
	Render::getInstance()->mutex.lock();

	for (int i = 0; i < ui.componentToolBox->count(); ++i)
	{
		QString name = ui.componentToolBox->itemText(i);
		Component* comp = this->goSelected->GetComponentByName(name.toStdString());
		if (comp->GetIsSelected())
		{
			comp->SetIsSelected(false);
			break;
		}
	}

	QString name = ui.componentToolBox->itemText(index);
	Component* comp = this->goSelected->GetComponentByName(name.toStdString());
	comp->SetIsSelected(true);

	Render::getInstance()->mutex.unlock();
}

void Engine::CreateNewScene()
{
	// TODO : Creer un fichier XML associe a la scene | Afficher la scene associe au nouveau XML dans le Render
	// Mettre a jour la liste du GameObject associe a la scene (normalement vide dans le cas du createScene)
	Scene* newScene = new Scene();
	newScene->SetName(CheckName("New scene"));

	HideStartingWindow();
	ClearAllInterface();

	this->listScene.push_back(newScene);
	ui.renderer->show();
	QWidget* newTab = new QWidget();
	ui.sceneTab->addTab(newTab, QString(newScene->GetName().c_str()));
	ui.sceneTab->setCurrentIndex(ui.sceneTab->count());

	Render::getInstance()->SetCurrentSceneRendered(newScene);
}

Engine* Engine::getInstance()
{
	if (instance == NULL)
	{
		instance = new Engine();
	}

	return instance;
}

void Engine::ShowContextMenuGOList(const QPoint &pos)
{
	QMenu contextMenu(tr("Context menu"), this);

	QAction actionAdd("Add a Game Object", this);
	connect(&actionAdd, SIGNAL(triggered()), this, SLOT(AddNewGameObject()));
	contextMenu.addAction(&actionAdd);

	QAction actionRmv("Remove selected Game Object", this);
	connect(&actionRmv, SIGNAL(triggered()), this, SLOT(RemoveGameObject()));
	contextMenu.addAction(&actionRmv);

	contextMenu.exec(mapToGlobal(pos));
}

void Engine::RemoveGameObject()
{
	bool res = this->model->removeRow(indiceitemGOSelected.row());
}

void Engine::RemoveComponent()
{
	GameObject* go = this->GetActiveScene()->GetGameObjectByName(goNameSelected.toStdString());
	std::string nameComponent = ui.componentToolBox->itemText(ui.componentToolBox->currentIndex()).toStdString();
	Component* comp = go->GetComponentByName(nameComponent);
	go->RemoveComponent(go->GetComponentByName(ui.componentToolBox->itemText(ui.componentToolBox->currentIndex()).toStdString()));
	ui.componentToolBox->removeItem(ui.componentToolBox->currentIndex());
}

void Engine::AddNewGameObject()
{
	GameObject* newGo = new GameObject(GetActiveScene()->CheckName("New Game Object"));
	GetActiveScene()->AddGameObject(newGo);
	ClearInterfaceGO();
	LoadGOListInterface(GetActiveScene()->GetName());
}

void Engine::AddNewComponent()
{
	Render::getInstance()->mutex.lock();
	QStringList listType;
	listType << "Cube" << "Sphere" << "Triangle";
	QString typeChoice = QInputDialog::getItem(this, "Select a type of component :", "Type : ", listType);
	Component* newComponent = new Component(this->goSelected->GetListComponent().size(), std::to_string(this->goSelected->GetListComponent().size()) + " - " + typeChoice.toStdString(), NULL);
	newComponent->SetType(typeChoice.toStdString());
	this->goSelected->AddComponent(newComponent);
	ClearInterfaceComponent();
	LoadComponentListInterface(GetActiveScene(), this->goSelected->GetName());
	Render::getInstance()->mutex.unlock();
}

void Engine::ShowContextMenuComponent(const QPoint &pos)
{
	QMenu contextMenu(tr("Context menu"), this);

	QAction actionAdd("Add a component", this);
	connect(&actionAdd, SIGNAL(triggered()), this, SLOT(AddNewComponent()));
	contextMenu.addAction(&actionAdd);

	QAction actionRmv("Remove selected component", this);
	connect(&actionRmv, SIGNAL(triggered()), this, SLOT(RemoveComponent()));
	contextMenu.addAction(&actionRmv);

	contextMenu.exec(mapToGlobal(pos));
}

void Engine::Rotate()
{
	glRotatef(1 / 16.0, 1.0, 0.0, 0.0);
}

std::string Engine::CheckName(std::string name)
{
	std::string result = "";
	bool isChecked = false;
	bool isChecked2 = true;
	int countSame = 1;
	bool isSure = false;

	while (!isChecked)
	{
		for (auto it = this->listScene.begin(); it != this->listScene.end(); ++it)
		{
			if ((*it)->GetName().compare(name) == 0)
			{
				if (!isSure && name.find("New scene") == std::string::npos)
				{
					QMessageBox msgBox;
					msgBox.setText(tr("This scene is already open.\nDo you really want to reopen it ?"));
					QAbstractButton* pButtonYes = msgBox.addButton(tr("Yes"), QMessageBox::YesRole);
					msgBox.addButton(tr("No"), QMessageBox::NoRole);

					msgBox.exec();

					if (msgBox.clickedButton() == pButtonYes)
					{
						isSure = true;
					}
					else
					{
						return "";
					}
				}
				isChecked2 = false;
				break;
			}
		}

		if (isChecked2)
			break;

		int indexOpen = 0;
		if ((indexOpen = name.find("(")) != std::string::npos)
		{
			int toIncrement = atoi(name.substr(indexOpen + 1, name.find(")") - indexOpen).c_str());
			std::string toReplace = "(" + std::to_string(toIncrement) + ")";
			name.replace(indexOpen, toReplace.length(), "(" + std::to_string(toIncrement + 1) + ")");
		}
		else
		{
			name = name + " (" + std::to_string(countSame) + ")";
		}

		++countSame;
		isChecked2 = true;
	}

	return name;
}

void Engine::OpenScene()
{
	// Mettre a jour la liste du GameObject associe a la scene
	QString fileName = QFileDialog::getOpenFileName(
		this,
		tr("Open file"),
		"C://",
		"YO Files (*.yo)");


	Scene* openScene = new Scene(fileName.toStdString());
	openScene->SetName(CheckName(openScene->GetName()));
	if (openScene->GetName() != "")
	{
		this->listScene.push_back(openScene);

		HideStartingWindow();
		QWidget* newTab = new QWidget();
		ui.sceneTab->addTab(newTab, QString(openScene->GetName().c_str()));
		ui.sceneTab->setCurrentIndex(ui.sceneTab->count());
		ui.renderer->show();

		// TODO verifier si la scene n'est pas deja ouverte
		ClearAllInterface();
		LoadGOListInterface(openScene->GetName());
	}
	else
	{
		delete openScene;
	}

	Render::getInstance()->SetCurrentSceneRendered(openScene);
}

void Engine::LoadGOListInterface(std::string& sceneName)
{
	Scene* scene = GetSceneByName(sceneName);

	// On alimente le TreeView de la liste des GameObject	
	for (int i = 0; i < scene->GetListGameObject().size(); ++i)
	{
		QStandardItem* newItem = new QStandardItem(0);
		newItem->setText(QString(scene->GetListGameObject()[i]->GetName().c_str()));
		this->model->appendRow(newItem);
	}

	ui.GOTreeView->setModel(this->model);
}

void Engine::LoadComponentListInterface(Scene* scene, std::string& goName)
{
	Render::getInstance()->mutex.lock();

	GameObject* go = scene->GetGameObjectByName(goName);

	for (int i = 0; i < go->GetListComponent().size(); ++i)
	{
		QFrame* newPage = new QFrame();
		ui.componentToolBox->addItem(newPage, QString((std::to_string(go->GetListComponent()[i]->GetId()) + " - " + go->GetListComponent()[i]->GetType()).c_str()));
	}

	Render::getInstance()->mutex.unlock();
}

void Engine::SceneSwitch()
{
	Render::getInstance()->SetCurrentSceneRendered(GetSceneByName(ui.sceneTab->tabText(ui.sceneTab->currentIndex()).toStdString()));
	SetActiveScene(GetSceneByName(ui.sceneTab->tabText(ui.sceneTab->currentIndex()).toStdString()));
	this->goSelected = NULL;
	ClearAllInterface();

	if (ui.sceneTab->count() > 1)
	{
		LoadGOListInterface(GetActiveScene()->GetName());
	}

	Render::getInstance()->updateGL(); // Permet de rappeler la fonction paintGL du render
}

void Engine::SaveCurrentScene()
{
	Render::getInstance()->mutex.lock();
	// TODO : Serialiser dans un XML les gameObjects de la Scene affiche dans le Render de l'engine, ainsi que leur position (du point de pivot deja)
	Scene* scene = this->GetActiveScene();

	if (scene->GetPathFile().compare("") == 0)
	{
		QString fileName = QFileDialog::getSaveFileName(this, tr("Save scene"),
			"C:/",
			tr("YO File (*.yo)"));

		scene->SetPathFile(fileName.toStdString());
	}

	std::ofstream fileScene;
	fileScene.open(scene->GetPathFile());

	if (scene->GetName().find("New scene") != std::string::npos)
	{
		bool ok;
		QString sceneName = QInputDialog::getText(this, tr("Enter a name for the scene :"),
			tr("User name:"), QLineEdit::Normal,
			QDir::home().dirName(), &ok);

		ui.sceneTab->setTabText(ui.sceneTab->currentIndex(), sceneName);
		scene->SetName(sceneName.toStdString());
	}

	// Header classique du fichier de scene
	fileScene << "<Scene>\n";
	fileScene << "\t<name>" << scene->GetName() << "</name>\n";
	fileScene << "\t<GameObjectList>\n";

	for (int i = 0; i < scene->GetListGameObject().size(); ++i)
	{
		fileScene << "\t\t<GameObject>\n";
		fileScene << "\t\t\t<name>" << scene->GetListGameObject()[i]->GetName() << "</name>\n";

		fileScene << "\t\t\t<pivotX>" << scene->GetListGameObject()[i]->GetPivot().x << "</pivotX>\n";
		fileScene << "\t\t\t<pivotY>" << scene->GetListGameObject()[i]->GetPivot().y << "</pivotY>\n";
		fileScene << "\t\t\t<pivotZ>" << scene->GetListGameObject()[i]->GetPivot().z << "</pivotZ>\n";

		fileScene << "\t\t\t<ComponentList>\n";

		for (int iComp = 0; iComp < scene->GetListGameObject()[i]->GetListComponent().size(); ++iComp)
		{
			fileScene << "\t\t\t\t<Component>\n";
			fileScene << "\t\t\t\t\t<type>" << scene->GetListGameObject()[i]->GetListComponent()[iComp]->GetType() << "</type>\n";
			fileScene << "\t\t\t\t</Component>\n";
		}
		
		fileScene << "\t\t\t</ComponentList>\n";
		fileScene << "\t\t</GameObject>\n";
	}

	fileScene << "\t</GameObjectList>\n";
	fileScene << "</Scene>\n";

	fileScene.close();
	Render::getInstance()->mutex.unlock();

	QMessageBox msgBox;
	msgBox.setText(tr("The scene has been saved succesfuly."));
	msgBox.exec();
}

void Engine::SaveAllScenes()
{
	Render::getInstance()->mutex.lock();

	for (int iScene = 0; iScene < this->listScene.size(); ++iScene)
	{
		Scene* scene = this->listScene[iScene];

		if (scene->GetPathFile().compare("") == 0)
		{
			QString fileName = QFileDialog::getSaveFileName(this, tr("Save scene"),
				"C:/",
				tr("YO File (*.yo)"));

			scene->SetPathFile(fileName.toStdString());
		}

		std::ofstream fileScene;
		fileScene.open(scene->GetPathFile());

		if (scene->GetName().find("New scene") != std::string::npos)
		{
			bool ok;
			QString sceneName = QInputDialog::getText(this, tr("Enter a name for the scene :"),
				tr("User name:"), QLineEdit::Normal,
				QDir::home().dirName(), &ok);

			// Pas de fonction permettant de set un nouveau label à un index de widget
			// Obligé de reparcourir chaque widget pour récupérer leur nom pour le comparer et renommer si c'est le bon, vive Qt...
			for (int u = 0; u < ui.sceneTab->count(); ++u)
			{
				if (ui.sceneTab->tabText(u).toStdString().compare(scene->GetName()) == 0 && ok && !sceneName.isEmpty())
				{
					ui.sceneTab->setTabText(u, sceneName);
				}
			}

			scene->SetName(sceneName.toStdString());
		}

		// Header classique du fichier de scene
		fileScene << "<Scene>\n";
		fileScene << "\t<name>" << scene->GetName() << "</name>\n";
		fileScene << "\t<GameObjectList>\n";

		for (int i = 0; i < scene->GetListGameObject().size(); ++i)
		{
			fileScene << "\t\t<GameObject>\n";
			fileScene << "\t\t\t<name>" << scene->GetListGameObject()[i]->GetName() << "</name>\n";

			fileScene << "\t\t\t<pivotX>" << scene->GetListGameObject()[i]->GetPivot().x << "</pivotX>\n";
			fileScene << "\t\t\t<pivotY>" << scene->GetListGameObject()[i]->GetPivot().y << "</pivotY>\n";
			fileScene << "\t\t\t<pivotZ>" << scene->GetListGameObject()[i]->GetPivot().z << "</pivotZ>\n";

			fileScene << "\t\t\t<ComponentList>\n";

			for (int iComp = 0; iComp < scene->GetListGameObject()[i]->GetListComponent().size(); ++iComp)
			{
				fileScene << "\t\t\t\t<Component>\n";
				fileScene << "\t\t\t\t\t<type>" << scene->GetListGameObject()[i]->GetListComponent()[iComp]->GetType() << "</type>\n";
				fileScene << "\t\t\t\t</Component>\n";
			}

			fileScene << "\t\t\t</ComponentList>\n";
			fileScene << "\t\t</GameObject>\n";
		}

		fileScene << "\t</GameObjectList>\n";
		fileScene << "</Scene>\n";

		fileScene.close();
	}

	Render::getInstance()->mutex.unlock();

	QMessageBox msgBox;
	msgBox.setText(tr("All opened scene have been saved succesfuly."));
	msgBox.exec();
}

void Engine::CreateMenuBar()
{
	this->menuFile = this->menuBar()->addMenu(tr("&File"));//(menuFile);

	this->actNewScene = new QAction("New Scene", this);
	this->actOpenScene = new QAction("Open Scene", this);
	this->actSaveScene = new QAction("Save Scene", this);
	this->actSaveAllScene = new QAction("Save all Scene", this);

	this->actNewScene->setShortcuts(QKeySequence::New);
	this->actNewScene->setStatusTip(tr("Create a new Scene"));
	connect(this->actNewScene, &QAction::triggered, this, &Engine::CreateNewScene);

	this->actOpenScene->setShortcuts(QKeySequence::Open);
	this->actOpenScene->setStatusTip(tr("Open Scene"));
	connect(this->actOpenScene, &QAction::triggered, this, &Engine::OpenScene);

	this->actSaveScene->setShortcuts(QKeySequence::Save);
	this->actSaveScene->setStatusTip(tr("Save Scene"));
	connect(this->actSaveScene, &QAction::triggered, this, &Engine::SaveCurrentScene);

	this->actSaveAllScene->setShortcuts(QKeySequence::Save);
	this->actSaveAllScene->setStatusTip(tr("Save all Scene"));
	connect(this->actSaveAllScene, &QAction::triggered, this, &Engine::SaveAllScenes);

	this->menuFile->addAction(actNewScene);
	this->menuFile->addAction(actOpenScene);
	this->menuFile->addAction(actSaveScene);
	this->menuFile->addAction(actSaveAllScene);
}

std::vector<Scene*> Engine::GetListScene()
{
	return this->listScene;
}

void Engine::SetActiveScene(Scene* s)
{
	this->activeScene = s;
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
	return GetSceneByName(ui.sceneTab->tabText(ui.sceneTab->currentIndex()).toStdString());
}

Ui::EngineClass* Engine::GetUI()
{
	return &ui;
}

void Engine::GOSelected(const QModelIndex& index)
{
	QStandardItem *item = this->model->itemFromIndex(index);
	indiceitemGOSelected = item->index();
	QString goName = item->text();
	goNameSelected = goName;
	GameObject* go = this->GetActiveScene()->GetGameObjectByName(goName.toStdString());
	this->goSelected = go;
	ClearInterfaceComponent();
	LoadComponentListInterface(GetActiveScene(), goName.toStdString());
}

void Engine::ClearAllInterface()
{
	// On reset la liste des gameobject
	if (this->model->hasChildren())
	{
		this->model->removeRows(0, this->model->rowCount());
	}

	// On reset la liste des component
	for (int i = 0; i < ui.componentToolBox->count(); ++i)
	{
		ui.componentToolBox->removeItem(i);
	}
}

void Engine::ClearInterfaceComponent()
{
	// On reset la liste des component
	int count = ui.componentToolBox->count();
	for (int i = 0; i < count; ++i)
	{
		ui.componentToolBox->removeItem(0);
	}
}

void Engine::ClearInterfaceGO()
{
	// On reset la liste des gameobject
	if (this->model->hasChildren())
	{
		this->model->removeRows(0, this->model->rowCount());
	}
}