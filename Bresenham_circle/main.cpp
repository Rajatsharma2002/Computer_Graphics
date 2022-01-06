#include <stdio.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

float xc , yc ;
float r;

void plot_points(float x,float y)
{
  glBegin(GL_POINTS);
  glVertex2i(xc+x, yc+y);
  glVertex2i(xc+x, yc-y);
  glVertex2i(xc+y, yc+x);
  glVertex2i(xc+y, yc-x);
  glVertex2i(xc-x, yc-y);
  glVertex2i(xc-y, yc-x);
  glVertex2i(xc-x, yc+y);
  glVertex2i(xc-y, yc+x);
  glEnd();
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  float x=0,y=r;
  float p=3-2*r;
  plot_points(x,y);

  while(x < y)
  {
    if(p < 0){
      x+= 1;
      y=y;
      p += 4*x+6;
    }
    else
    {
      x += 1;
      y -= 1;
      p +=4*(x - y) + 10;
    }
    plot_points(x,y);
  }
  glFlush();
}

void Init()
{
  glClearColor(1.0,1.0,1.0,0);
  glColor3f(0.0,0.0,0.0);
  gluOrtho2D(-100,700,-100,500);
}

int main(int argc, char **argv)
{
    cout<<"Enter value for x : ";
    cin>>xc;
    cout<<"Enter value for y : ";
    cin>>yc;
    cout<<"Enter the Radius : ";
    cin>>r;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(700,500);
    glutCreateWindow("Bresenham Circle");
    Init();
    glutDisplayFunc(display);
    glutMainLoop();
}
