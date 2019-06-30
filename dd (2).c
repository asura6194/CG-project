
#include <cstring>
#include <stdio.h>
#include <GL/glut.h>                  //GLUT toolkit
#include <time.h>
#define INIT_VIEW_X 0.0    //Define initial camera position and viewing window values
#define INIT_VIEW_Y 0.0
#define INIT_VIEW_Z -4.5
#define VIEW_LEFT -2.0
#define VIEW_RIGHT 2.0
#define VIEW_BOTTOM -2.0
#define VIEW_TOP 2.0
#define VIEW_NEAR 1.0
#define VIEW_FAR 200.0
GLfloat AmbientLight[]={0.3,0.3,0.3,1.0};                  //Initialization values for lighting
GLfloat DiffuseLight[] ={0.8,0.8,0.8,1.0};
GLfloat SpecularLight[] ={1.0,1.0,1.0,1.0};
GLfloat SpecRef[] = {0.7,0.7,0.7,1.0};
GLfloat LightPos[] = {-50.0,50.0,100.0,1.0};
GLint Shine =128,df=1;
GLint walkX=0,walkY=0,lookX=0,lookY=0;
GLint world=-1,oldX=-1,oldY=-1;
GLint chinku=-1,minku=-1,pinku=-1,rinku=-1;
void *currentfont;

void setFont(void *font)
{
	currentfont=font;
}
void drawstring(float x,float y,char *string)
{
	char *c;
	glRasterPos2f(x,y);
	for(c=string;*c!='\0';c++)
	{       glColor3f(1.0,0.0,0.0);
		glutBitmapCharacter(currentfont,*c);
	}
}
void frontscreen(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,1);
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0,0.0,0.0);
        drawstring(-2.0,0,"Maximize window for better view");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	drawstring(-2.0,-0.5," THEN PRESS ESC");
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

void intro(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,1);
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	drawstring(2.0,2.0,"Press ENTER to continue");
	glColor3f(0.0,0.0,1.0);
        drawstring(-0.7,1.0,"A CG Mini Project On :");
	glColor3f(0.0,1.0,0.0);
	drawstring(-0.65,0.8,"\"DANCING DOLLS\"");
	glColor3f(0.0,0.0,1.0);
        drawstring(-0.7,0.3,"By:");
	glColor3f(0.7,0.0,0.8);
	drawstring(-0.7,0.1,"Name :");
	glColor3f(0.0,1.0,0.0);
	drawstring(-0.2,0.1,"  ARAVIND R");
	glColor3f(0.7,0.0,0.8);
	drawstring(-0.7,-0.05,"USN :");

	glColor3f(0.0,1.0,0.0);
	drawstring(-0.2,-0.05,"  1KS16CS011");
	glColor3f(0.7,0.0,0.8);
	drawstring(-0.7,-0.2,"Class :");
	glColor3f(0.0,1.0,0.0);
	drawstring(-0.2,-0.2,"  6 'A' CSE ");

	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINES);
	glVertex2f(-0.7,0.95);
	glVertex2f(0.5,0.95);
	glEnd();
	glColor3f(0.0,0.0,1.0);
        glBegin(GL_LINES);
	glVertex2f(-0.7,0.25);
	glVertex2f(0.5,0.25);
	glEnd();
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

void opt(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,1);
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);

	drawstring(-3.0,2.0,"Press ESC to go back");
	glColor3f(0.0,0.0,1.0);
        drawstring(-0.7,1.0,"CHOOSE AN OPTION:");

	glColor3f(0.7,0.0,0.8);
	drawstring(-0.7,0.7,"1. View Dolls");
	glColor3f(0.7,0.0,0.8);
        drawstring(-0.7,0.4,"2. View Instructions");
	glColor3f(0.7,0.0,0.8);
	drawstring(-0.7,0.1,"3. Exit");
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINES);
	glVertex2f(-0.7,-0.15);
	glVertex2f(0.8,-0.15);
	glEnd();
	glColor3f(0.0,0.0,1.0);
        glBegin(GL_LINES);
	glVertex2f(-0.7,0.95);
	glVertex2f(0.8,0.95);
	glEnd();
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

void instruc(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,1);
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);

	drawstring(-3.0,2.0,"Press ESC to go back");
	drawstring(1.8,2.0,"Press ENTER to view dolls");
	glColor3f(0.0,0.0,1.0);
        drawstring(-0.7,1.0,"INSTRUCTIONS:");

	glColor3f(0.7,0.0,0.8);
	drawstring(-0.7,0.7,"1. Press U key to select all dolls for movement.");
	glColor3f(0.7,0.0,0.8);
	glColor3f(0.7,0.0,0.8);
        drawstring(-0.7,0.4,"2. Press F key to select Pinku doll for movement and rotation.");
	glColor3f(0.7,0.0,0.8);
	drawstring(-0.7,0.1,"3. Press G key to select Rinku doll for moviement and rotation.");
	glColor3f(0.7,0.0,0.8);
	drawstring(-0.7,-0.2,"4. Press H key to select Chinku doll for moviement and rotation.");
	glColor3f(0.7,0.0,0.8);
	drawstring(-0.7,-0.5,"5. Press J key to select Minku doll for moviement and rotation.");
	glColor3f(0.7,0.0,0.8);
	drawstring(-0.7,-0.8,"6. Use arrow keys to move dolls.");
	glColor3f(0.7,0.0,0.8);
	drawstring(-0.7,-1.1,"7. Move the mouse around to rotate the dolls.");
	glColor3f(0.7,0.0,0.8);
	drawstring(-0.7,-1.4,"8. Press Q to quit any time.");

	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINES);
	glVertex2f(-0.7,-1.7);
	glVertex2f(0.5,-1.7);
	glEnd();
	glColor3f(0.0,0.0,1.0);
        glBegin(GL_LINES);
	glVertex2f(-0.7,0.95);
	glVertex2f(0.5,0.95);
	glEnd();
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

void eyeright()
{
    //function for the right eye
    glPushMatrix();
    glTranslatef(.17,1.1,.75);     //Specify the coordinates for the right eye
    glRotatef(-45,0,0,1);
    glScalef(.9,.7,.7);            //Specify the size of the right eye
    glColor3f(1.0,1.0,1.0);       //Specify the color of the eye
    gluSphere(gluNewQuadric(),.3,100,100);
    glPopMatrix();
}
void eyeleft()
{
    glPushMatrix();
    glTranslatef(-.17,1.1,.75);     //Specify the position for the left eye
    glRotatef(45,0,0,1);
    glScalef(.9,.7,.7);
    glColor3f(1.0,1.0,1.0);
    gluSphere(gluNewQuadric(),.3,100,100);
    glPopMatrix();
}

void legleft()
{
    glPushMatrix();
    glTranslatef(.3,-.5,0);     //Specify the position for the left leg
    glRotatef(-90.0,1,0,0);
    glScalef(.8,.8,.8);
    gluCylinder(gluNewQuadric(),.5,.5,.5,30,6);
    glPopMatrix();
}

void legright()
{
    glPushMatrix();
    glTranslatef(-.3,-.5,0);     //Specify the position for the right leg
    glRotatef(-90.0,1,0,0);
    glScalef(.8,.8,.8);
    gluCylinder(gluNewQuadric(),.5,.5,.5,30,6);
    glPopMatrix();
}

void armleft()
{
    glPushMatrix();
    glTranslatef(-.82,0,.1);     //Specify the position for the left arm
    glRotatef(90,0,1,0);
    glRotatef(-50,1,0,0);
    gluCylinder(gluNewQuadric(),.15,.15,.48,30,6);
    glPopMatrix();
}

void armright()
{
    glPushMatrix();
    glTranslatef(.82,0,.1);      //Specify the position for the right arm
    glRotatef(90,0,1,0);
    glRotatef(-130,1,0,0);
    gluCylinder(gluNewQuadric(),.15,.15,.48,30,6);
    glPopMatrix();
}

void handleft()
{
    glPushMatrix();
    glTranslatef(.82,0,.1);     //Specify the position for the left hand
    glScalef(.4,.3,.3);
    gluSphere(gluNewQuadric(),.4,100,100);
    glPopMatrix();
}

void handright()
{
    glPushMatrix();
    glTranslatef(-.82,0,.1);    //Specify the position for the right hand
    glScalef(.4,.3,.3);
    gluSphere(gluNewQuadric(),.4,100,100);
    glPopMatrix();
}

void mouth()
{
    glPushMatrix();
    glTranslatef(0,.78,.74);
    glScalef(.4,.4,.1);
    glColor3f(0.0,0.0,0.0);
    gluSphere(gluNewQuadric(),.4,100,100);
    glPopMatrix();
}

void teeth()
{
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-.08,.72,.76);
    glTranslatef(.055,0,.005 );
    glutSolidCube(.035);
    glTranslatef(.055,0,0 );
    glutSolidCube(.035);
    glPopMatrix();
}

void eyebrowleft()
{
    glPushMatrix();
    glTranslatef(-.3,1.5,.97);;
    glRotatef(90,0,1,0);
    glRotatef(45,1,0,0);
    glColor3f(0.0,0.0,0.0);
    gluCylinder(gluNewQuadric(),.05,.01,.3,4,6);
    glPopMatrix();
}

void eyebrowright()
{
    glPushMatrix();
    glTranslatef(.3,1.5,.97);
    glRotatef(270,0,1,0);
    glRotatef(45,1,0,0);
    gluCylinder(gluNewQuadric(),.05,.01,.3,4,6);
    glPopMatrix();
}

void neckring()
{
    glPushMatrix();
    glTranslatef(0,.5,0);
    glScalef(.59,.59,.59);
    glRotatef(90.0,1,0,0);
    glutSolidTorus(.1,1.0,20,20);
    glPopMatrix();
}

void head()
{
    glPushMatrix();
    glTranslatef(0,1.2,0);
    glScalef(.9 ,.9,.9 );
    glColor3f(1.0,0.8,0.6);
    gluSphere(gluNewQuadric(),1,100,100);
    glPopMatrix();
}

void hatmain()
{
    glPushMatrix();
    glTranslatef(0,1.3,0);
    glScalef(.98,.98,.98);
    gluSphere(gluNewQuadric(),.9,100,100);
    glPopMatrix();
}

void maintopball()
{
    glPushMatrix();
    glTranslatef(0,2.2,0);
    glScalef(.9,.9,.9);
    gluSphere(gluNewQuadric(),.18,100,100);
    glPopMatrix() ;
}

void hatring()
{
    glPushMatrix();
    glTranslatef(0,1.4,0);
    glScalef(.84,.84,.84);
    glRotatef(90.0,1,0,0);
    glutSolidTorus(.1,1.0,20,20);
    glPopMatrix();
}

void footleft()
{
    glPushMatrix();
    glTranslatef(-.3,-.5,0);
    glScalef(1.5,.3,1.5);
    glColor3f(0.0,0.0,0.0);
    gluSphere(gluNewQuadric(),.3,100,100);
    glPopMatrix();
}

void footright()
{
    glPushMatrix();
    glTranslatef(.3,-.5,0);
    glScalef(1.5,.3,1.5);
    glColor3f(0.0,0.0,0.0);
    gluSphere(gluNewQuadric(),.3,100,100);
    glPopMatrix();
}

void coatline()
{
    glPushMatrix();
    glTranslatef(0,.12,.67);
    glRotatef(-17.0,1,0,0);
    glScalef(.05,.7,.1);
    glutSolidCube(1);
    glPopMatrix();
}

void bellyCoatbottom()
{
    glPushMatrix();
    glTranslatef(0,-.2,0);
    glScalef(1,.7,1);
    glRotatef(90.0,1,0,0);
    gluDisk(gluNewQuadric(),0,.8,30,30);
    glPopMatrix();
}

void BellyCoat()
{
    glPushMatrix();
    glTranslatef(0,.5,0);
    glScalef(1,.7,1);
    glRotatef(90.0,1,0,0);
    gluCylinder(gluNewQuadric(),.6,.8,1,100,100);
    glPopMatrix();
}

void pupilleft()
{
    glPushMatrix();
    glTranslatef(-.17,1.1,.88);
    glScalef(.9,.9,.9);
    gluSphere(gluNewQuadric(),.1,100,100);
    glPopMatrix();
}

void pupilright()
{
    glPushMatrix();
    glTranslatef(.17,1.1,.88);
    glScalef(.9,.9,.9);
    gluSphere(gluNewQuadric(),.1,100,100);
    glPopMatrix();
}

void topbutton()
{
    glPushMatrix();
    glTranslatef(-.1,.4,.85);
    glScalef(1.9,1.9,1.9);
    gluSphere(gluNewQuadric(),.04,100,100);
    glPopMatrix();
}
void middlebutton()
{
    glPushMatrix()  ;
    glTranslatef(-.1,.15,.98);
    glScalef(1.9,1.9,1.9);
    gluSphere(gluNewQuadric(),.04,100,100);
    glPopMatrix();
}
void bottombutton()
{
    glPushMatrix();
    glTranslatef(-.1,-.1,.92);
    glScalef(1.9,1.9,1.9);
    glColor3f(0.0,0.0,0.0);
    gluSphere(gluNewQuadric(),.04,100,100);
    glPopMatrix();
}

void Display()
{
    if(df==1)
     frontscreen();

    else if(df==2)
     intro();

    else if(df==3)
     opt();

    else if(df==5)
     instruc();

    else
   {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Clear the window
 glColor3f(1.0,0.54,0.0);
    drawstring(-0.5,1.5,"DANCING DOLLS");
    glClearColor(0.6,0.0,0.6,1.0);


    glColor3ub(50, 50, 150);//Change the draw color to slate blue
	glLineWidth(5);
        glBegin(GL_LINES);
	glVertex2f(-3.7,9.1);
	glVertex2f(-3.7,-9);
	glEnd();
	glLineWidth(5);
        glBegin(GL_LINES);
	glVertex2f(3.6,9.1);
	glVertex2f(3.6,-9);
	glEnd();

	glLineWidth(5);
        glBegin(GL_LINES);
	glVertex2f(-3.9,1.8);
	glVertex2f(3.9,1.8);
	glEnd();

	glLineWidth(5);
        glBegin(GL_LINES);
	glVertex2f(-3.9,-1.8);
	glVertex2f(3.9,-1.8);
	glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
	glVertex2f(-3.6,9.1);
	glVertex2f(-3.6,-9);
	glEnd();

	glLineWidth(5);
        glBegin(GL_LINES);
	glVertex2f(3.7,9.1);
	glVertex2f(3.7,-9);
	glEnd();

	glLineWidth(5);
        glBegin(GL_LINES);
	glVertex2f(-3.9,1.9);
	glVertex2f(3.9,1.9);
	glEnd();

	glLineWidth(5);
        glBegin(GL_LINES);
	glVertex2f(-3.9,-1.9);
	glVertex2f(3.9,-1.9);
	glEnd();


    glPushMatrix();//Save viewing matrix state
    if(world==1)
	{
       	      glTranslatef(walkX,-1,walkY);
                  //glRotatef(lookY,0,1,0);
                  //glRotatef(lookX,1,0,0);
	}

//*******************PINKU***********************
    glPushMatrix();
    glTranslatef(-3,0,-6);
    if(pinku==1)
	{
                  glTranslatef(walkX,-1,walkY);
                  glRotatef(lookY,0,1,0);
                  glRotatef(lookX,1,0,0);
	}
    eyeright();
    eyeleft();
    glColor3f(0.0,0.0,1.0);
    legleft();
    legright();
    hatmain();
    glColor3ub(160,82,45);
    armleft();
    armright();
    mouth();
    teeth();
    eyebrowleft();
    eyebrowright();
    head();
    glColor3f(1.0,0.0,0.0);
    maintopball();
    hatring();
    neckring();
    handleft();
    handright();
    glColor3f(0.0,0.0,0.0);
    footleft();
    footright();
    coatline();
    pupilleft();
    pupilright();
    glColor3ub(160,82,45);
    BellyCoat();
    bellyCoatbottom();
    glPopMatrix();

    //*******************RINKU***********************
    glPushMatrix();
    glTranslatef(-1,0,-6);



     if(rinku==1)
	{
                  glTranslatef(walkX,-1,walkY);
                  glRotatef(lookY,0,1,0);
                  glRotatef(lookX,1,0,0);
	}
    eyeright();
    eyeleft();
    eyebrowleft();
    eyebrowright();
    glColor3f(0.0,1.0,0.0);
    neckring();
    glColor3ub(50,40,60);
    legright();
    legleft();
    glColor3ub(255,90,0);
    armleft();
    armright();
    BellyCoat();
    bellyCoatbottom();
    glColor3ub(0,185,0);
    handleft();
    handright();
    mouth();
    teeth();
    glColor3ub(255,222,173);
    head();
    glColor3f(0.0,0.0,0.0);
    footleft();
    footright();
    topbutton();
    middlebutton();
    bottombutton();
    pupilleft();
    pupilright();
    glPopMatrix();

    //*******************CHINKU****************************
    glPushMatrix();
    glTranslatef(1.5,0,-6);
    if(chinku==1)
	{
                  glTranslatef(walkX,-1,walkY);
                  glRotatef(lookY,0,1,0);
                 glRotatef(lookX,1,0,0);
	}
    eyeright();
    eyeleft();
    glColor3f(0.0,0.0,0.0);
    pupilleft();
    pupilright();
    glColor3f(0.5,0.2,0.4);
    legright();
    legleft();
    glPushMatrix();                                    //****Arm left****
    glTranslatef(-.9,.2,.1);
    glRotatef(90,0,1,0);
    glRotatef(-45,1,0,0);
    glColor3f(1.0,0.0,0.0);
    glutSolidCone(.3,.55,30,30);
    glPopMatrix();

    glPushMatrix();                                   //****Arm right****
    glTranslatef(.9,.2,.1);
    glRotatef(90,0,1,0);
    glRotatef(-135,1,0,0);
    glColor3f(1.0,0.0,0.0);
    glutSolidCone(.3,.55,30,30);
    glPopMatrix();
    glPushMatrix();                                    //****Hand left****
    glTranslatef(.9,.22,.1);
    glScalef(.5,.3,.4);
    glColor3f(1.0,1.0,0.0);
    gluSphere(gluNewQuadric(),.6,100,100);
    glPopMatrix();
    glPushMatrix();                                    //****Hand right****
    glTranslatef(-.9,.22,.1);
    glScalef(.5,.3,.4);
    glColor3f(1.0,1.0,0.0);
    gluSphere(gluNewQuadric(),.6,100,100);
    glPopMatrix();
    glPushMatrix();                                    //****Mouth****
    glTranslatef(0,.78,.8);
    glScalef(.4,.4,.1);
    glColor3f(0.0,0.0,0.0);
    gluSphere(gluNewQuadric(),.4,100,100);
    glPopMatrix();
    glPushMatrix();                                    //****Teeth****
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-.08,.72,.817 );
    glutSolidCube(.035);
    glTranslatef(.055,0,.005 );
    glutSolidCube(.035);
    glTranslatef(.055,0,0 );
    glutSolidCube(.035);
    glTranslatef(.055,0,-.005 );
    glutSolidCube(.035);
    glPopMatrix();
    glPushMatrix();                                    //****Head****
    glTranslatef(0,1,0);
    glScalef(.9,.7,.9);
    glColor3ub(255,222,173);
    gluSphere(gluNewQuadric(),1,100,100);
    glPopMatrix();
    glPushMatrix();                                    //****Hat main****
    glTranslatef(0,1,0);
    glScalef(.9,.9,.9);
    glColor3ub(30,144,255);
    gluSphere(gluNewQuadric(),.9,100,100);
    glPopMatrix();
    glColor3f(1.0,1.0,0.0);
    hatring();
    footleft();
    footright();
    topbutton();
    middlebutton();
    bottombutton();
    glPushMatrix();                                    //****BellyCoat****
    glTranslatef(0,.1,0) ;
    glScalef(1,.6,1);
    glColor3f(1.0,0.0,0.0);
    gluSphere(gluNewQuadric(),1,100,100);
    glPopMatrix();
    glPopMatrix();


    //*******************MINKU***********************
    glPushMatrix();
    glTranslatef(4,0,-6);
    if(minku==1)
	{
                  glTranslatef(walkX,-1,walkY);
                  glRotatef(lookY,0,1,0);
                  glRotatef(lookX,1,0,0);
	}
    eyeleft();
    eyeright();
    glColor3f(0.0,0.0,0.0);
    pupilleft();
    pupilright();
    glColor3ub(255,127,0);
    legleft();
    legright();
    armleft();
    armright();
    BellyCoat();
    mouth();
    teeth();
    eyebrowleft();
    eyebrowright();
    glColor3ub(139,69,0);
    handright();
    handleft();
    head();
    glColor3f(0.3,0.2,0.1);
    hatmain();
    footleft();
    footright();
    coatline();
    neckring();
    glColor3f(1.0,0.7,0.0);
    hatring();
    maintopball();
    glPopMatrix();
    glPopMatrix();                                     //****Restore matrix state****
    glutSwapBuffers();
 }                            //****Flush drawing commands****
}

void keyboard(unsigned char key,int x,int y)
{

if(df==1 && key==27)
 df=2;
if(df==2 && key==13)
 df=3;
if(df==3 && key=='1')
 df=-3;
if(df==3 && key==27)
 df=2;
//if(df==-3 && key==27)
 //df=3;
//if(df==-3 && key=='i')
 //df=5;
if(df==3 && key=='2')
 df=5;
if(df==5 && key==27)
 df=3;
if(df==3 && key=='3')
 exit(0);
if(key=='q' || key=='Q')
 exit(0);
if(df==-3 && (key=='u'|| key=='U'))    world=-world;
if(df==-3 && (key=='f'|| key=='F'))    pinku=-pinku;
if(df==-3 && (key=='g'|| key=='G'))    rinku=-rinku;
if(df==-3 && (key=='h'|| key=='H'))    chinku=-chinku;
if(df==-3 && (key=='j'|| key=='J'))    minku=-minku;
}


void SetupRend()
{

    glEnable(GL_DEPTH_TEST);         //Enable depth testing
    glEnable(GL_LIGHTING);             //Enable lighting
    glLightfv(GL_LIGHT0,GL_AMBIENT,AmbientLight);//Set up and enable light zero
    glLightfv(GL_LIGHT0,GL_DIFFUSE,DiffuseLight);
    glLightfv(GL_LIGHT0,GL_SPECULAR,SpecularLight);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);                   //Enable color tracking
    glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);//Set material to follow
    glMaterialfv(GL_FRONT,GL_SPECULAR,SpecRef);//Set specular reflectivity and shine
    glMateriali(GL_FRONT,GL_SHININESS,Shine);
}

void walk(int key,int x,int y)                                      //change positions using arrow keys
{

    if(key==GLUT_KEY_UP)    walkY+=1;
    if(key==GLUT_KEY_DOWN)  walkY-=1;
    if(key==GLUT_KEY_RIGHT) walkX+=1;
    if(key==GLUT_KEY_LEFT)  walkX-=1;
}

void gaze(int x,int y)
{
    if((oldX<0) || (oldY<0))
	{

                  oldX=x;
                  oldY=y;
	}
    lookX+=y-oldY;
    lookY+=x-oldX;
    oldX=x;
    oldY=y;
}

void myReshape(int w, int h)
{
    GLfloat Ratio;
    glViewport(0,0,w,h);
    Ratio=1.0*w/h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0,Ratio,VIEW_NEAR,VIEW_FAR);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(INIT_VIEW_X,INIT_VIEW_Y,INIT_VIEW_Z);
    glLightfv(GL_LIGHT0, GL_POSITION, LightPos);
}

int main(int argc, char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutCreateWindow("Dancing dolls");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(Display);
    glutIdleFunc(Display);
    glutSpecialFunc(walk);
    glutKeyboardFunc(keyboard);
    glutPassiveMotionFunc(gaze);
    SetupRend();
    glEnable(GL_NORMALIZE);
    glutMainLoop();
    return 0;
}
