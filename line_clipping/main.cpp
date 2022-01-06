/*#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

int xmin,ymin,xmax,ymax,x1,y1,x2,y2;

int left=1,right=2,bottom=4,top=8;
int c1,c2;

int get_code(int x,int y){
    int code=0;
    if(x<xmin){
        code=code|left;
    }
    else if(x>xmax){
        code=code|right;
    }
    if(y<ymin){
        code=code|bottom;
    }
    else if(y>ymax){
        code=code|top;
    }
    return code;
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);

	glBegin(GL_POINTS);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);

    glEnd();

    c1=get_code(x1,y1);
    c2=get_code(x2,y2);

    while(1){
    int c,x,y;
    if((c1|c2)==0){
        break;
    }
    else if((c1&c2)!=0){
        break;
    }
    else{
        if(c1!=0){
            c=c1;
        }
        else{
            c=c2;
        }
        if(c&left){
            x=xmin;
            y=y1+(y2-y1)*((xmin-x1)/(x2-x1));
        }
        if(c&right){
            x=xmax;
            y=y1+(y2-y1)*((xmax-x1)/(x2-x1));
        }
        if(c&bottom){
            y=ymin;
            x=x1+(x2-x1)*((ymin-y1)/(y2-y1));
        }
        if(c&top){
            y=ymax;
            x=x1+(x2-x1)*((ymax-y1)/(y2-y1));
        }
        if(c==c1){
            x1=x;
            y1=y;
            c1=get_code(x1,y1);
        }
        else{
            x2=x;
            y2=y;
            c2=get_code(x2,y2);
        }

    }
    }

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
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D (-10,10,-10,10);
}

int main (int argc, char** argv)
{
    printf("Enter the value of xmin and ymin : ");
    scanf("%d%d",&xmin,&ymin);

    printf("\nEnter the value of xmax and ymax : ");
    scanf("%d%d",&xmax,&ymax);

    printf("\nEnter the point x1 and y1 : ");
    scanf("%d%d",&x1,&y1);

    printf("\nEnter the point x2 and y2 : ");
    scanf("%d%d",&x2,&y2);

	glutInit(&argc,argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Line Clipping");
	myinit();
    glutDisplayFunc(display);
    glutMainLoop();
}*/

/*#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

GLfloat xmin=-0.5,ymin=-0.5,xmax=0.5,ymax=0.5;
GLfloat x1,y1,x2,y2;

int left=1,right=2,bottom=4,top=8;
int c1,c2;

int get_code(GLfloat x,GLfloat y){
    int code=0;
    if(x<xmin){
        code=code|left;
    }
    else if(x>xmax){
        code=code|right;
    }
    if(y<ymin){
        code=code|bottom;
    }
    else if(y>ymax){
        code=code|top;
    }
    return code;
}

void display(){
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(0.0,1.0,0.0);
     glBegin(GL_LINE_LOOP);
         glVertex2f(xmin,ymin);
         glVertex2f(xmin,ymax);
         glVertex2f(xmax,ymax);
         glVertex2f(xmax,ymin);
    glEnd();

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
    glEnd();

    c1=get_code(x1,y1);
    c2=get_code(x2,y2);

    bool accept =false;

    while(1){
    int c,x,y;
    if((c1|c2)==0){
        accept=true;
        break;
    }
    else if((c1&c2)!=0){
        accept=true;
        break;
    }
    else{
        if(c1!=0){
            c=c1;
        }
        else{
            c=c2;
        }
        if(c&left){
            x=xmin;
            y=y1+(y2-y1)*((xmin-x1)/(x2-x1));
        }
        if(c&right){
            x=xmax;
            y=y1+(y2-y1)*((xmax-x1)/(x2-x1));
        }
        if(c&bottom){
            y=ymin;
            x=x1+(x2-x1)*((ymin-y1)/(y2-y1));
        }
        if(c&top){
            y=ymax;
            x=x1+(x2-x1)*((ymax-y1)/(y2-y1));
        }
        if(c==c1){
            x1=x;
            y1=y;
            c1=get_code(x1,y1);
        }
        else{
            x2=x;
            y2=y;
            c2=get_code(x2,y2);
        }

    }
    }
    if(accept) {
            glColor3f(1.0,0.0,0.0);
            glBegin(GL_LINES);
               glVertex2f(x1,y1);
               glVertex2f(x2,y2);
            glEnd();
    }
    else{
        glColor3f(0.0,0.0,1.0);
        glBegin(GL_LINES);
            glVertex2f(x1,y1);
            glVertex2f(x2,y2);
        glEnd();
    }


    glFlush();
}

int main (int argc, char** argv)
{
    printf("\nEnter the point x1 and y1 : ");
    scanf("%f%f",&x1,&y1);

    printf("\nEnter the point x2 and y2 : ");
    scanf("%f%f",&x2,&y2);

	glutInit(&argc,argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Line Clipping");
    glutDisplayFunc(display);
    glutMainLoop();
}*/

#include <windows.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<iostream>

using namespace std;

float xmin=-100,ymin=-100,xmax=100,ymax=100;
float xL1,yL1,xL2,yL2;

void init(void)
{
    glClearColor(0.0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-300,300,-300,300);
}

int getcode(float x,float y)
{
    int c=0;
    if(y>ymax)c=8;
    if(y<ymin)c=4;
    if(x>xmax)c=c|2;
    if(x<xmin)c=c|1;
    return c;
}

void LineClipping(float x1,float y1,float x2,float y2)
{
    int c1=getcode(x1,y1);
    int c2=getcode(x2,y2);
    float m=(y2-y1)/(x2-x1);
    while((c1|c2)>0)
    {
        if((c1 & c2)>0)
        {
           exit(0);
        }

    float xi=x1;float yi=y1;
    int c=c1;
    if(c==0)
    {
         c=c2;
         xi=x2;
         yi=y2;
    }
    float x,y;
    if((c & 8)>0)
    {
       y=ymax;
       x=xi+ 1.0/m*(ymax-yi);
    }
    else
      if((c & 4)>0)
      {
          y=ymin;
          x=xi+1.0/m*(ymin-yi);
      }
      else
       if((c & 2)>0)
       {
           x=xmax;
           y=yi+m*(xmax-xi);
       }
       else
       if((c & 1)>0)
       {
           x=xmin;
           y=yi+m*(xmin-xi);
       }

       if(c==c1)
       {
           xL1=x;
           yL1=y;
           c1=getcode(xL1,yL1);
       }

       if(c==c2)
       {
           xL2=x;
           yL2=y;
           c2=getcode(xL2,yL2);
       }
   }

}

void mykey(unsigned char key,int x,int y)
{
    if(key=='a')
    {
        LineClipping(xL1,yL1,xL2,yL2);
        glFlush();
    }
}
void display()
{

   glClear(GL_COLOR_BUFFER_BIT);
   glPointSize(2.0);
   glColor3f(1.0,0.0,0.0);

   glBegin(GL_LINE_LOOP);
   glVertex2i(xmin,ymin);
   glVertex2i(xmin,ymax);
   glVertex2i(xmax,ymax);
   glVertex2i(xmax,ymin);
   glEnd();

   glColor3f(0.0,0.0,1.0);
   glBegin(GL_LINES);
   glVertex2i(xL1,yL1);
   glVertex2i(xL2,yL2);
   glEnd();
   glFlush();
}


int main(int argc,char** argv)
{
    printf("Enter Points xL1 and yL1 :");
    cin>>xL1>>yL1;
    printf("Enter Points xL2 and yL2 :");
    cin>>xL2>>yL2;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Line Clipping Algorithm");
    glutDisplayFunc(display);
    glutKeyboardFunc(mykey);
    init();
    glutMainLoop();
    return 0;
}





