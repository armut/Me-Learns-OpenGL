#include <GL/freeglut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <math.h>
#include "../tools.cpp"

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
}

void drawAxes()
{
    glColor3f(0.0, 1.0, 1.0);
    GLintPoint topMid = {0, -HEIGHT/2};
    GLintPoint botMid = {0, HEIGHT/2};
    drawILine(topMid, botMid);

    GLintPoint leftMid = {-WIDTH/2, 0};
    GLintPoint rightMid = {WIDTH/2, 0};
    drawILine(leftMid, rightMid);
}

void drawMountain()
{
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);
    for (GLdouble x = -100; x <= 100; x += 0.005)
    {
        GLdouble sine = fabs(sin(x));
        GLdoublePoint point = {x, sine};
        point.x = point.x * (WIDTH/2) / MOUNT_WIDTH;
        point.y = point.y * (HEIGHT/2) / MOUNT_HEIGHT;
        glVertex2d(point.x, point.y);

    }
    glEnd();

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINE_STRIP);
    for (GLdouble x = -100; x <= 100; x += 0.005)
    {
        GLdouble cosine = fabs(cos(x));
        GLdoublePoint point2= {x, cosine};
        point2.x = point2.x * (WIDTH/2) / MOUNT_WIDTH;
        point2.y = point2.y * (HEIGHT/2) / MOUNT_HEIGHT;
        glVertex2d(point2.x, point2.y);
    }
    glEnd();

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
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Mount Erciyes");
    glutDisplayFunc(renderer);
    glutKeyboardFunc(keyboardListener);

    initGraphics();

    glutMainLoop();
    return 0;
}

