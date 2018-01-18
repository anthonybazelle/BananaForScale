#pragma once

#include <QGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLFunctions>
#include <QOpenGLContext>
#include <QGLWidget>
#include <qevent.h>
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
	Render(QWidget* parent = 0);
	~Render(void);

	static Render* getInstance();
	QSize MinimumSizeHint() const;
	QSize SizeHint() const;
	Scene* GetCurrentSceneRendered();
	void SetCurrentSceneRendered(Scene* s);

protected:
	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);

private:
	void draw1();
	void draw2();
	void drawCube();


	float angle;
	QGLShaderProgram* m_program;
	QOpenGLBuffer* m_cubeVB;
	QOpenGLBuffer* m_cubeI;
	QOpenGLVertexArrayObject m_cubeVAO;
	QPoint lastPos;
	Scene* sceneRendered;
	static Render* instance;

private slots:

};

