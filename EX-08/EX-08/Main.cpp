// Course:  IGME 309
// Student Name:  Conor Race
// Friday Exercise:  08

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include <ctime>
#include <cmath>

using namespace std;

float canvasSize[] = { 20.0f, 20.0f };
int rasterSize[] = { 600, 600 };

// tracking the game time - millisecond 
unsigned int curTime = 0;
unsigned int preTime = 0;
float deltaTime = 0;

float rotationAngle = 0.0f;
float rotateSpeed = 90.0f;

void display(void)
{
	glClearColor(0.9f, 0.9f, 0.7f, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/*****************************/
	// write your code below

	// Draw Pivot Point
	glPointSize(12.0f);
	glColor3f(0, 0, 0);
	glBegin(GL_POINTS);
	glVertex2f(10.0f, 15.0f);
	glEnd();

	// Set Rotation Point
	glTranslatef(10.0f, 15.0f, 0);
	glRotatef(rotationAngle, 0, 0, 1.0f);
	glTranslatef(-10.0f, -15.0f, 0);

	// Draw Connecting Line
	glLineWidth(3.0f);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(10.0f, 15.0f);
	glVertex2f(10.0f, 5.0f);
	glEnd();

	// Draw Pendulum Circle
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	for (float i = 0.0; i < 6.2832; i += (6.2832 / 30.0)) { glVertex2f(10.0f + (1.5f * cos(i)), 5.0f + (1.5f * sin(i))); }
	glEnd();

	// write your code above
	/*****************************/

	glutSwapBuffers();
}

void reshape(int w, int h)
{
	rasterSize[0] = w;
	rasterSize[1] = h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, canvasSize[0], 0, canvasSize[1]);
	glViewport(0, 0, rasterSize[0], rasterSize[1]);

	glutPostRedisplay();
}


void update() {
	curTime = glutGet(GLUT_ELAPSED_TIME);
	deltaTime = (float)(curTime - preTime) / 1000.0f;


	if (rotationAngle > 45.0f) {
		rotateSpeed = -abs(rotateSpeed);
	}
	else if (rotationAngle < -45.0f) {
		rotateSpeed = abs(rotateSpeed);
	}
	rotationAngle += deltaTime * rotateSpeed;

	preTime = curTime;
	glutPostRedisplay();
}


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(rasterSize[0], rasterSize[1]);
	glutCreateWindow("Simple Pendulum");

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutIdleFunc(update);

	preTime = glutGet(GLUT_ELAPSED_TIME);
	glutMainLoop();
	return 0;
}