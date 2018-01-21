#include <GL/freeglut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../tools.h"

void initGraphics(void)
{
    glEnable(GL_POINT_SMOOTH);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640, 0, 480);
    glPointSize(8.0);
}

void drawPoint(GLfloat size, GLintPoint point)
{
    glPointSize(size);
    glBegin(GL_POINTS);
        glVertex2i(point.x, point.y);
    glEnd();
}

void drawBackground()
{
    for (int i = 0; i < 100; i++)
    {
        glColor3f(0.7, 0.7, 0.6);
        GLintPoint point = {random(640), random(480)};
        drawPoint(random(2), point);
    }
}

void drawTheBigDipper()
{
    GLintPoint dipperPoints[8] = {
        {359, 230},
        {360, 168},
        {279, 107},
        {234, 141},
        {169, 123},
        {115, 113},
        {114, 114},
        {60, 50}
    };
    
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i < 8; i++)
        drawPoint(4.0, dipperPoints[i]);
}

void renderer(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawBackground();
    drawTheBigDipper();
    glFlush();
}

int main(int argc, char** argv)
{
    srand(time(0));

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(320, 240);
    glutInitWindowPosition(100, 200);
    glutCreateWindow("The Big Dipper");
    glutDisplayFunc(renderer);

    initGraphics();

    glutMainLoop();
    return 0;
}
