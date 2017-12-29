#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>


// Etat donne qu'il serait cool de gerer plusieurs scene a la fois, il faudrait donc gerer plusieurs instance de Render a la fois
// Ce qui pose probleme pour openGL, donc je pense que l'on creera une stack d'instance de Render


class Render
{
public:
	Render(void);
	~Render(void);

private:
	void Update();
};

