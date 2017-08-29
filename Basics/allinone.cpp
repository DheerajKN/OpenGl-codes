#include<stdio.h>
#include<math.h>
#include<GL/freeglut.h>

int screen=0;
int type=0;
int onMouse=0;

void mouseClicks(int,int,int,int);

void display()
{      
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glColor3f(1,1,1);
 glRasterPos2i(-185,300);
 glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned const char*)"Press B for Bresenhan and D for DDA algorithm");
glColor3f(0,1,0);
glRasterPos2i(-120,330);
glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned const char*)"K N Dheeraj, 500037782, 80");
 glFlush();
}


void display_ddao()
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glColor3f(1,1,1);
 glRasterPos2i(-285,300);
 glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned const char*)"Press C for console input and M for mouse input for DDA algorithm");
glColor3f(0,1,0);
glRasterPos2i(-120,330);
glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned const char*)"K N Dheeraj, 500037782, 80");
 glFlush();
}

void display_breso()
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glColor3f(1,1,1);
 glRasterPos2i(-295,300);
 glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned const char*)"Press C for console input and M for mouse input for Bresenham algorithm");
glColor3f(0,1,0);
glRasterPos2i(-120,330);
glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned const char*)"K N Dheeraj, 500037782, 80");
 glFlush();
}

int xi,yi,xf,yf;

void getInput()
{glColor3f(0,1,0);
glRasterPos2i(-120,330);
glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned const char*)"K N Dheeraj, 500037782, 80");
 glRasterPos2i(-125,210);
 glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned const char*)"Input Coordinates from Console");
 glFlush();	
 printf("Enter coordinate 1: ");
 scanf("%d %d",&xi,&yi); 
 printf("Enter coordinate 2: ");
 scanf("%d %d",&xf,&yf); 
}


void display_dda()
{
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glColor3f(0,1,0);
glRasterPos2i(-120,330);
glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned const char*)"K N Dheeraj, 500037782, 80");
  float m;
  float x,y;
  m=(float)(yf-yi)/(float)(xf-xi);
  glColor3f(0,1,0); 
  glBegin(GL_POINTS);
  if(m>0 && m<=1)
 {
   x=(xi<xf)?xi:xf;
   y=(x==xi)?yi:yf;
   while((x<=xf && x>=xi) || (x>=xf && x<=xi))
   {
    glVertex2i(x,y);
    x+=1;
    y=y+m;
   }
}
  else if(m>1)
 {
   x=(xi<xf)?xi:xf;
   y=(x==xi)?yi:yf;
  while((y<=yf && y>=yi) || (y>=yf && y<=yi))
   {
    glVertex2i(x,y);
    y+=1;
    x=x+1/m;
   }
}
  else if(m<=0.0 && m>-1)
  {
   x=(xi>xf)?xi:xf;
   y=(x==xi)?yi:yf;
  while((x<=xf && x>=xi) || (x>=xf && x<=xi))
   {
    glVertex2i(x,y);
    x-=1;
    y=y-m;
   }
 }
  else if(m<-1)
 {
   y=(yi>yf)?yi:yf;
   x=(y==yi)?xi:xf; 
 
  while((y<=yf && y>=yi) || (y>=yf && y<=yi))
   {
    glVertex2i(x,y);
    y-=1;
    x=x-1/m;
   }
 }
  glEnd();
glBegin(GL_POINTS);
 glColor3f (1.0, 1.0, 1.0);
 for(int i=-400 ; i<=400 ; i++)
 {
 glVertex2i(i,0);
 glVertex2i(0,i);
 }
 for(int i=-12; i<=12 ; i++)
 { glVertex2i(385+i,16+i);
   glVertex2i(385-i,16+i);
 } 
 for(int i=0; i<=12 ; i++)
 {  glVertex2i(16+i,335+i);
     glVertex2i(16-i,335+i);
     glVertex2i(16,335-i);
 }
 for(int i=-10; i<=10 ; i++)
 { glVertex2i(-385+i,12);
   glVertex2i(-(365+i),13+i);
   glVertex2i(-(365-i),13+i);
 } 
 for(int i=0; i<=10 ; i++)
 { glVertex2i(12+i,-340);
     glVertex2i(29+i,-(340-i));
     glVertex2i(29-i,-(340-i));
     glVertex2i(29,-(340+i));
 }

 glEnd();
  glFlush();
}

void display_bres()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glColor3f(0,1,0);
glRasterPos2i(-120,330);
glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned const char*)"K N Dheeraj, 500037782, 80");
  glBegin(GL_POINTS);
 glColor3f(1,0,0);
  int x=(xi>xf)?xf:xi;
  int y=(x==xi?yi:yf); 
  int xg=(xi<xf)?xf:xi;
  int yg=(xg==xi?yi:yf);
  if(x==xg)
  	{
  	  if(yi<yf)
  	  {y=yi;
  	   yg=yf;}
  	   else
  	   {y=yf;
  	   yg=yi;} 
  	}
  int dx=xg-x;
  int dy=yg-y;
  float m=0.0;
  if (dx!=0)
  m=(float)dy/dx;
  dy=abs(dy);
  dx=abs(dx);
  int p=2*dy-dx;
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
glBegin(GL_POINTS);
 glColor3f (1.0, 1.0, 1.0);
 for(int i=-400 ; i<=400 ; i++)
 {
 glVertex2i(i,0);
 glVertex2i(0,i);
 }
 for(int i=-10; i<=10 ; i++)
 { glVertex2i(385+i,13+i);
   glVertex2i(385-i,13+i);
 } 
 for(int i=0; i<=10 ; i++)
 {  glVertex2i(16+i,340+i);
     glVertex2i(16-i,340+i);
     glVertex2i(16,340-i);
 }
for(int i=-10; i<=10 ; i++)
 { glVertex2i(-385+i,12);
   glVertex2i(-(365+i),13+i);
   glVertex2i(-(365-i),13+i);
 } 
 for(int i=0; i<=10 ; i++)
 { glVertex2i(12+i,-340);
     glVertex2i(29+i,-(340-i));
     glVertex2i(29-i,-(340-i));
     glVertex2i(29,-(340+i));
 }
 glEnd();
 glFlush();
}

void keypress(unsigned char key,int x,int y)
{
  switch(key)
  {
    case 100:
	glutDisplayFunc(display_ddao);
	glutPostRedisplay();
        screen++; 
        type=0;
   break;
   case 98:
	glutDisplayFunc(display_breso);
	glutPostRedisplay();
        screen++;
        type=1;   
  break;  
  case 99:
	if(type==0 && screen==1)
	 { 
	   getInput();
       glutDisplayFunc(display_dda);
	   glutPostRedisplay();
	   screen=2; }

         else if(type==1 && screen==1)
	 { getInput();
           glutDisplayFunc(display_bres);
	   glutPostRedisplay();
	   screen=2; }
 break;
 case 109:
	if(type==0 && screen==1)
	 { 
	 	xi=0;
	 	xf=0;
	 	yi=0;
	 	yf=0;
	 	onMouse=0;
	   glutMouseFunc(mouseClicks);
           glutDisplayFunc(display_dda);
	   glutPostRedisplay();
	   screen=2; }
       
       else if(type==1 && screen==1)
	 { 
	 	xi=0;
	 	xf=0;
	 	yi=0;
	 	yf=0;
	 	onMouse=0;
	 	glutMouseFunc(mouseClicks);
           glutDisplayFunc(display_bres);
	   glutPostRedisplay();
	   screen=2; }
 break;
	
 case 27:
 	if(type==0 && screen==2)
 	{glutDisplayFunc(display_ddao);
	 glutPostRedisplay();
     screen--;
    }
    else if(type==1 && screen==2)
 	{glutDisplayFunc(display_breso);
	 glutPostRedisplay();
     screen--;
    }
    else if(screen==1)
 	{glutDisplayFunc(display);
	 glutPostRedisplay();
     screen--;
    }
    else if(screen==0)
    {
    	glutDestroyWindow(glutGetWindow());
    }
  break;
  default:         	         
		 glColor3f(1,0,0);
  		 glRasterPos2i(-50,220);
		 glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned const char*)"Error: Invalid Input");
		 glFlush();	
  }
}

void mouseClicks(int button, int state, int x, int y) {

    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if(onMouse==0)
        {onMouse++; 
         xi=x-400;
         yi=350-y;
         }
	else if(onMouse==1)
	{ 
         xf=x-400;
         yf=350-y;
	glutPostRedisplay();
	onMouse=0;
        }	       
    }
}

void myinit()
{
 glLoadIdentity();
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-400, 400, -350, 350);
}

int main(int argc,char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
 glutInitWindowSize(800,700);
 glutInitWindowPosition(20,20);
 glutCreateWindow("All in One Line Creator");
 myinit();
 glutDisplayFunc(display);
 glutKeyboardFunc(keypress);
 glutMainLoop();
 return 0;
}																	
