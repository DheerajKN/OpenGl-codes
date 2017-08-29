#include <math.h> 
#include <GL/freeglut.h> 
#include <stdio.h> 
#include <stdlib.h>

float Matrix [4][4];
float TransMatrix [4][4];
float NewMatrix [4][4];
int NEdges;
float xy[4];
void display(){
glColor3f(1.0,1.0,1.0);
            glRasterPos2f(0.25,0.5);
glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"Enter Inital Values from console");
glFlush();
float i;
for(i=0;i<3;i++){
 printf("Enter coordinate: ");
 scanf("%f %f",&xy[0][i],&xy[1][i]); 
 }
  insert(xy);
  glBegin(GL_POLYGON);
  for(i=0;i<3;i++){
    glVertex2fv(xy[i]);}
    glEnd();
  glColor3f(1.0,1.0,1.0);
            glRasterPos2f(-0.75,0.35);
glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"Press T for transulaton R for rotation S for scaling H for Shearing E for Reflection");
glFlush();}
void matrixSetIdentity(float m[4][4])
{
   float i, j;
   for (i=0; i<3; i++)
   for (j=0; j<3; j++)
   m[i][j] = (i == j);
}
void insert(float xy[4][4]){
  float i;
for(i=0;i<4;i++){
  Matrix[0][i]=xy[0][i];
  Matrix[1][i]=xy[1][i];
  Matrix[2][i]=0;
  Matrix[3][i]=1;
}
}
void matrixPreMultiply(float a[4][4], float b[4][4])
{
   int i,j;
   float tmp[4][4];
   for ( i = 0; i < 4; i++)
     for ( j = 0; j < 4; j++)
       tmp[i][j] = a[
        i][0]*b[0][j] + a[i][1]*b[1][j] + a[i][2]*b[2][j];
   for (i = 0; i < 4; i++)
     for ( j = 0; j < 4; j++)
       Matrix[i][j] = tmp[i][j];
}

void transulate(){
  float tx,ty,tz=0;
 printf("Enter transulate Values\n");
 scanf("%f %f",&tx,&ty);
 matrixSetIdentity(TransMatrix);
   TransMatrix[3][0] = tx;
   TransMatrix[3][1] = ty;
   TransMatrix[3][2] = tz;
   matrixPreMultiply(Matrix, TransMatrix);
}

void init()
{
 glMatrixMode(GL_PROJECTION);
   glLoadIdentity();  
   glMatrixMode(GL_MODELVIEW);  
  }

void keypress(unsigned char key,int x,int y)
{
  switch(key)
  {
    case 116: // transulation
	 glutDisplayFunc(transulate);
	 glutPostRedisplay();
 //        screen++; 
 //        type=0;

   break;
 //   case 114:// rotation
	// glutDisplayFunc(display_breso);
	// glutPostRedisplay();
 //        screen++;
 //        type=1;   
 //  break;  
 //  case 115:// scaling
	// if(type==0 && screen==1)
	//  { 
	//    getInput();
 //       glutDisplayFunc(display_dda);
	//    glutPostRedisplay();
	//    screen=2; }

 //         else if(type==1 && screen==1)
	//  { getInput();
 //           glutDisplayFunc(display_bres);
	//    glutPostRedisplay();
	//    screen=2; }
 // break;
 // case 104:// shearing
	// if(type==0 && screen==1)
	//  { 
	//  	xi=0;
	//  	xf=0;
	//  	yi=0;
	//  	yf=0;
	//  	onMouse=0;
	//    glutMouseFunc(mouseClicks);
 //           glutDisplayFunc(display_dda);
	//    glutPostRedisplay();
	//    screen=2; }
       
 //       else if(type==1 && screen==1)
	//  { 
	//  	xi=0;
	//  	xf=0;
	//  	yi=0;
	//  	yf=0;
	//  	onMouse=0;
	//  	glutMouseFunc(mouseClicks);
 //           glutDisplayFunc(display_bres);
	//    glutPostRedisplay();
	//    screen=2; }
 // break;
	
 // case 101:// reflection
 // 	if(type==0 && screen==2)
 // 	{glutDisplayFunc(display_ddao);
	//  glutPostRedisplay();
 //     screen--;
 //    }
 //    else if(type==1 && screen==2)
 // 	{glutDisplayFunc(display_breso);
	//  glutPostRedisplay();
 //     screen--;
 //    }
 //    else if(screen==1)
 // 	{glutDisplayFunc(display);
	//  glutPostRedisplay();
 //     screen--;
 //    }
 //    else if(screen==0)
 //    {
 //    	glutDestroyWindow(glutGetWindow());
 //    }
 //  break;
 //  default:         	         
	// 	 glColor3f(1,0,0);
 //  		 glRasterPos2i(-50,220);
	// 	 glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned const char*)"Error: Invalid Input");
	// 	 glFlush();	
   }
}


int main(int argc, char **argv)
{
         glutInit(&argc,argv);
         glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
         glutInitWindowSize(800,700);
         glutInitWindowPosition(0,0);
         glutCreateWindow("3D Transformations");
         init();
  glutDisplayFunc(display);
  glutKeyboardFunc(keypress);
  glutMainLoop();
  return 0;
  }
