#include <GL/freeglut.h>
#include <iostream>
#include <math.h>
using namespace std;

int SCREEN_WIDTH=640;
int SCREEN_HEIGHT = 480;
int NUMPOINTS = 0;

class Point {
public:
    float x, y;
    void setxy(float x2, float y2) { x = x2; y = y2; }
    const Point & operator=(const Point &rPoint) {
         x = rPoint.x;
         y = rPoint.y;

         return *this;
      }

};

Point abc[3];

void myInit() {
    glClearColor(0.0,0.0,0.0,0.0);
    glColor3f(1.0,0.0,0.0);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,(float)SCREEN_WIDTH,0.0,(float)SCREEN_HEIGHT);

}

void drawDot(int x, int y) {
    glBegin(GL_POINTS);
     glVertex2i(x,y);
    glEnd();
    glFlush();
}

void drawLine(Point p1, Point p2) {
    glBegin(GL_LINE_LOOP);
      glVertex2f(p1.x, p1.y);
      glVertex2f(p2.x, p2.y);
    glEnd();
    glFlush();
}

Point drawBezier(Point A, Point B, Point C, double t) {
    Point P;

    P.x = pow((1 - t), 2) * A.x + 2 * t * (1 -t) * B.x + pow(t, 2) * C.x;
    P.y = pow((1 - t), 2) * A.y + 2 * t * (1 -t) * B.y + pow(t, 2) * C.y;

    return P;
}
Point drawBeziercubic(Point A, Point B, Point C, Point D,double t) {
    Point Pcubic;

    Pcubic.x = pow (1-t, 3) * A.x + 3 * t * pow (1-t, 2) * B.x + 3 * pow (t, 2) * (1-t) * C.x + pow (t, 3) * D.x;
 
    Pcubic.y = pow (1-t, 3) * A.y + 3 * t * pow (1-t, 2) * B.y + 3 * pow (t, 2) * (1-t) * C.y + pow (t, 3) * D.y;
 
    return Pcubic;
}

void keypress(unsigned char key,int x,int y)
{
if(key=='e') {
        glColor3f(1.0,1.0,0.0);
/*for(int i=0;i<NUMPOINTS-1;i++){        
	drawLine(abc[i], abc[i+1]);

}*/
        Point POld = abc[0];
        glColor3f(1.0,1.0,1.0);

if(NUMPOINTS==3){ 
       for(double t = 0.0;t < 1.0; t += 0.0005) {
            Point P = drawBezier(abc[0], abc[1], abc[2], t);
            drawLine(POld, P);
            POld = P;
        }        glColor3f(1.0,0.0,0.0);
        NUMPOINTS = 0;}

else if(NUMPOINTS>3){
for (double t = 0.0; t < 1.0; t += 0.0005){
            Point P = drawBeziercubic(abc[0], abc[1], abc[2],abc[3], t);
            drawLine(POld, P);
            POld = P;
}
        glColor3f(1.0,0.0,0.0);
        NUMPOINTS = 0;
    }}}
void myMouse(int button, int state, int x, int y) {

  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    abc[NUMPOINTS].setxy((float)x,(float)(SCREEN_HEIGHT - y));

    NUMPOINTS++;
 
   drawDot(x, SCREEN_HEIGHT - y);
      }
}

void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(SCREEN_WIDTH,SCREEN_HEIGHT);
    glutInitWindowPosition(100,150);
    glutCreateWindow("Bezier Curve");

    glutMouseFunc(myMouse);
    glutDisplayFunc(myDisplay);
   glutKeyboardFunc(keypress);
    myInit();
    glutMainLoop();

    return 0;
}
