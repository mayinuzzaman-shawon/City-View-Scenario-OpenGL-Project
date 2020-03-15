#include<cstdio>
#include<windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>>

# define PI           3.14159265358979323846


void display_day();
void display_day_view(int val){

glutDisplayFunc(display_day);

}

void display_raining();
void display_night();

//for cloud forward moving in day
GLfloat position1 = 0.0f;
GLfloat speed1 = 0.1f;
void update1(int value) {
    if(position1 >1.0)
        position1 = -1.0f;
    position1 += speed1;
	glutPostRedisplay();
	glutTimerFunc(100, update1, 0);
}

//for cloud in raining
GLfloat position11 = 0.0f;
GLfloat speed11 = 0.1f;
void update11(int value) {
    if(position11 >1.0)
        position11 = -1.0f;
    position11 += speed11;
	glutPostRedisplay();
	glutTimerFunc(100, update11, 0);
}

//for cloud in night

GLfloat position21 = 0.0f;
GLfloat speed21 = 0.1f;
void update21(int value) {
    if(position21 >1.0)
        position21 = -1.0f;
    position21 += speed21;
	glutPostRedisplay();
	glutTimerFunc(100, update21, 0);
}

//for plane moving forward

GLfloat position2 = 0.0f;
GLfloat speed2 = 0.1f;
void update2(int value) {
    if(position2 >1.0)
        position2 = -1.0f;
    position2 += speed2;
	glutPostRedisplay();
	glutTimerFunc(100, update2, 0);
}

//for  pickup car moving forward

GLfloat position3 = 0.0f;
GLfloat speed3 = 0.1f;
void update3(int value) {
    if(position3 >1.0)
        position3 = -1.0f;
    position3 += speed3;
	glutPostRedisplay();
	glutTimerFunc(100, update3, 0);
}

//for private car moving left

GLfloat position4 = 0.0f;
GLfloat speed4 = 0.1f;
void update4(int value) {
    if(position4 <-1.0)
        position4 = 1.0f;
    position4 -= speed4;
	glutPostRedisplay();
	glutTimerFunc(100, update4, 0);
}

//for bus moving right

GLfloat position5 = 0.0f;
GLfloat speed5 = 0.1f;
void update5(int value) {
    if(position5 >1.0)
        position5 = -1.0f;
    position5 += speed5;
	glutPostRedisplay();
	glutTimerFunc(100, update5, 0);
}

//for boat moving right

GLfloat position6 = 0.0f;
GLfloat speed6 = 0.1f;
void update6(int value) {
    if(position6 >1.0)
        position6 = -1.0f;
    position6 += speed6;
	glutPostRedisplay();
	glutTimerFunc(100, update6, 0);
}


//for raining
GLfloat position7 = 0.0f;
GLfloat speed7 = 0.1f;
void update7(int value) {
    if(position7 <-1.0)
        position7 = 1.0f;
    position7 -= speed7;
	glutPostRedisplay();
	glutTimerFunc(100, update7, 0);
}

//for sun in day
GLfloat position8 = 0.0f;
GLfloat speed8 = 0.1f;
void update8(int value) {
    if(position8 >1.0)
        position8 = -1.0f;
    position8 += speed8;
	glutPostRedisplay();
	glutTimerFunc(100, update8, 0);
}

//for moon in night
GLfloat position9 = 0.0f;
GLfloat speed9 = 0.1f;
void update9(int value) {
    if(position9 <-1.0)
        position9 = 1.0f;
    position9 -= speed9;
	glutPostRedisplay();
	glutTimerFunc(100, update9, 0);
}

//for sun in rainy

GLfloat position10 = 0.0f;
GLfloat speed10 = 0.1f;
void update10(int value) {
    if(position10 >1.0)
        position10 = -1.0f;
    position10+= speed10;
	glutPostRedisplay();
	glutTimerFunc(100, update10, 0);
}

void init() {
   glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void display_night()
{


  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_LIGHTING);//Enable Light Effect

    GLfloat global_ambient[] = {0.0,0.0,2.0, 0.1};//ambient RGBA intensity of light
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);//A lighting model parameter.

   //sky

   glColor3f(0.20,.63,.87);
   glBegin(GL_QUADS);
   glVertex2f(-1.0f,1.0f);
   glVertex2f(1.0f,1.0f);
   glVertex2f(1.0f,0.5f);
   glVertex2f(-1.0f,0.5f);

   glEnd();
   glDisable(GL_LIGHTING);



   //sun
   glLoadIdentity();
   glPushMatrix();
   glTranslatef(0.0,position9, 0.0f);
   speed9 = 0.009f;
   glColor3f(1,1,1);
   int i1;

	GLfloat x1=.7f; GLfloat y1=.8f; GLfloat radius1 =.15f;

	int triangleAmount1 = 20; //# of triangles used to draw circle


	GLfloat twicePi1 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount1;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi1 / triangleAmount1)),
			    y1 + (radius1 * sin(i1 * twicePi1 / triangleAmount1))
			);
		}
	glEnd();



	//left cloud


    glLoadIdentity();
   glPushMatrix();
   glTranslatef(position21,0.0, 0.0f);
   speed21 = 0.02f;
	//cloud upper middle

	glColor3f(.65,.65,.65);
   int i2;

	GLfloat x2=-.65f; GLfloat y2=.9f; GLfloat radius2 =.08f;

	int triangleAmount2 = 20; //# of triangles used to draw circle


	GLfloat twicePi2 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2, y2); // center of circle
		for(i2 = 0; i2 <= triangleAmount2;i2++) {
			glVertex2f(
		            x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
			);
		}
	glEnd();



	//cloud left middle

	glColor3f(.65,.65,.65);
   int i3;

	GLfloat x3=-.75f; GLfloat y3=.85f; GLfloat radius3 =.08f;

	int triangleAmount3 = 20; //# of triangles used to draw circle


	GLfloat twicePi3 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3, y3); // center of circle
		for(i3 = 0; i3 <= triangleAmount3;i3++) {
			glVertex2f(
		            x3 + (radius3 * cos(i3 *  twicePi3 / triangleAmount3)),
			    y3 + (radius3 * sin(i3 * twicePi3 / triangleAmount3))
			);
		}
	glEnd();


	//cloud in right middle
   glColor3f(.65,.65,.65);
   int i4;

	GLfloat x4=-.55f; GLfloat y4=.85f; GLfloat radius4 =.08f;

	int triangleAmount4 = 20; //# of triangles used to draw circle


	GLfloat twicePi4 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x4, y4); // center of circle
		for(i4 = 0; i4 <= triangleAmount4;i4++) {
			glVertex2f(
		            x4 + (radius4 * cos(i4 *  twicePi4 / triangleAmount4)),
			    y4 + (radius4 * sin(i4 * twicePi4 / triangleAmount4))
			);
		}
	glEnd();



	//cloud in the lower right

	glColor3f(.65,.65,.65);
   int i5;

	GLfloat x5=-.6f; GLfloat y5=.8f; GLfloat radius5 =.08f;

	int triangleAmount5 = 20; //# of triangles used to draw circle


	GLfloat twicePi5 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x5, y5); // center of circle
		for(i5 = 0; i5 <= triangleAmount5;i5++) {
			glVertex2f(
		            x5 + (radius5 * cos(i5 *  twicePi5 / triangleAmount5)),
			    y5 + (radius5 * sin(i5 * twicePi5 / triangleAmount5))
			);
		}
	glEnd();



	//cloud in the lower left

	glColor3f(.65,.65,.65);
   int i6;

	GLfloat x6=-.7f; GLfloat y6=.8f; GLfloat radius6 =.08f;

	int triangleAmount6 = 20; //# of triangles used to draw circle


	GLfloat twicePi6 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x6, y6); // center of circle
		for(i6 = 0; i6 <= triangleAmount6;i6++) {
			glVertex2f(
		            x6 + (radius6 * cos(i6 *  twicePi6 / triangleAmount6)),
			    y6 + (radius6 * sin(i6 * twicePi6 / triangleAmount6))
			);
		}
	glEnd();
    glPopMatrix();


	//plane

	glLoadIdentity();
   glPushMatrix();
   glTranslatef(position2,0.0, 0.0f);
   speed2 = 0.1f;
    //body of plane

   glColor3f(1.0,.95,.71);
   glBegin(GL_QUADS);
   glVertex2f(-.35f,0.8f);
   glVertex2f(.1f,0.8f);
   glVertex2f(.1f,0.7f);
   glVertex2f(-.35f,0.7f);

   glEnd();

   //front of plane

   glColor3f(1,0,0);
   glBegin(GL_TRIANGLES);
   glVertex2f(.1f,0.8f);
   glVertex2f(.2f,0.75f);
   glVertex2f(.1f,0.7f);

   glEnd();


   //tail of plane

   glColor3f(1,0,0);
   glBegin(GL_QUADS);
   glVertex2f(-.35f,0.9f);
   glVertex2f(-.32f,0.9f);
   glVertex2f(-.25f,0.8f);
   glVertex2f(-.35f,0.8f);

   glEnd();


   //upper fan of plane

   glColor3f(1,0,0);
   glBegin(GL_QUADS);
   glVertex2f(-.05f,0.9f);
   glVertex2f(-.15f,0.9f);
   glVertex2f(-.1f,0.8f);
   glVertex2f(0.0f,0.8f);

   glEnd();


   //lower  fan of plane

   glColor3f(1,0,0);
   glBegin(GL_QUADS);
   glVertex2f(0.0f,0.72f);
   glVertex2f(-.05f,0.6f);
   glVertex2f(-.15f,0.6f);
   glVertex2f(-.1f,0.72f);

   glEnd();

   //window 1 from right

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(0.04f,0.73f);
   glVertex2f(.04f,0.78f);
   glVertex2f(-.04f,0.78f);
   glVertex2f(-.04f,0.73f);

   glEnd();


   //window 2 from right

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-0.08f,0.73f);
   glVertex2f(-.08f,0.78f);
   glVertex2f(-.16f,0.78f);
   glVertex2f(-.16f,0.73f);

   glEnd();

   //window 3 from right

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-0.20f,0.73f);
   glVertex2f(-.20f,0.78f);
   glVertex2f(-.28f,0.78f);
   glVertex2f(-.28f,0.73f);

   glEnd();
   glPopMatrix();

   //road behind skyscraper 1,2,3,4

   //glColor3f(0.77,0.77,0.77);
   glColor3f(0.40,0.40,0.40);
   glBegin(GL_QUADS);
   glVertex2f(-1.0f,0.5f);
   glVertex2f(1.0f,0.5f);
   glVertex2f(1.0f,0.1f);
   glVertex2f(-1.0f,0.1f);

   glEnd();

  //leftmost left line of road behind skyscraper 1,2,3,4

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-1.0f,.3f);
   glVertex2f(-.7f,.3f);
   glVertex2f(-.7f,.35f);
   glVertex2f(-1.f,.35f);

   glEnd();


   //rightmost left line of road behind skyscraper 1,2,3,4

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.55f,.3f);
   glVertex2f(-.25f,.3f);
   glVertex2f(-.25f,.35f);
   glVertex2f(-.55f,.35f);

   glEnd();

   //middle line of road behind skyscraper 1,2,3,4

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.05f,.3f);
   glVertex2f(.3f,.3f);
   glVertex2f(.3f,.35f);
   glVertex2f(-.05f,.35f);

   glEnd();


   //right line of road behind skyscraper 1,2,3,4

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(.6f,.3f);
   glVertex2f(1.0f,.3f);
   glVertex2f(1.0f,.35f);
   glVertex2f(.6f,.35f);

   glEnd();


   //car behind skyscraper 1,2,3,4

   glLoadIdentity();
   glPushMatrix();
   glTranslatef(position3,0.0, 0.0f);
   speed3 = 0.15f;
   //main body
   glColor3f(.38,0.20,0.07);
   glBegin(GL_QUADS);
   glVertex2f(-0.3f,0.45f);
   glVertex2f(.05f,0.45f);
   glVertex2f(.05f,0.25f);
   glVertex2f(-.3f,0.25f);

   glEnd();


   //window 1

   glColor3f(.40,.56,.53);

   glBegin(GL_QUADS);
   glVertex2f(0.01f,0.385f);
   glVertex2f(-.1f,0.385f);
   glVertex2f(-.1f,0.31f);
   glVertex2f(.01f,0.31f);

   glEnd();


   //window 2

   glColor3f(.40,.56,.53);
   glBegin(GL_QUADS);
   glVertex2f(-0.25f,0.385f);
   glVertex2f(-.14f,0.385f);
   glVertex2f(-.14f,0.31f);
   glVertex2f(-.25f,0.31f);

   glEnd();


   //backwheel outer

   glColor3f(0,0,0);
   int i9;

	GLfloat x9=-.2f; GLfloat y9=.22f; GLfloat radius9 =.062f;

	int triangleAmount9 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi9 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x9, y9); // center of circle
		for(i9 = 0; i9<= triangleAmount9;i9++) {
			glVertex2f(
		            x9 + (radius9 * cos(i9 *  twicePi9 / triangleAmount9)),
			    y9 + (radius9 * sin(i9 * twicePi9 / triangleAmount9))
			);
		}
	glEnd();



	//backwheel inner

   glColor3f(1,1,1);
   int i11;

	GLfloat x11=-.2f; GLfloat y11=.22f; GLfloat radius11 =.045f;

	int triangleAmount11 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi11 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x11, y11); // center of circle
		for(i11 = 0; i11<= triangleAmount11;i11++) {
			glVertex2f(
		            x11 + (radius11 * cos(i11 *  twicePi11 / triangleAmount11)),
			    y11 + (radius11 * sin(i11 * twicePi11/ triangleAmount11))
			);
		}
	glEnd();




   //front part
   glColor3f(0.62,0.02,0.03);

   glBegin(GL_QUADS);
   glVertex2f(0.05f,0.45f);
   glVertex2f(.25f,0.4f);
   glVertex2f(.25f,0.25f);
   glVertex2f(.05f,0.25f);

   glEnd();


   //window
   glColor3f(.40,.56,.53);

   glBegin(GL_QUADS);
   glVertex2f(0.1f,0.385f);
   glVertex2f(.2f,0.385f);
   glVertex2f(.2f,0.31f);
   glVertex2f(.1f,0.31f);

   glEnd();


   //front wheel outer

	glColor3f(0,0,0);
   int i10;

	GLfloat x10=.15f; GLfloat y10=.22f; GLfloat radius10 =.062f;

	int triangleAmount10 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi10 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x10, y10); // center of circle
		for(i10 = 0; i10<= triangleAmount10;i10++) {
			glVertex2f(
		            x10 + (radius10 * cos(i10 *  twicePi10 / triangleAmount10)),
			    y10 + (radius10 * sin(i10 * twicePi10 / triangleAmount10))
			);
		}
	glEnd();




   //front wheel inner

	glColor3f(1,1,1);
   int i12;

	GLfloat x12=.15f; GLfloat y12=.22f; GLfloat radius12 =.045f;

	int triangleAmount12 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi12 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x12, y12); // center of circle
		for(i12 = 0; i12<= triangleAmount12;i12++) {
			glVertex2f(
		            x12 + (radius12 * cos(i12 *  twicePi12 / triangleAmount12)),
			    y12 + (radius12 * sin(i12 * twicePi12 / triangleAmount12))
			);
		}
	glEnd();
    glPopMatrix();

   //skycraper 1

   glColor3f(.56,0.74,.56);
   glBegin(GL_QUADS);
   glVertex2f(-0.95f,0.55f);
   glVertex2f(-.65f,0.55f);
   glVertex2f(-.65f,0.1f);
   glVertex2f(-.95f,0.1f);

   glEnd();


   //window 1 from upper left

   glColor3f(1,1,0);
   glBegin(GL_QUADS);
   glVertex2f(-0.9f,0.5f);
   glVertex2f(-.82f,0.5f);
   glVertex2f(-.82f,0.42f);
   glVertex2f(-.9f,0.42f);

   glEnd();


   //window 2
   glColor3f(1,1,0);
   glBegin(GL_QUADS);
   glVertex2f(-0.77f,0.5f);
   glVertex2f(-.69f,0.5f);
   glVertex2f(-.69f,0.42f);
   glVertex2f(-.77f,0.42f);

   glEnd();


   //window 3

   glColor3f(1,1,0);
   glBegin(GL_QUADS);
   glVertex2f(-0.9f,0.37f);
   glVertex2f(-.82f,0.37f);
   glVertex2f(-.82f,0.29f);
   glVertex2f(-.9f,0.29f);

   glEnd();


   //window 4

   glColor3f(1,1,0);
   glBegin(GL_QUADS);
   glVertex2f(-0.77f,0.37f);
   glVertex2f(-.69f,0.37f);
   glVertex2f(-.69f,0.29f);
   glVertex2f(-.77f,0.29f);

   glEnd();


   //window 5

   glColor3f(1,1,0);
   glBegin(GL_QUADS);
   glVertex2f(-0.9f,0.24f);
   glVertex2f(-.82f,0.24f);
   glVertex2f(-.82f,0.16f);
   glVertex2f(-.9f,0.16f);

   glEnd();


   //window 6

   glColor3f(1,1,0);
   glBegin(GL_QUADS);
   glVertex2f(-0.77f,0.24f);
   glVertex2f(-.69f,0.24f);
   glVertex2f(-.69f,0.16f);
   glVertex2f(-.77f,0.16f);

   glEnd();

   //tree beside skyscraper 1

   //lower part
   glColor3f(0.32,.48,0.35);
   glBegin(GL_TRIANGLES);
   glVertex2f(-.63f,0.25f);
   glVertex2f(-.57f,0.38f);
   glVertex2f(-.51f,0.25f);

   glEnd();


   //upper part
   glColor3f(0.47,.67,0.27);
   glBegin(GL_TRIANGLES);
   glVertex2f(-.62f,0.32f);
   glVertex2f(-.57f,0.55f);
   glVertex2f(-.52f,0.32f);

   glEnd();


   //log of tree

   glColor3f(.42,0.26,0.15);
   glBegin(GL_QUADS);
   glVertex2f(-.55f,.25f);
   glVertex2f(-.59f,.25f);
   glVertex2f(-.59f,.1f);
   glVertex2f(-.55f,.1f);

   glEnd();


   //skyscraper 2

   glColor3f(0.55,0.37,0.40);
   glBegin(GL_QUADS);
   glVertex2f(-.48f,.42f);
   glVertex2f(-.18f,.42f);
   glVertex2f(-.18f,.1f);
   glVertex2f(-.48f,.1f);

   glEnd();


   //window 1 from upper left

    glColor3f(1,1,0);
   glBegin(GL_QUADS);
   glVertex2f(-0.43f,0.37f);
   glVertex2f(-.35f,0.37f);
   glVertex2f(-.35f,0.29f);
   glVertex2f(-.43f,0.29f);

   glEnd();


   //window 2

   glColor3f(1,1,0);
   glBegin(GL_QUADS);
   glVertex2f(-0.3f,0.37f);
   glVertex2f(-.22f,0.37f);
   glVertex2f(-.22f,0.29f);
   glVertex2f(-.3f,0.29f);

   glEnd();


   //window 3

    glColor3f(1,1,0);
   glBegin(GL_QUADS);
   glVertex2f(-0.43f,0.24f);
   glVertex2f(-.35f,0.24f);
   glVertex2f(-.35f,0.16f);
   glVertex2f(-.43f,0.16f);

   glEnd();


   //window 4

   glColor3f(1,1,0);
   glBegin(GL_QUADS);
   glVertex2f(-0.3f,0.24f);
   glVertex2f(-.22f,0.24f);
   glVertex2f(-.22f,0.16f);
   glVertex2f(-.3f,0.16f);

   glEnd();


   //roadside lamp beside skyscraper 2

   glColor3f(.96,0.97,.46);
   int i7;

	GLfloat x7=-.1f; GLfloat y7=.33f; GLfloat radius7 =.06f;

	int triangleAmount7 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi7 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x7, y7); // center of circle
		for(i7 = 0; i7 <= triangleAmount7;i7++) {
			glVertex2f(
		            x7 + (radius7 * cos(i7 *  twicePi7 / triangleAmount7)),
			    y7 + (radius7 * sin(i7 * twicePi7 / triangleAmount7))
			);
		}
	glEnd();



	//stand of lamp

	glColor3f(.3,.3,.3);
	glBegin(GL_QUADS);
   glVertex2f(-0.09f,0.275f);
   glVertex2f(-.11f,0.275f);
   glVertex2f(-.11f,0.1f);
   glVertex2f(-.09f,0.1f);

   glEnd();


   //skyscraper 3

   glColor3f(.82,.57,.46);
   glBegin(GL_QUADS);
   glVertex2f(-0.02f,0.55f);
   glVertex2f(.38f,0.55f);
   glVertex2f(.38f,0.1f);
   glVertex2f(-0.02f,0.1f);

   glEnd();


   //window 1 from upper left

   glColor3f(1,1,0);
   glBegin(GL_QUADS);
   glVertex2f(0.02f,0.5f);
   glVertex2f(.1f,0.5f);
   glVertex2f(.1f,0.42f);
   glVertex2f(.02f,0.42f);

   glEnd();


   //window 2

   glColor3f(1,1,0);
   glBegin(GL_QUADS);
   glVertex2f(0.14f,0.5f);
   glVertex2f(.22f,0.5f);
   glVertex2f(.22f,0.42f);
   glVertex2f(.14f,0.42f);

   glEnd();


   //window 3

   glColor3f(1,1,0);
   glBegin(GL_QUADS);
   glVertex2f(0.26f,0.5f);
   glVertex2f(.34f,0.5f);
   glVertex2f(.34f,0.42f);
   glVertex2f(.26f,0.42f);

   glEnd();

   //window 4

   glColor3f(1,1,0);
   glBegin(GL_QUADS);
   glVertex2f(0.02f,0.37f);
   glVertex2f(.1f,0.37f);
   glVertex2f(.1f,0.29f);
   glVertex2f(.02f,0.29f);

   glEnd();


   //window 5

   glColor3f(1,1,0);
   glBegin(GL_QUADS);
   glVertex2f(0.14f,0.37f);
   glVertex2f(.22f,0.37f);
   glVertex2f(.22f,0.29f);
   glVertex2f(.14f,0.29f);

   glEnd();


   //window 6

   glColor3f(1,1,0);
   glBegin(GL_QUADS);
   glVertex2f(0.26f,0.37f);
   glVertex2f(.34f,0.37f);
   glVertex2f(.34f,0.29f);
   glVertex2f(.26f,0.29f);

   glEnd();


   //window 7

    glColor3f(1,1,0);
   glBegin(GL_QUADS);
   glVertex2f(0.02f,0.24f);
   glVertex2f(.1f,0.24f);
   glVertex2f(.1f,0.16f);
   glVertex2f(.02f,0.16f);

   glEnd();

   //window 8

   glColor3f(1,1,0);
   glBegin(GL_QUADS);
   glVertex2f(0.14f,0.24f);
   glVertex2f(.22f,0.24f);
   glVertex2f(.22f,0.16f);
   glVertex2f(.14f,0.16f);

   glEnd();


   //window 9

   glColor3f(1,1,0);
   glBegin(GL_QUADS);
   glVertex2f(0.26f,0.24f);
   glVertex2f(.34f,0.24f);
   glVertex2f(.34f,0.16f);
   glVertex2f(.26f,0.16f);

   glEnd();


   //tree beside skyscraper 3


   //lower part
   glColor3f(0.32,.48,0.35);
   glBegin(GL_TRIANGLES);
   glVertex2f(.4f,0.25f);
   glVertex2f(.46f,0.38f);
   glVertex2f(.52f,0.25f);

   glEnd();


   //upper part
   glColor3f(0.47,.67,0.27);
   glBegin(GL_TRIANGLES);
   glVertex2f(.41f,0.32f);
   glVertex2f(.46f,0.55f);
   glVertex2f(.51f,0.32f);

   glEnd();


   //log of tree

   glColor3f(.42,0.26,0.15);
   glBegin(GL_QUADS);
   glVertex2f(.44f,.25f);
   glVertex2f(.48f,.25f);
   glVertex2f(.48f,.1f);
   glVertex2f(.44f,.1f);

   glEnd();



   //skyscraper 4

   glColor3f(0.40,0.0,0.0);
   glBegin(GL_QUADS);
   glVertex2f(.54f,.42f);
   glVertex2f(.84f,.42f);
   glVertex2f(.84f,.1f);
   glVertex2f(.54f,.1f);

   glEnd();

   //window 1 from upper left

   glColor3f(1,1,0);
   glBegin(GL_QUADS);
   glVertex2f(0.59f,0.37f);
   glVertex2f(.67f,0.37f);
   glVertex2f(.67f,0.29f);
   glVertex2f(.59f,0.29f);

   glEnd();


   //window 2

   glColor3f(1,1,0);
   glBegin(GL_QUADS);
   glVertex2f(0.72f,0.37f);
   glVertex2f(.8f,0.37f);
   glVertex2f(.8f,0.29f);
   glVertex2f(.72f,0.29f);

   glEnd();

   //window 3

   glColor3f(1,1,0);
   glBegin(GL_QUADS);
   glVertex2f(0.59f,0.24f);
   glVertex2f(.67f,0.24f);
   glVertex2f(.67f,0.16f);
   glVertex2f(.59f,0.16f);

   glEnd();


   //window 4

   glColor3f(1,1,0);
   glBegin(GL_QUADS);
   glVertex2f(0.72f,0.24f);
   glVertex2f(.8f,0.24f);
   glVertex2f(.8f,0.16f);
   glVertex2f(.72f,0.16f);

   glEnd();


   //roadside lamp beside skyscraper 4

    glColor3f(.96,0.97,.46);
   int i8;

	GLfloat x8=.92f; GLfloat y8=.33f; GLfloat radius8 =.06f;

	int triangleAmount8 = 20; //# of triangles used to draw circle


	GLfloat twicePi8 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x8, y8); // center of circle
		for(i8 = 0; i8 <= triangleAmount8;i8++) {
			glVertex2f(
		            x8 + (radius8 * cos(i8 *  twicePi8 / triangleAmount8)),
			    y8 + (radius8 * sin(i8 * twicePi8 / triangleAmount8))
			);
		}
	glEnd();



	//stand of lamp

	glColor3f(.3,.3,.3);
	glBegin(GL_QUADS);
   glVertex2f(0.91f,0.275f);
   glVertex2f(.93f,0.275f);
   glVertex2f(.93f,0.1f);
   glVertex2f(.91f,0.1f);

   glEnd();


   //footpath in front of skyscraper 1,2,3,4

   glColor3f(.3,.3,.3);
   glBegin(GL_QUADS);
   glVertex2f(-1.0f,0.1f);
   glVertex2f(1.0f,0.1f);
   glVertex2f(1.0f,0.05f);
   glVertex2f(-1.0f,0.05f);

   glEnd();



   //road behind school and park

   glColor3f(0.40,0.40,0.40);
   glBegin(GL_QUADS);
   glVertex2f(-1.0f,0.05f);
   glVertex2f(1.0f,0.05f);
   glVertex2f(1.0f,-1.0f);
   glVertex2f(-1.0f,-1.0f);

   glEnd();


   //lake

   glColor3f(0,0.25,0.53);
   glBegin(GL_QUADS);
   glVertex2f(-1.0f,-0.7f);
   glVertex2f(1.0f,-0.7f);
   glVertex2f(1.f,-1.0f);
   glVertex2f(-1.0f,-1.0f);

   glEnd();


   //boat in the lake

    glLoadIdentity();
   glPushMatrix();
   glTranslatef(position6,0.0, 0.0f);
   speed6 = 0.07f;
   //lower deck

   glColor3f(0.4,0.0,0.0);
   glBegin(GL_QUADS);
   glVertex2f(.0f,-.85f);
   glVertex2f(-.5f,-.85f);
   glVertex2f(-.4f,-0.95f);
   glVertex2f(-.1f,-0.95f);


    glEnd();


   //upper deck

   glColor3f(1.0,.95,.71);
   glBegin(GL_QUADS);
   glVertex2f(-.1f,-.75f);
   glVertex2f(-.4f,-.75f);
   glVertex2f(-.4f,-0.85f);
   glVertex2f(-.1f,-0.85f);


    glEnd();


   //window 1 from left

    glColor3f(0.55,0.37,0.40);
    glBegin(GL_QUADS);
   glVertex2f(-.31f,-.77f);
   glVertex2f(-.37f,-.77f);
   glVertex2f(-.37f,-0.83f);
   glVertex2f(-.31f,-0.83f);


    glEnd();


   //window 2

   glColor3f(0.55,0.37,0.40);
    glBegin(GL_QUADS);
   glVertex2f(-.28f,-.77f);
   glVertex2f(-.22f,-.77f);
   glVertex2f(-.22f,-0.83f);
   glVertex2f(-.28f,-0.83f);


    glEnd();


   //window 3

   glColor3f(0.55,0.37,0.40);
   glBegin(GL_QUADS);
   glVertex2f(-.19f,-.77f);
   glVertex2f(-.13f,-.77f);
   glVertex2f(-.13f,-0.83f);
   glVertex2f(-.19f,-0.83f);


    glEnd();
    glPopMatrix();

   // footpath in front of school and park

   glColor3f(.3,.3,.3);
   glBegin(GL_QUADS);
   glVertex2f(-1.0f,-0.7f);
   glVertex2f(1.0f,-0.7f);
   glVertex2f(1.0f,-0.65f);
   glVertex2f(-1.0f,-.65f);

   glEnd();


   //leftmost left line of road behind school

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-1.0f,-.3f);
   glVertex2f(-.7f,-.3f);
   glVertex2f(-.7f,-.35f);
   glVertex2f(-1.f,-.35f);

   glEnd();


   //rightmost left line of road

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.55f,-.3f);
   glVertex2f(-.25f,-.3f);
   glVertex2f(-.25f,-.35f);
   glVertex2f(-.55f,-.35f);

   glEnd();

   //middle line of road behind school

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.0f,-.3f);
   glVertex2f(.3f,-.3f);
   glVertex2f(.3f,-.35f);
   glVertex2f(-.0f,-.35f);

   glEnd();


   //right line of road behind school

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(.6f,-.3f);
   glVertex2f(1.0f,-.3f);
   glVertex2f(1.0f,-.35f);
   glVertex2f(.6f,-.35f);

   glEnd();


   //car in road behind school
   glLoadIdentity();
   glPushMatrix();
   glTranslatef(position4,0.0, 0.0f);
   speed4 = 0.15f;
   //lower body of car

   glColor3f(1,0,0);
   glBegin(GL_QUADS);
   glVertex2f(-.1f,-.08f);
   glVertex2f(.4f,-.08f);
   glVertex2f(.4f,-.2f);
   glVertex2f(-.1f,-.2f);

   glEnd();


   //upper body of car

   glColor3f(1,0,0);
   glBegin(GL_QUADS);
   glVertex2f(.05f,.02f);
   glVertex2f(.25f,.02f);
   glVertex2f(.33f,-.08f);
   glVertex2f(-.03f,-.08f);

   glEnd();


   //left window

   glColor3f(.98,.93,.36);
   glBegin(GL_QUADS);
   glVertex2f(.06f,-.0f);
   glVertex2f(.14f,-.0f);
   glVertex2f(.14f,-.08f);
   glVertex2f(.01f,-.08f);

   glEnd();


   //right window

   glColor3f(.98,.93,.36);
   glBegin(GL_QUADS);
   glVertex2f(.16f,-.0f);
   glVertex2f(.24f,-.0f);
   glVertex2f(.29f,-.08f);
   glVertex2f(.16f,-.08f);

   glEnd();


   //front wheel outer

    glColor3f(0,0,0);
   int i17;

	GLfloat x17=.0f; GLfloat y17=-.2f; GLfloat radius17 =.06f;

	int triangleAmount17 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi17 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x17, y17); // center of circle
		for(i17 = 0; i17 <= triangleAmount17;i17++) {
			glVertex2f(
		            x17 + (radius17 * cos(i17 *  twicePi17 / triangleAmount17)),
			    y17 + (radius17 * sin(i17 * twicePi17 / triangleAmount17))
			);
		}
	glEnd();



	//front wheel inner

	glColor3f(1,1,1);
   int i18;

	GLfloat x18=.0f; GLfloat y18=-.2f; GLfloat radius18 =.04f;

	int triangleAmount18 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi18 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x18, y18); // center of circle
		for(i18 = 0; i18 <= triangleAmount18;i18++) {
			glVertex2f(
		            x18 + (radius18 * cos(i18 *  twicePi18 / triangleAmount18)),
			    y18 + (radius18 * sin(i18 * twicePi18 / triangleAmount18))
			);
		}
	glEnd();



	//back wheel outer

	glColor3f(0,0,0);
   int i19;

	GLfloat x19=.3f; GLfloat y19=-.2f; GLfloat radius19 =.06f;

	int triangleAmount19 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi19 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x19, y19); // center of circle
		for(i19 = 0; i19 <= triangleAmount19;i19++) {
			glVertex2f(
		            x19 + (radius19 * cos(i19 *  twicePi19 / triangleAmount19)),
			    y19 + (radius19 * sin(i19 * twicePi19 / triangleAmount19))
			);
		}
	glEnd();



	//back wheel inner

	glColor3f(1,1,1);
   int i20;

	GLfloat x20=.3f; GLfloat y20=-.2f; GLfloat radius20 =.04f;

	int triangleAmount20 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi20 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x20, y20); // center of circle
		for(i20 = 0; i20 <= triangleAmount20;i20++) {
			glVertex2f(
		            x20 + (radius20 * cos(i20 *  twicePi20 / triangleAmount20)),
			    y20 + (radius20 * sin(i20 * twicePi20 / triangleAmount20))
			);
		}
	glEnd();
    glPopMatrix();



	//bus

	glLoadIdentity();
   glPushMatrix();
   glTranslatef(position5,0.0, 0.0f);
   speed5 = 0.15f;
	//main body

	glColor3f(.47,0.63,0.53);
   glBegin(GL_QUADS);
   glVertex2f(-.7f,-.38f);
   glVertex2f(-.1f,-.38f);
   glVertex2f(-.1f,-.58f);
   glVertex2f(-.7f,-.58f);

   glEnd();


   //back wheel outer

   glColor3f(0,0,0);
   int i21;

	GLfloat x21=-.6f; GLfloat y21=-.58f; GLfloat radius21 =.06f;

	int triangleAmount21 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi21 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x21, y21); // center of circle
		for(i21 = 0; i21 <= triangleAmount21;i21++) {
			glVertex2f(
		            x21 + (radius21 * cos(i21 *  twicePi21 / triangleAmount21)),
			    y21 + (radius21 * sin(i21 * twicePi21 / triangleAmount21))
			);
		}
	glEnd();



	//back wheel inner

	glColor3f(1,1,1);
   int i22;

	GLfloat x22=-.6f; GLfloat y22=-.58f; GLfloat radius22 =.04f;

	int triangleAmount22 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi22 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x22, y22); // center of circle
		for(i22 = 0; i22 <= triangleAmount21;i22++) {
			glVertex2f(
		            x22 + (radius22 * cos(i22 *  twicePi22 / triangleAmount22)),
			    y22 + (radius22 * sin(i22 * twicePi22 / triangleAmount22))
			);
		}
	glEnd();



	//front wheel outer

	glColor3f(0,0,0);
   int i23;

	GLfloat x23=-.2f; GLfloat y23=-.58f; GLfloat radius23 =.06f;

	int triangleAmount23 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi23 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x23, y23); // center of circle
		for(i23 = 0; i23 <= triangleAmount23;i23++) {
			glVertex2f(
		            x23 + (radius23 * cos(i23 *  twicePi23 / triangleAmount23)),
			    y23 + (radius23 * sin(i23 * twicePi23 / triangleAmount23))
			);
		}
	glEnd();



	//front wheel inner

	glColor3f(1,1,1);
   int i24;

	GLfloat x24=-.2f; GLfloat y24=-.58f; GLfloat radius24 =.04f;

	int triangleAmount24 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi24 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x24, y24); // center of circle
		for(i24 = 0; i24 <= triangleAmount24;i24++) {
			glVertex2f(
		            x24 + (radius24 * cos(i24 *  twicePi24 / triangleAmount24)),
			    y24 + (radius24 * sin(i24 * twicePi24 / triangleAmount24))
			);
		}
	glEnd();



	//leftmost window

	glColor3f(.98,.93,.36);
   glBegin(GL_QUADS);
   glVertex2f(-.56f,-.4f);
   glVertex2f(-.66f,-.4f);
   glVertex2f(-.66f,-.5f);
   glVertex2f(-.56f,-.5f);

   glEnd();


   //leftmost middle window

   glColor3f(.98,.93,.36);
   glBegin(GL_QUADS);
   glVertex2f(-.52f,-.4f);
   glVertex2f(-.42f,-.4f);
   glVertex2f(-.42f,-.5f);
   glVertex2f(-.52f,-.5f);

   glEnd();


   //rightmost middle window

   glColor3f(.98,.93,.36);
   glBegin(GL_QUADS);
   glVertex2f(-.38f,-.4f);
   glVertex2f(-.28f,-.4f);
   glVertex2f(-.28f,-.5f);
   glVertex2f(-.38f,-.5f);

   glEnd();


   //rightmost window

   glColor3f(.98,.93,.36);
   glBegin(GL_QUADS);
   glVertex2f(-.24f,-.4f);
   glVertex2f(-.14f,-.4f);
   glVertex2f(-.14f,-.5f);
   glVertex2f(-.24f,-.5f);

   glEnd();
   glPopMatrix();



   //school building


   glColor3f(.65,.50,.69);
   glBegin(GL_QUADS);
   glVertex2f(.43f,-.35f);
   glVertex2f(.84f,-.35f);
   glVertex2f(.84f,-.65f);
   glVertex2f(.43f,-.65f);

   glEnd();


   //window 1 from upper right

   glColor3f(1,1,0);
   glBegin(GL_QUADS);
   glVertex2f(0.72f,-0.46f);
   glVertex2f(.8f,-0.46f);
   glVertex2f(.8f,-0.38f);
   glVertex2f(.72f,-0.38f);

   glEnd();


   //window 2

   glColor3f(1,1,0);
   glBegin(GL_QUADS);
   glVertex2f(0.68f,-0.46f);
   glVertex2f(.6f,-0.46f);
   glVertex2f(.6f,-0.38f);
   glVertex2f(.68f,-0.38f);

   glEnd();


   //window 3

   glColor3f(1,1,0);
   glBegin(GL_QUADS);
   glVertex2f(0.56f,-0.46f);
   glVertex2f(.48f,-0.46f);
   glVertex2f(.48f,-0.38f);
   glVertex2f(.56f,-0.38f);

   glEnd();


   //window 4

    glColor3f(1,1,0);
   glBegin(GL_QUADS);
   glVertex2f(0.72f,-0.5f);
   glVertex2f(.8f,-0.5f);
   glVertex2f(.8f,-0.58f);
   glVertex2f(.72f,-0.58f);

   glEnd();


   //window 5

   glColor3f(1,1,0);
   glBegin(GL_QUADS);
   glVertex2f(0.68f,-0.5f);
   glVertex2f(.6f,-0.5f);
   glVertex2f(.6f,-0.58f);
   glVertex2f(.68f,-0.58f);

   glEnd();


   //door of school

   glColor3f(.65,.30,.67);
   glBegin(GL_QUADS);
   glVertex2f(0.56f,-0.5f);
   glVertex2f(.48f,-0.5f);
   glVertex2f(.48f,-0.65f);
   glVertex2f(.56f,-0.65f);

   glEnd();


    //roadside lamp beside school


     glColor3f(.96,0.97,.46);
   int i13;

	GLfloat x13=.92f; GLfloat y13=-.42f; GLfloat radius13 =.06f;

	int triangleAmount13 = 20; //# of triangles used to draw circle


	GLfloat twicePi13 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x13, y13); // center of circle
		for(i13 = 0; i13 <= triangleAmount13;i13++) {
			glVertex2f(
		            x13 + (radius13 * cos(i13 *  twicePi13 / triangleAmount13)),
			    y13 + (radius13 * sin(i13 * twicePi13 / triangleAmount13))
			);
		}
	glEnd();



	//stand of lamp

	glColor3f(.3,.3,.3);
	glBegin(GL_QUADS);
   glVertex2f(0.91f,-0.475f);
   glVertex2f(.93f,-0.475f);
   glVertex2f(.93f,-0.65f);
   glVertex2f(.91f,-0.65f);

   glEnd();


   //flag beside school

   //main green body
   glColor3f(.39,0.67,.38);
   glBegin(GL_QUADS);
   glVertex2f(0.41f,-0.49f);
   glVertex2f(.26f,-0.49f);
   glVertex2f(.26f,-0.38f);
   glVertex2f(.41f,-0.38f);

   glEnd();


   //red circle
    glColor3f(1,0,0);
   int i14;

	GLfloat x14=.335f; GLfloat y14=-.435f; GLfloat radius14 =.04f;

	int triangleAmount14 = 20; //# of triangles used to draw circle


	GLfloat twicePi14 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x14, y14); // center of circle
		for(i14 = 0; i14 <= triangleAmount14;i14++) {
			glVertex2f(
		            x14 + (radius14 * cos(i14 *  twicePi14 / triangleAmount14)),
			    y14 + (radius14 * sin(i14 * twicePi14 / triangleAmount14))
			);
		}
	glEnd();



   //stand of flag

   glColor3f(.38,.20,.07);
	glBegin(GL_QUADS);
   glVertex2f(0.26f,-0.38f);
   glVertex2f(.24f,-0.38f);
   glVertex2f(.24f,-0.65f);
   glVertex2f(.26f,-0.65f);

   glEnd();


   //tree beside flag

   //lower part
   glColor3f(0.32,.48,0.35);
   glBegin(GL_TRIANGLES);
   glVertex2f(.08f,-0.5f);
   glVertex2f(.14f,-0.37f);
   glVertex2f(.2f,-0.5f);

   glEnd();


   //upper part
   glColor3f(0.47,.67,0.27);
   glBegin(GL_TRIANGLES);
   glVertex2f(.09f,-0.43f);
   glVertex2f(.14f,-0.22f);
   glVertex2f(.19f,-0.43f);

   glEnd();


   //log of tree

   glColor3f(.42,0.26,0.15);
   glBegin(GL_QUADS);
   glVertex2f(.12f,-.5f);
   glVertex2f(.16f,-.5f);
   glVertex2f(.16f,-.65f);
   glVertex2f(.12f,-.65f);

   glEnd();



   //cafe building

   //main building
   glColor3f(1.0,1.0,.67);
   glBegin(GL_QUADS);
   glVertex2f(-.95f,-.4f);
   glVertex2f(-.65f,-.4f);
   glVertex2f(-.65f,-.65f);
   glVertex2f(-.95f,-.65f);

   glEnd();


   //upper left

   glColor3f(.71,.49,.24);
   glBegin(GL_QUADS);
   glVertex2f(-.95f,-.4f);
   glVertex2f(-.85f,-.4f);
   glVertex2f(-.85f,-.45f);
   glVertex2f(-.95f,-.45f);

   glEnd();


   //upper middle

   glColor3f(0.90,0.74,0.23);
   glBegin(GL_QUADS);
   glVertex2f(-.85f,-.4f);
   glVertex2f(-.75f,-.4f);
   glVertex2f(-.75f,-.45f);
   glVertex2f(-.85f,-.45f);

   glEnd();




   glColor3f(.71,.49,.24);
   glBegin(GL_QUADS);
   glVertex2f(-.75f,-.4f);
   glVertex2f(-.65f,-.4f);
   glVertex2f(-.65f,-.45f);
   glVertex2f(-.75f,-.45f);

   glEnd();


   //door of cafe

   glColor3f(.71,.49,.24);
   glBegin(GL_QUADS);
   glVertex2f(-.92f,-.5f);
   glVertex2f(-.82f,-.5f);
   glVertex2f(-.82f,-.65f);
   glVertex2f(-.92f,-.65f);

   glEnd();


   //window upper
   glColor3f(1,1,0);
   glBegin(GL_QUADS);
   glVertex2f(-.78f,-.5f);
   glVertex2f(-.68f,-.5f);
   glVertex2f(-.68f,-.55f);
   glVertex2f(-.78f,-.55f);

   glEnd();


   //window lower
   glColor3f(1,1,0);
   glBegin(GL_QUADS);
   glVertex2f(-.78f,-.56f);
   glVertex2f(-.68f,-.56f);
   glVertex2f(-.68f,-.61f);
   glVertex2f(-.78f,-.61f);

   glEnd();

   //roadside lamp beside cafe

    glColor3f(.96,0.97,.46);
   int i15;

	GLfloat x15=-.57f; GLfloat y15=-.42f; GLfloat radius15 =.06f;

	int triangleAmount15 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi15 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x15, y15); // center of circle
		for(i15 = 0; i15 <= triangleAmount15;i15++) {
			glVertex2f(
		            x15 + (radius15 * cos(i15 *  twicePi15 / triangleAmount15)),
			    y15 + (radius15 * sin(i15 * twicePi15 / triangleAmount15))
			);
		}
	glEnd();



	//stand of lamp

	glColor3f(.3,.3,.3);
	glBegin(GL_QUADS);
   glVertex2f(-0.56f,-0.475f);
   glVertex2f(-.58f,-0.475f);
   glVertex2f(-.58f,-0.65f);
   glVertex2f(-.56f,-0.65f);

   glEnd();


   //tree beside cafe

   //lower part
   glColor3f(0.32,.48,0.35);
   glBegin(GL_TRIANGLES);
   glVertex2f(-.47f,-0.5f);
   glVertex2f(-.41f,-0.37f);
   glVertex2f(-.35f,-0.5f);

   glEnd();


   //upper part
   glColor3f(0.47,.67,0.27);
   glBegin(GL_TRIANGLES);
   glVertex2f(-.46f,-0.43f);
   glVertex2f(-.41f,-0.22f);
   glVertex2f(-.36f,-0.43f);

   glEnd();


   //log of tree

   glColor3f(.42,0.26,0.15);
   glBegin(GL_QUADS);
   glVertex2f(-.39f,-.5f);
   glVertex2f(-.43f,-.5f);
   glVertex2f(-.43f,-.65f);
   glVertex2f(-.39f,-.65f);

   glEnd();


   //shaheed minar

   //red sun of shaheed minar

   glColor3f(1,0,0);
   int i16;

	GLfloat x16=-.13f; GLfloat y16=-.45f; GLfloat radius16 =.12f;

	int triangleAmount16 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi16 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x16, y16); // center of circle
		for(i16 = 0; i16 <= triangleAmount16;i16++) {
			glVertex2f(
		            x16 + (radius16 * cos(i16 *  twicePi16 / triangleAmount16)),
			    y16 + (radius16 * sin(i16 * twicePi16 / triangleAmount16))
			);
		}
	glEnd();



   //pillar leftmost

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.22f,-.3f);
   glVertex2f(-.18f,-.3f);
   glVertex2f(-.18f,-.65f);
   glVertex2f(-.22f,-.65f);

   glEnd();

   //pillar middle

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.15f,-.3f);
   glVertex2f(-.11f,-.3f);
   glVertex2f(-.11f,-.65f);
   glVertex2f(-.15f,-.65f);

   glEnd();


   //pillar rightmost

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.08f,-.3f);
   glVertex2f(-.04f,-.3f);
   glVertex2f(-.04f,-.65f);
   glVertex2f(-.08f,-.65f);

   glEnd();


   //pillar upper

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.22f,-.26f);
   glVertex2f(-.04f,-.26f);
   glVertex2f(-.04f,-.3f);
   glVertex2f(-.22f,-.3f);

   glEnd();
    glutTimerFunc(5000,display_day_view,0);
   glFlush();


}
void display_night_view(int val)

{
    glutDisplayFunc(display_night);

}

void display_raining() {
   glClear(GL_COLOR_BUFFER_BIT);



   //sky

   glColor3f(0.41,.59,.68);
   glBegin(GL_QUADS);
   glVertex2f(-1.0f,1.0f);
   glVertex2f(1.0f,1.0f);
   glVertex2f(1.0f,0.5f);
   glVertex2f(-1.0f,0.5f);

   glEnd();


   //sun

   glColor3f(1,1,0);
   int i1;

	GLfloat x1=.7f; GLfloat y1=.8f; GLfloat radius1 =.15f;

	int triangleAmount1 = 20; //# of triangles used to draw circle


	GLfloat twicePi1 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount1;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi1 / triangleAmount1)),
			    y1 + (radius1 * sin(i1 * twicePi1 / triangleAmount1))
			);
		}
	glEnd();


	//left cloud

    glLoadIdentity();
   glPushMatrix();
   glTranslatef(position11,0.0, 0.0f);
   speed11 = 0.02f;
	//cloud upper middle

	glColor3f(.65,.65,.65);
   int i2;

	GLfloat x2=-.65f; GLfloat y2=.9f; GLfloat radius2 =.08f;

	int triangleAmount2 = 20; //# of triangles used to draw circle


	GLfloat twicePi2 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2, y2); // center of circle
		for(i2 = 0; i2 <= triangleAmount2;i2++) {
			glVertex2f(
		            x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
			);
		}
	glEnd();




	//cloud left middle

	glColor3f(.65,.65,.65);
   int i3;

	GLfloat x3=-.75f; GLfloat y3=.85f; GLfloat radius3 =.08f;

	int triangleAmount3 = 20; //# of triangles used to draw circle


	GLfloat twicePi3 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3, y3); // center of circle
		for(i3 = 0; i3 <= triangleAmount3;i3++) {
			glVertex2f(
		            x3 + (radius3 * cos(i3 *  twicePi3 / triangleAmount3)),
			    y3 + (radius3 * sin(i3 * twicePi3 / triangleAmount3))
			);
		}
	glEnd();



	//cloud in right middle

	glColor3f(.65,.65,.65);
   int i4;

	GLfloat x4=-.55f; GLfloat y4=.85f; GLfloat radius4 =.08f;

	int triangleAmount4 = 20; //# of triangles used to draw circle


	GLfloat twicePi4 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x4, y4); // center of circle
		for(i4 = 0; i4 <= triangleAmount4;i4++) {
			glVertex2f(
		            x4 + (radius4 * cos(i4 *  twicePi4 / triangleAmount4)),
			    y4 + (radius4 * sin(i4 * twicePi4 / triangleAmount4))
			);
		}
	glEnd();



	//cloud in the lower right

	glColor3f(.65,.65,.65);
   int i5;

	GLfloat x5=-.6f; GLfloat y5=.8f; GLfloat radius5 =.08f;

	int triangleAmount5 = 20; //# of triangles used to draw circle


	GLfloat twicePi5 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x5, y5); // center of circle
		for(i5 = 0; i5 <= triangleAmount5;i5++) {
			glVertex2f(
		            x5 + (radius5 * cos(i5 *  twicePi5 / triangleAmount5)),
			    y5 + (radius5 * sin(i5 * twicePi5 / triangleAmount5))
			);
		}
	glEnd();



	//cloud in the lower left

	glColor3f(.65,.65,.65);
   int i6;

	GLfloat x6=-.7f; GLfloat y6=.8f; GLfloat radius6 =.08f;

	int triangleAmount6 = 20; //# of triangles used to draw circle


	GLfloat twicePi6 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x6, y6); // center of circle
		for(i6 = 0; i6 <= triangleAmount6;i6++) {
			glVertex2f(
		            x6 + (radius6 * cos(i6 *  twicePi6 / triangleAmount6)),
			    y6 + (radius6 * sin(i6 * twicePi6 / triangleAmount6))
			);
		}
	glEnd();
    glPopMatrix();


	//cloud covering sun



	//cloud upper middle

	glColor3f(.65,.65,.65);
   int i222;

	GLfloat x222=.75f; GLfloat y222=.8f; GLfloat radius222 =.08f;

	int triangleAmount222 = 20; //# of triangles used to draw circle


	GLfloat twicePi222 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x222, y222); // center of circle
		for(i222 = 0; i222 <= triangleAmount222;i222++) {
			glVertex2f(
		            x222 + (radius222 * cos(i222 *  twicePi222 / triangleAmount222)),
			    y222 + (radius222 * sin(i222 * twicePi222 / triangleAmount222))
			);
		}
	glEnd();



	//cloud left middle

	glColor3f(.65,.65,.65);
   int i223;

	GLfloat x223=.85f; GLfloat y223=.75f; GLfloat radius223 =.08f;

	int triangleAmount223 = 20; //# of triangles used to draw circle


	GLfloat twicePi223 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x223, y223); // center of circle
		for(i223 = 0; i223 <= triangleAmount223;i223++) {
			glVertex2f(
		            x223 + (radius223 * cos(i223 *  twicePi223 / triangleAmount223)),
			    y223 + (radius223 * sin(i223 * twicePi223 / triangleAmount223))
			);
		}
	glEnd();



	//cloud in right middle

	glColor3f(.65,.65,.65);
   int i224;

	GLfloat x224=.65f; GLfloat y224=.75f; GLfloat radius224 =.08f;

	int triangleAmount224 = 20; //# of triangles used to draw circle


	GLfloat twicePi224 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x224, y224); // center of circle
		for(i224 = 0; i224 <= triangleAmount4;i224++) {
			glVertex2f(
		            x224 + (radius224 * cos(i224 *  twicePi224 / triangleAmount224)),
			    y224 + (radius224 * sin(i224 * twicePi224 / triangleAmount224))
			);
		}
	glEnd();



	//cloud in the lower right

	glColor3f(.65,.65,.65);
   int i25;

	GLfloat x25=.7f; GLfloat y25=.7f; GLfloat radius25 =.08f;

	int triangleAmount25 = 20; //# of triangles used to draw circle


	GLfloat twicePi25 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x25, y25); // center of circle
		for(i25 = 0; i25 <= triangleAmount25;i25++) {
			glVertex2f(
		            x25 + (radius25 * cos(i25 *  twicePi25 / triangleAmount25)),
			    y25 + (radius25 * sin(i25 * twicePi25 / triangleAmount25))
			);
		}
	glEnd();



	//cloud in the lower left

	glColor3f(.65,.65,.65);
   int i26;

	GLfloat x26=.8f; GLfloat y26=.7f; GLfloat radius26 =.08f;

	int triangleAmount26 = 20; //# of triangles used to draw circle


	GLfloat twicePi26 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x26, y26); // center of circle
		for(i26 = 0; i26 <= triangleAmount26;i26++) {
			glVertex2f(
		            x26 + (radius26 * cos(i26 *  twicePi26 / triangleAmount26)),
			    y26 + (radius26 * sin(i26 * twicePi26 / triangleAmount26))
			);
		}
	glEnd();


	//plane

	glLoadIdentity();
   glPushMatrix();
   glTranslatef(position2,0.0, 0.0f);
   speed2 = 0.1f;
    //body of plane

   glColor3f(1.0,.95,.71);
   glBegin(GL_QUADS);
   glVertex2f(-.35f,0.8f);
   glVertex2f(.1f,0.8f);
   glVertex2f(.1f,0.7f);
   glVertex2f(-.35f,0.7f);

   glEnd();

   //front of plane

   glColor3f(1,0,0);
   glBegin(GL_TRIANGLES);
   glVertex2f(.1f,0.8f);
   glVertex2f(.2f,0.75f);
   glVertex2f(.1f,0.7f);

   glEnd();


   //tail of plane

   glColor3f(1,0,0);
   glBegin(GL_QUADS);
   glVertex2f(-.35f,0.9f);
   glVertex2f(-.32f,0.9f);
   glVertex2f(-.25f,0.8f);
   glVertex2f(-.35f,0.8f);

   glEnd();


   //upper fan of plane

   glColor3f(1,0,0);
   glBegin(GL_QUADS);
   glVertex2f(-.05f,0.9f);
   glVertex2f(-.15f,0.9f);
   glVertex2f(-.1f,0.8f);
   glVertex2f(0.0f,0.8f);

   glEnd();

   //lower  fan of plane

   glColor3f(1,0,0);
   glBegin(GL_QUADS);
   glVertex2f(0.0f,0.72f);
   glVertex2f(-.05f,0.6f);
   glVertex2f(-.15f,0.6f);
   glVertex2f(-.1f,0.72f);

   glEnd();


   //window 1 from right

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(0.04f,0.73f);
   glVertex2f(.04f,0.78f);
   glVertex2f(-.04f,0.78f);
   glVertex2f(-.04f,0.73f);

   glEnd();

   //window 2 from right

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-0.08f,0.73f);
   glVertex2f(-.08f,0.78f);
   glVertex2f(-.16f,0.78f);
   glVertex2f(-.16f,0.73f);

   glEnd();


   //window 3 from right

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-0.20f,0.73f);
   glVertex2f(-.20f,0.78f);
   glVertex2f(-.28f,0.78f);
   glVertex2f(-.28f,0.73f);

   glEnd();
   glPopMatrix();


   //road behind skyscraper 1,2,3,4

   glColor3f(0.68,0.68,0.68);
   glBegin(GL_QUADS);
   glVertex2f(-1.0f,0.5f);
   glVertex2f(1.0f,0.5f);
   glVertex2f(1.0f,0.1f);
   glVertex2f(-1.0f,0.1f);

   glEnd();


   //leftmost left line of road behind skyscraper 1,2,3,4

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-1.0f,.3f);
   glVertex2f(-.7f,.3f);
   glVertex2f(-.7f,.35f);
   glVertex2f(-1.f,.35f);

   glEnd();


   //rightmost left line of road behind skyscraper 1,2,3,4

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.55f,.3f);
   glVertex2f(-.25f,.3f);
   glVertex2f(-.25f,.35f);
   glVertex2f(-.55f,.35f);

   glEnd();
   //middle line of road behind skyscraper 1,2,3,4

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.05f,.3f);
   glVertex2f(.3f,.3f);
   glVertex2f(.3f,.35f);
   glVertex2f(-.05f,.35f);

   glEnd();


   //right line of road behind skyscraper 1,2,3,4

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(.6f,.3f);
   glVertex2f(1.0f,.3f);
   glVertex2f(1.0f,.35f);
   glVertex2f(.6f,.35f);

   glEnd();


   //car behind skyscraper 1,2,3,4

   glLoadIdentity();
   glPushMatrix();
   glTranslatef(position3,0.0, 0.0f);
   speed3 = 0.15f;

   //main body
   glColor3f(.38,0.20,0.07);
   glBegin(GL_QUADS);
   glVertex2f(-0.3f,0.45f);
   glVertex2f(.05f,0.45f);
   glVertex2f(.05f,0.25f);
   glVertex2f(-.3f,0.25f);

   glEnd();


   //window 1

   glColor3f(.40,.56,.53);

   glBegin(GL_QUADS);
   glVertex2f(0.01f,0.385f);
   glVertex2f(-.1f,0.385f);
   glVertex2f(-.1f,0.31f);
   glVertex2f(.01f,0.31f);

   glEnd();


   //window 2

   glColor3f(.40,.56,.53);
   glBegin(GL_QUADS);
   glVertex2f(-0.25f,0.385f);
   glVertex2f(-.14f,0.385f);
   glVertex2f(-.14f,0.31f);
   glVertex2f(-.25f,0.31f);

   glEnd();

   //backwheel outer

   glColor3f(0,0,0);
   int i9;

	GLfloat x9=-.2f; GLfloat y9=.22f; GLfloat radius9 =.062f;

	int triangleAmount9 = 20; //# of triangles used to draw circle


	GLfloat twicePi9 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x9, y9); // center of circle
		for(i9 = 0; i9<= triangleAmount9;i9++) {
			glVertex2f(
		            x9 + (radius9 * cos(i9 *  twicePi9 / triangleAmount9)),
			    y9 + (radius9 * sin(i9 * twicePi9 / triangleAmount9))
			);
		}
	glEnd();



	//backwheel inner

   glColor3f(1,1,1);
   int i11;

	GLfloat x11=-.2f; GLfloat y11=.22f; GLfloat radius11 =.045f;

	int triangleAmount11 = 20; //# of triangles used to draw circle


	GLfloat twicePi11 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x11, y11); // center of circle
		for(i11 = 0; i11<= triangleAmount11;i11++) {
			glVertex2f(
		            x11 + (radius11 * cos(i11 *  twicePi11 / triangleAmount11)),
			    y11 + (radius11 * sin(i11 * twicePi11/ triangleAmount11))
			);
		}
	glEnd();




   //front part
   glColor3f(0.62,0.02,0.03);

   glBegin(GL_QUADS);
   glVertex2f(0.05f,0.45f);
   glVertex2f(.25f,0.4f);
   glVertex2f(.25f,0.25f);
   glVertex2f(.05f,0.25f);

   glEnd();


   //window
   glColor3f(.40,.56,.53);

   glBegin(GL_QUADS);
   glVertex2f(0.1f,0.385f);
   glVertex2f(.2f,0.385f);
   glVertex2f(.2f,0.31f);
   glVertex2f(.1f,0.31f);

   glEnd();


   //front wheel outer

	glColor3f(0,0,0);
   int i10;

	GLfloat x10=.15f; GLfloat y10=.22f; GLfloat radius10 =.062f;

	int triangleAmount10 = 20; //# of triangles used to draw circle


	GLfloat twicePi10 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x10, y10); // center of circle
		for(i10 = 0; i10<= triangleAmount10;i10++) {
			glVertex2f(
		            x10 + (radius10 * cos(i10 *  twicePi10 / triangleAmount10)),
			    y10 + (radius10 * sin(i10 * twicePi10 / triangleAmount10))
			);
		}
	glEnd();




   //front wheel inner

	glColor3f(1,1,1);
   int i12;

	GLfloat x12=.15f; GLfloat y12=.22f; GLfloat radius12 =.045f;

	int triangleAmount12 = 20; //# of triangles used to draw circle


	GLfloat twicePi12 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x12, y12); // center of circle
		for(i12 = 0; i12<= triangleAmount12;i12++) {
			glVertex2f(
		            x12 + (radius12 * cos(i12 *  twicePi12 / triangleAmount12)),
			    y12 + (radius12 * sin(i12 * twicePi12 / triangleAmount12))
			);
		}
	glEnd();
    glPopMatrix();


   //skycraper 1

   glColor3f(.56,0.74,.56);
   glBegin(GL_QUADS);
   glVertex2f(-0.95f,0.55f);
   glVertex2f(-.65f,0.55f);
   glVertex2f(-.65f,0.1f);
   glVertex2f(-.95f,0.1f);

   glEnd();


   //window 1 from upper left

   glColor3f(.23,.52,.44);
   glBegin(GL_QUADS);
   glVertex2f(-0.9f,0.5f);
   glVertex2f(-.82f,0.5f);
   glVertex2f(-.82f,0.42f);
   glVertex2f(-.9f,0.42f);

   glEnd();


   //window 2
   glColor3f(.23,.52,.44);
   glBegin(GL_QUADS);
   glVertex2f(-0.77f,0.5f);
   glVertex2f(-.69f,0.5f);
   glVertex2f(-.69f,0.42f);
   glVertex2f(-.77f,0.42f);

   glEnd();


   //window 3

   glColor3f(.23,.52,.44);
   glBegin(GL_QUADS);
   glVertex2f(-0.9f,0.37f);
   glVertex2f(-.82f,0.37f);
   glVertex2f(-.82f,0.29f);
   glVertex2f(-.9f,0.29f);

   glEnd();


   //window 4

   glColor3f(.23,.52,.44);
   glBegin(GL_QUADS);
   glVertex2f(-0.77f,0.37f);
   glVertex2f(-.69f,0.37f);
   glVertex2f(-.69f,0.29f);
   glVertex2f(-.77f,0.29f);

   glEnd();


   //window 5

   glColor3f(.23,.52,.44);
   glBegin(GL_QUADS);
   glVertex2f(-0.9f,0.24f);
   glVertex2f(-.82f,0.24f);
   glVertex2f(-.82f,0.16f);
   glVertex2f(-.9f,0.16f);

   glEnd();


   //window 6

   glColor3f(.23,.52,.44);
   glBegin(GL_QUADS);
   glVertex2f(-0.77f,0.24f);
   glVertex2f(-.69f,0.24f);
   glVertex2f(-.69f,0.16f);
   glVertex2f(-.77f,0.16f);

   glEnd();


   //tree beside skyscraper 1

   //lower part
   glColor3f(0.32,.48,0.35);
   glBegin(GL_TRIANGLES);
   glVertex2f(-.63f,0.25f);
   glVertex2f(-.57f,0.38f);
   glVertex2f(-.51f,0.25f);

   glEnd();


   //upper part
   glColor3f(0.47,.67,0.27);
   glBegin(GL_TRIANGLES);
   glVertex2f(-.62f,0.32f);
   glVertex2f(-.57f,0.55f);
   glVertex2f(-.52f,0.32f);

   glEnd();

   //log of tree

   glColor3f(.42,0.26,0.15);
   glBegin(GL_QUADS);
   glVertex2f(-.55f,.25f);
   glVertex2f(-.59f,.25f);
   glVertex2f(-.59f,.1f);
   glVertex2f(-.55f,.1f);

   glEnd();


   //skyscraper 2

   glColor3f(0.55,0.37,0.40);
   glBegin(GL_QUADS);
   glVertex2f(-.48f,.42f);
   glVertex2f(-.18f,.42f);
   glVertex2f(-.18f,.1f);
   glVertex2f(-.48f,.1f);

   glEnd();


   //window 1 from upper left

   glColor3f(.33,.06,.20);
   glBegin(GL_QUADS);
   glVertex2f(-0.43f,0.37f);
   glVertex2f(-.35f,0.37f);
   glVertex2f(-.35f,0.29f);
   glVertex2f(-.43f,0.29f);

   glEnd();


   //window 2

   glColor3f(.33,.06,.20);
   glBegin(GL_QUADS);
   glVertex2f(-0.3f,0.37f);
   glVertex2f(-.22f,0.37f);
   glVertex2f(-.22f,0.29f);
   glVertex2f(-.3f,0.29f);

   glEnd();


   //window 3

   glColor3f(.33,.06,.20);
   glBegin(GL_QUADS);
   glVertex2f(-0.43f,0.24f);
   glVertex2f(-.35f,0.24f);
   glVertex2f(-.35f,0.16f);
   glVertex2f(-.43f,0.16f);

   glEnd();

   //window 4

   glColor3f(.33,.06,.20);
   glBegin(GL_QUADS);
   glVertex2f(-0.3f,0.24f);
   glVertex2f(-.22f,0.24f);
   glVertex2f(-.22f,0.16f);
   glVertex2f(-.3f,0.16f);

   glEnd();

   //roadside lamp beside skyscraper 2

   glColor3f(.55,0.55,.48);
   int i7;

	GLfloat x7=-.1f; GLfloat y7=.33f; GLfloat radius7 =.06f;

	int triangleAmount7 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi7 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x7, y7); // center of circle
		for(i7 = 0; i7 <= triangleAmount7;i7++) {
			glVertex2f(
		            x7 + (radius7 * cos(i7 *  twicePi7 / triangleAmount7)),
			    y7 + (radius7 * sin(i7 * twicePi7 / triangleAmount7))
			);
		}
	glEnd();



	//stand of lamp

	glColor3f(.3,.3,.3);
	glBegin(GL_QUADS);
   glVertex2f(-0.09f,0.275f);
   glVertex2f(-.11f,0.275f);
   glVertex2f(-.11f,0.1f);
   glVertex2f(-.09f,0.1f);

   glEnd();


   //skyscraper 3

   glColor3f(.82,.57,.46);
   glBegin(GL_QUADS);
   glVertex2f(-0.02f,0.55f);
   glVertex2f(.38f,0.55f);
   glVertex2f(.38f,0.1f);
   glVertex2f(-0.02f,0.1f);

   glEnd();


   //window 1 from upper left

   glColor3f(.80,.41,.22);
   glBegin(GL_QUADS);
   glVertex2f(0.02f,0.5f);
   glVertex2f(.1f,0.5f);
   glVertex2f(.1f,0.42f);
   glVertex2f(.02f,0.42f);

   glEnd();


   //window 2

   glColor3f(.80,.41,.22);
   glBegin(GL_QUADS);
   glVertex2f(0.14f,0.5f);
   glVertex2f(.22f,0.5f);
   glVertex2f(.22f,0.42f);
   glVertex2f(.14f,0.42f);

   glEnd();

   //window 3

   glColor3f(.80,.41,.22);
   glBegin(GL_QUADS);
   glVertex2f(0.26f,0.5f);
   glVertex2f(.34f,0.5f);
   glVertex2f(.34f,0.42f);
   glVertex2f(.26f,0.42f);

   glEnd();


   //window 4

   glColor3f(.80,.41,.22);
   glBegin(GL_QUADS);
   glVertex2f(0.02f,0.37f);
   glVertex2f(.1f,0.37f);
   glVertex2f(.1f,0.29f);
   glVertex2f(.02f,0.29f);

   glEnd();


   //window 5

   glColor3f(.80,.41,.22);
   glBegin(GL_QUADS);
   glVertex2f(0.14f,0.37f);
   glVertex2f(.22f,0.37f);
   glVertex2f(.22f,0.29f);
   glVertex2f(.14f,0.29f);

   glEnd();


   //window 6

   glColor3f(.80,.41,.22);
   glBegin(GL_QUADS);
   glVertex2f(0.26f,0.37f);
   glVertex2f(.34f,0.37f);
   glVertex2f(.34f,0.29f);
   glVertex2f(.26f,0.29f);

   glEnd();

   //window 7

    glColor3f(.80,.41,.22);
   glBegin(GL_QUADS);
   glVertex2f(0.02f,0.24f);
   glVertex2f(.1f,0.24f);
   glVertex2f(.1f,0.16f);
   glVertex2f(.02f,0.16f);

   glEnd();


   //window 8

   glColor3f(.80,.41,.22);
   glBegin(GL_QUADS);
   glVertex2f(0.14f,0.24f);
   glVertex2f(.22f,0.24f);
   glVertex2f(.22f,0.16f);
   glVertex2f(.14f,0.16f);

   glEnd();


   //window 9

   glColor3f(.80,.41,.22);
   glBegin(GL_QUADS);
   glVertex2f(0.26f,0.24f);
   glVertex2f(.34f,0.24f);
   glVertex2f(.34f,0.16f);
   glVertex2f(.26f,0.16f);

   glEnd();


   //tree beside skyscraper 3


   //lower part
   glColor3f(0.32,.48,0.35);
   glBegin(GL_TRIANGLES);
   glVertex2f(.4f,0.25f);
   glVertex2f(.46f,0.38f);
   glVertex2f(.52f,0.25f);

   glEnd();


   //upper part
   glColor3f(0.47,.67,0.27);
   glBegin(GL_TRIANGLES);
   glVertex2f(.41f,0.32f);
   glVertex2f(.46f,0.55f);
   glVertex2f(.51f,0.32f);

   glEnd();

   //log of tree

   glColor3f(.42,0.26,0.15);
   glBegin(GL_QUADS);
   glVertex2f(.44f,.25f);
   glVertex2f(.48f,.25f);
   glVertex2f(.48f,.1f);
   glVertex2f(.44f,.1f);

   glEnd();



   //skyscraper 4

   glColor3f(0.40,0.0,0.0);
   glBegin(GL_QUADS);
   glVertex2f(.54f,.42f);
   glVertex2f(.84f,.42f);
   glVertex2f(.84f,.1f);
   glVertex2f(.54f,.1f);

   glEnd();


   //window 1 from upper left

   glColor3f(.48,.28,.26);
   glBegin(GL_QUADS);
   glVertex2f(0.59f,0.37f);
   glVertex2f(.67f,0.37f);
   glVertex2f(.67f,0.29f);
   glVertex2f(.59f,0.29f);

   glEnd();


   //window 2

   glColor3f(.48,.28,.26);
   glBegin(GL_QUADS);
   glVertex2f(0.72f,0.37f);
   glVertex2f(.8f,0.37f);
   glVertex2f(.8f,0.29f);
   glVertex2f(.72f,0.29f);

   glEnd();


   //window 3

   glColor3f(.48,.28,.26);
   glBegin(GL_QUADS);
   glVertex2f(0.59f,0.24f);
   glVertex2f(.67f,0.24f);
   glVertex2f(.67f,0.16f);
   glVertex2f(.59f,0.16f);

   glEnd();


   //window 4
   glColor3f(.48,.28,.26);
   glBegin(GL_QUADS);
   glVertex2f(0.72f,0.24f);
   glVertex2f(.8f,0.24f);
   glVertex2f(.8f,0.16f);
   glVertex2f(.72f,0.16f);

   glEnd();


   //roadside lamp beside skyscraper 4

   glColor3f(.55,0.55,.48);
   int i8;

	GLfloat x8=.92f; GLfloat y8=.33f; GLfloat radius8 =.06f;

	int triangleAmount8 = 20; //# of triangles used to draw circle


	GLfloat twicePi8 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x8, y8); // center of circle
		for(i8 = 0; i8 <= triangleAmount8;i8++) {
			glVertex2f(
		            x8 + (radius8 * cos(i8 *  twicePi8 / triangleAmount8)),
			    y8 + (radius8 * sin(i8 * twicePi8 / triangleAmount8))
			);
		}
	glEnd();



	//stand of lamp

	glColor3f(.3,.3,.3);
	glBegin(GL_QUADS);
   glVertex2f(0.91f,0.275f);
   glVertex2f(.93f,0.275f);
   glVertex2f(.93f,0.1f);
   glVertex2f(.91f,0.1f);

   glEnd();


   //footpath in front of skyscraper 1,2,3,4

   glColor3f(.3,.3,.3);
   glBegin(GL_QUADS);
   glVertex2f(-1.0f,0.1f);
   glVertex2f(1.0f,0.1f);
   glVertex2f(1.0f,0.05f);
   glVertex2f(-1.0f,0.05f);

   glEnd();


   //road behind school and park

   glColor3f(0.68,0.68,0.68);
   glBegin(GL_QUADS);
   glVertex2f(-1.0f,0.05f);
   glVertex2f(1.0f,0.05f);
   glVertex2f(1.0f,-1.0f);
   glVertex2f(-1.0f,-1.0f);

   glEnd();


   //lake

   glColor3f(0.41,.59,.68);
   glBegin(GL_QUADS);
   glVertex2f(-1.0f,-0.7f);
   glVertex2f(1.0f,-0.7f);
   glVertex2f(1.f,-1.0f);
   glVertex2f(-1.0f,-1.0f);

   glEnd();


   //boat in the lake

    glLoadIdentity();
   glPushMatrix();
   glTranslatef(position6,0.0, 0.0f);
   speed6 = 0.07f;
   //lower deck

   glColor3f(0.4,0.0,0.0);
   glBegin(GL_QUADS);
   glVertex2f(.0f,-.85f);
   glVertex2f(-.5f,-.85f);
   glVertex2f(-.4f,-0.95f);
   glVertex2f(-.1f,-0.95f);


    glEnd();


   //upper deck

   glColor3f(1.0,.95,.71);
   glBegin(GL_QUADS);
   glVertex2f(-.1f,-.75f);
   glVertex2f(-.4f,-.75f);
   glVertex2f(-.4f,-0.85f);
   glVertex2f(-.1f,-0.85f);


    glEnd();


   //window 1 from left

    glColor3f(0.55,0.37,0.40);
    glBegin(GL_QUADS);
   glVertex2f(-.31f,-.77f);
   glVertex2f(-.37f,-.77f);
   glVertex2f(-.37f,-0.83f);
   glVertex2f(-.31f,-0.83f);


    glEnd();

   //window 2

   glColor3f(0.55,0.37,0.40);
    glBegin(GL_QUADS);
   glVertex2f(-.28f,-.77f);
   glVertex2f(-.22f,-.77f);
   glVertex2f(-.22f,-0.83f);
   glVertex2f(-.28f,-0.83f);


    glEnd();


   //window 3

   glColor3f(0.55,0.37,0.40);
   glBegin(GL_QUADS);
   glVertex2f(-.19f,-.77f);
   glVertex2f(-.13f,-.77f);
   glVertex2f(-.13f,-0.83f);
   glVertex2f(-.19f,-0.83f);


    glEnd();
    glPopMatrix();

   // footpath in front of school and park

   glColor3f(.3,.3,.3);
   glBegin(GL_QUADS);
   glVertex2f(-1.0f,-0.7f);
   glVertex2f(1.0f,-0.7f);
   glVertex2f(1.0f,-0.65f);
   glVertex2f(-1.0f,-.65f);

   glEnd();


   //leftmost left line of road behind school

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-1.0f,-.3f);
   glVertex2f(-.7f,-.3f);
   glVertex2f(-.7f,-.35f);
   glVertex2f(-1.f,-.35f);

   glEnd();


   //rightmost left line of road

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.55f,-.3f);
   glVertex2f(-.25f,-.3f);
   glVertex2f(-.25f,-.35f);
   glVertex2f(-.55f,-.35f);

   glEnd();

   //middle line of road behind school

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.0f,-.3f);
   glVertex2f(.3f,-.3f);
   glVertex2f(.3f,-.35f);
   glVertex2f(-.0f,-.35f);

   glEnd();


   //right line of road behind school

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(.6f,-.3f);
   glVertex2f(1.0f,-.3f);
   glVertex2f(1.0f,-.35f);
   glVertex2f(.6f,-.35f);

   glEnd();

   //car in road behind school
   glLoadIdentity();
   glPushMatrix();
   glTranslatef(position4,0.0, 0.0f);
   speed4 = 0.15f;
   //lower body of car

   glColor3f(1,0,0);
   glBegin(GL_QUADS);
   glVertex2f(-.1f,-.08f);
   glVertex2f(.4f,-.08f);
   glVertex2f(.4f,-.2f);
   glVertex2f(-.1f,-.2f);

   glEnd();


   //upper body of car

   glColor3f(1,0,0);
   glBegin(GL_QUADS);
   glVertex2f(.05f,.02f);
   glVertex2f(.25f,.02f);
   glVertex2f(.33f,-.08f);
   glVertex2f(-.03f,-.08f);

   glEnd();


   //left window

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(.06f,-.0f);
   glVertex2f(.14f,-.0f);
   glVertex2f(.14f,-.08f);
   glVertex2f(.01f,-.08f);

   glEnd();


   //right window

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(.16f,-.0f);
   glVertex2f(.24f,-.0f);
   glVertex2f(.29f,-.08f);
   glVertex2f(.16f,-.08f);

   glEnd();

   //front wheel outer

    glColor3f(0,0,0);
   int i17;

	GLfloat x17=.0f; GLfloat y17=-.2f; GLfloat radius17 =.06f;

	int triangleAmount17 = 20; //# of triangles used to draw circle


	GLfloat twicePi17 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x17, y17); // center of circle
		for(i17 = 0; i17 <= triangleAmount17;i17++) {
			glVertex2f(
		            x17 + (radius17 * cos(i17 *  twicePi17 / triangleAmount17)),
			    y17 + (radius17 * sin(i17 * twicePi17 / triangleAmount17))
			);
		}
	glEnd();



	//front wheel inner

	glColor3f(1,1,1);
   int i18;

	GLfloat x18=.0f; GLfloat y18=-.2f; GLfloat radius18 =.04f;

	int triangleAmount18 = 20; //# of triangles used to draw circle


	GLfloat twicePi18 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x18, y18); // center of circle
		for(i18 = 0; i18 <= triangleAmount18;i18++) {
			glVertex2f(
		            x18 + (radius18 * cos(i18 *  twicePi18 / triangleAmount18)),
			    y18 + (radius18 * sin(i18 * twicePi18 / triangleAmount18))
			);
		}
	glEnd();



	//back wheel outer

	glColor3f(0,0,0);
   int i19;

	GLfloat x19=.3f; GLfloat y19=-.2f; GLfloat radius19 =.06f;

	int triangleAmount19 = 20; //# of triangles used to draw circle


	GLfloat twicePi19 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x19, y19); // center of circle
		for(i19 = 0; i19 <= triangleAmount19;i19++) {
			glVertex2f(
		            x19 + (radius19 * cos(i19 *  twicePi19 / triangleAmount19)),
			    y19 + (radius19 * sin(i19 * twicePi19 / triangleAmount19))
			);
		}
	glEnd();



	//back wheel inner

	glColor3f(1,1,1);
   int i20;

	GLfloat x20=.3f; GLfloat y20=-.2f; GLfloat radius20 =.04f;

	int triangleAmount20 = 20; //# of triangles used to draw circle


	GLfloat twicePi20 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x20, y20); // center of circle
		for(i20 = 0; i20 <= triangleAmount20;i20++) {
			glVertex2f(
		            x20 + (radius20 * cos(i20 *  twicePi20 / triangleAmount20)),
			    y20 + (radius20 * sin(i20 * twicePi20 / triangleAmount20))
			);
		}
	glEnd();
    glPopMatrix();



	//bus

	glLoadIdentity();
   glPushMatrix();
   glTranslatef(position5,0.0, 0.0f);
   speed5 = 0.15f;
	//main body

	glColor3f(.47,0.63,0.53);
   glBegin(GL_QUADS);
   glVertex2f(-.7f,-.38f);
   glVertex2f(-.1f,-.38f);
   glVertex2f(-.1f,-.58f);
   glVertex2f(-.7f,-.58f);

   glEnd();


   //back wheel outer

   glColor3f(0,0,0);
   int i21;

	GLfloat x21=-.6f; GLfloat y21=-.58f; GLfloat radius21 =.06f;

	int triangleAmount21 = 20; //# of triangles used to draw circle


	GLfloat twicePi21 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x21, y21); // center of circle
		for(i21 = 0; i21 <= triangleAmount21;i21++) {
			glVertex2f(
		            x21 + (radius21 * cos(i21 *  twicePi21 / triangleAmount21)),
			    y21 + (radius21 * sin(i21 * twicePi21 / triangleAmount21))
			);
		}
	glEnd();



	//back wheel inner

	glColor3f(1,1,1);
   int i22;

	GLfloat x22=-.6f; GLfloat y22=-.58f; GLfloat radius22 =.04f;

	int triangleAmount22 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi22 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x22, y22); // center of circle
		for(i22 = 0; i22 <= triangleAmount21;i22++) {
			glVertex2f(
		            x22 + (radius22 * cos(i22 *  twicePi22 / triangleAmount22)),
			    y22 + (radius22 * sin(i22 * twicePi22 / triangleAmount22))
			);
		}
	glEnd();



	//front wheel outer

	glColor3f(0,0,0);
   int i23;

	GLfloat x23=-.2f; GLfloat y23=-.58f; GLfloat radius23 =.06f;

	int triangleAmount23 = 20; //# of triangles used to draw circle


	GLfloat twicePi23 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x23, y23); // center of circle
		for(i23 = 0; i23 <= triangleAmount23;i23++) {
			glVertex2f(
		            x23 + (radius23 * cos(i23 *  twicePi23 / triangleAmount23)),
			    y23 + (radius23 * sin(i23 * twicePi23 / triangleAmount23))
			);
		}
	glEnd();



	//front wheel inner

	glColor3f(1,1,1);
   int i24;

	GLfloat x24=-.2f; GLfloat y24=-.58f; GLfloat radius24 =.04f;

	int triangleAmount24 = 20; //# of triangles used to draw circle


	GLfloat twicePi24 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x24, y24); // center of circle
		for(i24 = 0; i24 <= triangleAmount24;i24++) {
			glVertex2f(
		            x24 + (radius24 * cos(i24 *  twicePi24 / triangleAmount24)),
			    y24 + (radius24 * sin(i24 * twicePi24 / triangleAmount24))
			);
		}
	glEnd();



	//leftmost window

	glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.56f,-.4f);
   glVertex2f(-.66f,-.4f);
   glVertex2f(-.66f,-.5f);
   glVertex2f(-.56f,-.5f);

   glEnd();


   //leftmost middle window

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.52f,-.4f);
   glVertex2f(-.42f,-.4f);
   glVertex2f(-.42f,-.5f);
   glVertex2f(-.52f,-.5f);

   glEnd();

   //rightmost middle window

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.38f,-.4f);
   glVertex2f(-.28f,-.4f);
   glVertex2f(-.28f,-.5f);
   glVertex2f(-.38f,-.5f);

   glEnd();


   //rightmost window

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.24f,-.4f);
   glVertex2f(-.14f,-.4f);
   glVertex2f(-.14f,-.5f);
   glVertex2f(-.24f,-.5f);

   glEnd();
   glPopMatrix();



   //school building


   glColor3f(.65,.50,.69);
   glBegin(GL_QUADS);
   glVertex2f(.43f,-.35f);
   glVertex2f(.84f,-.35f);
   glVertex2f(.84f,-.65f);
   glVertex2f(.43f,-.65f);

   glEnd();


   //window 1 from upper right

   glColor3f(.65,.30,.67);
   glBegin(GL_QUADS);
   glVertex2f(0.72f,-0.46f);
   glVertex2f(.8f,-0.46f);
   glVertex2f(.8f,-0.38f);
   glVertex2f(.72f,-0.38f);

   glEnd();


   //window 2

   glColor3f(.65,.30,.67);
   glBegin(GL_QUADS);
   glVertex2f(0.68f,-0.46f);
   glVertex2f(.6f,-0.46f);
   glVertex2f(.6f,-0.38f);
   glVertex2f(.68f,-0.38f);

   glEnd();


   //window 3

   glColor3f(.65,.30,.67);
   glBegin(GL_QUADS);
   glVertex2f(0.56f,-0.46f);
   glVertex2f(.48f,-0.46f);
   glVertex2f(.48f,-0.38f);
   glVertex2f(.56f,-0.38f);

   glEnd();


   //window 4

    glColor3f(.65,.30,.67);
   glBegin(GL_QUADS);
   glVertex2f(0.72f,-0.5f);
   glVertex2f(.8f,-0.5f);
   glVertex2f(.8f,-0.58f);
   glVertex2f(.72f,-0.58f);

   glEnd();

   //window 5

   glColor3f(.65,.30,.67);
   glBegin(GL_QUADS);
   glVertex2f(0.68f,-0.5f);
   glVertex2f(.6f,-0.5f);
   glVertex2f(.6f,-0.58f);
   glVertex2f(.68f,-0.58f);

   glEnd();


   //door of school

   glColor3f(.65,.30,.67);
   glBegin(GL_QUADS);
   glVertex2f(0.56f,-0.5f);
   glVertex2f(.48f,-0.5f);
   glVertex2f(.48f,-0.65f);
   glVertex2f(.56f,-0.65f);

   glEnd();


    //roadside lamp beside school

   glColor3f(.55,0.55,.48);
   int i13;

	GLfloat x13=.92f; GLfloat y13=-.42f; GLfloat radius13 =.06f;

	int triangleAmount13 = 20; //# of triangles used to draw circle


	GLfloat twicePi13 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x13, y13); // center of circle
		for(i13 = 0; i13 <= triangleAmount13;i13++) {
			glVertex2f(
		            x13 + (radius13 * cos(i13 *  twicePi13 / triangleAmount13)),
			    y13 + (radius13 * sin(i13 * twicePi13 / triangleAmount13))
			);
		}
	glEnd();



	//stand of lamp

	glColor3f(.3,.3,.3);
	glBegin(GL_QUADS);
   glVertex2f(0.91f,-0.475f);
   glVertex2f(.93f,-0.475f);
   glVertex2f(.93f,-0.65f);
   glVertex2f(.91f,-0.65f);

   glEnd();


   //flag beside school

   //main green body
   glColor3f(.39,0.67,.38);
   glBegin(GL_QUADS);
   glVertex2f(0.41f,-0.49f);
   glVertex2f(.26f,-0.49f);
   glVertex2f(.26f,-0.38f);
   glVertex2f(.41f,-0.38f);

   glEnd();


   //red circle
    glColor3f(1,0,0);
   int i14;

	GLfloat x14=.335f; GLfloat y14=-.435f; GLfloat radius14 =.04f;

	int triangleAmount14 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi14 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x14, y14); // center of circle
		for(i14 = 0; i14 <= triangleAmount14;i14++) {
			glVertex2f(
		            x14 + (radius14 * cos(i14 *  twicePi14 / triangleAmount14)),
			    y14 + (radius14 * sin(i14 * twicePi14 / triangleAmount14))
			);
		}
	glEnd();



   //stand of flag

   glColor3f(.38,.20,.07);
	glBegin(GL_QUADS);
   glVertex2f(0.26f,-0.38f);
   glVertex2f(.24f,-0.38f);
   glVertex2f(.24f,-0.65f);
   glVertex2f(.26f,-0.65f);

   glEnd();


   //tree beside flag

   //lower part
   glColor3f(0.32,.48,0.35);
   glBegin(GL_TRIANGLES);
   glVertex2f(.08f,-0.5f);
   glVertex2f(.14f,-0.37f);
   glVertex2f(.2f,-0.5f);

   glEnd();


   //upper part
   glColor3f(0.47,.67,0.27);
   glBegin(GL_TRIANGLES);
   glVertex2f(.09f,-0.43f);
   glVertex2f(.14f,-0.22f);
   glVertex2f(.19f,-0.43f);

   glEnd();


   //log of tree

   glColor3f(.42,0.26,0.15);
   glBegin(GL_QUADS);
   glVertex2f(.12f,-.5f);
   glVertex2f(.16f,-.5f);
   glVertex2f(.16f,-.65f);
   glVertex2f(.12f,-.65f);

   glEnd();


   //cafe building

   //main building
   glColor3f(1.0,1.0,.67);
   glBegin(GL_QUADS);
   glVertex2f(-.95f,-.4f);
   glVertex2f(-.65f,-.4f);
   glVertex2f(-.65f,-.65f);
   glVertex2f(-.95f,-.65f);

   glEnd();


   //upper left

   glColor3f(.71,.49,.24);
   glBegin(GL_QUADS);
   glVertex2f(-.95f,-.4f);
   glVertex2f(-.85f,-.4f);
   glVertex2f(-.85f,-.45f);
   glVertex2f(-.95f,-.45f);

   glEnd();


   //upper middle

   glColor3f(0.90,0.74,0.23);
   glBegin(GL_QUADS);
   glVertex2f(-.85f,-.4f);
   glVertex2f(-.75f,-.4f);
   glVertex2f(-.75f,-.45f);
   glVertex2f(-.85f,-.45f);

   glEnd();


   //upper right

   glColor3f(.71,.49,.24);
   glBegin(GL_QUADS);
   glVertex2f(-.75f,-.4f);
   glVertex2f(-.65f,-.4f);
   glVertex2f(-.65f,-.45f);
   glVertex2f(-.75f,-.45f);

   glEnd();


   //door of cafe

   glColor3f(.71,.49,.24);
   glBegin(GL_QUADS);
   glVertex2f(-.92f,-.5f);
   glVertex2f(-.82f,-.5f);
   glVertex2f(-.82f,-.65f);
   glVertex2f(-.92f,-.65f);

   glEnd();


   //window upper
   glColor3f(.71,.49,.24);
   glBegin(GL_QUADS);
   glVertex2f(-.78f,-.5f);
   glVertex2f(-.68f,-.5f);
   glVertex2f(-.68f,-.55f);
   glVertex2f(-.78f,-.55f);

   glEnd();


   //window lower
   glColor3f(.71,.49,.24);
   glBegin(GL_QUADS);
   glVertex2f(-.78f,-.56f);
   glVertex2f(-.68f,-.56f);
   glVertex2f(-.68f,-.61f);
   glVertex2f(-.78f,-.61f);

   glEnd();


   //roadside lamp beside cafe

   glColor3f(.55,0.55,.48);
   int i15;

	GLfloat x15=-.57f; GLfloat y15=-.42f; GLfloat radius15 =.06f;

	int triangleAmount15 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi15 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x15, y15); // center of circle
		for(i15 = 0; i15 <= triangleAmount15;i15++) {
			glVertex2f(
		            x15 + (radius15 * cos(i15 *  twicePi15 / triangleAmount15)),
			    y15 + (radius15 * sin(i15 * twicePi15 / triangleAmount15))
			);
		}
	glEnd();



	//stand of lamp

	glColor3f(.3,.3,.3);
	glBegin(GL_QUADS);
   glVertex2f(-0.56f,-0.475f);
   glVertex2f(-.58f,-0.475f);
   glVertex2f(-.58f,-0.65f);
   glVertex2f(-.56f,-0.65f);

   glEnd();


   //tree beside cafe

   //lower part
   glColor3f(0.32,.48,0.35);
   glBegin(GL_TRIANGLES);
   glVertex2f(-.47f,-0.5f);
   glVertex2f(-.41f,-0.37f);
   glVertex2f(-.35f,-0.5f);

   glEnd();


   //upper part
   glColor3f(0.47,.67,0.27);
   glBegin(GL_TRIANGLES);
   glVertex2f(-.46f,-0.43f);
   glVertex2f(-.41f,-0.22f);
   glVertex2f(-.36f,-0.43f);

   glEnd();

   //log of tree

   glColor3f(.42,0.26,0.15);
   glBegin(GL_QUADS);
   glVertex2f(-.39f,-.5f);
   glVertex2f(-.43f,-.5f);
   glVertex2f(-.43f,-.65f);
   glVertex2f(-.39f,-.65f);

   glEnd();


   //shaheed minar

   //red sun of shaheed minar

   glColor3f(1,0,0);
   int i16;

	GLfloat x16=-.13f; GLfloat y16=-.45f; GLfloat radius16 =.12f;

	int triangleAmount16 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi16 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x16, y16); // center of circle
		for(i16 = 0; i16 <= triangleAmount16;i16++) {
			glVertex2f(
		            x16 + (radius16 * cos(i16 *  twicePi16 / triangleAmount16)),
			    y16 + (radius16 * sin(i16 * twicePi16 / triangleAmount16))
			);
		}
	glEnd();




   //pillar leftmost

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.22f,-.3f);
   glVertex2f(-.18f,-.3f);
   glVertex2f(-.18f,-.65f);
   glVertex2f(-.22f,-.65f);

   glEnd();


   //pillar middle

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.15f,-.3f);
   glVertex2f(-.11f,-.3f);
   glVertex2f(-.11f,-.65f);
   glVertex2f(-.15f,-.65f);

   glEnd();


   //pillar rightmost

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.08f,-.3f);
   glVertex2f(-.04f,-.3f);
   glVertex2f(-.04f,-.65f);
   glVertex2f(-.08f,-.65f);

   glEnd();


   //pillar upper

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.22f,-.26f);
   glVertex2f(-.04f,-.26f);
   glVertex2f(-.04f,-.3f);
   glVertex2f(-.22f,-.3f);

   glEnd();




   // raining upper row

   glLoadIdentity();
   glPushMatrix();
   glTranslatef(0.0,position7, 0.0f);
   speed1 = 0.5f;
   //from left 0
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(-.95f,.8f);
   glVertex2f(-.9f,.85f);

   glEnd();


   //from left 1
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(-.8f,.8f);
   glVertex2f(-.75f,.85f);

   glEnd();


   //from left 2
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(-.65f,.8f);
   glVertex2f(-.6f,.85f);

   glEnd();


   //from left 3
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(-.5f,.8f);
   glVertex2f(-.45f,.85f);

   glEnd();


    //from left 5
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(-.35f,.8f);
   glVertex2f(-.3f,.85f);

   glEnd();


   //from left 6
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(-.2f,.8f);
   glVertex2f(-.15f,.85f);

   glEnd();


   //from left 7
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(-.05f,.8f);
   glVertex2f(-.0f,.85f);

   glEnd();


   //from left 8
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(.1f,.8f);
   glVertex2f(.15f,.85f);

   glEnd();


   //from left 9
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(.25f,.8f);
   glVertex2f(.3f,.85f);

   glEnd();


   //from left 10
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(.4f,.8f);
   glVertex2f(.45f,.85f);

   glEnd();


    //from left 11
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(.55f,.8f);
   glVertex2f(.6f,.85f);

   glEnd();


   //from left 12
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(.7f,.8f);
   glVertex2f(.75f,.85f);

   glEnd();


    //from left 13
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(.85f,.8f);
   glVertex2f(.9f,.85f);

   glEnd();


   //middle row of rain

   //from left 0
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(-.95f,.15f);
   glVertex2f(-.9f,.2f);

   glEnd();


   //from left 1
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(-.8f,.15f);
   glVertex2f(-.75f,.2f);

   glEnd();


   //from left 2
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(-.65f,.15f);
   glVertex2f(-.6f,.2f);

   glEnd();


   //from left 3
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(-.5f,.15f);
   glVertex2f(-.45f,.2f);

   glEnd();


    //from left 5
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(-.35f,.15f);
   glVertex2f(-.3f,.2f);

   glEnd();


   //from left 6
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(-.2f,.15f);
   glVertex2f(-.15f,.2f);

   glEnd();


   //from left 7
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(-.05f,.15f);
   glVertex2f(-.0f,.2f);

   glEnd();


   //from left 8
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(.1f,.15);
   glVertex2f(.15f,.2f);

   glEnd();


   //from left 9
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(.25f,.15f);
   glVertex2f(.3f,.2f);

   glEnd();


   //from left 10
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(.4f,.15f);
   glVertex2f(.45f,.2f);

   glEnd();


    //from left 11
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(.55f,.15f);
   glVertex2f(.6f,.2f);

   glEnd();


   //from left 12
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(.7f,.15f);
   glVertex2f(.75f,.2f);

   glEnd();


    //from left 13
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(.85f,.15f);
   glVertex2f(.9f,.2f);

   glEnd();


   //lower row of raining
   //from left 0
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(-.95f,-.6f);
   glVertex2f(-.9f,-.55f);

   glEnd();


   //from left 1
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(-.8f,-.6f);
   glVertex2f(-.75f,-.55f);

   glEnd();


   //from left 2
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(-.65f,-.6f);
   glVertex2f(-.6f,-.55f);

   glEnd();


   //from left 3
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(-.5f,-.6f);
   glVertex2f(-.45f,-.55f);

   glEnd();


    //from left 5
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(-.35f,-.6f);
   glVertex2f(-.3f,-.55f);

   glEnd();


   //from left 6
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(-.2f,-.6f);
   glVertex2f(-.15f,-.55f);

   glEnd();


   //from left 7
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(-.05f,-.6f);
   glVertex2f(-.0f,-.55f);

   glEnd();


   //from left 8
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(.1f,-.6);
   glVertex2f(.15f,-.55f);

   glEnd();


   //from left 9
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(.25f,-.6f);
   glVertex2f(.3f,-.55f);

   glEnd();


   //from left 10
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(.4f,-.6f);
   glVertex2f(.45f,-.55f);

   glEnd();


    //from left 11
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(.55f,-.6f);
   glVertex2f(.6f,-.55f);

   glEnd();


   //from left 12
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(.7f,-.6f);
   glVertex2f(.75f,-.55f);

   glEnd();


    //from left 13
   glColor3f(0,0,0);
   glBegin(GL_LINES);

   glVertex2f(.85f,-.6f);
   glVertex2f(.9f,-.55f);

   glEnd();
   glPopMatrix();
    glutTimerFunc(5000,display_night_view,0);
   glFlush();

}

void display_raining_view(int val) {

 glutDisplayFunc(display_raining);



}
void display_day() {
   glClear(GL_COLOR_BUFFER_BIT);


   //sky

   glColor3f(0.20,.63,.87);
   glBegin(GL_QUADS);
   glVertex2f(-1.0f,1.0f);
   glVertex2f(1.0f,1.0f);
   glVertex2f(1.0f,0.5f);
   glVertex2f(-1.0f,0.5f);

   glEnd();



   //sun
   glLoadIdentity();
   glPushMatrix();
   glTranslatef(0.0,position8, 0.0f);
   speed8 = 0.009f;
   glColor3f(1,1,0);
   int i1;

	GLfloat x1=.7f; GLfloat y1=0.4f; GLfloat radius1 =.15f;

	int triangleAmount1 = 20; //# of triangles used to draw circle


	GLfloat twicePi1 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount1;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi1 / triangleAmount1)),
			    y1 + (radius1 * sin(i1 * twicePi1 / triangleAmount1))
			);
		}
	glEnd();

	glPopMatrix();


	//left cloud

    glLoadIdentity();
   glPushMatrix();
   glTranslatef(position1,0.0, 0.0f);
   speed1 = 0.02f;
	//cloud upper middle

	glColor3f(1,1,1);
   int i2;

	GLfloat x2=-.65f; GLfloat y2=.9f; GLfloat radius2 =.08f;

	int triangleAmount2 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2, y2); // center of circle
		for(i2 = 0; i2 <= triangleAmount2;i2++) {
			glVertex2f(
		            x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
			);
		}
	glEnd();



	//cloud left middle

	glColor3f(1,1,1);
   int i3;

	GLfloat x3=-.75f; GLfloat y3=.85f; GLfloat radius3 =.08f;

	int triangleAmount3 = 20; //# of triangles used to draw circle


	GLfloat twicePi3 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3, y3); // center of circle
		for(i3 = 0; i3 <= triangleAmount3;i3++) {
			glVertex2f(
		            x3 + (radius3 * cos(i3 *  twicePi3 / triangleAmount3)),
			    y3 + (radius3 * sin(i3 * twicePi3 / triangleAmount3))
			);
		}
	glEnd();



	//cloud in right middle

	glColor3f(1,1,1);
   int i4;

	GLfloat x4=-.55f; GLfloat y4=.85f; GLfloat radius4 =.08f;

	int triangleAmount4 = 20; //# of triangles used to draw circle


	GLfloat twicePi4 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x4, y4); // center of circle
		for(i4 = 0; i4 <= triangleAmount4;i4++) {
			glVertex2f(
		            x4 + (radius4 * cos(i4 *  twicePi4 / triangleAmount4)),
			    y4 + (radius4 * sin(i4 * twicePi4 / triangleAmount4))
			);
		}
	glEnd();



	//cloud in the lower right

	glColor3f(1,1,1);
   int i5;

	GLfloat x5=-.6f; GLfloat y5=.8f; GLfloat radius5 =.08f;

	int triangleAmount5 = 20; //# of triangles used to draw circle


	GLfloat twicePi5 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x5, y5); // center of circle
		for(i5 = 0; i5 <= triangleAmount5;i5++) {
			glVertex2f(
		            x5 + (radius5 * cos(i5 *  twicePi5 / triangleAmount5)),
			    y5 + (radius5 * sin(i5 * twicePi5 / triangleAmount5))
			);
		}
	glEnd();



	//cloud in the lower left

	glColor3f(1,1,1);
   int i6;

	GLfloat x6=-.7f; GLfloat y6=.8f; GLfloat radius6 =.08f;

	int triangleAmount6 = 20; //# of triangles used to draw circle

	GLfloat twicePi6 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x6, y6); // center of circle
		for(i6 = 0; i6 <= triangleAmount6;i6++) {
			glVertex2f(
		            x6 + (radius6 * cos(i6 *  twicePi6 / triangleAmount6)),
			    y6 + (radius6 * sin(i6 * twicePi6 / triangleAmount6))
			);
		}
	glEnd();
    glPopMatrix();



	//plane

	glLoadIdentity();
   glPushMatrix();
   glTranslatef(position2,0.0, 0.0f);
   speed2 = 0.1f;
    //body of plane

   glColor3f(1.0,.95,.71);
   glBegin(GL_QUADS);
   glVertex2f(-.35f,0.8f);
   glVertex2f(.1f,0.8f);
   glVertex2f(.1f,0.7f);
   glVertex2f(-.35f,0.7f);

   glEnd();


   //front of plane

   glColor3f(1,0,0);
   glBegin(GL_TRIANGLES);
   glVertex2f(.1f,0.8f);
   glVertex2f(.2f,0.75f);
   glVertex2f(.1f,0.7f);

   glEnd();


   //tail of plane

   glColor3f(1,0,0);
   glBegin(GL_QUADS);
   glVertex2f(-.35f,0.9f);
   glVertex2f(-.32f,0.9f);
   glVertex2f(-.25f,0.8f);
   glVertex2f(-.35f,0.8f);

   glEnd();


   //upper fan of plane

   glColor3f(1,0,0);
   glBegin(GL_QUADS);
   glVertex2f(-.05f,0.9f);
   glVertex2f(-.15f,0.9f);
   glVertex2f(-.1f,0.8f);
   glVertex2f(0.0f,0.8f);

   glEnd();


   //lower  fan of plane

   glColor3f(1,0,0);
   glBegin(GL_QUADS);
   glVertex2f(0.0f,0.72f);
   glVertex2f(-.05f,0.6f);
   glVertex2f(-.15f,0.6f);
   glVertex2f(-.1f,0.72f);

   glEnd();


   //window 1 from right

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(0.04f,0.73f);
   glVertex2f(.04f,0.78f);
   glVertex2f(-.04f,0.78f);
   glVertex2f(-.04f,0.73f);

   glEnd();


   //window 2 from right

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-0.08f,0.73f);
   glVertex2f(-.08f,0.78f);
   glVertex2f(-.16f,0.78f);
   glVertex2f(-.16f,0.73f);

   glEnd();


   //window 3 from right

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-0.20f,0.73f);
   glVertex2f(-.20f,0.78f);
   glVertex2f(-.28f,0.78f);
   glVertex2f(-.28f,0.73f);

   glEnd();
   glPopMatrix();


   //road behind skyscraper 1,2,3,4

   glColor3f(0.77,0.77,0.77);
   glBegin(GL_QUADS);
   glVertex2f(-1.0f,0.5f);
   glVertex2f(1.0f,0.5f);
   glVertex2f(1.0f,0.1f);
   glVertex2f(-1.0f,0.1f);

   glEnd();


   //leftmost left line of road behind skyscraper 1,2,3,4

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-1.0f,.3f);
   glVertex2f(-.7f,.3f);
   glVertex2f(-.7f,.35f);
   glVertex2f(-1.f,.35f);

   glEnd();

   //rightmost left line of road behind skyscraper 1,2,3,4

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.55f,.3f);
   glVertex2f(-.25f,.3f);
   glVertex2f(-.25f,.35f);
   glVertex2f(-.55f,.35f);

   glEnd();


   //middle line of road behind skyscraper 1,2,3,4

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.05f,.3f);
   glVertex2f(.3f,.3f);
   glVertex2f(.3f,.35f);
   glVertex2f(-.05f,.35f);

   glEnd();


   //right line of road behind skyscraper 1,2,3,4

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(.6f,.3f);
   glVertex2f(1.0f,.3f);
   glVertex2f(1.0f,.35f);
   glVertex2f(.6f,.35f);

   glEnd();


   //car behind skyscraper 1,2,3,4

   glLoadIdentity();
   glPushMatrix();
   glTranslatef(position3,0.0, 0.0f);
   speed3 = 0.15f;
   //main body
   glColor3f(.38,0.20,0.07);
   glBegin(GL_QUADS);
   glVertex2f(-0.3f,0.45f);
   glVertex2f(.05f,0.45f);
   glVertex2f(.05f,0.25f);
   glVertex2f(-.3f,0.25f);

   glEnd();


   //window 1

   glColor3f(.40,.56,.53);

   glBegin(GL_QUADS);
   glVertex2f(0.01f,0.385f);
   glVertex2f(-.1f,0.385f);
   glVertex2f(-.1f,0.31f);
   glVertex2f(.01f,0.31f);

   glEnd();


   //window 2

   glColor3f(.40,.56,.53);
   glBegin(GL_QUADS);
   glVertex2f(-0.25f,0.385f);
   glVertex2f(-.14f,0.385f);
   glVertex2f(-.14f,0.31f);
   glVertex2f(-.25f,0.31f);

   glEnd();


   //backwheel outer

   glColor3f(0,0,0);
   int i9;

	GLfloat x9=-.2f; GLfloat y9=.22f; GLfloat radius9 =.062f;

	int triangleAmount9 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi9 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x9, y9); // center of circle
		for(i9 = 0; i9<= triangleAmount9;i9++) {
			glVertex2f(
		            x9 + (radius9 * cos(i9 *  twicePi9 / triangleAmount9)),
			    y9 + (radius9 * sin(i9 * twicePi9 / triangleAmount9))
			);
		}
	glEnd();


	//backwheel inner

   glColor3f(1,1,1);
   int i11;

	GLfloat x11=-.2f; GLfloat y11=.22f; GLfloat radius11 =.045f;

	int triangleAmount11 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi11 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x11, y11); // center of circle
		for(i11 = 0; i11<= triangleAmount11;i11++) {
			glVertex2f(
		            x11 + (radius11 * cos(i11 *  twicePi11 / triangleAmount11)),
			    y11 + (radius11 * sin(i11 * twicePi11/ triangleAmount11))
			);
		}
	glEnd();




   //front part
   glColor3f(0.62,0.02,0.03);

   glBegin(GL_QUADS);
   glVertex2f(0.05f,0.45f);
   glVertex2f(.25f,0.4f);
   glVertex2f(.25f,0.25f);
   glVertex2f(.05f,0.25f);

   glEnd();

   //window
   glColor3f(.40,.56,.53);

   glBegin(GL_QUADS);
   glVertex2f(0.1f,0.385f);
   glVertex2f(.2f,0.385f);
   glVertex2f(.2f,0.31f);
   glVertex2f(.1f,0.31f);

   glEnd();


   //front wheel outer

	glColor3f(0,0,0);
   int i10;

	GLfloat x10=.15f; GLfloat y10=.22f; GLfloat radius10 =.062f;

	int triangleAmount10 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi10 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x10, y10); // center of circle
		for(i10 = 0; i10<= triangleAmount10;i10++) {
			glVertex2f(
		            x10 + (radius10 * cos(i10 *  twicePi10 / triangleAmount10)),
			    y10 + (radius10 * sin(i10 * twicePi10 / triangleAmount10))
			);
		}
	glEnd();




   //front wheel inner

	glColor3f(1,1,1);
   int i12;

	GLfloat x12=.15f; GLfloat y12=.22f; GLfloat radius12 =.045f;

	int triangleAmount12 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi12 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x12, y12); // center of circle
		for(i12 = 0; i12<= triangleAmount12;i12++) {
			glVertex2f(
		            x12 + (radius12 * cos(i12 *  twicePi12 / triangleAmount12)),
			    y12 + (radius12 * sin(i12 * twicePi12 / triangleAmount12))
			);
		}
	glEnd();
    glPopMatrix();


   //skycraper 1

   glColor3f(.56,0.74,.56);
   glBegin(GL_QUADS);
   glVertex2f(-0.95f,0.55f);
   glVertex2f(-.65f,0.55f);
   glVertex2f(-.65f,0.1f);
   glVertex2f(-.95f,0.1f);

   glEnd();


   //window 1 from upper left

   glColor3f(.23,.52,.44);
   glBegin(GL_QUADS);
   glVertex2f(-0.9f,0.5f);
   glVertex2f(-.82f,0.5f);
   glVertex2f(-.82f,0.42f);
   glVertex2f(-.9f,0.42f);

   glEnd();


   //window 2
   glColor3f(.23,.52,.44);
   glBegin(GL_QUADS);
   glVertex2f(-0.77f,0.5f);
   glVertex2f(-.69f,0.5f);
   glVertex2f(-.69f,0.42f);
   glVertex2f(-.77f,0.42f);

   glEnd();


   //window 3

   glColor3f(.23,.52,.44);
   glBegin(GL_QUADS);
   glVertex2f(-0.9f,0.37f);
   glVertex2f(-.82f,0.37f);
   glVertex2f(-.82f,0.29f);
   glVertex2f(-.9f,0.29f);

   glEnd();


   //window 4

   glColor3f(.23,.52,.44);
   glBegin(GL_QUADS);
   glVertex2f(-0.77f,0.37f);
   glVertex2f(-.69f,0.37f);
   glVertex2f(-.69f,0.29f);
   glVertex2f(-.77f,0.29f);

   glEnd();


   //window 5

   glColor3f(.23,.52,.44);
   glBegin(GL_QUADS);
   glVertex2f(-0.9f,0.24f);
   glVertex2f(-.82f,0.24f);
   glVertex2f(-.82f,0.16f);
   glVertex2f(-.9f,0.16f);

   glEnd();


   //window 6

   glColor3f(.23,.52,.44);
   glBegin(GL_QUADS);
   glVertex2f(-0.77f,0.24f);
   glVertex2f(-.69f,0.24f);
   glVertex2f(-.69f,0.16f);
   glVertex2f(-.77f,0.16f);

   glEnd();


   //tree beside skyscraper 1

   //lower part
   glColor3f(0.32,.48,0.35);
   glBegin(GL_TRIANGLES);
   glVertex2f(-.63f,0.25f);
   glVertex2f(-.57f,0.38f);
   glVertex2f(-.51f,0.25f);

   glEnd();


   //upper part
   glColor3f(0.47,.67,0.27);
   glBegin(GL_TRIANGLES);
   glVertex2f(-.62f,0.32f);
   glVertex2f(-.57f,0.55f);
   glVertex2f(-.52f,0.32f);

   glEnd();


   //log of tree

   glColor3f(.42,0.26,0.15);
   glBegin(GL_QUADS);
   glVertex2f(-.55f,.25f);
   glVertex2f(-.59f,.25f);
   glVertex2f(-.59f,.1f);
   glVertex2f(-.55f,.1f);

   glEnd();


   //skyscraper 2

   glColor3f(0.55,0.37,0.40);
   glBegin(GL_QUADS);
   glVertex2f(-.48f,.42f);
   glVertex2f(-.18f,.42f);
   glVertex2f(-.18f,.1f);
   glVertex2f(-.48f,.1f);

   glEnd();

   //window 1 from upper left

    glColor3f(.33,.06,.20);
   glBegin(GL_QUADS);
   glVertex2f(-0.43f,0.37f);
   glVertex2f(-.35f,0.37f);
   glVertex2f(-.35f,0.29f);
   glVertex2f(-.43f,0.29f);

   glEnd();


   //window 2

   glColor3f(.33,.06,.20);
   glBegin(GL_QUADS);
   glVertex2f(-0.3f,0.37f);
   glVertex2f(-.22f,0.37f);
   glVertex2f(-.22f,0.29f);
   glVertex2f(-.3f,0.29f);

   glEnd();


   //window 3

    glColor3f(.33,.06,.20);
   glBegin(GL_QUADS);
   glVertex2f(-0.43f,0.24f);
   glVertex2f(-.35f,0.24f);
   glVertex2f(-.35f,0.16f);
   glVertex2f(-.43f,0.16f);

   glEnd();


   //window 4

    glColor3f(.33,.06,.20);
   glBegin(GL_QUADS);
   glVertex2f(-0.3f,0.24f);
   glVertex2f(-.22f,0.24f);
   glVertex2f(-.22f,0.16f);
   glVertex2f(-.3f,0.16f);

   glEnd();


   //roadside lamp beside skyscraper 2

   glColor3f(.55,0.55,.48);
   int i7;

	GLfloat x7=-.1f; GLfloat y7=.33f; GLfloat radius7 =.06f;

	int triangleAmount7 = 20; //# of triangles used to draw circle


	GLfloat twicePi7 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x7, y7); // center of circle
		for(i7 = 0; i7 <= triangleAmount7;i7++) {
			glVertex2f(
		            x7 + (radius7 * cos(i7 *  twicePi7 / triangleAmount7)),
			    y7 + (radius7 * sin(i7 * twicePi7 / triangleAmount7))
			);
		}
	glEnd();



	//stand of lamp

	glColor3f(.3,.3,.3);
	glBegin(GL_QUADS);
   glVertex2f(-0.09f,0.275f);
   glVertex2f(-.11f,0.275f);
   glVertex2f(-.11f,0.1f);
   glVertex2f(-.09f,0.1f);

   glEnd();


   //skyscraper 3

   glColor3f(.82,.57,.46);
   glBegin(GL_QUADS);
   glVertex2f(-0.02f,0.55f);
   glVertex2f(.38f,0.55f);
   glVertex2f(.38f,0.1f);
   glVertex2f(-0.02f,0.1f);

   glEnd();


   //window 1 from upper left

   glColor3f(.80,.41,.22);
   glBegin(GL_QUADS);
   glVertex2f(0.02f,0.5f);
   glVertex2f(.1f,0.5f);
   glVertex2f(.1f,0.42f);
   glVertex2f(.02f,0.42f);

   glEnd();


   //window 2

   glColor3f(.80,.41,.22);
   glBegin(GL_QUADS);
   glVertex2f(0.14f,0.5f);
   glVertex2f(.22f,0.5f);
   glVertex2f(.22f,0.42f);
   glVertex2f(.14f,0.42f);

   glEnd();


   //window 3

   glColor3f(.80,.41,.22);
   glBegin(GL_QUADS);
   glVertex2f(0.26f,0.5f);
   glVertex2f(.34f,0.5f);
   glVertex2f(.34f,0.42f);
   glVertex2f(.26f,0.42f);

   glEnd();


   //window 4

   glColor3f(.80,.41,.22);
   glBegin(GL_QUADS);
   glVertex2f(0.02f,0.37f);
   glVertex2f(.1f,0.37f);
   glVertex2f(.1f,0.29f);
   glVertex2f(.02f,0.29f);

   glEnd();


   //window 5

   glColor3f(.80,.41,.22);
   glBegin(GL_QUADS);
   glVertex2f(0.14f,0.37f);
   glVertex2f(.22f,0.37f);
   glVertex2f(.22f,0.29f);
   glVertex2f(.14f,0.29f);

   glEnd();


   //window 6

   glColor3f(.80,.41,.22);
   glBegin(GL_QUADS);
   glVertex2f(0.26f,0.37f);
   glVertex2f(.34f,0.37f);
   glVertex2f(.34f,0.29f);
   glVertex2f(.26f,0.29f);

   glEnd();

   //window 7

    glColor3f(.80,.41,.22);
   glBegin(GL_QUADS);
   glVertex2f(0.02f,0.24f);
   glVertex2f(.1f,0.24f);
   glVertex2f(.1f,0.16f);
   glVertex2f(.02f,0.16f);

   glEnd();


   //window 8

   glColor3f(.80,.41,.22);
   glBegin(GL_QUADS);
   glVertex2f(0.14f,0.24f);
   glVertex2f(.22f,0.24f);
   glVertex2f(.22f,0.16f);
   glVertex2f(.14f,0.16f);

   glEnd();


   //window 9

   glColor3f(.80,.41,.22);
   glBegin(GL_QUADS);
   glVertex2f(0.26f,0.24f);
   glVertex2f(.34f,0.24f);
   glVertex2f(.34f,0.16f);
   glVertex2f(.26f,0.16f);

   glEnd();


   //tree beside skyscraper 3


   //lower part
   glColor3f(0.32,.48,0.35);
   glBegin(GL_TRIANGLES);
   glVertex2f(.4f,0.25f);
   glVertex2f(.46f,0.38f);
   glVertex2f(.52f,0.25f);

   glEnd();


   //upper part
   glColor3f(0.47,.67,0.27);
   glBegin(GL_TRIANGLES);
   glVertex2f(.41f,0.32f);
   glVertex2f(.46f,0.55f);
   glVertex2f(.51f,0.32f);

   glEnd();


   //log of tree

   glColor3f(.42,0.26,0.15);
   glBegin(GL_QUADS);
   glVertex2f(.44f,.25f);
   glVertex2f(.48f,.25f);
   glVertex2f(.48f,.1f);
   glVertex2f(.44f,.1f);

   glEnd();



   //skyscraper 4

   glColor3f(0.40,0.0,0.0);
   glBegin(GL_QUADS);
   glVertex2f(.54f,.42f);
   glVertex2f(.84f,.42f);
   glVertex2f(.84f,.1f);
   glVertex2f(.54f,.1f);

   glEnd();


   //window 1 from upper left

   glColor3f(.48,.28,.26);
   glBegin(GL_QUADS);
   glVertex2f(0.59f,0.37f);
   glVertex2f(.67f,0.37f);
   glVertex2f(.67f,0.29f);
   glVertex2f(.59f,0.29f);

   glEnd();


   //window 2

   glColor3f(.48,.28,.26);
   glBegin(GL_QUADS);
   glVertex2f(0.72f,0.37f);
   glVertex2f(.8f,0.37f);
   glVertex2f(.8f,0.29f);
   glVertex2f(.72f,0.29f);

   glEnd();


   //window 3

   glColor3f(.48,.28,.26);
   glBegin(GL_QUADS);
   glVertex2f(0.59f,0.24f);
   glVertex2f(.67f,0.24f);
   glVertex2f(.67f,0.16f);
   glVertex2f(.59f,0.16f);

   glEnd();


   //window 4

   glColor3f(.48,.28,.26);
   glBegin(GL_QUADS);
   glVertex2f(0.72f,0.24f);
   glVertex2f(.8f,0.24f);
   glVertex2f(.8f,0.16f);
   glVertex2f(.72f,0.16f);

   glEnd();


   //roadside lamp beside skyscraper 4

   glColor3f(.55,0.55,.48);
   int i8;

	GLfloat x8=.92f; GLfloat y8=.33f; GLfloat radius8 =.06f;

	int triangleAmount8 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi8 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x8, y8); // center of circle
		for(i8 = 0; i8 <= triangleAmount8;i8++) {
			glVertex2f(
		            x8 + (radius8 * cos(i8 *  twicePi8 / triangleAmount8)),
			    y8 + (radius8 * sin(i8 * twicePi8 / triangleAmount8))
			);
		}
	glEnd();



	//stand of lamp

	glColor3f(.3,.3,.3);
	glBegin(GL_QUADS);
   glVertex2f(0.91f,0.275f);
   glVertex2f(.93f,0.275f);
   glVertex2f(.93f,0.1f);
   glVertex2f(.91f,0.1f);

   glEnd();


   //footpath in front of skyscraper 1,2,3,4

   glColor3f(.3,.3,.3);
   glBegin(GL_QUADS);
   glVertex2f(-1.0f,0.1f);
   glVertex2f(1.0f,0.1f);
   glVertex2f(1.0f,0.05f);
   glVertex2f(-1.0f,0.05f);

   glEnd();


   //road behind school and park

   glColor3f(0.77,0.77,0.77);
   glBegin(GL_QUADS);
   glVertex2f(-1.0f,0.05f);
   glVertex2f(1.0f,0.05f);
   glVertex2f(1.0f,-1.0f);
   glVertex2f(-1.0f,-1.0f);

   glEnd();


   //lake

   glColor3f(0.20,.63,.87);
   glBegin(GL_QUADS);
   glVertex2f(-1.0f,-0.7f);
   glVertex2f(1.0f,-0.7f);
   glVertex2f(1.f,-1.0f);
   glVertex2f(-1.0f,-1.0f);

   glEnd();


   //boat in the lake

    glLoadIdentity();
   glPushMatrix();
   glTranslatef(position6,0.0, 0.0f);
   speed6 = 0.07f;
   //lower deck

   glColor3f(0.4,0.0,0.0);
   glBegin(GL_QUADS);
   glVertex2f(.0f,-.85f);
   glVertex2f(-.5f,-.85f);
   glVertex2f(-.4f,-0.95f);
   glVertex2f(-.1f,-0.95f);


    glEnd();


   //upper deck

   glColor3f(1.0,.95,.71);
   glBegin(GL_QUADS);
   glVertex2f(-.1f,-.75f);
   glVertex2f(-.4f,-.75f);
   glVertex2f(-.4f,-0.85f);
   glVertex2f(-.1f,-0.85f);


    glEnd();

   //window 1 from left

    glColor3f(0.55,0.37,0.40);
    glBegin(GL_QUADS);
   glVertex2f(-.31f,-.77f);
   glVertex2f(-.37f,-.77f);
   glVertex2f(-.37f,-0.83f);
   glVertex2f(-.31f,-0.83f);


    glEnd();


   //window 2

   glColor3f(0.55,0.37,0.40);
    glBegin(GL_QUADS);
   glVertex2f(-.28f,-.77f);
   glVertex2f(-.22f,-.77f);
   glVertex2f(-.22f,-0.83f);
   glVertex2f(-.28f,-0.83f);


    glEnd();

   //window 3

   glColor3f(0.55,0.37,0.40);
   glBegin(GL_QUADS);
   glVertex2f(-.19f,-.77f);
   glVertex2f(-.13f,-.77f);
   glVertex2f(-.13f,-0.83f);
   glVertex2f(-.19f,-0.83f);


    glEnd();
    glPopMatrix();

   // footpath in front of school and park

   glColor3f(.3,.3,.3);
   glBegin(GL_QUADS);
   glVertex2f(-1.0f,-0.7f);
   glVertex2f(1.0f,-0.7f);
   glVertex2f(1.0f,-0.65f);
   glVertex2f(-1.0f,-.65f);

   glEnd();


   //leftmost left line of road behind school

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-1.0f,-.3f);
   glVertex2f(-.7f,-.3f);
   glVertex2f(-.7f,-.35f);
   glVertex2f(-1.f,-.35f);

   glEnd();


   //rightmost left line of road

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.55f,-.3f);
   glVertex2f(-.25f,-.3f);
   glVertex2f(-.25f,-.35f);
   glVertex2f(-.55f,-.35f);

   glEnd();

   //middle line of road behind school

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.0f,-.3f);
   glVertex2f(.3f,-.3f);
   glVertex2f(.3f,-.35f);
   glVertex2f(-.0f,-.35f);

   glEnd();

   //right line of road behind school

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(.6f,-.3f);
   glVertex2f(1.0f,-.3f);
   glVertex2f(1.0f,-.35f);
   glVertex2f(.6f,-.35f);

   glEnd();


   //car in road behind school
   glLoadIdentity();
   glPushMatrix();
   glTranslatef(position4,0.0, 0.0f);
   speed4 = 0.15f;
   //lower body of car

   glColor3f(1,0,0);
   glBegin(GL_QUADS);
   glVertex2f(-.1f,-.08f);
   glVertex2f(.4f,-.08f);
   glVertex2f(.4f,-.2f);
   glVertex2f(-.1f,-.2f);

   glEnd();


   //upper body of car

   glColor3f(1,0,0);
   glBegin(GL_QUADS);
   glVertex2f(.05f,.02f);
   glVertex2f(.25f,.02f);
   glVertex2f(.33f,-.08f);
   glVertex2f(-.03f,-.08f);

   glEnd();

   //left window

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(.06f,-.0f);
   glVertex2f(.14f,-.0f);
   glVertex2f(.14f,-.08f);
   glVertex2f(.01f,-.08f);

   glEnd();


   //right window

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(.16f,-.0f);
   glVertex2f(.24f,-.0f);
   glVertex2f(.29f,-.08f);
   glVertex2f(.16f,-.08f);

   glEnd();


   //front wheel outer

    glColor3f(0,0,0);
   int i17;

	GLfloat x17=.0f; GLfloat y17=-.2f; GLfloat radius17 =.06f;

	int triangleAmount17 = 20; //# of triangles used to draw circle


	GLfloat twicePi17 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x17, y17); // center of circle
		for(i17 = 0; i17 <= triangleAmount17;i17++) {
			glVertex2f(
		            x17 + (radius17 * cos(i17 *  twicePi17 / triangleAmount17)),
			    y17 + (radius17 * sin(i17 * twicePi17 / triangleAmount17))
			);
		}
	glEnd();



	//front wheel inner

	glColor3f(1,1,1);
   int i18;

	GLfloat x18=.0f; GLfloat y18=-.2f; GLfloat radius18 =.04f;

	int triangleAmount18 = 20; //# of triangles used to draw circle


	GLfloat twicePi18 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x18, y18); // center of circle
		for(i18 = 0; i18 <= triangleAmount18;i18++) {
			glVertex2f(
		            x18 + (radius18 * cos(i18 *  twicePi18 / triangleAmount18)),
			    y18 + (radius18 * sin(i18 * twicePi18 / triangleAmount18))
			);
		}
	glEnd();


	//back wheel outer

	glColor3f(0,0,0);
   int i19;

	GLfloat x19=.3f; GLfloat y19=-.2f; GLfloat radius19 =.06f;

	int triangleAmount19 = 20; //# of triangles used to draw circle


	GLfloat twicePi19 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x19, y19); // center of circle
		for(i19 = 0; i19 <= triangleAmount19;i19++) {
			glVertex2f(
		            x19 + (radius19 * cos(i19 *  twicePi19 / triangleAmount19)),
			    y19 + (radius19 * sin(i19 * twicePi19 / triangleAmount19))
			);
		}
	glEnd();



	//back wheel inner

	glColor3f(1,1,1);
   int i20;

	GLfloat x20=.3f; GLfloat y20=-.2f; GLfloat radius20 =.04f;

	int triangleAmount20 = 20; //# of triangles used to draw circle


	GLfloat twicePi20 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x20, y20); // center of circle
		for(i20 = 0; i20 <= triangleAmount20;i20++) {
			glVertex2f(
		            x20 + (radius20 * cos(i20 *  twicePi20 / triangleAmount20)),
			    y20 + (radius20 * sin(i20 * twicePi20 / triangleAmount20))
			);
		}
	glEnd();
    glPopMatrix();


	//bus

	glLoadIdentity();
   glPushMatrix();
   glTranslatef(position5,0.0, 0.0f);
   speed5 = 0.15f;
	//main body

	glColor3f(.47,0.63,0.53);
   glBegin(GL_QUADS);
   glVertex2f(-.7f,-.38f);
   glVertex2f(-.1f,-.38f);
   glVertex2f(-.1f,-.58f);
   glVertex2f(-.7f,-.58f);

   glEnd();

   //back wheel outer

   glColor3f(0,0,0);
   int i21;

	GLfloat x21=-.6f; GLfloat y21=-.58f; GLfloat radius21 =.06f;

	int triangleAmount21 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi21 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x21, y21); // center of circle
		for(i21 = 0; i21 <= triangleAmount21;i21++) {
			glVertex2f(
		            x21 + (radius21 * cos(i21 *  twicePi21 / triangleAmount21)),
			    y21 + (radius21 * sin(i21 * twicePi21 / triangleAmount21))
			);
		}
	glEnd();



	//back wheel inner

	glColor3f(1,1,1);
   int i22;

	GLfloat x22=-.6f; GLfloat y22=-.58f; GLfloat radius22 =.04f;

	int triangleAmount22 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi22 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x22, y22); // center of circle
		for(i22 = 0; i22 <= triangleAmount21;i22++) {
			glVertex2f(
		            x22 + (radius22 * cos(i22 *  twicePi22 / triangleAmount22)),
			    y22 + (radius22 * sin(i22 * twicePi22 / triangleAmount22))
			);
		}
	glEnd();



	//front wheel outer

	glColor3f(0,0,0);
   int i23;

	GLfloat x23=-.2f; GLfloat y23=-.58f; GLfloat radius23 =.06f;

	int triangleAmount23 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi23 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x23, y23); // center of circle
		for(i23 = 0; i23 <= triangleAmount23;i23++) {
			glVertex2f(
		            x23 + (radius23 * cos(i23 *  twicePi23 / triangleAmount23)),
			    y23 + (radius23 * sin(i23 * twicePi23 / triangleAmount23))
			);
		}
	glEnd();


	//front wheel inner

	glColor3f(1,1,1);
   int i24;

	GLfloat x24=-.2f; GLfloat y24=-.58f; GLfloat radius24 =.04f;

	int triangleAmount24 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi24 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x24, y24); // center of circle
		for(i24 = 0; i24 <= triangleAmount24;i24++) {
			glVertex2f(
		            x24 + (radius24 * cos(i24 *  twicePi24 / triangleAmount24)),
			    y24 + (radius24 * sin(i24 * twicePi24 / triangleAmount24))
			);
		}
	glEnd();



	//leftmost window

	glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.56f,-.4f);
   glVertex2f(-.66f,-.4f);
   glVertex2f(-.66f,-.5f);
   glVertex2f(-.56f,-.5f);

   glEnd();


   //leftmost middle window

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.52f,-.4f);
   glVertex2f(-.42f,-.4f);
   glVertex2f(-.42f,-.5f);
   glVertex2f(-.52f,-.5f);

   glEnd();


   //rightmost middle window

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.38f,-.4f);
   glVertex2f(-.28f,-.4f);
   glVertex2f(-.28f,-.5f);
   glVertex2f(-.38f,-.5f);

   glEnd();


   //rightmost window

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.24f,-.4f);
   glVertex2f(-.14f,-.4f);
   glVertex2f(-.14f,-.5f);
   glVertex2f(-.24f,-.5f);

   glEnd();
   glPopMatrix();



   //school building


   glColor3f(.65,.50,.69);
   glBegin(GL_QUADS);
   glVertex2f(.43f,-.35f);
   glVertex2f(.84f,-.35f);
   glVertex2f(.84f,-.65f);
   glVertex2f(.43f,-.65f);

   glEnd();


   //window 1 from upper right

   glColor3f(.65,.30,.67);
   glBegin(GL_QUADS);
   glVertex2f(0.72f,-0.46f);
   glVertex2f(.8f,-0.46f);
   glVertex2f(.8f,-0.38f);
   glVertex2f(.72f,-0.38f);

   glEnd();


   //window 2

   glColor3f(.65,.30,.67);
   glBegin(GL_QUADS);
   glVertex2f(0.68f,-0.46f);
   glVertex2f(.6f,-0.46f);
   glVertex2f(.6f,-0.38f);
   glVertex2f(.68f,-0.38f);

   glEnd();


   //window 3

   glColor3f(.65,.30,.67);
   glBegin(GL_QUADS);
   glVertex2f(0.56f,-0.46f);
   glVertex2f(.48f,-0.46f);
   glVertex2f(.48f,-0.38f);
   glVertex2f(.56f,-0.38f);

   glEnd();


   //window 4

     glColor3f(.65,.30,.67);
   glBegin(GL_QUADS);
   glVertex2f(0.72f,-0.5f);
   glVertex2f(.8f,-0.5f);
   glVertex2f(.8f,-0.58f);
   glVertex2f(.72f,-0.58f);

   glEnd();


   //window 5

   glColor3f(.65,.30,.67);
   glBegin(GL_QUADS);
   glVertex2f(0.68f,-0.5f);
   glVertex2f(.6f,-0.5f);
   glVertex2f(.6f,-0.58f);
   glVertex2f(.68f,-0.58f);

   glEnd();


   //door of school

   glColor3f(.65,.30,.67);
   glBegin(GL_QUADS);
   glVertex2f(0.56f,-0.5f);
   glVertex2f(.48f,-0.5f);
   glVertex2f(.48f,-0.65f);
   glVertex2f(.56f,-0.65f);

   glEnd();


    //roadside lamp beside school

   glColor3f(.55,0.55,.48);
   int i13;

	GLfloat x13=.92f; GLfloat y13=-.42f; GLfloat radius13 =.06f;

	int triangleAmount13 = 20; //# of triangles used to draw circle


	GLfloat twicePi13 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x13, y13); // center of circle
		for(i13 = 0; i13 <= triangleAmount13;i13++) {
			glVertex2f(
		            x13 + (radius13 * cos(i13 *  twicePi13 / triangleAmount13)),
			    y13 + (radius13 * sin(i13 * twicePi13 / triangleAmount13))
			);
		}
	glEnd();



	//stand of lamp

	glColor3f(.3,.3,.3);
	glBegin(GL_QUADS);
   glVertex2f(0.91f,-0.475f);
   glVertex2f(.93f,-0.475f);
   glVertex2f(.93f,-0.65f);
   glVertex2f(.91f,-0.65f);

   glEnd();


   //flag beside school

   //main green body
   glColor3f(.39,0.67,.38);
   glBegin(GL_QUADS);
   glVertex2f(0.41f,-0.49f);
   glVertex2f(.26f,-0.49f);
   glVertex2f(.26f,-0.38f);
   glVertex2f(.41f,-0.38f);

   glEnd();


   //red circle
    glColor3f(1,0,0);
   int i14;

	GLfloat x14=.335f; GLfloat y14=-.435f; GLfloat radius14 =.04f;

	int triangleAmount14 = 20; //# of triangles used to draw circle


	GLfloat twicePi14 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x14, y14); // center of circle
		for(i14 = 0; i14 <= triangleAmount14;i14++) {
			glVertex2f(
		            x14 + (radius14 * cos(i14 *  twicePi14 / triangleAmount14)),
			    y14 + (radius14 * sin(i14 * twicePi14 / triangleAmount14))
			);
		}
	glEnd();



   //stand of flag

   glColor3f(.38,.20,.07);
	glBegin(GL_QUADS);
   glVertex2f(0.26f,-0.38f);
   glVertex2f(.24f,-0.38f);
   glVertex2f(.24f,-0.65f);
   glVertex2f(.26f,-0.65f);

   glEnd();


   //tree beside flag

   //lower part
   glColor3f(0.32,.48,0.35);
   glBegin(GL_TRIANGLES);
   glVertex2f(.08f,-0.5f);
   glVertex2f(.14f,-0.37f);
   glVertex2f(.2f,-0.5f);

   glEnd();


   //upper part
   glColor3f(0.47,.67,0.27);
   glBegin(GL_TRIANGLES);
   glVertex2f(.09f,-0.43f);
   glVertex2f(.14f,-0.22f);
   glVertex2f(.19f,-0.43f);

   glEnd();


   //log of tree

   glColor3f(.42,0.26,0.15);
   glBegin(GL_QUADS);
   glVertex2f(.12f,-.5f);
   glVertex2f(.16f,-.5f);
   glVertex2f(.16f,-.65f);
   glVertex2f(.12f,-.65f);

   glEnd();



   //cafe building

   //main building
   glColor3f(1.0,1.0,.67);
   glBegin(GL_QUADS);
   glVertex2f(-.95f,-.4f);
   glVertex2f(-.65f,-.4f);
   glVertex2f(-.65f,-.65f);
   glVertex2f(-.95f,-.65f);

   glEnd();


   //upper left

   glColor3f(.71,.49,.24);
   glBegin(GL_QUADS);
   glVertex2f(-.95f,-.4f);
   glVertex2f(-.85f,-.4f);
   glVertex2f(-.85f,-.45f);
   glVertex2f(-.95f,-.45f);

   glEnd();


   //upper middle

   glColor3f(0.90,0.74,0.23);
   glBegin(GL_QUADS);
   glVertex2f(-.85f,-.4f);
   glVertex2f(-.75f,-.4f);
   glVertex2f(-.75f,-.45f);
   glVertex2f(-.85f,-.45f);

   glEnd();


   //upper right

   glColor3f(.71,.49,.24);
   glBegin(GL_QUADS);
   glVertex2f(-.75f,-.4f);
   glVertex2f(-.65f,-.4f);
   glVertex2f(-.65f,-.45f);
   glVertex2f(-.75f,-.45f);

   glEnd();


   //door of cafe

   glColor3f(.71,.49,.24);
   glBegin(GL_QUADS);
   glVertex2f(-.92f,-.5f);
   glVertex2f(-.82f,-.5f);
   glVertex2f(-.82f,-.65f);
   glVertex2f(-.92f,-.65f);

   glEnd();


   //window upper
   glColor3f(.71,.49,.24);
   glBegin(GL_QUADS);
   glVertex2f(-.78f,-.5f);
   glVertex2f(-.68f,-.5f);
   glVertex2f(-.68f,-.55f);
   glVertex2f(-.78f,-.55f);

   glEnd();


   //window lower
   glColor3f(.71,.49,.24);
   glBegin(GL_QUADS);
   glVertex2f(-.78f,-.56f);
   glVertex2f(-.68f,-.56f);
   glVertex2f(-.68f,-.61f);
   glVertex2f(-.78f,-.61f);

   glEnd();


   //roadside lamp beside cafe

   glColor3f(.55,0.55,.48);
   int i15;

	GLfloat x15=-.57f; GLfloat y15=-.42f; GLfloat radius15 =.06f;

	int triangleAmount15 = 20; //# of triangles used to draw circle


	GLfloat twicePi15 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x15, y15); // center of circle
		for(i15 = 0; i15 <= triangleAmount15;i15++) {
			glVertex2f(
		            x15 + (radius15 * cos(i15 *  twicePi15 / triangleAmount15)),
			    y15 + (radius15 * sin(i15 * twicePi15 / triangleAmount15))
			);
		}
	glEnd();



	//stand of lamp

	glColor3f(.3,.3,.3);
	glBegin(GL_QUADS);
   glVertex2f(-0.56f,-0.475f);
   glVertex2f(-.58f,-0.475f);
   glVertex2f(-.58f,-0.65f);
   glVertex2f(-.56f,-0.65f);

   glEnd();


   //tree beside cafe

   //lower part
   glColor3f(0.32,.48,0.35);
   glBegin(GL_TRIANGLES);
   glVertex2f(-.47f,-0.5f);
   glVertex2f(-.41f,-0.37f);
   glVertex2f(-.35f,-0.5f);

   glEnd();


   //upper part
   glColor3f(0.47,.67,0.27);
   glBegin(GL_TRIANGLES);
   glVertex2f(-.46f,-0.43f);
   glVertex2f(-.41f,-0.22f);
   glVertex2f(-.36f,-0.43f);

   glEnd();


   //log of tree

   glColor3f(.42,0.26,0.15);
   glBegin(GL_QUADS);
   glVertex2f(-.39f,-.5f);
   glVertex2f(-.43f,-.5f);
   glVertex2f(-.43f,-.65f);
   glVertex2f(-.39f,-.65f);

   glEnd();


   //shaheed minar

   //red sun of shaheed minar

   glColor3f(1,0,0);
   int i16;

	GLfloat x16=-.13f; GLfloat y16=-.45f; GLfloat radius16 =.12f;

	int triangleAmount16 = 20; //# of triangles used to draw circle


	GLfloat twicePi16 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x16, y16); // center of circle
		for(i16 = 0; i16 <= triangleAmount16;i16++) {
			glVertex2f(
		            x16 + (radius16 * cos(i16 *  twicePi16 / triangleAmount16)),
			    y16 + (radius16 * sin(i16 * twicePi16 / triangleAmount16))
			);
		}
	glEnd();




   //pillar leftmost

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.22f,-.3f);
   glVertex2f(-.18f,-.3f);
   glVertex2f(-.18f,-.65f);
   glVertex2f(-.22f,-.65f);

   glEnd();


   //pillar middle

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.15f,-.3f);
   glVertex2f(-.11f,-.3f);
   glVertex2f(-.11f,-.65f);
   glVertex2f(-.15f,-.65f);

   glEnd();

   //pillar rightmost

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.08f,-.3f);
   glVertex2f(-.04f,-.3f);
   glVertex2f(-.04f,-.65f);
   glVertex2f(-.08f,-.65f);

   glEnd();


   //pillar upper

   glColor3f(1,1,1);
   glBegin(GL_QUADS);
   glVertex2f(-.22f,-.26f);
   glVertex2f(-.04f,-.26f);
   glVertex2f(-.04f,-.3f);
   glVertex2f(-.22f,-.3f);

   glEnd();
    glutTimerFunc(5000,display_raining_view,0);
   glFlush();


}


 void sound2()
{


    PlaySound("street_sound.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(640, 640);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("City View Scenario");
   glutDisplayFunc(display_day);
  sound2();

   init();

   glutTimerFunc(100, update1, 0);
   glutTimerFunc(100, update2, 0);
   glutTimerFunc(100, update3, 0);
   glutTimerFunc(100, update4, 0);
   glutTimerFunc(100, update5, 0);
   glutTimerFunc(100, update6, 0);
   glutTimerFunc(100, update7, 0);
   glutTimerFunc(100, update11, 0);
   glutTimerFunc(100, update21, 0);
   glutTimerFunc(100, update8, 0);

   glutTimerFunc(100, update9, 0);
   glutTimerFunc(100, update10, 0);



   glutMainLoop();
   return 0;
}






