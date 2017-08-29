#include <GL/glut.h>
#include <GL/freeglut.h>

void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glBegin(GL_POLYGON);
   glColor3f(0,1,0);
   glVertex2f(-0.5,-0.5);
   glColor3f(0,0,1);
   glVertex2f(0.5,-0.5);
   glColor3f(1,0,0);
   glVertex2f(0,0.5);
   glEnd();
glColor3f(1,1,1);
glRasterPos2f(-0.25,0.65);
glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"Colored Triangle");

glColor3f(1,1,1);
glRasterPos2f(-0.35,-0.65);
glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"Name, 5000*****,R1102140** ");
   glFlush();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);  
   glutInitDisplayMode(GLUT_SINGLE);
   glutInitWindowSize(640, 480);   
   glutInitWindowPosition(50, 50); 
   glutCreateWindow("window");         
   glutDisplayFunc(display);       
   glutMainLoop();                
   return 0;
}

