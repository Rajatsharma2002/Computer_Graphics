#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

float r;
float mx ,my;

void display (void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    float x=0,y=r;
	float p = 1 - r;
 	glBegin(GL_POINTS);
    glVertex2i(mx+x, my+y);

 	while (x <= y)
 	{
  		if (p < 0) {
            x+=1;
            y=y;
   			p += 2*x + 1;
  		}
  		else {
   			x+=1;
   			y-=1;
   			p += 2 * x + 1 - 2 * y;
  		}
  		glVertex2i(x, y);
  		glVertex2i(-x, y);
  		glVertex2i(x, -y);
  		glVertex2i(-x, -y);

  		glVertex2i(y, x);
  		glVertex2i(-y, x);
  		glVertex2i(y, -x);
  		glVertex2i(-y, -x);

 	}
 	glEnd();
 	glFlush();
}

void init(void)
{
    glColor3f(0.0, 010.0, 0.0);
    glPointSize(1.0);
	glClearColor(1.0,1.0,1.0,0);
   	glMatrixMode(GL_PROJECTION);
   	gluOrtho2D(-100,700,-100,500);
}

int main(int argc, char** argv)
{
    cout<<"Enter value for x : ";
    cin>>mx;
    cout<<"Enter value for y : ";
    cin>>my;
    cout<<"Enter the Radius : ";
    cin>>r;
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (700,700);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("Mid Point Circle Drawing");
	init();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
