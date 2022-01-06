#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
int x0,x1,y0,y1;

void line_display(void)
{
    int x,y,dx,dy,Di,dD;
    dx=x1-x0;
    dy=y1-y0;

    Di=2*dy-dx;
    dD=2*(dy-dx);

    x=x0;
    y=y0;

    while(x<x1){
        if(Di<0){
            x=x+1;
            y=y;
            Di=Di+2*dy;
        }
        if(Di>=0){
            x=x+1;
            y=y+1;
            Di=Di+dD;
        }
        //printf("%d  %d  %d\n",x,y,Di);
        glColor3f(0,1,0);
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
    }

    glFlush();
}

void init(void)
{
    glClearColor(1.0,1.0,1.0,0);
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
    glutInitWindowSize (900,900);
    glutInitWindowPosition (100,100);
    glutCreateWindow ("Mid-Point Line Algorithm");
    init();
    glutDisplayFunc(line_display);
    glutMainLoop();

    return 0;
}
