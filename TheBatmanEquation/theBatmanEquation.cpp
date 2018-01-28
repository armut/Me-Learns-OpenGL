#include <GL/freeglut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <math.h>
#include "../tools.cpp"

const int LOGO_WIDTH = 7;
const int LOGO_HEIGHT = 3;

void initGraphics(void)
{
    glEnable(GL_POINT_SMOOTH);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-WIDTH/2, WIDTH/2, -HEIGHT/2, HEIGHT/2);
    glPointSize(4.0);
}

void drawAxes()
{
    glColor3f(0.0, 1.0, 1.0);
    glPointSize(2.0);
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

void drawBatmanLogo()
{
    glColor3f(1.0, 1.0, 1.0);
    GLdouble xs = (WIDTH/2 - 50) / LOGO_WIDTH;
    GLdouble ys = (HEIGHT/2 - 100) / LOGO_HEIGHT;

    for (GLdouble x = -7; x <= 7; x += 0.005)
    {
        // Tail
        GLdouble tailFunc = fabs(x/2) - ((3*sqrt(33)-7)/112)*pow(x, 2) - 3 \
            + sqrt(1 - pow(((fabs(fabs(x) - 2)) - 1), 2));
        GLdoublePoint point = {x, tailFunc};
        point.x = point.x * xs;
        point.y = point.y * ys;
        drawDPoint(point);

        // Ear
        GLdouble earFunc = 3 * fabs(x) + 0.75 * \
            sqrt( \
                fabs((0.75 - fabs(x)) * (fabs(x) - 0.5)) / ((0.75 - fabs(x)) * (fabs(x) - 0.5)) \
            );
        GLdoublePoint earPoint = {x * xs, earFunc * ys};
        drawDPoint(earPoint);

        // Head
        GLdouble headFunc = 2.25 * sqrt(fabs((0.5 - x) * (x + 0.5)) / \
            ((0.5 - x) * (x + 0.5)));
        GLdoublePoint headPoint = {x * xs, headFunc * ys};
        drawDPoint(headPoint);

        // Shoulders
        GLdouble shoulderFunc = 6 * sqrt(10) / 7 + (1.5 - 0.5 * fabs(x)) - (6 * sqrt(10) / 14) * \
            sqrt(4 - pow(fabs(x) - 1, 2));
        GLdoublePoint shoulderPoint = {x * xs, shoulderFunc * ys};
        drawDPoint(shoulderPoint);

        // More ears
        GLdouble earContdFunc = 9 * sqrt(fabs((1 - fabs(x)) * (fabs(x) - 0.75)) / \
            ((1 - fabs(x)) * (fabs(x) - 0.75))) - 8 * fabs(x);
        GLdoublePoint earContdPoint = {x * xs, earContdFunc * ys};
        drawDPoint(earContdPoint);

        // Wing1
        GLdouble wing1Func = sqrt( \
            -(pow(x/7, 2) * sqrt(fabs(fabs(x) - 3) / (fabs(x) - 3)) - 1) * 9 \
        );
        GLdoublePoint wing1Point = {x * xs, wing1Func * ys};
        drawDPoint(wing1Point);

        // Wing2
        GLdoublePoint wing2Point = {x * xs, -wing1Func * ys};
        drawDPoint(wing2Point);
    }

}

void renderer(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxes();
    drawBatmanLogo();
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
    glutInitWindowPosition(2000, 200);
    glutCreateWindow("The Batman Logo");
    glutDisplayFunc(renderer);
    glutKeyboardFunc(keyboardListener);

    initGraphics();

    glutMainLoop();
    return 0;
}

