#include <GL/freeglut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
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
    glPointSize(3.0);
}

void drawPoint(GLintPoint point)
{
    glBegin(GL_POINTS);
        glVertex2i(point.x, point.y);
    glEnd();
}

void drawSierpinskiGasket()
{
    GLintPoint T[3] = {
        {10, 10},
        {630, 10},
        {310, 470}
    };

    int index = random0(3);
    GLintPoint point = T[index];
    drawPoint(point);
    for (int i = 0; i < 10000; i++)
    {
        index = random0(3);
        point.x = (point.x + T[index].x) / 2;
        point.y = (point.y + T[index].y) / 2;
        drawPoint(point);
    }
}

void renderer(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawSierpinskiGasket();
    glFlush();
}

void keyboardListener(unsigned char key, int x, int y)
{
    exit(1);
}

int main(int argc, char** argv)
{
    srand(time(0));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(320, 240);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("The Sierpinski Gasket");
    glutDisplayFunc(renderer);
    glutKeyboardFunc(keyboardListener);

    initGraphics();

    glutMainLoop();
    return 0;
}

