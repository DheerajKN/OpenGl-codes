#include <stdio.h>
#include <GL/freeglut.h>
#include <math.h>
#define reflecty 100
#define TRANSLATE 101
#define ROTATE 102
#define SCALE 103
#define reflectx 104
#define SHEAR 105

void mul(float[3][3]);
void display();

float t_mat[3][3];
int n;
int points[20][2];
int d=0;

void compositetrans(int type,float tx,float ty,float theta)
{
  float arr[3][3];
  int i,j;
  for ( i = 0; i <3; ++i)
  {
    for (j = 0; j < 3; ++j)
    {
      arr[i][j]=(i==j)?1.0:0.0;
    }
  }
	theta=theta*3.14/180;

  switch(type)
  {
    case reflecty:
    arr[0][0]=-1;
     mul(arr);
    break;
    case reflectx:
    arr[1][1]=-1;
    mul(arr);
    break;
    case TRANSLATE:
    arr[2][0]=tx;
    arr[2][1]=ty;
    mul(arr);
    break;
    case ROTATE:
    arr[0][0]=cos(theta);
    arr[0][1]=sin(theta);
    arr[1][0]=-1*sin(theta);
    arr[1][1]=cos(theta);
    arr[2][0]=tx*(1-cos(theta))+ty*sin(theta);
    arr[2][1]=ty*(1-cos(theta))-tx*sin(theta);   
    mul(arr);
    break;
    case SCALE:
    arr[0][0]=tx;
    arr[1][1]=ty;
    mul(arr);
	break;
    case SHEAR:
    arr[1][0]=tx;
    arr[0][1]=ty;
    mul(arr);
break;
  }
}


void mul(float a1[][3])
{
  float temp[3][3];
  int i,j,k;
 for( i = 0; i < 3; i++)
 {
    for ( j = 0; j < 3; j++)
    {
      temp[i][j]=0.0;    
    }
 }

  for( i=0;i<3;i++)
    for (j=0; j<3; j++)
      for ( k=0; k<3; k++)
      {
        temp[i][j]=temp[i][j]+t_mat[i][k]*a1[k][j];
      }

 for(i = 0; i < 3; i++)
  {
     for (j = 0; j < 3; j++)
      {
       t_mat[i][j]=temp[i][j];
      }
  }
}

void setVertex(int x,int y)
{
  int a[3],b[3],i,j,k;
  a[0]=x;
  a[1]=y;
  a[2]=1;
  b[0]=0;
  b[1]=0;
  b[2]=0;
  for( i=0;i<1;i++)
    for( j=0;j<3;j++)
      for( k=0;k<3;k++)
        b[j]=b[j]+a[k]*t_mat[k][j];

    glVertex2i(b[0],b[1]);
}

void keypress(unsigned char key,int x,int y)
{
	int i;
	switch(key)
	{
		case 'i':
		d=1;
		printf("enter number of vertices: ");
		scanf("%d",&n);
		printf("\nenter vertices:\n");
		glColor3f(1,0,0);
		if(n==1)
		{
			glBegin(GL_POINTS);
		}
		else if(n==2)
		{
			glBegin(GL_LINES);	
		}
		else
			glBegin(GL_POLYGON);
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&points[i][0],&points[i][1]);
			glVertex2i(points[i][0],points[i][1]);
		}
		glEnd();
		glFlush();
		break;
		case 't':
				printf("move in x direction: ");
				int tx,ty;
				scanf("%d",&tx);
				printf("move in y direction: ");
				scanf("%d",&ty);
				compositetrans(TRANSLATE,tx,ty,0);
				glutPostRedisplay();
		case 'y':
				compositetrans(reflecty,0,0,0);
				glutPostRedisplay();	
		break;
		case 'x':
				compositetrans(reflectx,0,0,0);
				glutPostRedisplay();	
		break;
		case 'r':
				printf("enter angle: ");
				float theta;
				scanf("%f",&theta);
				compositetrans(ROTATE,0,0,theta);
				glutPostRedisplay();	
		break;
		case 's':
				printf("enter scale in x: ");
				float sx,sy;
				scanf("%f",&sx);
				printf("enter scale in y: ");
				scanf("%f",&sy);	
				compositetrans(SCALE,sx,sy,0);
				glutPostRedisplay();	
		break;
		case 'h':
			 printf("enter shear value along x:");
			 float shx,shy;
			 scanf("%f",&shx);
			 compositetrans(SHEAR,shx,0,0);
			 glutPostRedisplay();
                break;
		case 'j':	
			 printf("enter shear value along y:");
			 scanf("%f",&shy);
			 compositetrans(SHEAR,0,shy,0);		
			 glutPostRedisplay();
		break;
		case 27:
				exit(0);
		break;
	}
}

void display()
{
	glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,1);
 	glRasterPos2i(-350,450);
 	glutBitmapString(GLUT_BITMAP_HELVETICA_18,"Press I for Input,T for Translation,Y for Reflection along y,X for Reflection along x,R for rotation");
 	glRasterPos2i(-250,425);
 	glutBitmapString(GLUT_BITMAP_HELVETICA_18,"Press S for Scaling,H for Shearing and J for Shearing along y");
	glColor3f(1,0,0);
	int i;
	if(d==1)
	{
		if(n==1)
			glBegin(GL_POINTS);
		else if(n==2)
			glBegin(GL_LINES);	
		else
			glBegin(GL_POLYGON);
		for(i=0;i<n;i++)
		{
			setVertex(points[i][0],points[i][1]);
		}
		glEnd();
	}
	glBegin(GL_POINTS);
 glColor3f(1, 1, 1);
	 for(i=-500 ; i<=500 ; i++)
 	{
 	glVertex2i(i,0);
 	glVertex2i(0,i);
 	}
glEnd();
	glFlush();
}

void reflectyinit()
{
 glLoadIdentity();
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-500,500,-500,500);
}

int main(int argc,char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
 glutInitWindowSize(1000,1000);
 glutInitWindowPosition(200,200);
 glutCreateWindow("2D Transformation");
 reflectyinit();
 t_mat[0][0]=1;t_mat[0][1]=0;t_mat[0][2]=0;
 t_mat[1][0]=0;t_mat[1][1]=1;t_mat[1][2]=0;
 t_mat[2][0]=0;t_mat[2][1]=0;t_mat[2][2]=1; 
 glutDisplayFunc(display);
 glutKeyboardFunc(keypress);
 glutMainLoop();
 return 0;
}

