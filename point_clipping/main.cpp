#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>

int xmax,xmin,ymax,ymin,x,y;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);

	glBegin(GL_POINTS);
	if(x>=xmin&&x<=xmax){
        if(y>=ymin&&y<=ymax){
            glVertex2i(x,y);
        }
	}
    glEnd();

    glColor3f(0.0,1.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(xmin,ymin);
    glVertex2i(xmin,ymax);
    glVertex2i(xmax,ymax);
    glVertex2i(xmax,ymin);
    glEnd();

    glFlush();
}

void myinit(void)
{
	glPointSize(5.0);
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D (-700.0,700.0,-700.0,700.0);
}

int main (int argc, char** argv)
{
    printf("Enter the value of xmin and ymin : ");
    scanf("%d%d",&xmin,&ymin);

    printf("\nEnter the value of xmax and ymax : ");
    scanf("%d%d",&xmax,&ymax);

    printf("\nEnter the point x and y : ");
    scanf("%d%d",&x,&y);

	glutInit(&argc,argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Point Clipping");
	myinit();
    glutDisplayFunc(display);
    glutMainLoop();
}
