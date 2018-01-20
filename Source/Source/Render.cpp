#include "Render.h"
#include <QColorDialog>
#include <GL/glu.h>

Render* Render::instance = 0;

static const Vertex sg_vertexes[] = {
	Vertex(QVector3D(-0.5f,  -0.5f, 1.0f), QVector3D(1.0f, 0.0f, 0.0f)),
	Vertex(QVector3D(-0.5f, 0.5f, 1.0f), QVector3D(0.0f, 1.0f, 0.0f)),
	Vertex(QVector3D(0.5f, 0.5f, 1.0f), QVector3D(0.0f, 0.0f, 1.0f)),
	Vertex(QVector3D(0.5f, -0.5f, 1.0f), QVector3D(0.0f, 0.0f, 1.0f)),

	Vertex(QVector3D(-0.5f,  -0.5f, 2.0f), QVector3D(1.0f, 0.0f, 0.0f)),
	Vertex(QVector3D(-0.5f, 0.5f, 2.0f), QVector3D(0.0f, 1.0f, 0.0f)),
	Vertex(QVector3D(0.5f, 0.5f, 2.0f), QVector3D(0.0f, 0.0f, 1.0f)),
	Vertex(QVector3D(0.5f, -0.5f, 2.0f), QVector3D(0.0f, 0.0f, 1.0f))
};

unsigned short cubeIndices[] =
{
	// front plane
	0, 2, 1,
	0, 3, 2,
	// back plane
	7, 5, 6,
	7, 4, 5,
	// left plane
	4, 1, 5,
	4, 0, 1,
	// right plane
	3, 6, 2,
	3, 7, 6,
	// top plane
	1, 6, 5,
	1, 2, 6,
	// bottom plane
	4, 3, 0,
	4, 7, 3,
};

Render::Render(QWidget* parent) : QGLWidget(parent)
{
	this->sceneRendered = new Scene();
	this->instance = this; // Singleton, simplement car Qt lance le constructeur du Render dès le debut comme le constructeur d'Engine
	this->angle = 1.0f;
	this->currentAction = Action::SELECTION;

	// TEST CUBE
	setFormat(QGLFormat(QGL::DoubleBuffer | QGL::DepthBuffer));
	rotationX = 0;
	rotationY = 0;
	rotationZ = 0;
	faceColors[0] = Qt::red;
	faceColors[1] = Qt::green;
	faceColors[2] = Qt::blue;
	faceColors[3] = Qt::cyan;
	faceColors[4] = Qt::yellow;
	faceColors[5] = Qt::magenta;
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
	/*
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


	m_program = new QGLShaderProgram(this);
	m_program->addShaderFromSourceCode(QGLShader::Vertex, QString("..\Shaders\simple.vert"));
	m_program->addShaderFromSourceCode(QGLShader::Fragment, QString("..\Shaders\simple.frag"));
	m_program->link();
	m_program->bind();

	m_cubeVB = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
	m_cubeVB->create();
	m_cubeVB->bind();
	m_cubeVB->setUsagePattern(QOpenGLBuffer::StaticDraw);
	m_cubeVB->allocate(sg_vertexes, sizeof(sg_vertexes));

	m_cubeVAO.create();
	m_cubeVAO.bind();

	m_program->enableAttributeArray(0);
	m_program->enableAttributeArray(1);

	// TODO : METTRE EN PLACE CUBE
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, position)));
	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, color)));

	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	m_program->setAttributeBuffer(0, GL_FLOAT, Vertex::positionOffset(), Vertex::PositionTupleSize, Vertex::stride());
	m_program->setAttributeBuffer(1, GL_FLOAT, Vertex::colorOffset(), Vertex::ColorTupleSize, Vertex::stride());

	m_cubeVAO.release();
	m_cubeVB->release();
	m_program->release();*/


	// TEST CUBE
	qglClearColor(Qt::black);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
}

void Render::resizeGL(int width, int height)
{
	/*
	int side = qMin(width, height);
	glViewport((width - side) / 2, (height - side) / 2, side, side);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
#ifdef QT_OPENGL_ES_1
	glOrthof(-0.5, +0.5, -0.5, +0.5, 4.0, 15.0);
#else
	glOrtho(-0.5, +0.5, -0.5, +0.5, 4.0, 15.0);
#endif
	glMatrixMode(GL_MODELVIEW);*/

	// TEST CUBE 
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLfloat x = (GLfloat)width / height;
	glFrustum(-x, x, -1.0, 1.0, 4.0, 15.0);
	glMatrixMode(GL_MODELVIEW);
}


void Render::paintGL()
{
	/*
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (this->sceneRendered->GetName() != "")
	{
		if (this->sceneRendered->GetName().compare("Default") == 0)
		{
			QColor c(Qt::red);
			qglClearColor(c);
			this->hide();
			drawCube();
			//draw1();
		}
	}
	else
	{
		QColor c(Qt::green);
		qglClearColor(c);
	}
	QColor c(Qt::green);
	qglClearColor(c);
	drawCube();
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -10.0);
	glRotatef(1 / 16.0, 1.0, 0.0, 0.0);*/


	// TEST CUBE
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawCubeCop();



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

int Render::faceAtPosition(const QPoint &pos)
{
	const int MaxSize = 512;
	GLuint buffer[MaxSize];
	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	glSelectBuffer(MaxSize, buffer);
	glRenderMode(GL_SELECT);
	glInitNames();
	glPushName(0);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluPickMatrix((GLdouble)pos.x(),
		(GLdouble)(viewport[3] - pos.y()),
		5.0, 5.0, viewport);
	GLfloat x = (GLfloat)width() / height();
	glFrustum(-x, x, -1.0, 1.0, 4.0, 15.0);
	drawCubeCop();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	if (!glRenderMode(GL_RENDER))
		return -1;
	return buffer[3];
}

void Render::drawCube()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glRotatef(angle, 0.0, 1.0, 0.0);


	glFlush();

}

// TEST CUBE
void Render::drawCubeCop()
{
	GameObject::Point p;
	p.x = 2.f;
	p.y = 0.5f;
	p.z = 0.f;

	static const GLfloat coords[6][4][3] = {
		{ { +1.0 + p.x, -1.0, +1.0 },{ +1.0 + p.x, -1.0, -1.0 },
		{ +1.0 + p.x, +1.0, -1.0 },{ +1.0 + p.x, +1.0, +1.0 } },

		{ { -1.0 + p.x, -1.0, -1.0 },{ -1.0 + p.x, -1.0, +1.0 },
		{ -1.0 + p.x, +1.0, +1.0 },{ -1.0 + p.x, +1.0, -1.0 } },

		{ { +1.0 + p.x, -1.0, -1.0 },{ -1.0 + p.x, -1.0, -1.0 },
		{ -1.0 + p.x, +1.0, -1.0 },{ +1.0 + p.x, +1.0, -1.0 } },

		{ { -1.0 + p.x, -1.0, +1.0 },{ +1.0 + p.x, -1.0, +1.0 },
		{ +1.0 + p.x, +1.0, +1.0 },{ -1.0 + p.x, +1.0, +1.0 } },

		{ { -1.0 + p.x, -1.0, -1.0 },{ +1.0 + p.x, -1.0, -1.0 },
		{ +1.0 + p.x, -1.0, +1.0 },{ -1.0 + p.x, -1.0, +1.0 } },

		{ { -1.0 + p.x, +1.0, +1.0 },{ +1.0 + p.x, +1.0, +1.0 },
		{ +1.0 + p.x, +1.0, -1.0 },{ -1.0 + p.x, +1.0, -1.0 } }
	};
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -10.0);
	glRotatef(rotationX, 1.0, 0.0, 0.0);
	glRotatef(rotationY, 0.0, 1.0, 0.0);
	glRotatef(rotationZ, 0.0, 0.0, 1.0);
	for (int i = 0; i < 6; ++i) {
		glLoadName(i);
		glBegin(GL_QUADS);
		qglColor(faceColors[i]);
		for (int j = 0; j < 4; ++j) {
			glVertex3f(coords[i][j][0], coords[i][j][1],
				coords[i][j][2]);
		}
		glEnd();
	}
}

void Render::mouseDoubleClickEvent(QMouseEvent *event)
{
	int face = faceAtPosition(event->pos());
	if (face != -1) {
		QColor color = QColorDialog::getColor(faceColors[face],
			this);
		if (color.isValid()) {
			faceColors[face] = color;
			updateGL();
		}
	}
}
/*
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
*/
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
	if (event->button() == Qt::LeftButton) 
	{
		this->lastPos = event->pos();
	}
	else if (event->button() == Qt::RightButton) 
	{
		QMenu contextMenu(tr("Context menu"), this);

		QAction actionDeselect("Deselect this GameObject", this);
		connect(&actionDeselect, &QAction::triggered, this, &Render::SetDeselectAction);

		QAction actionScale("Scale this GameObject", this);
		connect(&actionScale, &QAction::triggered, this, &Render::SetScaleAction);

		QAction actionRotate("Rotate this GameObject", this);
		connect(&actionRotate, &QAction::triggered, this, &Render::SetRotateAction);

		QAction actionTranslate("Translate this GameObject", this);
		connect(&actionTranslate, &QAction::triggered, this, &Render::SetTranslateAction);

		if (this->currentAction != Render::Action::SELECTION)
		{
			contextMenu.addAction(&actionDeselect);
			contextMenu.addAction(&actionScale);
			contextMenu.addAction(&actionRotate);
			contextMenu.addAction(&actionTranslate);
		}
		else
		{
			contextMenu.addAction(&actionScale);
			contextMenu.addAction(&actionRotate);
			contextMenu.addAction(&actionTranslate);
		}
		
		contextMenu.exec(mapToGlobal(event->pos()));
	}
}

void Render::SetRotateAction()
{
	this->currentAction = Action::ROTATE;
}

void Render::SetTranslateAction()
{
	this->currentAction = Action::TRANSLATE;
}

void Render::SetScaleAction()
{
	this->currentAction = Action::SCALE;
}

void Render::SetDeselectAction()
{
	this->currentAction = Action::SELECTION;
}

void Render::mouseMoveEvent(QMouseEvent *event)
{
	//int dx = event->x() - lastPos.x();
	//int dy = event->y() - lastPos.y();

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
	//lastPos = event->pos();

	// TEST CUBE
	GLfloat dx = (GLfloat)(event->x() - lastPos.x()) / width();
	GLfloat dy = (GLfloat)(event->y() - lastPos.y()) / height();
	if (event->buttons() & Qt::LeftButton) {
		rotationX += 180 * dy;
		rotationY += 180 * dx;
		updateGL();
	}
	else if (event->buttons() & Qt::RightButton) {
		rotationX += 180 * dy;
		rotationZ += 180 * dx;
		updateGL();
	}
	lastPos = event->pos();
}