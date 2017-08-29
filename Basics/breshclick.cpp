#include <GL/freeglut.h> 
#include <math.h> 
#include <stdio.h>
#include <stdlib.h>

 int ww = 600, wh = 400;  
 int first = 0;  
  int xi, yi, xf, yf;  
 
  void display()  
  {  
   glClearColor(0,0,0,0);  
   glClear(GL_COLOR_BUFFER_BIT);  
   glFlush();  
  }  
  void bresenhamAlg (int xc1, int yc1, int xc2, int yc2)  
  {  
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glColor3f(0,1,0);
glRasterPos2i(270,360);
glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned const char*)"K N Dheeraj, 500037782, 80"); 
 glBegin(GL_POINTS);
  int x=(xc1>xc2)?xc2:xc1;
  int y=(x==xc1?yc1:yc2); 
  int xg=(xc1<xc2)?xc2:xc1;
  int yg=(xg==xc1?yc1:yc2);
  printf("%d %d\n",yg,y );
  if(x==xg)
  	{
  	  if(yc1<yc2)
  	  {y=yc1;
  	   yg=yc2;}
  	   else
  	   {y=yc2;
  	   yg=yc1;} 
  	}
  int dx=xg-x;
  int dy=yg-y;
  float m=0.0;
  if (dx!=0)
  m=(float)dy/dx;
  dy=abs(dy);
  dx=abs(dx);
  int p=2*dy-dx;
  printf("%d %d\n",yg,y );
  if(dx==0)
  while(y<=yg)
   {
     glVertex2i(x,y);
     y++;
   }

else if(m<=1 && m>=0)
  while(x<=xg)
   {
     glVertex2i(x,y);
     if(p>=0)
      {x++;
       y++;
       p=p+2*dy-2*dx;}
     else if(p<0)
	{x++;
	 p=p+2*dy;}
   }

else if(m>1)
 while(y<=yg)
   {
     glVertex2i(x,y);
     if(p>=0)
      {x++;
       y++;
       p=p+2*dx-2*dy;}
     else if(p<0)
	{y++;
	 p=p+2*dx;}
   }
else if(m<0 && m>=-1)
 while(x<=xg)
   {
     glVertex2i(x,y);
     if(p>=0)
      {x++;
       y--;
       p=p+2*dy-2*dx;}
     else if(p<0)
	{x++;
	 p=p+2*dy;}
   }
else if(m<-1 )
 while(x<=xg )
   {
     glVertex2i(x,y);
     if(p>=0)
      {x++;
       y--;
       p=p+2*dx-2*dy;}
     else if(p<0)
	{y--;
	 p=p+2*dx;}
   }

 glEnd();
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
         bresenhamAlg ( xi, yi, xf, yf);  
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
glutCreateWindow("Bresh on click"); 
glutDisplayFunc(display); 
myinit(); 
glutMouseFunc(mouse); 
glutMainLoop(); 
return 0; 
}
