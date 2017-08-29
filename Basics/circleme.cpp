#include<stdio.h>
#include<GL/freeglut.h>
#include <math.h>
#define PI 3.14159265
int q1,q2,q3,q4;
int mwh=700,mww=800;
int padding=2;
int m,s1,s2,s3,s4;
float rw=1,rh=1;
void ellipse()
{glClearColor(0,1,1,1);
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
if(q4==1){
        float rx=60, ry=20, xc=130,yc=-120;
        float rxSq = rx * rx;
        float rySq = ry * ry;
        float x = 0, y = ry, p;
        float px = 0, py = 2 * rxSq * y;
  glColor3f( 1 ,0, 0);
         glBegin(GL_POLYGON);       
          glVertex2d(xc+x,yc-y);
          glVertex2d(xc-x,yc-y);
          glVertex2d(xc-x,yc+y);
         glEnd();

        p = rySq - (rxSq * ry) + (0.25 * rxSq);
        while (px < py)
        {
                        x++;
                        px = px + 2 * rySq;
                        if (p < 0)
                        p = p + rySq + px;
                        else
                        {
                        y--;
                        py = py - 2 * rxSq;
                        p = p + rySq + px - py;
                        }
                         glBegin(GL_POLYGON);
                          glVertex2d(xc+x,yc+y);
                          glVertex2d(xc+x,yc-y);
                          glVertex2d(xc-x,yc-y);
                          glVertex2d(xc-x,yc+y);
                         glEnd();
        }

        p = rySq*(x+0.5)*(x+0.5) + rxSq*(y-1)*(y-1) - rxSq*rySq;
        while (y > 0)
        {
                y--;
                py = py - 2 * rxSq;
                if (p > 0)
                p = p + rxSq - py;
                else
                {
                x++;
                px = px + 2 * rySq;
                p = p + rxSq - py + px;
                }
               glBegin(GL_POLYGON);
          glVertex2d(xc+x,yc+y);
          glVertex2d(xc+x,yc-y);
          glVertex2d(xc-x,yc-y);
          glVertex2d(xc-x,yc+y);
         glEnd();}}
         glFlush();           
        }

void drawPCircle(){
glClearColor(0,1,0,1);
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
int i;
if(q1==1){
int lineAmount = 100; 
GLfloat twicePi = 2.0f * PI;
int x=120,y=100,radius=60;
glBegin(GL_POLYGON);
for(i = 0; i <= lineAmount;i++) {
glVertex2f(x + (radius * cos(i * twicePi / lineAmount)),y + (radius* sin(i * twicePi / lineAmount)));
}
glEnd();}
glFlush();}

void circle(){
glClearColor(0,1,1,1);
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  int xCenter=-105,yCenter=110,r=50;
  int x=0,y=r;
  int p = 1 - r;    
  glColor3f( 1 ,0, 0); 
if(q2==1){
glBegin(GL_TRIANGLE_STRIP);
  while(x<=y){
    glVertex2i(xCenter+x,yCenter+y);
    glVertex2i(xCenter+y,yCenter+x);  
    glVertex2i(xCenter-x,yCenter+y);
    glVertex2i(xCenter+y,yCenter-x);
    glVertex2i(xCenter-x,yCenter-y);
    glVertex2i(xCenter-y,yCenter-x);
    glVertex2i(xCenter+x,yCenter-y);
    glVertex2i(xCenter-y,yCenter+x);

    if (p<0)
  p += (2*x)+3;
    else {
 p += (2*(x-y))+5;
 y -= 1;
    }
    x++;
  }
glEnd();}
  glFlush();
}
void drawPellipse(){
glClearColor(0,1,0,1); 
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glColor3f(1,0,1); 
	 float x,y;
	 x=-80,y=-80;
	 float angle,tmpX,tmpY;
	double radius=50;
if(q3==1)	{
	glBegin(GL_POLYGON);
	glVertex2i(x,y);	 
	for (angle=1.0f;angle<361.0f;angle+=0.2)
	{
	    tmpX = x+cos(angle)*radius;
	    tmpY = y-0.5*sin(angle)*radius;
	    glVertex2i(tmpX,tmpY);
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
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-1*rh*(float)(mww-3*padding)/2,rh*(float)(mww-3*padding)/2,-1*rw*(float)(mwh-3*padding)/2,rw*(float)(mwh-3*padding)/2);
}

//int m,s1,s2,s3,s4;

void initdisplay()
{
	int w=glutGetWindow();

		if(w==s1)
		{
			glClearColor(1.0,0.0,0.0,1.0);
			glClear(GL_COLOR_BUFFER_BIT);		
		}
		else if(w==s2)
		{
			glClearColor(0.93,0.80,0.0,1.0);
			glClear(GL_COLOR_BUFFER_BIT);
		}
		else if(w==s3)
		{
			glClearColor(0.30,0.80,0.10,1.0);
		    glClear(GL_COLOR_BUFFER_BIT);
		}
		else if(w==s4)
		{
			glClearColor(0.0,1.0,1.0,1.0);
		    glClear(GL_COLOR_BUFFER_BIT);
		}
}

void resize(int width,int height)
{
	rw=(float)800/width;
	rh=(float)700/height;
	float temp;
    myinit();
   glutSetWindow(s1);
   	 init();
	 glutReshapeWindow((width-3*padding)/2,(height-3*padding)/2);
	 glutPositionWindow(padding,padding);
	 glutPostRedisplay();
   glutSetWindow(s2);
     init();
	 glutReshapeWindow((width-3*padding)/2,(height-3*padding)/2);
	 glutPositionWindow(width/2+1*padding,padding);
	 glutPostRedisplay();
   glutSetWindow(s3);
     init();
	 glutReshapeWindow((width-3*padding)/2,(height-3*padding)/2);
	 glutPositionWindow(padding,height/2+1*padding);
	 glutPostRedisplay();
   glutSetWindow(s4);
     init();
	 glutReshapeWindow((width-3*padding)/2,(height-3*padding)/2);
	 glutPositionWindow(width/2+padding,height/2+padding);
	 glutPostRedisplay();
}
void display(){
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	 glFlush();
}

void mouse1(int btn, int state, int x, int y){
if(btn==GLUT_LEFT_BUTTON && state==GLUT_UP){
  q1=1;
glutPostRedisplay();
}
if(btn==GLUT_RIGHT_BUTTON && state==GLUT_UP){
  q1=0;
glutPostRedisplay();
}
}
void mouse2(int btn, int state, int x, int y){
if(btn==GLUT_LEFT_BUTTON && state==GLUT_UP){
  q2=1;
glutPostRedisplay();
}
if(btn==GLUT_RIGHT_BUTTON && state==GLUT_UP){
  q2=0;
glutPostRedisplay();
}
}
void mouse3(int btn, int state, int x, int y){
if(btn==GLUT_LEFT_BUTTON && state==GLUT_UP){
  q3=1;
glutPostRedisplay();
}
if(btn==GLUT_RIGHT_BUTTON && state==GLUT_UP){
  q3=0;
glutPostRedisplay();
}
}
void mouse4(int btn, int state, int x, int y){
if(btn==GLUT_LEFT_BUTTON && state==GLUT_UP){
  q4=1;
glutPostRedisplay();
}
if(btn==GLUT_RIGHT_BUTTON && state==GLUT_UP){
  q4=0;
glutPostRedisplay();
}
}

int main(int argc, char **argv)
{
         glutInit(&argc,argv);
         glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
         glutInitWindowSize(800,700);
         glutInitWindowPosition(0,0);
         int main_window = glutCreateWindow("Circle Types");
 init();
 glutDisplayFunc(display);
glutReshapeFunc(resize);
s1=glutCreateSubWindow(m,padding,padding,mww/2-3*padding,mwh/2-3*padding);
  init();
 glutDisplayFunc(drawPCircle);
glutMouseFunc(mouse1);
 s2=glutCreateSubWindow(m,mww/2+1*padding,padding,mww/2-3*padding,mwh/2-3*padding);
 init();
 glutDisplayFunc(circle);
glutMouseFunc(mouse2);
 s3=glutCreateSubWindow(m,padding,mwh/2+padding,mww/2-3*padding,mwh/2-3*padding);
  init();
 glutDisplayFunc(drawPellipse);
glutMouseFunc(mouse3);
 s4=glutCreateSubWindow(m,mww/2+padding,mwh/2+padding,mww/2-3*padding,mwh/2-3*padding);
  init();
 glutDisplayFunc(ellipse);
 glutMouseFunc(mouse4);
glutMainLoop();
         return 0;
}  
