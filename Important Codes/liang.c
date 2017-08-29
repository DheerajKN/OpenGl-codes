#include<stdio.h>
#include<GL/glut.h>

int x1,x2,y3,y2;
float u1=0,u2=1;
int xmin=-50,ymin=-50,xmax=50,ymax=50;
double p[4],q[4];  // changed from int to double thats it
void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-320,320,-240,240);
}
void clip(int x1,int y1,int x2,int y2)
{
    int dx=x2-x1,dy=y2-y1,i;
    double t;
    p[0]=-dx;q[0]=x1-xmin;
    p[1]=dx;q[1]=xmax-x1;
    p[2]=-dy;q[2]=y1-ymin;
    p[3]=dy;q[3]=ymax-y1;

    for(i=0;i<4;i++)
    {
        if(p[i]==0 && q[i]<0)
            return;
       else if(p[i]<0)
        {
            t=(q[i])/(p[i]);  //q and p were int
            if(t>=u1 && t<=u2)
                {u1=t;}
        }
        else if(p[i]>0)
        {
            t=(q[i])/(p[i]);  
            if(t>=u1 && t<=u2)
                {u2=t;}
        }
    }
    if(u1<u2)
    {int x11=x1+u1*(x2-x1);
        int y11=y3+u1*(y2-y3);
        int x21=x1+u2*(x2-x1);
        int y21=y3+u2*(y2-y3);
        glBegin(GL_LINES);
 glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,1.0,0.0);          
  glVertex2i(x11,y11);
            glVertex2i(x21,y21);
        glEnd();
        glFlush();
    }
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
   /* glBegin(GL_LINES);
        glVertex2i(x1,y3);
        glVertex2i(x2,y2);
    glEnd();
   */ glFlush();
glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_LINES);
            glVertex2i(-50,-50);
            glVertex2i(-50,50);
            glVertex2i(-50,50);
            glVertex2i(50,50);
            glVertex2i(50,50);
            glVertex2i(50,-50);
            glVertex2i(50,-50);
            glVertex2i(-50,-50);
        glEnd();
        glFlush();
        clip(x1,y3,x2,y2);
}
/* void myKey(unsigned char key,int x,int y)
{
glClear(GL_COLOR_BUFFER_BIT);
    if(key=='c')
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
        glColor3f(0.0,0.0,0.0);
        glBegin(GL_LINES);
            glVertex2i(-50,-50);
            glVertex2i(-50,50);
            glVertex2i(-50,50);
            glVertex2i(50,50);
            glVertex2i(50,50);
            glVertex2i(50,-50);
            glVertex2i(50,-50);
            glVertex2i(-50,-50);
        glEnd();
        glFlush();
        clip(x1,y3,x2,y2);
    }


} */
int main(int argc,char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(0,0);
	printf("window size is : xmin=-50,ymin=-50,xmax=50,ymax=50");    
	printf("enter x1,y1,x2, y2");
    scanf("%d%d%d%d",&x1,&y3,&x2,&y2);
    glutCreateWindow("Clip");
    glutDisplayFunc(display);
 //   glutKeyboardFunc(myKey);
    init();
    glutMainLoop();
    return 0;
}
