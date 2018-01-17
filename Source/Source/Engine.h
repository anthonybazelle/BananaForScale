#ifndef ENGINE_H
#define ENGINE_H

#include <QtWidgets/QMainWindow>
#include <QtCore>
#include <QFileDialog>
#include <QtGui>
#include <QBitmap>
#include <QStandardItemModel>
#include <QMessageBox>
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
	QStandardItemModel* model; // modele à insérer dans le QTreeView qui correspond à la liste des GameObject de la scène selectionnée
	std::vector<Scene*> listScene;
	Scene* activeScene;
	GameObject* goSelected;

	void CreateMenuBar();
	void LoadGOListInterface(std::string& sceneName);
	void LoadComponentListInterface(Scene* scene, std::string& goName);
	void ClearAllInterface();
	void ClearInterfaceGO();
	void ClearInterfaceComponent();
	std::vector<Scene*> GetListScene();
	Scene* GetSceneByName(std::string& name);
	Scene* GetActiveScene();
	void SetActiveScene(Scene* s);
	void HideStartingWindow();
	void HideEditWindow();
	std::string CheckName(std::string name);

	// C'est très particulier comme syntax C++ mais c'est propre à Qt
private slots:
	void AddNewGameObject();
	void AddNewComponent();
	void ShowContextMenuGOList(const QPoint &pos);
	void ShowContextMenuComponent(const QPoint &pos);
	void ExitApplication();
	void CreateNewScene();
	void Rotate(); // juste pour tester
	void OpenScene();
	void SaveCurrentScene();
	void SaveAllScenes();
	void SceneSwitch();
	void GOSelected(const QModelIndex& index);
	Ui::EngineClass* GetUI();
};

#endif // ENGINE_H
