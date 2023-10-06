#include "polyObject.h"
#include <GL/freeglut.h>

polyObject::polyObject()
{
	color = vec3(0.0f, 0.0f, 0.0f);
}

polyObject::~polyObject()
{
}

void polyObject::addVertex(vec2 p_vert)
{
	vertices.push_back(p_vert);
}

void polyObject::setColor(vec3 p_color)
{
	color = p_color;
}

unsigned int polyObject::getVertNum()
{
	return vertices.size();
}

void polyObject::draw()
{
	glColor3fv((GLfloat*)&color);

	if (getVertNum() == 1) { glBegin(GL_POINTS); }
	else if (getVertNum() == 2) { glBegin(GL_LINES); }
	else { glBegin(GL_POLYGON); }

	for (int i = 0; i < getVertNum(); i++) glVertex2fv((GLfloat*)&vertices[i]);

	glEnd();
}

void polyObject::draw(vec2 p_mousePos)
{
	glColor3fv((GLfloat*)&color);

	if (getVertNum() == 1) { glBegin(GL_LINES); }
	else { glBegin(GL_POLYGON); }

	for (int i = 0; i < getVertNum(); i++) glVertex2fv((GLfloat*)&vertices[i]);
	glVertex2fv((GLfloat*)&p_mousePos);

	glEnd();
}

void polyObject::restart()
{
	vertices.clear();
}