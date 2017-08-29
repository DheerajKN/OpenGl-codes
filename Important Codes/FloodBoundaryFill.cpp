#include <GL/freeglut.h>  
#include <stdio.h>
  int ww = 600, wh = 500;   
  float bgCol[3] = {0.0, 0.0,0.0};   
  float intCol[3] = {1.0,0.0,0.0};   
  float fillCol[3] = {0.0,1.0,0.0};   
 float borderCol[3] = {1.0,0.0,1.0};  
 void setPixel(int pointx, int pointy, float f[3])   
      {   
             glBegin(GL_POINTS);   
                  glColor3fv(f);   
                  glVertex2i(pointx,pointy);   
             glEnd();   
             glFlush();   
      }   
 void getPixel(int x, int y,float pixels[3]) {
	glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT,pixels);
	
}

void init()
{
 glLoadIdentity();
 glMatrixMode(GL_PROJECTION);
   glLoadIdentity();  
   gluOrtho2D(0.0,(GLdouble)ww,0.0,(GLdouble)wh);  
   glMatrixMode(GL_MODELVIEW);  
  }
void myinit(){
glLoadIdentity();
 glMatrixMode(GL_PROJECTION);
   glLoadIdentity();  
   gluOrtho2D(0.0,(GLdouble)ww/2,0.0,(GLdouble)wh);  
   glMatrixMode(GL_MODELVIEW); 	
}
void draw(int x1, int y1, int x2, int y2)   
       {      glRasterPos2f(80,320);
glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"Flood Fill");
     glRasterPos2f(242,350);
glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"K.N.Dh");
     glRasterPos2f(249,335);
glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"50003");
             glColor3f(1.0, 0.0, 0.0);   
             glBegin(GL_POLYGON);   
                     glVertex2i(x1, y1);    
                  glVertex2i(x1, y2);   
                  glVertex2i(x2, y2);   
                     glVertex2i(x2, y1);   
             glEnd();   
             glFlush();   
       }   
       
void drawPolygon(int x1, int y1, int x2, int y2)  
  {glColor3f(1.0,1.0,1.0);
            glRasterPos2f(120,320);
glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"Boundary Fill");
          glRasterPos2f(5,350);
glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"eeraj");
          glRasterPos2f(5,335);
glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"7782, R.No 80");
       glBegin(GL_LINES);  
       glColor3f(0.0,0.0,1.0);    
            glVertex2i(x1, y1);  
            glVertex2i(x1, y2); 
            glColor3f(1.0,0.0,1.0);    
            glVertex2i(x2, y1);  
            glVertex2i(x2, y2);  
            glColor3f(1.0,1.0,0.0);    
            glVertex2i(x1, y1);  
            glVertex2i(x2, y1);  
            glColor3f(1.0,0.0,0.0);    
            glVertex2i(x1, y2);  
            glVertex2i(x2, y2);  
       glEnd();  
       glFlush();  
  }
  void floodfill4(int x,int y,float oldcolor[3],float newcolor[3])   
       {   
            float color[3];   
            getPixel(x,y,color);   
            if(color[0]==oldcolor[0] && (color[1])==oldcolor[1] && (color[2])==oldcolor[2])   
            {   
                     setPixel(x,y,newcolor);   
                     floodfill4(x+1,y,oldcolor,newcolor);   
                     floodfill4(x-1,y,oldcolor,newcolor);   
                  floodfill4(x,y+1,oldcolor,newcolor);   
                  floodfill4(x,y-1,oldcolor,newcolor);   
             }   
       }   
       void mouse(int btn, int state, int x, int y)   
       {   
             if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)    
            {   
                     int xi = x;   
                     int yi = (wh-y);   
                     floodfill4(xi,yi,intCol,fillCol);   
             }   
       }
       void boundaryFill4(int x,int y,float fillColor[3],float borderColor[3])  
  {  
       float interiorColor[3];  
        getPixel(x,y,interiorColor); 
       if((interiorColor[0]!=borderColor[0] || interiorColor[1]!=borderColor[1] || interiorColor[2]!=borderColor[2]) && (interiorColor[0]!=fillColor[0] || interiorColor[1]!=fillColor[1] || interiorColor[2]!=fillColor[2]))  
       { 
            setPixel(x,y,fillColor);  
            boundaryFill4(x+1,y,fillColor,borderColor);  
            boundaryFill4(x-1,y,fillColor,borderColor);  
            boundaryFill4(x,y+1,fillColor,borderColor);  
            boundaryFill4(x,y-1,fillColor,borderColor);  
       }  
  }  
  void mouse2(int btn, int state, int x, int y)  
  {  
       if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)   
      {  
            int xi = x;  
            int yi = (wh-y);  
            if((xi<200&&xi>150)&&(yi<300&&yi>250)){
            boundaryFill4(xi,yi,fillCol,borderCol);  }
       }  
  }   
   
       void display()  
  {  
       glClear(GL_COLOR_BUFFER_BIT);  
       draw(100,250,150,300);  
       glFlush();  
  }  
 void display2()  
  {  glClearColor(0.7,0.5,0.1, 1.0);
       glClear(GL_COLOR_BUFFER_BIT);  
       drawPolygon(150,250,200,300);  
       glFlush();  
  }   
int main(int argc, char **argv)
{
         glutInit(&argc,argv);
         glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
         glutInitWindowSize(600,500);
         glutInitWindowPosition(0,0);
         int m = glutCreateWindow("FloodBound");
 init();
 glutDisplayFunc(display);

int s1=glutCreateSubWindow(m,0,0,ww/2,wh);
  myinit();
 glutDisplayFunc(display);
     glutMouseFunc(mouse);   
 int s2=glutCreateSubWindow(m,ww/2,0,ww/2,wh);
 myinit();
 glutDisplayFunc(display2);
     glutMouseFunc(mouse2);   
glutMainLoop();
         return 0;
}  
