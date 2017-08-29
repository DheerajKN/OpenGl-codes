#include <stdio.h>
#include <GL/freeglut.h>
int first=0;
void drawCircle(GLfloat x, GLfloat y, GLfloat radius);
void display()
{
 glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POLYGON);
 int h1[4][2]={{50,50},{50,100},{100,100},{100,50}};
 int i;
 glColor3f(0,1,0);
 for(i=0;i<4;i++)
 glVertex2iv(h1[i]);
 glEnd();

 glBegin(GL_POLYGON);
 int h2[3][2]={{50,100},{75,125},{100,100}};
 glColor3f(1,1,0);
 for(i=0;i<3;i++)
 glVertex2iv(h2[i]);
 glEnd();
 
 glBegin(GL_POLYGON);
 int h3[4][2]={{74,125},{175,125},{200,100},{100,100}};
 glColor3f(1,1,0.75);
 for(i=0;i<4;i++)
 glVertex2iv(h3[i]);
 glEnd();

 glBegin(GL_POLYGON);
 int h4[4][2]={{100,100},{200,100},{200,50},{100,50}};
 glColor3f(1,0.89,0.75);
 for(i=0;i<4;i++)
 glVertex2iv(h4[i]);
 glEnd();

 glBegin(GL_POLYGON);
 int h6[4][2]={{60,50},{60,80},{80,80},{80,50}};
 glColor3f(1,0.7,0.7);
 for(i=0;i<4;i++)
 glVertex2iv(h6[i]);
 glEnd();

 glBegin(GL_POLYGON);
 int h7[4][2]={{150,70},{150,90},{170,90},{170,70}};
 glColor3f(1,0.4,0.4);
 for(i=0;i<4;i++)
 glVertex2iv(h7[i]);
 glEnd();

glBegin(GL_POLYGON);
glColor3f(1,0.9,0);
 glVertex2i(125,100);
 glVertex2i(175,100);
 glVertex2i(150,125);
 glVertex2i(100,125);

 glEnd();
glRasterPos2i(40,150);
glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned const char*)"K N Dheeraj, 500037782, 80");
 glFlush();
}
void redisplay(){
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POLYGON);
 int h11[4][2]={{50,50},{50,100},{100,100},{100,50}};
 glColor3f(0,1,0);
int i;
 for(i=0;i<4;i++)
 glVertex2iv(h11[i]);
 glEnd();

 glBegin(GL_POLYGON);
 int h12[3][2]={{50,100},{75,125},{100,100}};
 glColor3f(1,1,0);
 for(i=0;i<3;i++)
 glVertex2iv(h12[i]);
 glEnd();
 
 glBegin(GL_POLYGON);
 int h13[4][2]={{74,125},{175,125},{200,100},{100,100}};
 glColor3f(1,1,0.75);
 for(i=0;i<4;i++)
 glVertex2iv(h13[i]);
 glEnd();

 glBegin(GL_POLYGON);
 int h14[4][2]={{100,100},{200,100},{200,50},{100,50}};
 glColor3f(1,0,0.75);
 for(i=0;i<4;i++)
 glVertex2iv(h14[i]);
 glEnd();

 glBegin(GL_POLYGON);
 int h16[4][2]={{60,50},{60,80},{80,80},{80,50}};
 glColor3f(1,0.7,0.7);
 for(i=0;i<4;i++)
 glVertex2iv(h16[i]);
 glEnd();

 glBegin(GL_POLYGON);
 int h17[4][2]={{150,70},{150,90},{170,90},{170,70}};
 glColor3f(1,0.4,0.4);
 for(i=0;i<4;i++)
 glVertex2iv(h17[i]);
 glEnd();

glBegin(GL_POLYGON);
glColor3f(1,0.9,0);
 glVertex2i(125,100);
 glVertex2i(175,100);
 glVertex2i(150,125);
 glVertex2i(100,125);

 glEnd();
glRasterPos2i(40,150);
glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned const char*)"K N Dheeraj, 500037782, 80");
 glFlush();
}
void mouse(int button, int state, int x, int y);
void mousere(int button, int state, int x, int y) {
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        glutIdleFunc(display);
	glutMouseFunc(mouse);
    }
}
void mouse(int button, int state, int x, int y) {
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        glutIdleFunc(redisplay);
        glutMouseFunc(mousere);
    }
}void myinit()
{
 glLoadIdentity();
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(0,300,0,300);
}

int main(int argc,char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
 glutInitWindowSize(300,350);
 glutInitWindowPosition(200,200);
 glutCreateWindow("Amy's Hut");
 myinit();
 glutDisplayFunc(display);
 glutMouseFunc(mouse); 
 glutMainLoop();
 return 0;
}
