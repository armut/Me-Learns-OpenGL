#ifndef TOOL
#define TOOL
#include "tools.h"

GLintPoint CP;

void moveto(GLint x, GLint y)
{
    CP.x = x; CP.y = y;
}

void lineto(GLint x, GLint y)
{
    glBegin(GL_LINES);
        glVertex2i(CP.x, CP.y);
        glVertex2i(x, y);
    glEnd();
    glFlush();
    CP.x = x; CP.y = y;
}

void drawDPoint(GLdoublePoint point)
{
    glBegin(GL_POINTS);
        glVertex2d(point.x, point.y);
    glEnd();
}

void drawIPoint(GLintPoint point)
{
    glBegin(GL_POINTS);
        glVertex2i(point.x, point.y);
    glEnd();
}

void drawILine(GLintPoint p1, GLintPoint p2)
{
    glBegin(GL_LINES);
        glVertex2i(p1.x, p1.y);
        glVertex2i(p2.x, p2.y);
    glEnd();
}

#endif

