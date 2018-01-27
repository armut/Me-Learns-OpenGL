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

#endif
