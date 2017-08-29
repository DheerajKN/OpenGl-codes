#include <GL/glut.h>
#include <GL/freeglut.h>
//#include <string.h>
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
const unsigned char* m=reinterpret_cast<const unsigned char *>("Colorful Triangle");
glutBitmapString(GLUT_BITMAP_HELVETICA_18,m);

glColor3f(1,1,1);
glRasterPos2f(-0.50,-0.65);
const unsigned char* n=reinterpret_cast<const unsigned char *>("KNDheeraj, 500037782, B2, R110214080");
glutBitmapString(GLUT_BITMAP_HELVETICA_18,n);

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

