#pragma once

//#include <GL/glew.h>
#include <GL/freeglut.h>
#include <QGLWidget>
#include <qevent.h>
// Etat donne qu'il serait cool de gerer plusieurs scene a la fois, il faudrait donc gerer plusieurs instance de Render a la fois
// Ce qui pose probleme pour openGL, donc je pense que l'on creera une stack d'instance de Render


class Render : public QGLWidget
{
public:
	Render(QWidget* parent = 0);
	~Render(void);

	QSize MinimumSizeHint() const;
	QSize SizeHint() const;

protected:
	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);
	void MousePressEvent(QMouseEvent* event);
	void MouseMoveEvent(QMouseEvent* event);

private:
	void draw();

	QPoint lastPos;

private slots:

};

