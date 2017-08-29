#include <stdio.h>
#include <GL/freeglut.h>
#include <math.h>

int s=0;
int mwh=700,mww=800;
int p=2;
float rw=1,rh=1;
int h1,h2=1,h3=1,h4=1;
void display()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void display_s1()
{ 
  glClear(GL_COLOR_BUFFER_BIT);
   float x,y;
   int theta=0,i;
   glColor3f(1,1,1);
  if(h1==1){
   glBegin(GL_POLYGON);
   for(i=0;i<360;i++)
   {
    x=200*cos(i);
    y=200*sin(i);
    glVertex2i(x,y);
   }
   glEnd();
   glRasterPos2i(rh*mww/3*-1,rw*mwh/3);
   glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"K.N.Dheeraj, 500037782, 80");}
glFlush();
}

void display_s2()
{
glClearColor(0,1,1,1);
glClear(GL_COLOR_BUFFER_BIT);
float p;
int r=200;
p=1.0-r;
int x=0,y=200;
glColor3f(0.0,0.0,0.0);
	if(h2==1){
glBegin(GL_TRIANGLE_FAN);
while(x<=y)
{
	glVertex2i(x,y);
	glVertex2i(y,x);
	glVertex2i(-1*x,-1*y);
	glVertex2i(-1*y,-1*x);
	glVertex2i(x,-1*y);
	glVertex2i(-1*y,x);
	glVertex2i(-1*x,y);
	glVertex2i(y,-1*x);
	if(p>=0)
	{
		p=2*x-2*y+5+p;
		x++;
		y--;
	}
	else
	{
	   p=2*x+3+p;
		x++;
    }
}
glEnd();}	 
glFlush();
}

void display_s3()
{
glClear(GL_COLOR_BUFFER_BIT);
	
	 float x,y;
	 int a=200;
	 int b=100;
	 int i;
	 glColor3f(1,0,0);
if(h3==1){
	 glBegin(GL_POLYGON);
	 for(i=0;i<360;i++)
	 {
	 	x=a*cos(i);
	 	y=b*sin(i);
	 	glVertex2i(x,y);
	 }
	 glEnd();}
glFlush();
}

void display_s4()
{glClearColor(0,1,0,1);
 glClear(GL_COLOR_BUFFER_BIT);
 int a=200,b=100;
 double p;
 float root2=pow(2,0.5);
 int x=0,y=b;
 int xn,yn;
 p=b*b-a*a*b+a*a/4.0;
 glColor3ub(100,0,0);
	if(h4==1){
glBegin(GL_TRIANGLE_STRIP);
	 while(b*b*x<=a*a*y)
	 {
	 	glVertex2i(x,y);
	 	glVertex2i(x,-1*y);
	 	glVertex2i(-1*x,y);
	 	glVertex2i(-1*x,-1*y);
	 	if(p>0)
	 	{
	 		p=p+b*b*(2*x+3)-a*a*(2*y-2);
	 		x++;
	 		y--;
	 	}
	 	else
	 	{
	 		p=p+b*b*(2*x+3);
	 		x++;
	 	}
	 	xn=x;
	 	yn=y;
	 }

	 p=(double)b*b*(xn+0.5)*(xn+0.5)+(double)a*a*(yn-1)*(yn-1)-(double)a*a*b*b;
	 
	 x=xn;
	 y=yn;
	 
	while(y>=0)
	 {
	 	glVertex2i(x,y);
	 	glVertex2i(x,-1*y);
	 	glVertex2i(-1*x,y);
	 	glVertex2i(-1*x,-1*y);

	 	if(p<=0)
	 	{
	 		p=p-2*a*a*(y-1)+a*a+b*b*(2*x+2);
	 		x++;
	 		y--;
	 	}
	 	else
	 	{
	 		p=p-2*a*a*(y-1)+a*a;
	 		y--;
	 	}

	 }
 glEnd();}
 glFlush();
}

void myinit()
{glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
 glLoadIdentity();
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-1*rh*(float)mww/2,rh*(float)mww/2,-1*rw*(float)mwh/2,rw*(float)mwh/2);
 }

void init()
{
 glLoadIdentity();
 gluOrtho2D(-1*rh*(float)(mww-3)/2,rh*(float)(mww-3)/2,-1*rw*(float)(mwh-3)/2,rw*(float)(mwh-3)/2);
}

int m,s1,s2,s3,s4;

void initdisplay()
{
	int w=glutGetWindow();

		if(w==s1)
		{
			glClearColor(0,1,0,1);
			glClear(GL_COLOR_BUFFER_BIT);		
		}
		else if(w==s2)
		{
			glClearColor(0,1,1,1);
			glClear(GL_COLOR_BUFFER_BIT);
		}
		else if(w==s3)
		{
			glClearColor(0,1,1,1);
		    glClear(GL_COLOR_BUFFER_BIT);
		}
		else if(w==s4)
		{
			glClearColor(0,1,0,1);
		    glClear(GL_COLOR_BUFFER_BIT);
		}

}

void mouse(int button,int state,int x,int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		int w=glutGetWindow();

		if(w==s1)
		{h1=1;
			glutDisplayFunc(display_s1);
			glutPostRedisplay();
		}
		else if(w==s2)
		{h2=1;
			glutDisplayFunc(display_s2);
			glutPostRedisplay();
		}
		else if(w==s3)
		{h3=1; 
			glutDisplayFunc(display_s3);
			glutPostRedisplay();
		}
		else if(w==s4)
		{h4=1;
			glutDisplayFunc(display_s4);
			glutPostRedisplay();	
		}

	}
if(button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
		int w=glutGetWindow();

		if(w==s1)
		{h1=0;
			glutDisplayFunc(display_s1);
			glutPostRedisplay();
		}
		else if(w==s2)
		{h2=0;
			glutPostRedisplay();
		}
		else if(w==s3)
		{h3=0;
			glutPostRedisplay();
		}
		else if(w==s4)
		{h4=0;
			glutPostRedisplay();
		}
	}
}

void keypress(unsigned char key,int x,int y)
{
	if(key==27)
		{glutDestroyWindow(m);}

}

void resize(int width,int height)
{
	rw=(float)800/width;
	rh=(float)700/height;
	float temp;
	myinit();
   glutSetWindow(s1);
   	 init();
	 glutReshapeWindow((width-3)/2,(height-3)/2);
	 glutPositionWindow(2,2);
	 glutPostRedisplay();
   glutSetWindow(s2);
     init();
	 glutReshapeWindow((width-3)/2,(height-3)/2);
	 glutPositionWindow(width/2+1,2);
	 glutPostRedisplay();
   glutSetWindow(s3);
     init();
	 glutReshapeWindow((width-3)/2,(height-3)/2);
	 glutPositionWindow(p,height/2+2);
	 glutPostRedisplay();
   glutSetWindow(s4);
     init();
	 glutReshapeWindow((width-3)/2,(height-3)/2);
	 glutPositionWindow(width/2,height/2);
	 glutPostRedisplay();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
    glutInitWindowSize(800,700);
 	glutInitWindowPosition(100,20);
 	m=glutCreateWindow("Ellipse and Circle");
 	myinit();
 	glutDisplayFunc(display);
 	glutReshapeFunc(resize);
 	glutKeyboardFunc(keypress);
 	s1=glutCreateSubWindow(m,0,0,mww/2,mwh/2);
 	init();
 	glutDisplayFunc(initdisplay);
 	glutMouseFunc(mouse);
 	glutKeyboardFunc(keypress);
	s2=glutCreateSubWindow(m,mww/2+1,0,mww/2,mwh/2);
	init();
	glutDisplayFunc(initdisplay);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keypress);
    s3=glutCreateSubWindow(m,0,mwh/2,mww/2,mwh/2);
    init();
 	glutDisplayFunc(initdisplay);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keypress);
    s4=glutCreateSubWindow(m,mww/2,mwh/2,mww/2,mwh/2);
    init();
 	glutDisplayFunc(initdisplay);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keypress);
 	glutMainLoop();
	return 0;
}
