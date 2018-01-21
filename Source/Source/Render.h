#pragma once

#include <QGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLFunctions>
#include <QOpenGLContext>
#include <QGLWidget>
#include <QMenu>
#include <qevent.h>
#include <mutex>
#include "Scene.h"
#include "Vertex.h"

//#ifndef SCENE_H
//#define SCENE_H
//#include "Scene.h"
//#endif 

// Etat donne qu'il serait cool de gerer plusieurs scene a la fois, il faudrait donc gerer plusieurs instance de Render a la fois
// Ce qui pose probleme pour openGL, donc je pense que l'on creera une stack d'instance de Render


class Render : public QGLWidget
{
public:
	enum Action { SELECTION, ROTATE, TRANSLATE, SCALE };

	Render(QWidget* parent = 0);
	~Render(void);

	static Render* getInstance();
	QSize MinimumSizeHint() const;
	QSize SizeHint() const;
	Scene* GetCurrentSceneRendered();
	void SetCurrentSceneRendered(Scene* s);


	std::mutex mutex;
// en public pour la simple raison qu'elle est utilisé dans engine.cpp et que cet un enum déclaré dans Render donc impossible avec des accesseurs

protected:
	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseDoubleClickEvent(QMouseEvent *event);

private:
	void drawCube(Component::Point& position, bool isSelected);
	void drawTriangle(Component::Point& position, bool isSelected);
	void drawSphere(Component::Point& position, bool isSelected);

	// TEST CUBE
	int faceAtPosition(const QPoint &pos);
	GLfloat rotationX;
	GLfloat rotationY;
	GLfloat rotationZ;

	GLfloat translateX;
	GLfloat translateY;
	GLfloat translateZ;

	GLfloat scaleX;
	GLfloat scaleY;
	GLfloat scaleZ;

	QColor faceColors[6];
	Action currentAction;

	float angle;
	QGLShaderProgram* m_program;
	QOpenGLBuffer* m_cubeVB;
	QOpenGLBuffer* m_cubeI;
	QOpenGLVertexArrayObject m_cubeVAO;
	QPoint lastPos;
	Scene* sceneRendered;
	static Render* instance;

private slots:
	void SetRotateAction();
	void SetTranslateAction();
	void SetScaleAction();
	void SetDeselectAction();
};

