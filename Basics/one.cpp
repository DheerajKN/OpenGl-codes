#include <GL/glut.h>
void print(){
glColor3f(1,1,1);
char a[23]={'K','N','D','H','E','E','R','A','J',',',' ','5','0','0','3','7','7','8','2',',',' ','B','2'};
char f[15]={'G','R','E','E','N',' ','T','R','I','A','N','G','L','E'};
glRasterPos2f(-0.25,0.65);
for(int i=0;i<15;i++){
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,f[i]);
}
glRasterPos2f(-0.35,-0.65);
for(int i=0;i<23;i++){
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,a[i]);
}

}
void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0,1,0);
   glBegin(GL_POLYGON);
   glVertex2f(-0.5,-0.5);
   glVertex2f(0.5,-0.5);
   glVertex2f(0,0.5);
   glEnd();
print();
   glFlush();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);  
   glutInitDisplayMode(GLUT_SINGLE);
   glutInitWindowSize(640, 480);   
   glutInitWindowPosition(50, 50); 
   glutCreateWindow("window");         
   glutDisplayFunc(display);       
   //initGL();                       
   glutMainLoop();                
   return 0;
}

