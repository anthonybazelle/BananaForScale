#ifndef ENGINE_H
#define ENGINE_H

#include <QtWidgets/QMainWindow>
#include <QtCore>
#include <qpushbutton.h>
#include "ui_engine.h"
#include "Scene.h"
#include "Render.h"


class Engine : public QMainWindow
{
	Q_OBJECT

public:
	explicit Engine(QWidget *parent = 0);
	Engine* getInstance();
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
	Render* render;
	void CreateMenuBar();

	std::vector<Scene*> listScene;
	// C'est très particulier comme syntax C++ mais c'est propre à Qt
private slots:
	void ExitApplication();
	void CreateNewScene();
	void OpenScene();
	void SaveCurrentScene();
	void SaveAllScenes();
	std::vector<Scene*> GetListScene();
	Scene* GetSceneByName(std::string& name);
	Scene* GetActiveScene();
	Ui::EngineClass* GetUI();
};

#endif // ENGINE_H
