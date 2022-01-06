#include <iostream>
using namespace std;
#include<GL/glut.h>

float x1, y1, x2, y2 ;

void line_display(void)
{
    float m , dy , dx , step , x ,y , i  ;

    dx = x2 - x1 ;
    dy = y2 - y1 ;

    if(abs(dx)> abs(dy))
    {
        step = abs(dx);
    }

    else
        step = abs(dy);

    m = dy/dx;

    x = x1 ;
    y = y1 ;

    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();

    for (i=1 ;i<=step;i++)
    {
        if(m<1)
        {
            x = 1+x;
            y = m+y;
        }

    if(m==1)
    {
        x = 1+x;
        y = 1+y;
    }

    if(m>1)
    {
        x = (1/m) + x;
        y = 1+y;
    }

    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();

    }

    glFlush();
}


void init(void)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(" Bresenham Line Drawing");

    glClearColor(0.25, 0.25, 0.25, 0);
    glColor3f(255,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-100, 100,  -100,  100);

    glBegin(GL_LINES);
    glVertex2f(-60,0);
    glVertex2f(60,0);
    glVertex2f(0,-60);
    glVertex2f(0,60);
    glEnd();
}

int main(int argc, char** argv)
{
    cout << "Enter points\n";
    cout << "value of x1 : ";
    cin >> x1;
    cout << "value of y1 : ";
    cin >> y1;
    cout << "value of x2 : ";
    cin >> x2;
    cout << "value of y2 : ";
    cin >> y2;

    glutInit(&argc, argv);
    init();
    glutDisplayFunc(line_display);
    glutMainLoop();

    return 0;
}
