#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
int x1, y1, x2, y2;

void line_display(void)
{
    int dx,dy,i,pk,x,y,m;
    dx=x2-x1;
    dy=y2-y1;

    m=dy/dx;

    x=x1;
    y=y1;

    if(m<1){
       pk=2*dy-dx;
       for (i=0; i<dx; i++){
        if(pk>=0){
            pk=pk+2*(dy-dx);
            y=y+1;
            x=x+1;
        }
        else if(pk<0){
            pk=pk+2*dy;
            x=x+1;
            y=y;
        }
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
       }
    }
    else if(m>1){
       pk=2*dx-dy;
       for (i=0; i<dy; i++){
        if(pk>=0){
            pk=pk+2*(dx-dy);
            y=y+1;
            x=x+1;
        }
        else if(pk<0){
            pk=pk+2*dx;
            y=y+1;
            x=x;
        }
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
       }
    }
    glFlush();
}

void init(void)
{
glClearColor(1.0,1.0,1.0,0);
glMatrixMode(GL_PROJECTION);
glColor3f(255,0,0);
glLoadIdentity();
gluOrtho2D(-100,100,-100,100);
}

int main(int argc, char** argv) {
printf("Enter the points for line : \n");
printf("Enter x1 point : \n");
scanf("%d",&x1);

printf("Enter y1 point : \n");
scanf("%d",&y1);

printf("Enter x2 point : \n");
scanf("%d",&x2);

printf("Enter y2 point : \n");
scanf("%d",&y2);

glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (800,700);
glutInitWindowPosition (100,100);
glutCreateWindow ("Bresenhams LD");
init();
glutDisplayFunc(line_display);
glutMainLoop();

return 0;
}
