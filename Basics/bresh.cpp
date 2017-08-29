#include<GL/freeglut.h>
#include<stdio.h>
#include<math.h>

 int xc1, yc1, xc2, yc2;

void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glColor3f(0,1,0);
glRasterPos2i(210,360);
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
void init(void)
{
 glClearColor(0,0,0,0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(0.0,400.0,0.0,400.0);
}

int main (int argc,char **argv)
{
printf("Enter Coordinates");
scanf("%d %d %d %d",&xc1,&yc1,&xc2,&yc2);
 glutInit(&argc,argv); 
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(50,25);
 glutInitWindowSize(500,250);
 glutCreateWindow("Bresenham Line");
 
 init();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
