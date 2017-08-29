#include <GL/freeglut.h>
#include <stdio.h>

double xa,xb,ya,yb;
void display()
{
    
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
  glMatrixMode(GL_PROJECTION);
  
    glBegin(GL_POINTS);
  float m =(yb-ya)/(xb-xa);

  if(m<1.0&& m>=0.0){
      double xt,yt;
      xt=xa;
      yt=ya;
      while(xt!=xb){
printf("%lf,%lf",xt,yt);
          glVertex2d(xt,yt);
          xt = xt+1;
          yt = (yt+m);
          
      }
  }
  else if(m>=1){
    double xt,yt;
      xt=xa;
      yt=ya;
      while(yt!=yb){
printf("%lf,%lf",xt,yt);
          glVertex2d(xt,yt);
          xt = xt+(1/m);
          yt = (yt+1);
          
      }
    }
  else if(m<=-1){
     
    double xt,yt;
      xt=xa;
      yt=ya;
      while(yt!=yb){

printf("%lf,%lf",xt,yt);
          glVertex2d(xt,yt);
          yt = yt-1;
          xt = (xt-(1/m));
    
  }
}
  else if(m>-1 && m<0){
    
    double xt,yt;
      xt=xa;
      yt=ya;
      while(xt!=xb){
printf("%lf,%lf",xt,yt);
          glVertex2d(xt,yt);
          yt = yt+m;
          xt = (xt+(1));
  }
  }
  glEnd();
glBegin(GL_POINTS);
glColor3f(1,1,1);
 for(int i=-500 ; i<=500 ; i++)
 {
 glVertex2i(i,0);
 glVertex2i(0,i);
 }
 for(int i=-12; i<=12 ; i++)
 {
 glVertex2i(485+i,16+i);
 glVertex2i(485-i,16+i);
 } 
 for(int i=0; i<=12 ; i++)
 {
 glVertex2i(16+i,485+i);
 glVertex2i(16-i,485+i);
 glVertex2i(16,485-i);
 }
 glEnd();
glFlush();
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
 scanf("%lf %lf %lf %lf",&xa,&ya,&xb,&yb);
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
