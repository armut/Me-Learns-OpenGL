#ifndef TOOLS_H
#define TOOLS_H

#define random(a) rand()%a + 1
#define random0(a) rand()%a
#define WIDTH 640
#define HEIGHT 480

class GLintPoint 
{
    public:
        GLint x, y;
};

class GLdoublePoint
{
    public:
        GLdouble x, y;
};

void drawIPoint(GLint x, GLint y);
void drawDPoint(GLdouble x, GLdouble y);
void drawILine(GLint x1, GLint y1, GLint x2, GLint y2);

#endif
