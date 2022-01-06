#include<stdio.h>
#include<GL/glut.h>

void init() {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 200);
	glutCreateWindow("First Program");
}

void display()
{
	glClearColor(0.0, 1.0, 0.0, 1.0);

	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(0.0,100.0,0,100.0);
	glColor3f(0.0, 1.0, 0.0);
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	init();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
