#include <stdio.h>
#include <GL/freeglut.h>
#include <math.h>
#define PI 3.14159265

void drawCircle(GLfloat x, GLfloat y, GLfloat radius);

void display()
{
 glClear(GL_COLOR_BUFFER_BIT);

 int h1[10][2]={{-400,100},{-250,350},{-100,100},{-100,-400},{-400,-400},{-400,-300},{-300,-300},{-300,0},{-400,0},{-400,-300}};
 int h2[10][2]={{400,100},{250,350},{100,100},{100,-400},{400,-400},{400,-300},{300,-300},{300,0},{400,0},{400,-300}};
 int lines[9][2]={{-400,100},{400,100},{-100,-100},{100,-100},{100,-100},{-100,-400},{-100,-100},{100,-400},{200,100}};
 int sqr[4][2]={{200,125},{300,125},{300,225},{200,225}};
 glBegin(GL_LINE_LOOP);
 int i;
 for(i=0;i<10;i++)
 glVertex2iv(h1[i]);
 glEnd();
 glBegin(GL_LINE_LOOP);
 for(i=0;i<10;i++)
 glVertex2iv(h2[i]);
 glEnd();
 glBegin(GL_LINE_LOOP);
 for(i=0;i<4;i++)
 glVertex2iv(sqr[i]);
 glEnd();
 glBegin(GL_LINES);
 for(i=0;i<9;i++)
 glVertex2iv(lines[i]);
 glEnd();
 drawCircle(-250,180,50);
 glColor3f(1,1,1);
 glRasterPos2i(-120,360);
 glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned const char*)"K N Dheeraj, 500037782, 80");
 glFlush();
}

void drawCircle(GLfloat x, GLfloat y, GLfloat radius){
int i;
int lineAmount = 100; 
GLfloat twicePi = 2.0f * PI;
glBegin(GL_LINE_LOOP);
for(i = 0; i <= lineAmount;i++) {
glVertex2f(x + (radius * cos(i * twicePi / lineAmount)),y + (radius* sin(i * twicePi / lineAmount)));
}
glEnd();
}

void myinit()
{
 glLoadIdentity();
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-500,500,-500,500);
}

int main(int argc,char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
 glutInitWindowSize(1000,1000);
 glutInitWindowPosition(200,200);
 glutCreateWindow("Hut");
 myinit();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
