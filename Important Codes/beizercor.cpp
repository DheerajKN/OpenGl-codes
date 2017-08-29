#include <GL/freeglut.h>
#include <iostream>
#include <math.h>
using namespace std;

int SCREEN_WIDTH=640;
int SCREEN_HEIGHT = 480;

int NUMPOINTS = 0;

void myInit() {
    glClearColor(0.0,0.0,0.0,0.0);
    glColor3f(1.0,0.0,0.0);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,(float)SCREEN_WIDTH,0.0,(float)SCREEN_HEIGHT);

}

void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
glBegin(Gl_LINES);
glVertex2f(300,10);
glVertex2f(300,400);
    glFlush();
glEnd();
}

void myMotion(int x, int y){
	if(state==1){
		}
}
int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(SCREEN_WIDTH,SCREEN_HEIGHT);
    glutInitWindowPosition(100,150);
    glutCreateWindow("Bezier Curve");
    glutMouseFunc(myMouse);
    glutDisplayFunc(myDisplay);
   glutMotionFunc(myMotion);
    myInit();
    glutMainLoop();

    return 0;
}
