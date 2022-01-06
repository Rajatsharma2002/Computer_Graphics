#include <iostream>
#include <GL/glut.h>
using namespace std;

int mx, my, r;

void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x+mx, y+my);
	glEnd();
}

void myInit (void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void midPointCircleAlgo()
{
	int x = 0;
	int y = r;
	float p = 1 - r;
	plot(x, y);

	while (y > x)
	{
		if (p < 0)
		{
			x+=1;
			p += 2*x+1;
		}
		else
		{
			y-=1;
			x+=1;
			p += 2*(x-y)+1;
		}
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);
	}

}

void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);

	midPointCircleAlgo();
	glFlush ();
}

int main(int argc, char** argv)
{
	cout << "Enter value of x : ";
	cin >> mx;
	cout << "Enter value of y : ";
	cin >> my;
	cout << "Enter radius : ";
	cin >> r;

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 150);
	glutCreateWindow ("Mid point Circle Drawing");
	glutDisplayFunc(myDisplay);
	myInit ();
	glutMainLoop();
}
