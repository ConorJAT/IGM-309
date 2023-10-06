// Course:  IGME 309
// Student Name:  Conor Race
// Assignment Number:  02

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "polyObject.h"
#include <vector>
#include <iostream>
using namespace std;

float canvasSize[] = { 10.0f, 10.0f };
int rasterSize[] = { 800, 600 };

polyObject currentShape;
vector<polyObject> drawnShapes;
float mousePos[2];

void init(void)
{
    mousePos[0] = mousePos[1] = 0.0f;

    currentShape = polyObject();
}

void drawCursor()
{
    glColor3f(1.0f, 0.0f, 1.0f);
    glPointSize(10.0f);
    glBegin(GL_POINTS);
    glVertex2fv(mousePos);
    glEnd();
    glPointSize(1.0f);
}

void display(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    currentShape.draw(vec2(mousePos[0], mousePos[1]));
    for (polyObject s : drawnShapes) s.draw();

    drawCursor();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    rasterSize[0] = w;
    rasterSize[1] = h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, canvasSize[0], 0.0, canvasSize[1]);
    glViewport(0, 0, rasterSize[0], rasterSize[1]);

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mousePos[0] = (float)x / rasterSize[0] * canvasSize[0];
        mousePos[1] = (float)(rasterSize[1] - y) / rasterSize[1] * canvasSize[1];
        currentShape.addVertex(vec2(mousePos[0], mousePos[1]));

        glutPostRedisplay();
    }
}

void motion(int x, int y)
{
    // mouse events are handled by OS, eventually. When using mouse in the raster window, it assumes top-left is the origin.
    // Note: the raster window created by GLUT assumes bottom-left is the origin.
    mousePos[0] = (float)x / rasterSize[0] * canvasSize[0];
    mousePos[1] = (float)(rasterSize[1] - y) / rasterSize[1] * canvasSize[1];

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:    // Esc Key
        exit(0);
        break;
    case 13:    // Enter Key
        drawnShapes.push_back(currentShape);
        currentShape = polyObject();
        break;
    }
}

void menu(int value)
{
    switch (value) {
    case 0: // clear
        currentShape.restart();
        drawnShapes.clear();
        glutPostRedisplay();
        break;
    case 1: //exit
        exit(0);
    case 2: // red
        currentShape.setColor(vec3(1.0f, 0.0f, 0.0f));
        glutPostRedisplay();
        break;
    case 3: // green
        currentShape.setColor(vec3(0.0f, 1.0f, 0.0f));
        glutPostRedisplay();
        break;
    case 4: // blue
        currentShape.setColor(vec3(0.0f, 0.0f, 1.0f));
        glutPostRedisplay();
        break;
    case 5: // black
        currentShape.setColor(vec3(0.0f, 0.0f, 0.0f));
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

void createMenu()
{
    int colorMenu = glutCreateMenu(menu);
    glutAddMenuEntry("Red", 2);
    glutAddMenuEntry("Green", 3);
    glutAddMenuEntry("Blue", 4);
    glutAddMenuEntry("Black", 5);

    glutCreateMenu(menu);
    glutAddMenuEntry("Clear", 0);
    glutAddSubMenu("Colors", colorMenu);
    glutAddMenuEntry("Exit", 1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char* argv[])
{
    init();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(rasterSize[0], rasterSize[1]);
    glutCreateWindow("Polygon Creator - Draw a Shape!");

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutPassiveMotionFunc(motion);
    createMenu();
    glutMainLoop();
    return 0;
}