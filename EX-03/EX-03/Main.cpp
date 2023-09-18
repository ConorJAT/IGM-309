// Course:  IGME 309
// Student Name:  Conor Race
// Friday Exercise:  03

#ifdef __APPLE__
#include <GLUT/glut.h> // include glut for Mac
#else
#include <GL/freeglut.h> //include glut for Windows
#endif


// the window's width and height
int width, height;

void init(void)
{
    // initialize the size of the window
    width = 600;
    height = 600;
}

void DrawTree() {
    // this is immedidate mode of OpenGL usded prior to OpenGL 3.0
    // Draw trunk and base!
    glColor3f(130.0 / 255, 77.0 / 255, 24.0 / 255);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(14.0f, 3.0f);
    glVertex2f(14.0f, 16.0f);
    glVertex2f(16.0f, 3.0f);
    glVertex2f(16.0f, 16.0f);
    glEnd();
    
    glColor3f(68.0 / 255, 11.0 / 255, 11.0 / 255);
    glBegin(GL_POLYGON);
    glVertex2f(12.0f, 3.5f);
    glVertex2f(13.0f, 2.0f);
    glVertex2f(17.0f, 2.0f);
    glVertex2f(18.0f, 3.5f);
    glEnd();
    
    // Draw branches/leaves!
    glColor3f(31.0 / 255, 81.0 / 255, 20.0 / 255);
    glBegin(GL_TRIANGLES);
    glVertex2f(8.0f, 5.0f);
    glVertex2f(22.0f, 5.0f);
    glVertex2f(15.0f, 10.0f);
    glEnd();

    glColor3f(39.0 / 255, 119.0 / 255, 23.0 / 255);
    glBegin(GL_TRIANGLES);
    glVertex2f(9.0f, 9.0f);
    glVertex2f(21.0f, 9.0f);
    glVertex2f(15.0f, 13.0f);
    glEnd();

    glColor3f(35.0 / 255, 168.0 / 255, 57.0 / 255);
    glBegin(GL_TRIANGLES);
    glVertex2f(10.0f, 12.0f);
    glVertex2f(20.0f, 12.0f);
    glVertex2f(15.0f, 15.0f);
    glEnd();
    
    glColor3f(49.0 / 255, 226.0 / 255, 79.0 / 255);
    glBegin(GL_TRIANGLES);
    glVertex2f(11.0f, 14.0f);
    glVertex2f(19.0f, 14.0f);
    glVertex2f(15.0f, 17.0f);
    glEnd();
    
    // Draw ornaments!
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(12.0f, 7.5f);
    glVertex2f(11.0f, 6.5f);
    glColor3f(1.0f, .0f, .0f);
    glVertex2f(12.0f, 5.5f);
    glVertex2f(13.0f, 6.5f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(17.0f, 11.0f);
    glVertex2f(16.0f, 9.5f);
    glColor3f(.0f, 1.0f, .0f);
    glVertex2f(18.0f, 9.5f);
    glEnd();
    
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(15.0f, 13.75f);
    glVertex2f(14.0f, 12.75f);
    glColor3f(168.0 / 255, 239.0 / 255, 244.0 / 255);
    glVertex2f(15.0f, 11.75f);
    glVertex2f(16.0f, 12.75f);
    glEnd();

    // Draw star!
    glColor3f(245.0 / 255, 247.0 / 255, 145.0 / 255);
    glBegin(GL_TRIANGLES);
    glVertex2f(15.0f, 15.5f);
    glVertex2f(13.0f, 18.5f);
    glVertex2f(17.0f, 18.5f);
    glEnd();

    glColor3f(245.0 / 255, 247.0 / 255, 145.0 / 255);
    glBegin(GL_TRIANGLES);
    glVertex2f(15.0f, 19.5f);
    glVertex2f(13.0f, 16.5f);
    glVertex2f(17.0f, 16.5f);
    glEnd();
}

// called when the GL context need to be rendered
void display(void)
{
    // clear the screen to white, which is the background color
    glClearColor(.90f, 1.0f, .99f, .90f);

    // clear the buffer stored for drawing
    glClear(GL_COLOR_BUFFER_BIT);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // specify the color for drawing
    glColor3f(1.0, 0.0, 0.0);

    // this is immedidate mode of OpenGL usded prior to OpenGL 3.0
    DrawTree();

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
    gluOrtho2D(0.0, 30.0, 0.0, 25.0);
    //gluOrtho2D(-5.0, 5.0, -5.0, 5.0);

    /* tell OpenGL to use the whole window for drawing */
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    //glViewport((GLsizei) width/2, (GLsizei) height/2, (GLsizei) width, (GLsizei) height);

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
    glutCreateWindow("Conor Race - Merry Christmas!");

    /* --- register callbacks with GLUT --- */

    //register function to handle window resizes
    glutReshapeFunc(reshape);

    //register function that draws in the window
    glutDisplayFunc(display);

    //start the glut main loop
    glutMainLoop();

    return 0;
}