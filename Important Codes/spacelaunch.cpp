#include <GL/freeglut.h>
#include<math.h>
const float DEG2RAD = 3.14159/180;

void stars();
void stars1();
int p,type=0,s=0;
void mars(float radius);
float i,j,k,count1=0,count=0,flag1=0,t=0,f=0,count2=0,count3=0;

void semicircle(float radius,float u,float v)
{
	glColor3f(1.0 ,1.0 ,1.0);
        glBegin(GL_POLYGON);
	for (int i=135; i<=315; i++)
	   {
	      float degInRad = i*DEG2RAD;
	      glVertex2f(u+cos(degInRad)*radius,v+(sin			(degInRad))*radius);
	   }
   	glEnd();
}

void star_loop()
{
                if(count>=5|count2>=5){
			glClearColor(0.0 ,0.0 ,0.0,1.0);
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			if(flag1==0){
				stars();
				flag1=1;
			}
			else{
				stars1();
				flag1=0;
			}
		 }
		 else{
			glClearColor(0.0  ,0.0 ,0.0,1.0);
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		 }
}

void display()
{        
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	 glColor3f(1,1,1);
	 glRasterPos2i(100,450);
	 glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned const char*)"Mini Project in Computer Graphics");
	 glColor3f(1,0,0);
	 glRasterPos2i(100,350);
	 glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,(unsigned const char*)"Simulation of Rocket Launch");
	 glColor3f(1,1,1);
	 glRasterPos2i(80,270);
	 glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned const char*)"Press a for auto mode and m for manual");
	 glColor3f(0,1,1);
	 glRasterPos2i(20,100);
	 glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned const char*)"Submitted to:");
	 glRasterPos2i(345,70);
	 glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned const char*)"Mr. Pankaj Badoni");
	 glFlush();

}

void display_manual(){        
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	 glColor3f(1,1,1);
	 glRasterPos2i(100,450);
	 glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned const char*)"press t for take off");
	 glRasterPos2i(100,400);
	 glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned const char*)"press f to off the booster");
	 glRasterPos2i(100,350);
	 glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned const char*)"press b to seperate the booster from rocket");
	 glRasterPos2i(100,300);
	 glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned const char*)"press r to  remove the booster completely");
	 glRasterPos2i(100,250);
	 glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned const char*)"press d to dismantle the rocket");
	 glRasterPos2i(100,200);
	 glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned const char*)"press R to   remove the dismantled part");
	 glRasterPos2i(100,150);
	 glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned const char*)"press n to  proceed forward");
	 glFlush();
}

void stars(){
	glColor3f(1.0,1.0,1.0);
	glPointSize(0.5);
	glBegin(GL_POINTS);
	glVertex2i(10,20);
	glVertex2i(20,100);
	glVertex2i(30,10);
	glVertex2i(15,150);
	glVertex2i(200,200);
	glVertex2i(55,33);
	glVertex2i(400,300);
	glVertex2i(125,63);
	glVertex2i(63,125);
	glVertex2i(20,10);
	glVertex2i(110,330);
	glVertex2i(440,430);
	glVertex2i(32,65);
	glVertex2i(110,440);
	glVertex2i(210,230);
	glVertex2i(390,490);
	glVertex2i(12,90);
	glVertex2i(400,322);
	glVertex2i(420,366);
	glVertex2i(455,400);
	glVertex2i(20,20);
	glVertex2i(111,120);
	glVertex2i(401,200);
	glVertex2i(230,30);
	glVertex2i(220,20);
	glVertex2i(122,378);
	glVertex2i(133,340);
	glVertex2i(345,420);
	glVertex2i(130,360);
	glVertex2i(333,120);
	glVertex2i(250,22);
	glVertex2i(242,11);
	glVertex2i(280,332);
	glVertex2i(229,342);
	glVertex2i(257,47);
	glVertex2i(290,63);
	glVertex2i(232,72);
	glVertex2i(243,143);
	glVertex2i(100,200);
	glVertex2i(90,250);
	glVertex2i(80,225);
	glVertex2i(50,333);
	glVertex2i(60,350);
	glVertex2i(243,143);
	glVertex2i(243,143);
	glEnd();
}

void stars1(){
	int l;
	glColor3f(1.0,1.0,1.0);
	glPointSize(0.3);
	glBegin(GL_POINTS);
	glVertex2i(50,20);
	glVertex2i(70,100);
	glVertex2i(80,10);
	glVertex2i(65,150);
	glVertex2i(67,80);
	glVertex2i(105,33);
	glVertex2i(450,300);
	glVertex2i(380,110);
	glVertex2i(113,125);
	glVertex2i(70,10);
	glVertex2i(160,330);
	glVertex2i(160,440);
	glVertex2i(440,490);
	glVertex2i(62,90);
	glVertex2i(450,322);
	glVertex2i(420,366);
	glVertex2i(455,400);
	glVertex2i(60,20);
	glVertex2i(111,120);
	glVertex2i(451,200);
	glVertex2i(280,30);
	glVertex2i(220,20);
	glVertex2i(132,378);
	glVertex2i(173,340);
	glVertex2i(200,22);
	glVertex2i(342,11);
	glVertex2i(330,332);
	glVertex2i(283,40);
	glVertex2i(210,418);
	glVertex2i(256,12);
	glVertex2i(288,232);
	glVertex2i(247,36);
	glVertex2i(229,342);
	glVertex2i(257,47);
	glVertex2i(290,63);
	glVertex2i(232,72);
	glVertex2i(243,143);
	glVertex2i(100,200);
	glVertex2i(90,250);
	glVertex2i(80,225);
	glVertex2i(50,333);
	glVertex2i(60,350);
	glVertex2i(243,143);
	glVertex2i(243,143);
	glEnd();
	for(l=0;l<=10000;l++)
		;
}

void background(){
	glClearColor(0.0  ,0.75 ,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
       if((count1>=60&&count1<120)) {
	glColor3f(0.0f,0.0f,0.0f);
	glRasterPos2f(250,470);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"10");
    	}        
 	else if ((count1>=120&&count1<180)) {
        glColor3f(0.0f,0.0f,0.0f);
	glRasterPos2f(250,450);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"09");
        }
 	else if ((count1>=180&&count1<240)) {
        glColor3f(0.0f,0.0f,0.0f);
	glRasterPos2f(250,440);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"08");
        }
 	else if ((count1>=240&&count1<300)) {
        glColor3f(0.0f,0.0f,0.0f);
	glRasterPos2f(250,430);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"07");
        }
 	else if ((count1>=300&&count1<360)){
        glColor3f(0.0f,0.0f,0.0f);
	glRasterPos2f(250,420);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"06");
        }
 	else if ((count1>=360&&count1<420)){
        glColor3f(0.0f,0.0f,0.0f);
	glRasterPos2f(250,410);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"05");
        }
	else if ((count1>=420&&count1<480)){
        glColor3f(0.0f,0.0f,0.0f);
	glRasterPos2f(250,400);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"04");
        }
	else if ((count1>=480&&count1<540)){
        glColor3f(0.0f,0.0f,0.0f);
	glRasterPos2f(250,390);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"03");
        }
	else if ((count1>=540&&count1<600)){
        glColor3f(0.0f,0.0f,0.0f);
	glRasterPos2f(250,380);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"02");
        }
	else if ((count1>=600&&count1<660)){
        glColor3f(0.0f,0.0f,0.0f);
	glRasterPos2f(250,370);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned 
char*)"01 ");
        }
    	glColor3f(0.0,0.7,0.2);
		glBegin(GL_POLYGON);//green ground
		glVertex2f(0.0,0.0);
		glVertex2f(0.0,250.0);
		glVertex2f(270.0,250.0);
		glVertex2f(500.0,50.0);
		glVertex2f(500.0,0.0);
		glEnd();
	glBegin(GL_POLYGON);//green ground
		glVertex2f(280.0,250.0);
		glVertex2f(500.0,250.0);
		glVertex2f(500.0,60.0);
		glEnd();
	glColor3f(0.0,0.0,0.0);
		glBegin(GL_POLYGON);     //road
		glVertex2f(240.0,250.0);
		glVertex2f(320.0,250.0);
		glVertex2f(500.0,100.0);
		glVertex2f(500.0,0.0);
		glEnd();
	 glColor3f(1.0f,1.0f,1.0f);
	   glRasterPos2f(120,390);
	   glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"ISRO");
               glColor3f(0.0,0.0,0.0);
		glBegin(GL_LINE_LOOP);  //banner
		glVertex2f(80.0,380.0);
		glVertex2f(220.0,380.0);
		glVertex2f(220.0,410.0);
		glVertex2f(80.0,410.0);
		glEnd();
	glColor3f(0.4,0.5,0.5);
		glBegin(GL_POLYGON);  //isro
		glVertex2f(80.0,250.0);
		glVertex2f(220.0,250.0);
		glVertex2f(220.0,380.0);
		glVertex2f(80.0,380.0);
		glEnd();
               glColor3f(1.0,1.0,1.0);
		glBegin(GL_POLYGON); //window i_1
		glVertex2f(90,320.5);
		glVertex2f(120.0,320.5);
		glVertex2f(120.0,360.5);
		glVertex2f(90.0,360.5);
		glEnd();
               glColor3f(1,1,1);
		glBegin(GL_POLYGON); //window i_2
			glVertex2f(170,320.5);
			glVertex2f(200.0,320.5);
			glVertex2f(200.0,360.5);
			glVertex2f(170.0,360.5);
			glEnd();
                glColor3f(0,0,0);
		glBegin(GL_LINES); //window i_2
			glVertex2f(90,340.5);
			glVertex2f(120.0,340.5);
			glVertex2f(170.0,340.5);
			glVertex2f(200.0,340.5);
			glEnd();
  		glColor3f(0.5,0.0,0.0);
		glBegin(GL_POLYGON); //door isro
			glVertex2f(130,250.5);
			glVertex2f(160.0,250.5);
			glVertex2f(160.0,300.5);
			glVertex2f(130.0,300.5);
			glEnd();	         
                glColor3f(0.8,0.6,0.1);
	        glBegin(GL_POLYGON);  // cone2
			glVertex2f(440,250);
			glVertex2f(490,250);
			glVertex2f(465,310);
			glEnd();
			semicircle(20.0,475,320);
		glColor3f(0.0,0.0 ,0.0);
	 	glBegin(GL_LINES);//wires2
			glVertex2f(460,333);
			glVertex2f(487,340);
			glVertex2f(490,308);
			glVertex2f(487,340);
			glEnd();
	glColor3f(0.5,0.4,0.5);
		glBegin(GL_POLYGON);  //building1
		glVertex2f(250.0,250.0);
		glVertex2f(300.0,250.0);
		glVertex2f(300.0,350.0);
		glVertex2f(250.0,350.0);
		glEnd();
               glColor3f(0.8,0.6,0.8);
		glBegin(GL_POLYGON);  //building2
		glVertex2f(300.0,250.0);
		glVertex2f(350.0,250.0);
		glVertex2f(350.0,450.0);
		glVertex2f(300.0,450.0);
		glEnd();	
                 glColor3f(0.2,0.6,0.5);
		glBegin(GL_POLYGON);  //building3
		glVertex2f(360.0,250.0);
		glVertex2f(420.0,250.0);
		glVertex2f(420.0,400.0);
		glVertex2f(360.0,400.0);
		glEnd();
 		
      		glColor3f(0.9,0.0,0.5);
		glBegin(GL_POLYGON); //window 2_1
			glVertex2f(305,320.5);
			glVertex2f(325.0,320.5);
			glVertex2f(325.0,350.5);
			glVertex2f(305.0,350.5);
			glEnd();
                glColor3f(0.9,0.0,0.5);
		glBegin(GL_POLYGON); //window 2_2
			glVertex2f(325,360.5);
			glVertex2f(345.0,360.5);
			glVertex2f(345.0,390.5);
			glVertex2f(325.0,390.5);
			glEnd();

 		glColor3f(0.9,0.0,0.5);
		glBegin(GL_POLYGON); //window 2_3
			glVertex2f(305,402.5);
			glVertex2f(325.0,402.5);
			glVertex2f(325.0,430.5);
			glVertex2f(305.0,430.5);
			glEnd();
 
  		glColor3f(0.0,0.7,0.7);
		glBegin(GL_POLYGON); //door 2
			glVertex2f(315,250.5);
			glVertex2f(335.0,250.5);
			glVertex2f(335.0,300.5);
			glVertex2f(315.0,300.5);
			glEnd();

		glColor3f(0.7,0.7,0.7);
		glBegin(GL_POLYGON); //window 1_1
			glVertex2f(255,267.5);
			glVertex2f(275.0,267.5);
			glVertex2f(275.0,277.5);
			glVertex2f(255.0,277.5);
			glEnd();

		glBegin(GL_POLYGON); //window 1_2
			glVertex2f(255,285.0);
			glVertex2f(275.0,285);
			glVertex2f(275.0,295);
			glVertex2f(255.0,295);
			glEnd();

		glBegin(GL_POLYGON); //window 1_3
			glVertex2f(255,302);
			glVertex2f(275.0,302);
			glVertex2f(275.0,312);
			glVertex2f(255.0,312);
			glEnd();

		glBegin(GL_POLYGON); //window 1_4
			glVertex2f(255,320.0);
			glVertex2f(275.0,320.0);
			glVertex2f(275.0,330.0);
			glVertex2f(255.0,330.0);
			glEnd();

		glBegin(GL_POLYGON); //window 1_5
			glVertex2f(285,267);
			glVertex2f(295.0,267);
			glVertex2f(295.0,277);
			glVertex2f(285.0,277);
			glEnd();

		glBegin(GL_POLYGON); //window 1_6
			glVertex2f(285,285.0);
			glVertex2f(295.0,285);
			glVertex2f(295.0,295);
			glVertex2f(285.0,295);
			glEnd();
		glBegin(GL_POLYGON); //window 1_7
			glVertex2f(285,302);
			glVertex2f(295.0,302);
			glVertex2f(295.0,312);
			glVertex2f(285.0,312);
			glEnd();
		glBegin(GL_POLYGON); //window 1_8
			glVertex2f(285,320.0);
			glVertex2f(295.0,320.0);
			glVertex2f(295.0,330.0);
			glVertex2f(285.0,330.0);
			glEnd();

			glColor3f(0.8,0.6,0.1);
			glBegin(GL_POLYGON);  // cone1
			glVertex2f(26,250);
			glVertex2f(52,250);
			glVertex2f(39,290);
			glEnd();
			semicircle(20.0,50,300);

			glColor3f(0.0,0.0 ,0.0);
	 		glBegin(GL_LINES);//wires1
			glVertex2f(37,313);
			glVertex2f(62,310);
			glVertex2f(63,287);
			glVertex2f(62,310);
			glEnd();
                 
	            glColor3f(1.0,1.0 ,1.0);
			glBegin(GL_POINTS);//road points
			glVertex2f(497,56);
			glVertex2f(479,74);
			glVertex2f(460,92);
			glVertex2f(439,110);
			glVertex2f(418,128);
			glVertex2f(398,146);
			glVertex2f(378,164);
			glVertex2f(356,182);
			glVertex2f(336,200);
			glVertex2f(314,218);
			glVertex2f(294,234);
	        	glVertex2f(278,248);
			glEnd();
}

void exhaust(){
		glColor3f(1.0,0.5,0.0);
		glBegin(GL_POLYGON);//1_exhaust
		glVertex2f(237,20.0);
		glVertex2f(244,20.0);
		glVertex2f(241,0.0);
		glEnd();

		glBegin(GL_POLYGON);//2_exhaust
		glVertex2f(246,20.0);
		glVertex2f(253,20.0);
		glVertex2f(249,0.0);
		glEnd();

		glBegin(GL_POLYGON);//3_exhaust
		glVertex2f(262,20.0);
		glVertex2f(255,20.0);
		glVertex2f(258,0.0);
		glEnd();
}

void holder(){
		glColor3f(0.5,0.0,0.0);
		glBegin(GL_POLYGON);//left_stand_holder
		glVertex2f(182,85.0);
		glVertex2f(182,0.0);
		glVertex2f(187,0.0);
		glVertex2f(187,80.0);
		glVertex2f(237,80.0);
		glVertex2f(237,85.0);
		glVertex2f(182,85.0);
		glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(312,85.0);//right_stand_holder
		glVertex2f(312,0.0);
		glVertex2f(307,0.0);
		glVertex2f(307,80.0);
		glVertex2f(262,80.0);
		glVertex2f(262,85.0);
		glVertex2f(312,85.0);
		glEnd();
}

void rocket_body_1_slant(){
		glColor3f(1.0,0.0,0.0);//cone
		glBegin(GL_POLYGON);
		glVertex2f(237.5+(i/2),120.0+i);
		glVertex2f(262.5+(i/2),120.0+i);
		glVertex2f(250+(i/2),170.0+i);
		glEnd();
}
void rocket_body_1(){
		glColor3f(1.0,0.0,0.0);//cone
		glBegin(GL_POLYGON);
		glVertex2f(237.5,120.0);
		glVertex2f(262.5,120.0);
		glVertex2f(250,170.0);
		glEnd();
}

void rocket_body_1_motion(){
		glColor3f(1.0,0.0,0.0);//cone
		glBegin(GL_POLYGON);
		glVertex2f(237.5,120.0+i);
		glVertex2f(262.5,120.0+i);
		glVertex2f(250,170.0+i);
		glEnd();
}

void rocket_body_2_slant(){   
	        glColor3f(0.5,0.0,0.5);
		glBegin(GL_POLYGON);//middlecore_1
		glVertex2f(237.5+(i/2),70.0+i);
		glVertex2f(262.5+(i/2),70.0+i);
		glVertex2f(262.5+(i/2),120.0+i);
		glVertex2f(237.5+(i/2),120.0+i);
		glEnd();
	glColor3f(1.0,1.0,1.0);
		glBegin(GL_POLYGON);//left_top
		glVertex2f(237.5+(i/2),120.0+i);
		glVertex2f(217.5+(i/2),95.0+i);
		glVertex2f(237.5+(i/2),95.0+i);
		glEnd();
	glBegin(GL_POLYGON);//right_top
		glVertex2f(262.5+(i/2),120.0+i);
		glVertex2f(262.5+(i/2),95.0+i);
		glVertex2f(282.5+(i/2),95.0+i);
		glEnd();
}

void rocket_body_2_motion(){   
		glColor3f(0.5,0.0,0.5);
		glBegin(GL_POLYGON);//middlecore_1
		glVertex2f(237.5,70.0+i);
		glVertex2f(262.5,70.0+i);
		glVertex2f(262.5,120.0+i);
		glVertex2f(237.5,120.0+i);
		glEnd();
	glColor3f(1.0,1.0,1.0);
		glBegin(GL_POLYGON);//left_top
		glVertex2f(237.5,120.0+i);
		glVertex2f(217.5,95.0+i);
		glVertex2f(237.5,95.0+i);
		glEnd();
	glBegin(GL_POLYGON);//right_top
		glVertex2f(262.5,120.0+i);
		glVertex2f(262.5,95.0+i);
		glVertex2f(282.5,95.0+i);
		glEnd();
}

void rocket_body_2(){   
		glColor3f(0.5,0.0,0.5);
		glBegin(GL_POLYGON);//middlecore_1
		glVertex2f(237.5,70.0);
		glVertex2f(262.5,70.0);
		glVertex2f(262.5,120.0);
		glVertex2f(237.5,120.0);
		glEnd();
	
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_POLYGON);//left_top
		glVertex2f(237.5,120.0);
		glVertex2f(217.5,95.0);
		glVertex2f(237.5,95.0);
		glEnd();

		glBegin(GL_POLYGON);//right_top
		glVertex2f(262.5,120.0);
		glVertex2f(262.5,95.0);
		glVertex2f(282.5,95.0);
		glEnd();
}
 
void rocket_body_3_slant(){  
		glColor3f(0.5,0.0,0.5);
		glBegin(GL_POLYGON);//middlecore_2
		glVertex2f(237.5+(i/2),20.0+i);
		glVertex2f(262.5+(i/2),20.0+i);
		glVertex2f(262.5+(i/2),70.0+i);
		glVertex2f(237.5+(i/2),70.0+i);
		glEnd();
                
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_POLYGON);//left_bottom
		glVertex2f(237.5+(i/2),20.0+i);
		glVertex2f(217.5+(i/2),20.0+i);
		glVertex2f(237.5+(i/2),70.0+i);
		glEnd();

		glBegin(GL_POLYGON);//right_bottom
		glVertex2f(262.5+(i/2),20.0+i);
		glVertex2f(282.5+(i/2),20.0+i);
		glVertex2f(262.5+(i/2),70.0+i);
		glEnd();
}

void rocket_body_3_motion(){  
		glColor3f(0.5,0.0,0.5);
		glBegin(GL_POLYGON);//middlecore_2
		glVertex2f(237.5,20.0+i);
		glVertex2f(262.5,20.0+i);
		glVertex2f(262.5,70.0+i);
		glVertex2f(237.5,70.0+i);
		glEnd();
               
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_POLYGON);//left_bottom
		glVertex2f(237.5,20.0+i);
		glVertex2f(217.5,20.0+i);
		glVertex2f(237.5,70.0+i);
		glEnd();

		glBegin(GL_POLYGON);//right_bottom
		glVertex2f(262.5,20.0+i);
		glVertex2f(282.5,20.0+i);
		glVertex2f(262.5,70.0+i);
		glEnd();
}

void rocket_body_3(){  
		glColor3f(0.5,0.0,0.5);
		glBegin(GL_POLYGON);//middlecore_2
		glVertex2f(237.5,20.0);
		glVertex2f(262.5,20.0);
		glVertex2f(262.5,70.0);
		glVertex2f(237.5,70.0);
		glEnd();
               
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_POLYGON);//left_bottom
		glVertex2f(237.5,20.0);
		glVertex2f(217.5,20.0);
		glVertex2f(237.5,70.0);
		glEnd();

		glBegin(GL_POLYGON);//right_bottom
		glVertex2f(262.5,20.0);
		glVertex2f(282.5,20.0);
		glVertex2f(262.5,70.0);
		glEnd();
}

void fume_slant(){
		if((p%2)==0)
			 glColor3f(1.0,0.25,0.0);
		else
		    glColor3f(1.0,0.8,0.0);
		    glBegin(GL_POLYGON);//fume points are from left to right side.
		    glVertex2f(237+(i/2),20+i);//1
		    glVertex2f(217+(i/2),0+i);//2
		    glVertex2f(250+(i/2),-40+i);//3
		    glVertex2f(282+(i/2),0+i);//4
		    glVertex2f(262+(i/2),20+i);//5
		    glEnd();
		    p=p+1;
}

void fume(){

		if((p%2)==0)
			 glColor3f(1.0,0.25,0.0);
		else
		    glColor3f(1.0,0.8,0.0);
		    glBegin(GL_POLYGON);//fume points are from left to right side.
		        glVertex2f(237,20+i);//1
			glVertex2f(217,0+i);//2
			glVertex2f(250,-40+i);//3
			glVertex2f(282,0+i);//4
			glVertex2f(262,20+i);//5
			glEnd();
			p=p+1;
}

void static_rocket(){        
		background();
		rocket_body_1();
		rocket_body_2();
		rocket_body_3();
		exhaust();
		holder();
		for(j=0;j<=1000000;j++)
			;
		glutSwapBuffers();
		glutPostRedisplay();
		glFlush();
}

void rocket_transition(){
		for(i=0;i<=320;i++)
		{  
		background();
		holder();
		rocket_body_1_motion();
		rocket_body_2_motion();
		rocket_body_3_motion();
		fume();
			for(k=0;k<=1000000;k++)
				;
			glutSwapBuffers();
			glutPostRedisplay();
		}
}

void rocket_motion(){ 
		for(i=0;i<=320;i++)
		{
			glClearColor(0.0 ,0.75,1.0,1.0);
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		        rocket_body_1_slant();
			rocket_body_2_slant();
			rocket_body_3_slant();
			fume_slant();
			for(j=0;j<=1000000;j++)
				;
			glutSwapBuffers();
			glutPostRedisplay();	
		}
}

void rocket_motion_2_1(){
	        count++;
	        count2++;
		for(i=195;i<=200;i++)
		{
			 star_loop();
			 if((count>=20)|(count2>=20))
			 mars(20.0);
			 rocket_body_1_motion();
			 rocket_body_2_motion();
			 rocket_body_3_motion();	
				fume();
			for(j=0;j<=10000000;j++)
				;
			glutSwapBuffers();
			glutPostRedisplay();
			glFlush();
		}
}

void fumeoff(){
		count2++;
		for(i=195;i<=200;i++)
		{
			 star_loop();
			 glColor3f(1.0f,1.0f,1.0f);
			 glRasterPos2f(120,470);
			 glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"Booster Off stage");
			 rocket_body_1_motion();
			 rocket_body_2_motion();
			 rocket_body_3_motion();
			for(j=0;j<=10000000;j++)
				;
			glutSwapBuffers();
			glutPostRedisplay();
			glFlush();
		}
}

void booster_separation(){  
		for(i=195;i<=200;i++)
		{
			 star_loop();
			 rocket_body_1_motion();
			 rocket_body_2_motion();	   
		  	 glColor3f(1.0f,1.0f,1.0f);
			   glRasterPos2f(120,470);
			 glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"Booster Seperation stage");
			 
			glColor3f(0.5,0.0,0.5);
			glBegin(GL_POLYGON);//middlecore_2
			glVertex2f(237.5,20.0+i-50);
			glVertex2f(262.5,20.0+i-50);
			glVertex2f(262.5,70.0+i-50);
			glVertex2f(237.5,70.0+i-50);
			glEnd();
				
		   	glColor3f(1.0,1.0,1.0);
			glBegin(GL_POLYGON);//left_bottom
			glVertex2f(237.5,20.0+i-50);
			glVertex2f(217.5,20.0+i-50);
			glVertex2f(237.5,70.0+i-50);
			glEnd();

			glBegin(GL_POLYGON);//right_bottom
			glVertex2f(262.5,20.0+i-50);
			glVertex2f(282.5,20.0+i-50);
			glVertex2f(262.5,70.0+i-50);
			glEnd();

			for(j=0;j<=10000000;j++)
					;
			glutSwapBuffers();
			glutPostRedisplay();
			glFlush();
		}
}

void booster_remove()
{

		for(i=195;i<=200;i++)
		{
			 star_loop();
			 rocket_body_1_motion();
			 rocket_body_2_motion();
		         glColor3f(1.0f,1.0f,1.0f);
			 glRasterPos2f(120,470);
			 glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"booster is removed");


			for(j=0;j<=10000000;j++)
					;
			glutSwapBuffers();
			glutPostRedisplay();
			glFlush();
		}
} 

void dismantle()
{
		for(i=195;i<=200;i++)
		{
			star_loop();
			glColor3f(1.0f,1.0f,1.0f);
			glRasterPos2f(120,470);
			glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"Dismantling stage");

			rocket_body_1_motion();		
			glColor3f(0.5,0.0,0.5);
			glBegin(GL_POLYGON);//middlecore_1
			glVertex2f(237.5,70.0+i-50);
			glVertex2f(262.5,70.0+i-50);
			glVertex2f(262.5,120.0+i-50);
			glVertex2f(237.5,120.0+i-50);
 			glEnd();
	
			glColor3f(1.0,1.0,1.0);
			glBegin(GL_POLYGON);//left_top
			glVertex2f(237.5,120.0+i-50);
			glVertex2f(217.5,95.0+i-50);
			glVertex2f(237.5,95.0+i-50);
			glEnd();

			glBegin(GL_POLYGON);//right_top
			glVertex2f(262.5,120.0+i-50);
			glVertex2f(262.5,95.0+i-50);
			glVertex2f(282.5,95.0+i-50);
			glEnd();

			for(j=0;j<=10000000;j++)
					;
			glutSwapBuffers();
			glutPostRedisplay();
			glFlush();
		}
}

void remove(){
		for(i=195;i<=200;i++)
		{
			 star_loop();
 			 glColor3f(1.0f,1.0f,1.0f);
			 glRasterPos2f(120,470);
			 glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"Dismantling completed");
			 rocket_body_1_motion();     	
			for(j=0;j<=10000000;j++)
					;
			glutSwapBuffers();
			glutPostRedisplay();
			glFlush();
		}
}

void rocket_motion_2_2()
{
                count++;
		for(i=195;i<=200;i++)
		{
			 star_loop();

			 if(count>=5 && count<=15){
			 fumeoff();
			 }

			 else if(count>15&&count<=20){
			 booster_separation();
		        }
	 
			else if(count>20 && count<=25){
			booster_remove();
			     }

			else if (count>25 && count<=30)	{
			 dismantle();
			}

			 else if (count>30 && count<=35){
			 remove();
			 }

			 else if (count>35){
			glColor3f(1.0f,1.0f,1.0f);
			 glRasterPos2f(250,250);
			 display();
			 }
		
			for(j=0;j<=10000000;j++)
				;
			glutSwapBuffers();
			glutPostRedisplay();
			glFlush();
		}
}

void mars(float radius)
{
	   	glBegin(GL_POLYGON);

	   	for (int i=0; i<=359; i++)
	   	{
		      float degInRad = i*DEG2RAD;
		      glVertex2f(300+f+cos(degInRad)*radius,500-t+(sin  		(degInRad))*radius);
	        }
		   glEnd();
		   t=t+0.1;
		   f=f+0.1;
}

void display_auto()
{
		 count1++;
		 if(count1<=660)
		       static_rocket();
		 else if((count1==661))
		       rocket_transition();
		 else if ((count1==662)| (count1==663))
		    rocket_motion();
		 else if (count1>=664&& count1<=670)
		    rocket_motion_2_1();
		 else if (count1>=670)
		    rocket_motion_2_2(); 
}

void manual()
{
		 count3++;
		 if((count3==1))
		       rocket_transition();
		 else if ((count3==2)| (count3==3))
		    rocket_motion();
		 else if (count3>=4)
		    rocket_motion_2_1(); 
}

void myinit()
{
		gluOrtho2D(0.0,499.0,0.0,499.0);
}

void keypress(unsigned char key,int x,int y)
{
		switch(key)
		  {
			    case 'a':
					glutDisplayFunc(display_auto);
					glutPostRedisplay(); 
					type=0;
					break;
			    case 'm':
					glutDisplayFunc(display_manual);
					glutPostRedisplay();
					s++;
					type=1; 
					break;
			    case 'n':
					if(type==1 && s==1)
					 { 
					glutDisplayFunc(static_rocket);
					glutPostRedisplay();
					s=2;
					 }
				         break;
			     case 't':
					 if(type==1 && s==2)
					 {
					    glutDisplayFunc(manual);
					    glutPostRedisplay();
					    s=3;
					 }
				         break;
			      case 'f':
				         if(type==1 && s==3){
				    	    glutDisplayFunc(fumeoff);
					    glutPostRedisplay();
						s=4;
					 }
					 break;
			      case 'b':
				        if(type==1 && s==4)
					 {
				        glutDisplayFunc(booster_separation);
					glutPostRedisplay();
					s=5;
					}
					break;
			      case 'r':
				       if(type==1 && s==5)
					 {
				        glutDisplayFunc(booster_remove);
					glutPostRedisplay();
					s=6;
					}
					break;
			     case 'd':
				        if(type==1 && s==6)
					 {
				    	glutDisplayFunc(dismantle);
					glutPostRedisplay();
					s=7;
					}
					break;
			    case 'R':
				        if(type==1 && s==7)
					 {
				    	glutDisplayFunc(remove);
					glutPostRedisplay();
					s=8;}
					break;	
			     default:
				       glutDisplayFunc(display);
				       glutPostRedisplay();
				       break;   
		  }
}

int main(int argc,char** argv)
{
		 glutInit(&argc,argv);
		 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
		 glutInitWindowSize(500,500);
		 glutInitWindowPosition(140,000);
		 glutCreateWindow("Graphics mini project on rocket launcher");
		 myinit();
		  glutFullScreen();
		 glutDisplayFunc(display);
		 glutKeyboardFunc(keypress);
		 glutMainLoop();
		 return 0;
}

