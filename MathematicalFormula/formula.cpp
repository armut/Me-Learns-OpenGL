#include <GL/freeglut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <math.h>
#include "../tools.h"

const int MOUNT_WIDTH = 7;
const int MOUNT_HEIGHT = 3;

void initGraphics(void)
{
    glEnable(GL_POINT_SMOOTH);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-WIDTH/2, WIDTH/2, -HEIGHT/2, HEIGHT/2);
    glPointSize(2.0);
}

void drawDPoint(GLdoublePoint point)
{
    glBegin(GL_POINTS);
        glVertex2d(point.x, point.y);
    glEnd();
}

void drawAxes()
{
    glColor3f(0.0, 1.0, 1.0);
    for (int i = -(WIDTH/2); i < (WIDTH/2); i++)
    {
        GLdoublePoint point = {i, 0};
        drawDPoint(point);
    }

    for (int i = -(HEIGHT/2); i < (HEIGHT/2); i++)
    {
        GLdoublePoint point = {0, i};
        drawDPoint(point);
    }
}

void drawMountain()
{
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(2.0);
    for (GLdouble x = -100; x <= 100; x += 0.005)
    {
        GLdouble func = (pow(x, 3) + pow(x, 2)) / (pow(x, 5) + pow(x, 2));
        GLdoublePoint point = {x, func};
        point.x = point.x * (WIDTH/2) / MOUNT_WIDTH;
        point.y = point.y * (HEIGHT/2) / MOUNT_HEIGHT;
        drawDPoint(point);
    }
}

void renderer(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxes();
    drawMountain();
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
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Mount Erciyes");
    glutDisplayFunc(renderer);
    glutKeyboardFunc(keyboardListener);

    initGraphics();

    glutMainLoop();
    return 0;
}

