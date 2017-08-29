#include <GL/glut.h>
#include <stdio.h>
int n,m;
void pytree(int n)
{
    if(n>0)
    {
     glPushMatrix();

     glTranslatef(-0.4,1.0,0);
     glRotatef(45, 0.0, 0.0, 1.0);
     glScalef(0.707,0.707,0.707);
     pytree(n-1);

     glPopMatrix();

     glPushMatrix();

    glTranslatef(0.5,1.0,0);
     glRotatef(-45, 0.0, 0.0, 1.0);
     glScalef(0.707,0.707,0.707);
     pytree(n-1);

     glPopMatrix();
     glutWireCube(1);
    }
}

void pytreeInit(int n)
{	glColor3f(0.0,1.0,0.0);
   pytree(n);
}

void display (void)
{
    glClearColor (0.0,0.0,0.0,1.0);
    glClear (GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    pytreeInit(n);
    glFlush();
}

void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
    glMatrixMode (GL_MODELVIEW);
}

int main (int argc, char **argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE);
	printf("ENter degree of the tree");
	scanf("%d",&n);
	m=n; 
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Pythagoras Tree");
   glutDisplayFunc (display);
   glutReshapeFunc (reshape);
    glutMainLoop ();
    return 0;
}
