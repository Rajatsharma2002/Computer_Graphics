/*#include<iostream>
#include<math.h>
#include<GL/glut.h>
using namespace std;

typedef float Matrix4 [4][4];

Matrix4 theMatrix;
static GLfloat input[8][3]=
{
    {40,40,-50},{90,40,-50},{90,90,-50},{40,90,-50},
    {30,30,0},{80,30,0},{80,80,0},{30,80,0}

};

float output[8][3];
float tx,ty,tz;
float sx,sy,sz;
float angle;

int choice,choiceRot;

void setIdentityM(Matrix4 m)
{
for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
        m[i][j]=(i==j);
}

void translate(int tx,int ty,int tz)
{

for(int i=0;i<8;i++)
{
output[i][0]=input[i][0]+tx;
output[i][1]=input[i][1]+ty;
output[i][2]=input[i][2]+tz;
}
}
void scale(int sx,int sy,int sz)
{
    theMatrix[0][0]=sx;
    theMatrix[1][1]=sy;
    theMatrix[2][2]=sz;
}
void RotateX(float angle) //Parallel to x
{

 angle = angle*3.142/180;
  theMatrix[1][1] = cos(angle);
 theMatrix[1][2] = -sin(angle);
 theMatrix[2][1] = sin(angle);
 theMatrix[2][2] = cos(angle);

}
void RotateY(float angle) //parallel to y
{

 angle = angle*3.14/180;
 theMatrix[0][0] = cos(angle);
 theMatrix[0][2] = -sin(angle);
 theMatrix[2][0] = sin(angle);
 theMatrix[2][2] = cos(angle);

}
void RotateZ(float angle) //parallel to z
{

 angle = angle*3.14/180;
 theMatrix[0][0] = cos(angle);
 theMatrix[0][1] = sin(angle);
 theMatrix[1][0] = -sin(angle);
 theMatrix[1][1] = cos(angle);

}

void multiplyM()
{
//We Don't require 4th row and column in scaling and rotation
//[8][3]=[8][3]*[3][3] //4th not used
for(int i=0;i<8;i++)
 {
    for(int j=0;j<3;j++)
    {
        output[i][j]=0;
        for(int k=0;k<3;k++)
        {
            output[i][j]=output[i][j]+input[i][k]*theMatrix[k][j];
        }
    }
}

}
void Axes(void)
{
 glColor3f (0.0, 0.0, 0.0);               // Set the color to BLACK
 glBegin(GL_LINES);                       // Plotting X-Axis
 glVertex2s(-1000 ,0);
 glVertex2s( 1000 ,0);
 glEnd();
 glBegin(GL_LINES);                       // Plotting Y-Axis
 glVertex2s(0 ,-1000);
 glVertex2s(0 , 1000);
 glEnd();
}
void draw(float a[8][3])
{


    glBegin(GL_QUADS);
     glColor3f(0.7,0.4,0.5); //behind
    glVertex3fv(a[0]);
    glVertex3fv(a[1]);
    glVertex3fv(a[2]);
    glVertex3fv(a[3]);

    glColor3f(0.8,0.2,0.4);  //bottom
   glVertex3fv(a[0]);
   glVertex3fv(a[1]);
   glVertex3fv(a[5]);
   glVertex3fv(a[4]);

   glColor3f(0.3,0.6,0.7); //left
  glVertex3fv(a[0]);
  glVertex3fv(a[4]);
  glVertex3fv(a[7]);
  glVertex3fv(a[3]);

  glColor3f(0.2,0.8,0.2);  //right
 glVertex3fv(a[1]);
 glVertex3fv(a[2]);
 glVertex3fv(a[6]);
 glVertex3fv(a[5]);

 glColor3f(0.7,0.7,0.2); //up
glVertex3fv(a[2]);
glVertex3fv(a[3]);
glVertex3fv(a[7]);
glVertex3fv(a[6]);

glColor3f(1.0,0.1,0.1);
glVertex3fv(a[4]);
glVertex3fv(a[5]);
glVertex3fv(a[6]);
glVertex3fv(a[7]);

glEnd();
}

void init()
{
    glClearColor(1.0,1.0,1.0,1.0); //set backgrond color to white
    glOrtho(-454.0,454.0,-250.0,250.0,-250.0,250.0);
    // Set the no. of Co-ordinates along X & Y axes and their gappings
    glEnable(GL_DEPTH_TEST);
     // To Render the surfaces Properly according to their depths
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
Axes();
glColor3f(1.0,0.0,0.0);
draw(input);
setIdentityM(theMatrix);
switch(choice)
{
case 1:
    translate(tx,ty,tz);
    break;
 case 2:
    scale(sx,sy,sz);
multiplyM();
    break;
 case 3:
    switch (choiceRot) {
    case 1:
        RotateX(angle);
        break;
    case 2: RotateY(angle);
        break;
    case 3:
        RotateZ(angle);
        break;
    default:
        break;
    }
multiplyM();
    break;
}

draw(output);
glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(1362,750);
    glutInitWindowPosition(0,0);
    glutCreateWindow("3D TRANSFORMATIONS");
    init();
    cout<<"Enter your choice number:\n1.Translation\n2.Scaling\n3.Rotation\n=>";
    cin>>choice;
    switch (choice) {
    case 1:
        cout<<"\nEnter Tx,Ty &Tz: \n";
        cin>>tx>>ty>>tz;
        break;
    case 2:
        cout<<"\nEnter Sx,Sy & Sz: \n";
        cin>>sx>>sy>>sz;
        break;
    case 3:
        cout<<"Enter your choice for Rotation about axis:\n1.parallel to X-axis."
             <<"(y& z)\n2.parallel to Y-axis.(x& z)\n3.parallel to Z-axis."
              <<"(x& y)\n =>";
        cin>>choiceRot;
        switch (choiceRot) {
        case 1:
            cout<<"\nENter Rotation angle: ";
            cin>>angle;
            break;
        case 2:
            cout<<"\nENter Rotation angle: ";
            cin>>angle;
            break;
        case 3:
            cout<<"\nENter Rotation angle: ";
            cin>>angle;
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
    glutDisplayFunc(display);
    glutMainLoop();
return 0;
}*/

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <GL/glut.h>

// window size
#define maxWD 800
#define maxHT 600

// rotation speed
#define thetaSpeed 0.005

// this creates delay between two actions
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock())
        ;
}

// this is a basic init for the glut window
void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, maxWD, 0.0, maxHT);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

// this function just draws a point
void drawPoint(int x, int y)
{
    glPointSize(7.0);
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void rotateAroundPt(int px, int py, int cx, int cy)
{
    float theta = 0.0;
    while (1) {
        glClear(GL_COLOR_BUFFER_BIT);
        int xf, yf;

        // update theta anticlockwise rotation
        theta = theta - thetaSpeed;

        // check overflow
        if (theta >= (2.0 * 3.14159))
            theta = 0.0;
            //theta = theta - (2.0 * 3.14159);

        // actual calculations..
        xf = cx + (int)((float)(px - cx) * cos(theta))
             - ((float)(py - cy) * sin(theta));
        yf = cy + (int)((float)(px - cx) * sin(theta))
             + ((float)(py - cy) * cos(theta));

        // drawing the centre point
        drawPoint(cx, cy);

        // drawing the rotating point
        drawPoint(xf, yf);
        glFlush();
        // creating a delay
        // so that the point can be noticed
        delay(10);
    }
}

// this function will translate the point
void translatePoint(int px, int py, int tx, int ty)
{
    int fx = px, fy = py;
    while (1) {
        glClear(GL_COLOR_BUFFER_BIT);

        // update
        px = px + tx;
        py = py + ty;

        // check overflow to keep point in screen
        if (px > maxWD || px < 0 || py > maxHT || py < 0) {
            px = fx;
            py = fy;
        }

        drawPoint(px, py); // drawing the point

        glFlush();
        // creating a delay
        // so that the point can be noticed
        delay(10);
    }
}

// this function draws
void scalePoint(int px, int py, int sx, int sy)
{
    int fx, fy;
    while (1) {
        glClear(GL_COLOR_BUFFER_BIT);

        // update
        fx = px * sx;
        fy = py * sy;

        drawPoint(fx, fy); // drawing the point

        glFlush();
        // creating a delay
        // so that the point can be noticed
        delay(500);

        glClear(GL_COLOR_BUFFER_BIT);

        // update
        fx = px;
        fy = py;

        // drawing the point
        drawPoint(fx, fy);
        glFlush();
        // creating a delay
        // so that the point can be noticed
        delay(500);
    }
}

// Actual display function
void myDisplay(void)
{
    int opt;
    /*printf("\nEnter\n\t<1> for translation"
           "\n\t<2> for rotation"
           "\n\t<3> for scaling\n\t:");
    scanf("%d", &opt);
    printf("\nGo to the window...");
    switch (opt) {
    case 1:
        translatePoint(100, 200, 1, 5);
        break;
    case 2:
        rotateAroundPt(200, 200, maxWD / 2, maxHT / 2);
        // point will circle around
        // the centre of the window
        break;
    case 3:
        scalePoint(10, 20, 2, 3);
        break;
    }
    */
    rotateAroundPt(200, 200, maxWD / 2, maxHT / 2);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(maxWD, maxHT);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Transforming point");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
}
