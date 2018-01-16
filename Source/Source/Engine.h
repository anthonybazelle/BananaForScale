#ifndef ENGINE_H
#define ENGINE_H

#include <QtWidgets/QMainWindow>
#include <QtCore>
#include <QFileDialog>
#include <qpushbutton.h>
#include "ui_engine.h"


#ifndef SCENE_H
#define SCENE_H
#include "Scene.h"
#endif 


#include "Render.h"


class Engine : public QMainWindow
{
	Q_OBJECT

public:
	explicit Engine(QWidget *parent = 0);
	static Engine* getInstance();
	~Engine();

protected:
	void contextMenuEvent(QContextMenuEvent *event) override;

private:
	static Engine* instance;
	Ui::EngineClass ui;
	QMenu* menuFile;
	QAction* actNewScene;
	QAction* actOpenScene;
	QAction* actSaveScene;
	QAction* actSaveAllScene;
	std::vector<Scene*> listScene;

	void CreateMenuBar();
	// C'est très particulier comme syntax C++ mais c'est propre à Qt
private slots:
	void ExitApplication();
	void CreateNewScene();
	void Rotate(); // juste pour tester
	void OpenScene();
	void SaveCurrentScene();
	void SaveAllScenes();
	void SceneSwitch();
	std::vector<Scene*> GetListScene();
	Scene* GetSceneByName(std::string& name);
	Scene* GetActiveScene();
	Ui::EngineClass* GetUI();
};

#endif // ENGINE_H
