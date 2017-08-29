#include<stdio.h>
#include<GL/freeglut.h>

void ellipse()
{
        float xc=250, yc=250,  rx=100, ry=60;
        float rxSq = rx * rx;
        float rySq = ry * ry;
        float x = 0, y = ry, p;
        float px = 0, py = 2 * rxSq * y;
        glClear(GL_COLOR_BUFFER_BIT);
  glColor3f( 1 ,0, 0);
         glBegin(GL_POINTS);       
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
                         glBegin(GL_POINTS);
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
               glBegin(GL_POINTS);
          glVertex2d(xc+x,yc+y);
          glVertex2d(xc+x,yc-y);
          glVertex2d(xc-x,yc-y);
          glVertex2d(xc-x,yc+y);
         glEnd();
         glFlush();           
        }
        }
 void Init(){
         glViewport(0 , 0 , 640 , 480);
          glMatrixMode(GL_PROJECTION);
          glLoadIdentity();
          gluOrtho2D(0 , 640 , 0 , 480);
}

int main(int argc, char **argv)
{
         glutInit(&argc,argv);
         glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
         glutInitWindowSize(640,480);
         glutInitWindowPosition(0,0);
         glutCreateWindow("Ellipse");
         Init();
         glutDisplayFunc(ellipse);
         glutMainLoop();
         return 0;
}  
