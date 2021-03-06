#include <stdio.h>
#include <GL/freeglut.h>
#include <math.h>
int onMouse;
int xmin=270,xmax=370,ymin=200,ymax=300;
int xi,yi,xf,yf;
void clip(int x1,int y1,int x2,int y2)
{
	int dx=x2-x1;
	int dy=y2-y1;
	int p[4],q[4];

	p[0]=-1*dx;
	p[1]=dx;
	p[2]=-1*dy;
	p[3]=dy;
	q[0]=x1-xmin;
	q[1]=xmax-x1;
	q[2]=y1-ymin;
	q[3]=ymax-y1;

	float t1=0;
	float t2=1;
	float temp;

	int i;
	int x11,y11,x21,y21;

	for(i=0;i<4;i++)
	{
	if(p[i]==0&&q[i]<0)
		return;

	else if(p[i]<0)
		{
		temp=(float)q[i]/p[i];
		if(t1<temp)
		t1=temp;
		}
		else if(p[i]>0)
		{
		temp=(float)q[i]/p[i];
		if(t2>temp)
		t2=temp;	
		}

		else
		 { if(dx==0)
		{
		x11=x1;
		x21=x2;
		y11=(ymin>y1)?ymin:y1;
		y21=(ymax<y2)?ymax:y2;
		}
		 else if(dy==0)
		   {
		  	y11=y1;
			y21=y2;
			x11=(xmin>x1)?xmin:x1;
			x21=(xmax<x2)?xmax:x2;
		   }
		 
		 break;
		}
	}

	if(i>3)
	{
		if(t1>t2)
			{return;}
		else
			{x11=x1+t1*dx;
			 y11=y1+t1*dy;
			 x21=x1+t2*dx;
			 y21=y1+t2*dy;}
	}

	glColor3f(1,0,1);
	glBegin(GL_LINES);
	glLineWidth(5.0);
	glVertex2i(x11,y11);
	glVertex2i(x21,y21);
	glEnd();
}

void mouse(int button, int state, int x, int y) {
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if(onMouse==0)
        {onMouse++; 
         xi=x;
         yi=480-y;
         }
	else if(onMouse==1)
	{ 
         xf=x;
         yf=480-y;
	glColor3f(1,1,1);
	glBegin(GL_LINES);
	glVertex2i(xi,yi);
	glVertex2i(xf,yf);
	glEnd();
	glFlush();
	clip(xi,yi,xf,yf);
	glutPostRedisplay();
	onMouse=0;
        }	       
    }
}

void init()
{
 glLoadIdentity();
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(0, 640, 0, 480);
}

void display()
{
	glClearColor(0,0,0,0);
 	glColor3f(0,1,1);
	glBegin(GL_LINE_LOOP);
	glVertex2i(xmin,ymin);
	glVertex2i(xmax,ymin);
	glVertex2i(xmax,ymax);
	glVertex2i(xmin,ymax);
	glEnd();
	glFlush();
}


int main(int argc,char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(0,0);
    glutCreateWindow("LiangClip");
    glutDisplayFunc(display);
	glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}
