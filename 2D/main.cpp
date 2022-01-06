#include <windows.h>
#include <GL/glut.h>

void initGL() {

   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void display() {

   glClear(GL_COLOR_BUFFER_BIT);

   glMatrixMode(GL_MODELVIEW);

   glLoadIdentity();

   glTranslatef(-0.5f, 0.4f, 0.0f);

   glBegin(GL_QUADS);

      glColor3f(1.0f, 0.0f, 0.0f);

      glVertex2f(-0.3f, -0.3f);

      glVertex2f( 0.3f, -0.3f);

      glVertex2f( 0.3f,  0.3f);

      glVertex2f(-0.3f,  0.3f);

   glEnd();


   glTranslatef(0.1f, -0.7f, 0.0f);

   glBegin(GL_QUADS);

      glColor3f(0.0f, 1.0f, 0.0f);

      glVertex2f(-0.3f, -0.3f);

      glVertex2f( 0.3f, -0.3f);

      glVertex2f( 0.3f,  0.3f);

      glVertex2f(-0.3f,  0.3f);

   glEnd();


   glTranslatef(-0.3f, -0.2f, 0.0f);

   glBegin(GL_QUADS);

      glColor3f(0.2f, 0.2f, 0.2f);

      glVertex2f(-0.2f, -0.2f);

      glColor3f(1.0f, 1.0f, 1.0f);

      glVertex2f( 0.2f, -0.2f);

      glColor3f(0.2f, 0.2f, 0.2f);

      glVertex2f( 0.2f,  0.2f);

      glColor3f(1.0f, 1.0f, 1.0f);

      glVertex2f(-0.2f,  0.2f);

   glEnd();


   glTranslatef(1.1f, 0.2f, 0.0f);

   glBegin(GL_TRIANGLES);

      glColor3f(0.0f, 0.0f, 1.0f);

      glVertex2f(-0.3f, -0.2f);

      glVertex2f( 0.3f, -0.2f);

      glVertex2f( 0.0f,  0.3f);

   glEnd();


   glTranslatef(0.2f, -0.3f, 0.0f);

   glRotatef(180.0f, 0.0f, 0.0f, 1.0f);

      glBegin(GL_TRIANGLES);

      glColor3f(1.0f, 0.0f, 0.0f);

      glVertex2f(-0.3f, -0.2f);

      glColor3f(0.0f, 1.0f, 0.0f);

      glVertex2f( 0.3f, -0.2f);

      glColor3f(0.0f, 0.0f, 1.0f);

      glVertex2f( 0.0f,  0.3f);

   glEnd();


   glRotatef(-180.0f, 0.0f, 0.0f, 1.0f);

   glTranslatef(-0.1f, 1.0f, 0.0f);

   glBegin(GL_POLYGON);

      glColor3f(1.0f, 1.0f, 0.0f);

      glVertex2f(-0.1f, -0.2f);

      glVertex2f( 0.1f, -0.2f);

      glVertex2f( 0.2f,  0.0f);

      glVertex2f( 0.1f,  0.2f);

      glVertex2f(-0.1f,  0.2f);

      glVertex2f(-0.2f,  0.0f);

   glEnd();


   glFlush();

}

void reshape(GLsizei width, GLsizei height) {

   if (height == 0) height = 1;

   GLfloat aspect = (GLfloat)width / (GLfloat)height;


   glViewport(0, 0, width, height);


   glMatrixMode(GL_PROJECTION);

   glLoadIdentity();

   if (width >= height) {

      gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);

   } else {

    gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);

   }

}

int main(int argc, char** argv) {

   glutInit(&argc, argv);

   glutInitWindowSize(640, 480);

   glutInitWindowPosition(50, 50);

   glutCreateWindow("Model Transform");

   glutDisplayFunc(display);

   glutReshapeFunc(reshape);

   initGL();

   glutMainLoop();

   return 0;

}
