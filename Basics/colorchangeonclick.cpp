#include <GL/freeglut.h>

void display() {
glClear(GL_COLOR_BUFFER_BIT);

glRasterPos2f(-0.3,0.85);
glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"Color Changing Sqaure");

glColor3f(1,1,1);
glRasterPos2f(-0.35,0.65);
glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"K N Dheeraj, 500037782, 80");

glBegin(GL_POLYGON);
glColor3f(1,0,0);
glVertex2f(-0.4,0.4);
glVertex2f(-0.4,-0.4);
glVertex2f(0.4,-0.4);
glVertex2f(0.4,0.4);
glEnd();
glFlush();
}
void newDisplay() {
glClear(GL_COLOR_BUFFER_BIT);

glRasterPos2f(-0.3,0.85);
glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"Color Changing Sqaure");

glColor3f(1,1,1);
glRasterPos2f(-0.35,0.65);
glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"K N Dheeraj, 500037782, 80");

glBegin(GL_POLYGON);
glColor3f(0,1,0);
glVertex2f(-0.4,0.4);
glVertex2f(-0.4,-0.4);
glVertex2f(0.4,-0.4);
glVertex2f(0.4,0.4);
glEnd();
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
        glutIdleFunc(newDisplay);
        glutMouseFunc(mousere);
    }
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);  
   glutInitDisplayMode(GLUT_SINGLE);
   glutInitWindowSize(640, 480);   
   glutInitWindowPosition(50, 50); 
   glutCreateWindow("Color Changer");         
   glutDisplayFunc(display);       
 glutMouseFunc(mouse);
   glutMainLoop();                
   return 0;
}
