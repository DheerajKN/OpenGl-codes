#include <math.h>
#include <GL/freeglut.h>
  float fillCol[3] = {0.0,1.0,0.0};   

struct Point {
  GLint x;
  GLint y;
};

struct Color {
  GLfloat r;
  GLfloat g;
  GLfloat b;
};

void init() {
  glClear(GL_COLOR_BUFFER_BIT);  
  glColor3f(0.0, 0.0, 0.0);
  glPointSize(1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 640, 0, 480);
}

Color getPixelColor(GLint x, GLint y) {
  Color color;
  glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
  return color;
}

void setPixelColor(GLint x, GLint y, Color color) {
  glColor3f(color.r, color.g, color.b);
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
  glFlush();

}

void Boundaryfill4(int x, int y, Color fillColor,Color boundaryColor) {
  Color currentColor = getPixelColor(x, y);
    if((currentColor.r != boundaryColor.r || currentColor.g != boundaryColor.g || currentColor.b != boundaryColor.b) ) {
    setPixelColor(x, y, fillColor);
    Boundaryfill4(x+1, y, fillColor,boundaryColor);
    Boundaryfill4(x-1, y, fillColor,boundaryColor);
    Boundaryfill4(x, y+1, fillColor,boundaryColor);
    Boundaryfill4(x, y-1, fillColor,boundaryColor);
  }
}

void onMouseClick(int btn, int state, int x, int y)  
  {  Color fillColor = {1.0, 0.0, 0.0};   
  Color boundaryColor = {0.0, 0.0, 1.0};
       if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)   
      {  
            int xi = x;  
            int yi = (480-y);  
            Boundaryfill4(xi,yi,fillColor,boundaryColor);  
       }  
}
void drawPolygon(int x1, int y1, int x2, int y2)  
  {          glRasterPos2f(120,320);
glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"Boundary Fill");
       glBegin(GL_LINES);  
       glColor3f(0.0,0.0,1.0);  
            glVertex2i(x1, y1);  
            glVertex2i(x1, y2); 

            glVertex2i(x2, y1);  
            glVertex2i(x2, y2);  

            glVertex2i(x1, y1);  
            glVertex2i(x2, y1);  

            glVertex2i(x1, y2);  
            glVertex2i(x2, y2);  
       glEnd();  
       glFlush();  
  }

void display(void) {
  Point pt = {320, 240};
  GLfloat radius = 20;

  glClear(GL_COLOR_BUFFER_BIT);
  drawPolygon(150,250,200,300);
  glEnd();
  glFlush();
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(200, 200);
  glutCreateWindow("Open GL");
  init();
  glutDisplayFunc(display);
  glutMouseFunc(onMouseClick);
  glutMainLoop();
  return 0;
}