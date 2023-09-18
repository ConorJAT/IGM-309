// Course:  IGME 309
// Student Name:  Conor Race
// Assignment Number:  01

#ifdef __APPLE__
#include <GLUT/glut.h> // include glut for Mac
#else
#include <GL/freeglut.h> //include glut for Windows
#endif

#include <math.h>


// the window's width and height
int width, height, vertex;

void init(void)
{
    // initialize the size of the window
    width = 600;
    height = 600;
    vertex = 18;
}

void drawFilledCircle(float red, float green, float blue, float center_x, float center_y, float radius)
{
    glColor3f(red, green, blue);

    glBegin(GL_POLYGON);
    for (float i = 0.0; i < 6.2832; i += (6.2832 / vertex)) {
        glVertex2f(center_x + (radius * cos(i)), center_y + (radius * sin(i)));
    }
    glEnd();
}

void drawWireCircle(float red, float green, float blue, float center_x, float center_y, float radius, float lineWidth) 
{
    glColor3f(red, green, blue);
    glLineWidth(lineWidth);

    glBegin(GL_LINE_LOOP);
    for (float i = 0.0; i < 6.2832; i += (6.2832 / vertex)) {
        glVertex2f(center_x + (radius * cos(i)), center_y + (radius * sin(i)));
    }
    glEnd();
}

void DrawPanda() {
    // this is immedidate mode of OpenGL usded prior to OpenGL 3.0
    
    // Draw tail!
    drawFilledCircle(0, 0, 0, 25.0, 11.0, 2.0);
    
    // Draw body!
    drawFilledCircle(0, 0, 0, 25.0, 19.0, 7.0);
    drawFilledCircle(1.0, 1.0, 1.0, 25.0, 16.0, 4.0);
    
    // Draw ears!
    drawFilledCircle(0, 0, 0, 17.0, 43.0, 4.0);
    drawFilledCircle(0, 0, 0, 33.0, 43.0, 4.0);

    // Draw head!
    drawFilledCircle(1.0, 1.0, 1.0, 25.0, 35.0, 10.0);
    
    // Draw left eye!
    drawFilledCircle(0, 0, 0, 20.0, 35.0, 4.0);
    drawFilledCircle(1.0, 1.0, 1.0, 21.0, 35.0, 2.0);
    drawFilledCircle(85.0 / 255, 106.0 / 255, 242.0 / 255, 21.5, 35.5, 1.5);
    drawFilledCircle(0, 0, 0, 22.0, 36.0, .75);

    // Draw right eye!
    drawFilledCircle(0, 0, 0, 30.0, 35.0, 4.0);
    drawFilledCircle(1.0, 1.0, 1.0, 29.0, 35.0, 2.0);
    drawFilledCircle(85.0 / 255, 106.0 / 255, 242.0 / 255, 28.5, 35.5, 1.5);
    drawFilledCircle(0, 0, 0, 28.0, 36.0, .75);

    // Draw nose!
    drawFilledCircle(0, 0, 0, 25.0, 31.0, 2.0);

    // Draw mouth!
    drawFilledCircle(219.0 / 255, 134.0 / 255, 134.0 / 255, 25.0, 27.0, .75);

    // Draw front paws!
    drawFilledCircle(0, 0, 0, 18.0, 23.0, 3.0);
    drawFilledCircle(1.0, 1.0, 1.0, 18.0, 22.0, 2.0);
    drawFilledCircle(0, 0, 0, 32.0, 23.0, 3.0);
    drawFilledCircle(1.0, 1.0, 1.0, 32.0, 22.0, 2.0);

    // Draw back paws!
    drawFilledCircle(0, 0, 0, 19.0, 14.0, 3.0);
    drawFilledCircle(1.0, 1.0, 1.0, 19.0, 13.0, 2.0);
    drawFilledCircle(0, 0, 0, 31.0, 14.0, 3.0);
    drawFilledCircle(1.0, 1.0, 1.0, 31.0, 13.0, 2.0);
}

// called when the GL context need to be rendered
void display(void)
{
    // clear the screen to white, which is the background color
    glClearColor(137.0/255, 201.0/255, 135.0/255, 0.0);

    // clear the buffer stored for drawing
    glClear(GL_COLOR_BUFFER_BIT);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // specify the color for drawing
    glColor3f(1.0, 0.0, 0.0);

    // this is immedidate mode of OpenGL usded prior to OpenGL 3.0
    DrawPanda();

    // specify the color for new drawing
    glColor3f(0.0, 0.0, 1.0);

    // draw the origin of the canvas
    glPointSize(30.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.0f, 0.0f);
    glEnd();
    glPointSize(1.0f);

    glutSwapBuffers();
}

// called when window is first created or when window is resized
void reshape(int w, int h)
{
    // update thescreen dimensions
    width = w;
    height = h;

    //do an orthographic parallel projection, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 50.0, 0.0, 50.0);

    /* tell OpenGL to use the whole window for drawing */
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);

    glutPostRedisplay();
}

int main(int argc, char* argv[])
{
    // before create a glut window,
    // initialize stuff not opengl/glut dependent
    init();

    //initialize GLUT, let it extract command-line GLUT options that you may provide
    //NOTE that the '&' before argc
    glutInit(&argc, argv);

    // specify as double bufferred can make the display faster
    // Color is speicfied to RGBA, four color channels with Red, Green, Blue and Alpha(depth)
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    //set the initial window size */
    glutInitWindowSize((int)width, (int)height);

    // create the window with a title
    glutCreateWindow("First OpenGL Program");

    /* --- register callbacks with GLUT --- */

    //register function to handle window resizes
    glutReshapeFunc(reshape);

    //register function that draws in the window
    glutDisplayFunc(display);

    //start the glut main loop
    glutMainLoop();

    return 0;
}