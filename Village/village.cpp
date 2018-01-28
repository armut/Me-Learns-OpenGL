#include <GL/freeglut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include "../tools.h"

void initGraphics(void)
{
    glEnable(GL_POINT_SMOOTH);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);
}

GLdouble findY(GLintPoint point, GLdouble slope, GLint x)
{
    return slope * (x - point.x) + point.y;
}

void drawHouse(GLintPoint peak, GLdouble width, GLdouble height)
{
    // Draw the shell of the house.
    GLdouble slope = ( peak.y - (peak.y - height / 3) ) / ( peak.x - (peak.x - width / 2) );
    GLint hsign = width > 0 ? 1: -1;
    GLint vsign = height > 0 ? 1: -1;
    glBegin(GL_LINE_LOOP);
        glVertex2d(peak.x, peak.y);
        glVertex2d(peak.x + width / 2, peak.y - height / 3);
        glVertex2d(peak.x + width / 2, peak.y - 2*height / 3);
        glVertex2d(peak.x + width / 2 - hsign * 10, peak.y - 2*height / 3);
        glVertex2d(peak.x + width / 2 - hsign * 10, peak.y - height);
        glVertex2d(peak.x - width / 2 + hsign * 10, peak.y - height);
        glVertex2d(peak.x - width / 2 + hsign * 10, peak.y - 2*height / 3);
        glVertex2d(peak.x - width / 2, peak.y - 2*height / 3);
        glVertex2d(peak.x - width / 2, peak.y - height / 3);
        glVertex2d(peak.x - width / 4, findY(peak, slope, peak.x - width / 4));
        glVertex2d(peak.x - width / 4, peak.y);
        glVertex2d(peak.x - width / 8, peak.y);
        glVertex2d(peak.x - width / 8, findY(peak, slope, peak.x - width / 8));
    glEnd();

    // Draw the door.
    glBegin(GL_LINE_LOOP);
        glVertex2d(peak.x - width / 16, peak.y - height);
        glVertex2d(peak.x + width / 16, peak.y - height);
        glVertex2d(peak.x + width / 16, peak.y - 2*height / 3 - vsign*10);
        glVertex2d(peak.x - width / 16, peak.y - 2*height / 3 - vsign*10);
    glEnd();
    
    // Draw window1
    glBegin(GL_LINE_LOOP);
        glVertex2d(peak.x + width / 16, peak.y - 2*height / 3 + vsign*10);
        glVertex2d(peak.x - width / 16, peak.y - 2*height / 3 + vsign*10);
        glVertex2d(peak.x - width / 16, peak.y - height / 3);
        glVertex2d(peak.x + width / 16, peak.y - height / 3);
    glEnd();
    glBegin(GL_LINES);
        glVertex2d(peak.x + width / 16, peak.y - 2*height / 3 + vsign*10);
        glVertex2d(peak.x + width / 16 - hsign * 2, peak.y - 2*height / 3);
        glVertex2d(peak.x - width / 16, peak.y - 2*height / 3 + vsign*10);
        glVertex2d(peak.x - width / 16 + hsign * 2, peak.y - 2*height / 3);
    glEnd();

    // Draw window2
    glBegin(GL_LINE_LOOP);
        glVertex2d(peak.x + 2*width / 16, peak.y - 2*height / 3 + vsign*10);
        glVertex2d(peak.x - 2*width / 16, peak.y - 2*height / 3 + vsign*10);
        glVertex2d(peak.x - 2*width / 16, peak.y - height / 3);
        glVertex2d(peak.x + 2*width / 16, peak.y - height / 3);
    glEnd();

    // Draw window3
    glBegin(GL_LINE_LOOP);
        glVertex2d(peak.x - width / 3, peak.y - 2*height / 3 + vsign*10);
        glVertex2d(peak.x - width / 3 + hsign * 10, peak.y - 2*height / 3 + vsign*10);
        glVertex2d(peak.x - width / 3 + hsign * 10, peak.y - height / 3);
        glVertex2d(peak.x - width / 3, peak.y - height / 3);
    glEnd();

    // Draw window4
    glBegin(GL_LINE_LOOP);
        glVertex2d(peak.x + width / 3, peak.y - 2*height / 3 + vsign*10);
        glVertex2d(peak.x + width / 3 - hsign * 10, peak.y - 2*height / 3 + vsign*10);
        glVertex2d(peak.x + width / 3 - hsign * 10, peak.y - height / 3);
        glVertex2d(peak.x + width / 3, peak.y - height / 3);
    glEnd();

    // Draw window decoration.
    glBegin(GL_LINES);
        glVertex2d(peak.x - width / 3, peak.y - 2*height / 3 + vsign*15);
        glVertex2d(peak.x - width / 3 + hsign * 10, peak.y - 2*height / 3 + vsign*15);

        glVertex2d(peak.x - 2*width / 16, peak.y - 2*height / 3 + vsign*15);
        glVertex2d(peak.x + 2*width / 16, peak.y - 2*height / 3 + vsign*15);

        glVertex2d(peak.x + width / 3, peak.y - 2*height / 3 + vsign*15);
        glVertex2d(peak.x + width / 3 - hsign * 10, peak.y - 2*height / 3 + vsign*15);
    glEnd();
}

void keyboardListener(unsigned char key, int x, int y)
{
    exit(1);
}

void renderer(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    GLintPoint point[6] = {
        {200, 100},
        {200, 400},
        {400, 100},
        {400, 400}
    };
    drawHouse(point[0], 70, -100);
    drawHouse(point[1], 100, 120);
    drawHouse(point[2], 100, -100);
    drawHouse(point[3], 100, 100);
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 200);
    glutCreateWindow("A Peaceful Village");
    glutDisplayFunc(renderer);
    glutKeyboardFunc(keyboardListener);

    initGraphics();

    glutMainLoop();
    return 0;
}
