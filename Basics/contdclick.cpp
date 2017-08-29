#include <GL/freeglut.h> 
#include <math.h> 
#include <stdio.h>

int ww = 600, wh = 400; 
int first = 0,i=0; 
int xi, yi, xf, yf; 
int h[20][2];
void drawLine(int x1, int y1, int x2, int y2) 
{ 
glBegin(GL_LINES);
glColor3f(1,0,0);
for(int l=0;l<i;l++){
glVertex2iv(h[l]);
}
glEnd(); 
glColor3f(0,1,0);
glRasterPos2i(270,360);
glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned const char*)"K N Dheeraj, 500037782, 80");
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
h[i][0]=xi;
h[i][1]=yi;i++;
break; 
case 1: 
xf = x; 
yf = (wh-y); 
first = 2; 
h[i][0]=xf;
h[i][1]=yf;i++;
drawLine(xi,yi,xf,yf); 
break; 
case 2:
h[i][0]=xf;
h[i][1]=yf;
i++; 
xf = x; 
yf = (wh-y); 
h[i][0]=xf;
h[i][1]=yf;
first = 2;
int x=h[i-1][0];
int y=h[i-1][1];i++;
drawLine(x,y,xf,yf); 
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
glutCreateWindow("COntinuous lines on click"); 
glutDisplayFunc(display); 
myinit(); 
glutMouseFunc(mouse); 
glutMainLoop(); 
return 0; 
}
