// Course:  IGME 309
// Student Name:  Conor Race
// Assignment Number:  04
// Controls: A/D to swap between joints | W/S to rotate the joints.

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include <iostream>
#include <math.h>
using namespace std;

#define MAX_NUM_RECTS 16

int win_width = 600, win_height = 600;
float canvas_width = 30.0f; float canvas_height = 30.0f;

float colors[3 * MAX_NUM_RECTS];
float rotations[MAX_NUM_RECTS];
float translations[2 * MAX_NUM_RECTS] =
{
    0.0f, 0.0f,     // Torso
    0.0f, 2.0f,     // Chest
    0.0f, 5.0f,     // Neck
    0.0f, 6.0f,     // Head
    -3.0f, 4.5f,    // Left Bicep
    -6.0f, 4.5f,    // Left Tricep
    -9.0f, 4.5f,    // Left Hand
    3.0f, 4.5f,     // Right Bicep
    6.0f, 4.5f,     // Right Tricep
    9.0f, 4.5f,     // Right Hand
    -1.5f, 0.0f,    // Left Thigh
    -1.5f, -3.0f,   // Left Shin
    -1.5f, -6.0f,   // Left Foot
    1.5f, 0.0f,     // Right Thigh
    1.5f, -3.0f,    // Right Shin
    1.5f, -6.0f     // Right Foot
};

int selected;

void init(void)
{
    for (int i = 0; i < MAX_NUM_RECTS; i++) {
        colors[i * 3 + 0] = 0.0f; // red
        colors[i * 3 + 1] = 0.0f; // green
        colors[i * 3 + 2] = 0.0f; // blue

        rotations[i] = 0.0f;
    }

    colors[0] = 1.0f;
    selected = 0;
}

void drawQuad(float left, float right, float top, float bottom, float* color) 
{
    glColor3fv(color);
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(left, top);
        glVertex2f(left, bottom);
        glVertex2f(right, bottom);
        glVertex2f(right, top);
    glEnd();
}


void display(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    int current;

    current = 0;    // Lower Torso
    glTranslatef(translations[current * 2 + 0], translations[current * 2 + 1], 0.0f);
    glRotatef(rotations[current], 0.0f, 0.0f, 1.0f);
    glTranslatef(-translations[current * 2 + 0], -translations[current * 2 + 1], 0.0f);
    glPopMatrix();
    drawQuad(-2.0f, 2.0f, 2.0f, 0.0f, colors + (current * 3));

    glPushMatrix();
        current = 1;    // Upper Chest
        glTranslatef(translations[current * 2 + 0], translations[current * 2 + 1], 0.0f);
        glRotatef(rotations[current], 0.0f, 0.0f, 1.0f);
        glTranslatef(-translations[current * 2 + 0], -translations[current * 2 + 1], 0.0f);
        drawQuad(-3.0f, 3.0f, 5.0f, 2.0f, colors + (current * 3));

        glPushMatrix();     
            current = 2;    // Neck
            glTranslatef(translations[current * 2 + 0], translations[current * 2 + 1], 0.0f);
            glRotatef(rotations[current], 0.0f, 0.0f, 1.0f);
            glTranslatef(-translations[current * 2 + 0], -translations[current * 2 + 1], 0.0f);
            drawQuad(-0.5f, 0.5f, 6.0f, 5.0f, colors + (current * 3));

            current = 3;    // Head
            glTranslatef(translations[current * 2 + 0], translations[current * 2 + 1], 0.0f);
            glRotatef(rotations[current], 0.0f, 0.0f, 1.0f);
            glTranslatef(-translations[current * 2 + 0], -translations[current * 2 + 1], 0.0f);
            drawQuad(-1.5f, 1.5f, 9.0f, 6.0f, colors + (current * 3));
        glPopMatrix();

        glPushMatrix();
            current = 4;    // Left Bicep
            glTranslatef(translations[current * 2 + 0], translations[current * 2 + 1], 0.0f);
            glRotatef(rotations[current], 0.0f, 0.0f, 1.0f);
            glTranslatef(-translations[current * 2 + 0], -translations[current * 2 + 1], 0.0f);
            drawQuad(-6.0f, -3.0f, 5.0f, 4.0f, colors + (current * 3));

            current = 5;    // Left Tricep
            glTranslatef(translations[current * 2 + 0], translations[current * 2 + 1], 0.0f);
            glRotatef(rotations[current], 0.0f, 0.0f, 1.0f);
            glTranslatef(-translations[current * 2 + 0], -translations[current * 2 + 1], 0.0f);
            drawQuad(-9.0f, -6.0f, 5.0f, 4.0f, colors + (current * 3));

            current = 6;    // Left Hand
            glTranslatef(translations[current * 2 + 0], translations[current * 2 + 1], 0.0f);
            glRotatef(rotations[current], 0.0f, 0.0f, 1.0f);
            glTranslatef(-translations[current * 2 + 0], -translations[current * 2 + 1], 0.0f);
            drawQuad(-11.0f, -9.0f, 5.5f, 3.5f, colors + (current * 3));
        glPopMatrix();

        glPushMatrix();
            current = 7;    // Right Bicep
            glTranslatef(translations[current * 2 + 0], translations[current * 2 + 1], 0.0f);
            glRotatef(rotations[current], 0.0f, 0.0f, 1.0f);
            glTranslatef(-translations[current * 2 + 0], -translations[current * 2 + 1], 0.0f);
            drawQuad(3.0f, 6.0f, 5.0f, 4.0f, colors + (current * 3));

            current = 8;    // Right Tricep
            glTranslatef(translations[current * 2 + 0], translations[current * 2 + 1], 0.0f);
            glRotatef(rotations[current], 0.0f, 0.0f, 1.0f);
            glTranslatef(-translations[current * 2 + 0], -translations[current * 2 + 1], 0.0f);
            drawQuad(6.0f, 9.0f, 5.0f, 4.0f, colors + (current * 3));

            current = 9;    // Right Hand
            glTranslatef(translations[current * 2 + 0], translations[current * 2 + 1], 0.0f);
            glRotatef(rotations[current], 0.0f, 0.0f, 1.0f);
            glTranslatef(-translations[current * 2 + 0], -translations[current * 2 + 1], 0.0f);
            drawQuad(9.0f, 11.0f, 5.5f, 3.5f, colors + (current * 3));
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        current = 10;   // Left Thigh
        glTranslatef(translations[current * 2 + 0], translations[current * 2 + 1], 0.0f);
        glRotatef(rotations[current], 0.0f, 0.0f, 1.0f);
        glTranslatef(-translations[current * 2 + 0], -translations[current * 2 + 1], 0.0f);
        drawQuad(-2.0f, -1.0f, 0.0f, -3.0f, colors + (current * 3));

        current = 11;   // Left Shin
        glTranslatef(translations[current * 2 + 0], translations[current * 2 + 1], 0.0f);
        glRotatef(rotations[current], 0.0f, 0.0f, 1.0f);
        glTranslatef(-translations[current * 2 + 0], -translations[current * 2 + 1], 0.0f);
        drawQuad(-2.0f, -1.0f, -3.0f, -6.0f, colors + (current * 3));

        current = 12;   // Left Foot
        glTranslatef(translations[current * 2 + 0], translations[current * 2 + 1], 0.0f);
        glRotatef(rotations[current], 0.0f, 0.0f, 1.0f);
        glTranslatef(-translations[current * 2 + 0], -translations[current * 2 + 1], 0.0f);
        drawQuad(-4.0f, -1.0f, -6.0f, -8.0f, colors + (current * 3));
    glPopMatrix();

    glPushMatrix();
        current = 13;   // Right Thigh
        glTranslatef(translations[current * 2 + 0], translations[current * 2 + 1], 0.0f);
        glRotatef(rotations[current], 0.0f, 0.0f, 1.0f);
        glTranslatef(-translations[current * 2 + 0], -translations[current * 2 + 1], 0.0f);
        drawQuad(1.0f, 2.0f, 0.0f, -3.0f, colors + (current * 3));

        current = 14;   // Right Shin
        glTranslatef(translations[current * 2 + 0], translations[current * 2 + 1], 0.0f);
        glRotatef(rotations[current], 0.0f, 0.0f, 1.0f);
        glTranslatef(-translations[current * 2 + 0], -translations[current * 2 + 1], 0.0f);
        drawQuad(1.0f, 2.0f, -3.0f, -6.0f, colors + (current * 3));

        current = 15;   // Right Foot
        glTranslatef(translations[current * 2 + 0], translations[current * 2 + 1], 0.0f);
        glRotatef(rotations[current], 0.0f, 0.0f, 1.0f);
        glTranslatef(-translations[current * 2 + 0], -translations[current * 2 + 1], 0.0f);
        drawQuad(1.0f, 4.0f, -6.0f, -8.0f, colors + (current * 3));
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    win_width = w;
    win_height = h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-canvas_width / 2.0f, canvas_width / 2.0f, -canvas_height / 2.0f, canvas_height / 2.0f);
    glViewport(0, 0, (GLsizei)win_width, (GLsizei)win_height);

    glutPostRedisplay();
}


void keyboard(unsigned char key, int x, int y)
{
    if (key == 27) // 'esc' key
        exit(0);

    if (key == 'a' && selected > 0) // Move to next shape in hierarchy (if able).
    { 
        for (int i = 0; i < MAX_NUM_RECTS; i++) {
            colors[i * 3 + 0] = 0.0f;
            colors[i * 3 + 1] = 0.0f;
            colors[i * 3 + 2] = 0.0f;
        }

        selected--;
        colors[selected * 3 + 0] = 1.0f;
        colors[selected * 3 + 1] = 0.0f;
        colors[selected * 3 + 2] = 0.0f;
    }

    if (key == 'd' && selected < 15) // Move to previous shape in hierarchy (if able).
    { 
        for (int i = 0; i < MAX_NUM_RECTS; i++) {
            colors[i * 3 + 0] = 0.0f;
            colors[i * 3 + 1] = 0.0f;
            colors[i * 3 + 2] = 0.0f;
        }

        selected++; 
        colors[selected * 3 + 0] = 1.0f;
        colors[selected * 3 + 1] = 0.0f;
        colors[selected * 3 + 2] = 0.0f;
    }
    
    if (key == 'w') // Rotate the selected shape (and its connected children, if any).
    {
        rotations[selected] += (3.14159 / 4.0f);
    }

    if (key == 's') 
    {
        rotations[selected] -= (3.14159 / 4.0f);
    }

    glutPostRedisplay();
}


int main(int argc, char* argv[])
{
    init();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(win_width, win_height);
    glutCreateWindow("HW-04: Friendly Robot!");

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}