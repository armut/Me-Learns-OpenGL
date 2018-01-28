#include <GL/freeglut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include "../tools.cpp"

void initGraphics(void)
{
    glEnable(GL_POINT_SMOOTH);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);
}

void keyboardListener(unsigned char key, int x, int y)
{
    exit(1);
}

void drawFlurryRectangles(int num, int width, int height)
{
    for (int i = 0; i < num; i++)
    {
        GLint x1 = random0(width);
        GLint y1 = random0(height);
        GLint x2 = random0(width);
        GLint y2 = random0(height);
        GLfloat grayLevel = random0(10) / 10.0;
        glColor3f(grayLevel, grayLevel, grayLevel);
        glRecti(x1, y1, x2, y2);
    }
}

void renderer(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawFlurryRectangles(10, 640, 480);
    glFlush();
}

int main(int argc, char** argv)
{
    srand(time(0));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 200);
    glutCreateWindow("Flurry Rectangles");
    glutDisplayFunc(renderer);
    glutKeyboardFunc(keyboardListener);

    initGraphics();

    glutMainLoop();
    return 0;
}

