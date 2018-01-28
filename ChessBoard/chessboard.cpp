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
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);
}

void keyboardListener(unsigned char key, int x, int y)
{
    exit(1);
}

void checkerboard(int size)
{
    GLfloat level[2] = {0.1, 0.7};
    int index = 0;
    for (int i = 0; i < 64; i++)
    {
        glColor3f(level[index], level[index], level[index]);
        glRecti((i%8)*size, (i/8)*size, ((i%8)+1)*size, ((i/8)+1)*size);
        ((i+1) % 8 == 0 && i != 0) ? index = index : index = ++index % 2;
    }
}

void renderer(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    checkerboard(30);
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 200);
    glutCreateWindow("Chess Board");
    glutDisplayFunc(renderer);
    glutKeyboardFunc(keyboardListener);

    initGraphics();

    glutMainLoop();
    return 0;
}
