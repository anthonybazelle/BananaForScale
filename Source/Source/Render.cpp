#include "Render.h"


Render* Render::instance = 0;

Render::Render(QWidget* parent) : QGLWidget(parent)
{
	this->sceneRendered = new Scene();
	this->instance = this; // Singleton, simplement car Qt lance le constructeur du Render d�s le debut comme le constructeur d'Engine
}

Render::~Render(void)
{

}

Render* Render::getInstance()
{
	if (instance == NULL)
	{
		instance = new Render();
	}

	return instance;
}


QSize Render::MinimumSizeHint() const
{
	return QSize(50, 50);
}

QSize Render::SizeHint() const
{
	return QSize(400, 400);
}

Scene* Render::GetCurrentSceneRendered()
{
	return this->sceneRendered;
}

void Render::SetCurrentSceneRendered(Scene* s)
{
	this->sceneRendered = s;
}

void Render::initializeGL()
{
	glClearColor(0.2, 0.2, 0.2, 1);

	//this->logo = new QtLogo(this, 64);
	//this->logo->SetColor(qtGreen.dark());


	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_MULTISAMPLE);
	static GLfloat lightPosition[4] = { 0.5, 5.0, 7.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void Render::resizeGL(int width, int height)
{
	int side = qMin(width, height);
	glViewport((width - side) / 2, (height - side) / 2, side, side);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
#ifdef QT_OPENGL_ES_1
	glOrthof(-0.5, +0.5, -0.5, +0.5, 4.0, 15.0);
#else
	glOrtho(-0.5, +0.5, -0.5, +0.5, 4.0, 15.0);
#endif
	glMatrixMode(GL_MODELVIEW);
}

void Render::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (this->sceneRendered->GetName() != "")
	{
		if (this->sceneRendered->GetName().compare("Default") == 0)
		{
			QColor c(Qt::red);
			qglClearColor(c);
			this->hide();
			//draw1();
		}
	}
	else
	{
		QColor c(Qt::green);
		qglClearColor(c);
	}

	glLoadIdentity();
	glTranslatef(0.0, 0.0, -10.0);
	glRotatef(1 / 16.0, 1.0, 0.0, 0.0);
	//glutSolidSphere(1, 20, 20);
	//draw();
	//glLoadIdentity();
	//glTranslatef(0.0, 0.0, -10.0);
	//glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
	//glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
	//glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);


	/* Draw OpenGL de n'importe quel forme (cube, tetrahedre, etc)
	...
	...
	*/
}

void Render::draw1()
{
	qglColor(Qt::red);
	glBegin(GL_QUADS);
	glNormal3f(0, 0, -1);
	glVertex3f(-1, -1, 0);
	glVertex3f(-1, 1, 0);
	glVertex3f(1, 1, 0);
	glVertex3f(1, -1, 0);

	glEnd();
	glBegin(GL_TRIANGLES);
	glNormal3f(0, -1, 0.707);
	glVertex3f(-1, -1, 0);
	glVertex3f(1, -1, 0);
	glVertex3f(0, 0, 1.2);
	glEnd();
	glBegin(GL_TRIANGLES);
	glNormal3f(1, 0, 0.707);
	glVertex3f(1, -1, 0);
	glVertex3f(1, 1, 0);
	glVertex3f(0, 0, 1.2);
	glEnd();
	glBegin(GL_TRIANGLES);
	glNormal3f(0, 1, 0.707);
	glVertex3f(1, 1, 0);
	glVertex3f(-1, 1, 0);
	glVertex3f(0, 0, 1.2);
	glEnd();
	glBegin(GL_TRIANGLES);
	glNormal3f(-1, 0, 0.707);
	glVertex3f(-1, 1, 0);
	glVertex3f(-1, -1, 0);
	glVertex3f(0, 0, 1.2);
	glEnd();
}

void Render::draw2()
{
	qglColor(Qt::red);
	glBegin(GL_QUADS);
	glNormal3f(0, 0, -1);
	glVertex3f(-1, -1, 0);
	glVertex3f(-1, 1, 0);
	glVertex3f(1, 1, 0);
	glVertex3f(1, -1, 0);
	glEnd();
}

void Render::mousePressEvent(QMouseEvent *event)
{
	this->lastPos = event->pos();
}

void Render::mouseMoveEvent(QMouseEvent *event)
{
	int dx = event->x() - lastPos.x();
	int dy = event->y() - lastPos.y();

	// TODO :: Ici il faut gerer trois differents etats : rotate, translate, scale
	// TODO :: Verifier si et quel gameObject est selectionne et faire l'action attendu celon l'etat

	/*

	// TODO :: a la place du "this" mettre le pointeur du gameObject en cours de seleciton
	if (event->buttons() & Qt::LeftButton) {
		this->SetXRotation(xRot + 8 * dy);
		this->SetYRotation(yRot + 8 * dx);
	}
	else if (event->buttons() & Qt::RightButton) {
		this->SetXRotation(xRot + 8 * dy);
		this->SetZRotation(zRot + 8 * dx);
	}
	*/
	lastPos = event->pos();
}