#include<GL/freeglut.h>
#include <stdio.h>
#include <math.h>

int X1, Y1, X2, Y2;

float round_value(float v)
{
  return floor(v + 0.5);
}
void display (void)
 {
  double dx=(X2-X1);
  double dy=(Y2-Y1);
  double steps;
  float xInc,yInc,x=X1,y=Y1;
    steps=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
  xInc=dx/(float)steps;
  yInc=dy/(float)steps;
printf("%lf,%f,%f",steps,xInc,yInc);
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
 glColor3f (1.0, 1.0, 1.0);
 for(int i=-500 ; i<=500 ; i++)
 {
 glVertex2i(i,0);
 glVertex2i(0,i);
 }
 for(int i=-12; i<=12 ; i++)
 { glVertex2i(485+i,16+i);
   glVertex2i(485-i,16+i);
 } 
 for(int i=0; i<=12 ; i++)
 {  glVertex2i(16+i,485+i);
     glVertex2i(16-i,485+i);
     glVertex2i(16,485-i);
 }
 glEnd();
glColor3f(0,1,0);
glRasterPos2i(-205,400);
glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned const char*)"K N Dheeraj, 500037782, 80");
 glFlush();
 }

 void init(void)
 {
 glClearColor (0.0, 0.0, 0.0, 0.0);
 gluOrtho2D(-500, 500, -500, 500);
 }

int main(int argc, char** argv)
{
 printf("Enter the points\n");
 scanf("%d %d %d %d",&X1,&Y1,&X2,&Y2);
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (500, 500);
 glutInitWindowPosition (100, 100);
 glutCreateWindow ("DDA Line");
 init ();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
