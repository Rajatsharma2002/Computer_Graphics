#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
int x0,x1,y0,y1;

void line_display(void)
{
float m,dy,dx,step,x,y,i;
dx=x1-x0;
dy=y1-y0;

if(abs(dx)> abs(dy))
{
  step = abs(dx);
}
else
  step = abs(dy);

m=dy/dx;

x= x0;
y= y0;

glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();

for (i=1 ;i<=step;i++)
{
 if(m<1){
    x=1+x;
    y=m+y;
 }
 if(m==1){
    x=1+x;
    y=1+y;
 }
 if(m>1){
    x=(1/m)+x;
    y=1+y;
 }

glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
}

glFlush();
}

void init(void)
{
glClearColor(1.0,1.0,1.0,1.0);
glColor3f(255,0,0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-100,100,-100,100);
}

int main(int argc, char** argv) {
printf("Enter the points for line : \n");
printf("Enter x0 point : \n");
scanf("%d",&x0);

printf("Enter y0 point : \n");
scanf("%d",&y0);

printf("Enter x1 point : \n");
scanf("%d",&x1);

printf("Enter y1 point : \n");
scanf("%d",&y1);

glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (600,600);
glutInitWindowPosition (100,100);
glutCreateWindow ("DDA");
init();
glutDisplayFunc(line_display);
glutMainLoop();

return 0;
}
