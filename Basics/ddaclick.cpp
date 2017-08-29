#include <GL/freeglut.h> 
#include <math.h> 
#include <stdio.h>
#include <stdlib.h>

int ww = 600, wh = 400; 
int first = 0; 
int xi, yi, xf, yf; 
float round_value(float v)
{
  return floor(v + 0.5);
}
void drawLine(int x1, int y1, int x2, int y2) 
{ 
glClear(GL_COLOR_BUFFER_BIT); 
glColor3f(0,1,0);
glRasterPos2i(270,360);
glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned const char*)"K N Dheeraj, 500037782, 80");
double dx=(xf-xi);
  double dy=(yf-yi);
  double steps;
  float xInc,yInc,x=xi,y=yi;
  steps=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
  xInc=dx/(float)steps;
  yInc=dy/(float)steps;

  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_POINTS);
   glVertex2d(x,y);
  int k;
glColor3f(1,0,0);
  for(k=0;k<steps;k++)
  {
    x+=xInc;
    y+=yInc;
    glVertex2d(round_value(x), round_value(y));
    printf("%lf,%lf",round_value(x), round_value(y));
    printf("\n");
}
glEnd();
glFlush(); 
} 
void display() 
{ 
glColor3f(1.0, 0.0, 0.0); 
glClear(GL_COLOR_BUFFER_BIT); 
glFlush(); 
} 
void mouse(int btn, int state, int x, int y) 
{ 
if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
{ 
switch(first) 
{ 
case 0: 
xi = x; 
yi = (wh-y); 
first = 1; 
break; 
case 1: 
xf = x; 
yf = (wh-y); 
drawLine(xi,yi,xf,yf); 
first = 0; 
break; 
} 
} 
} 
void myinit() 
{ 
glViewport(0,0,ww,wh); 
glMatrixMode(GL_PROJECTION); 
glLoadIdentity(); 
gluOrtho2D(0.0,(GLdouble)ww,0.0,(GLdouble)wh); 
glMatrixMode(GL_MODELVIEW); 
} 
int main(int argc, char** argv) 
{ 
glutInit(&argc,argv); 
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
glutInitWindowSize(ww,wh); 
glutInitWindowPosition(10,10);
glutCreateWindow("Line on click"); 
glutDisplayFunc(display); 
myinit(); 
glutMouseFunc(mouse); 
glutMainLoop(); 
return 0; 
}
