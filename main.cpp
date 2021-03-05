#include<windows.h>
#include <GL/glut.h>
#include <math.h>
#define PI 3.1416

float c1 = 0, c2 = 0, c3 = 0, c4 = 100, c5 = 0, runner_right = 0, move_speed = 1;
int spin = 0, flag =1, multiplier =1;

void initGL(void)
{
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    gluOrtho2D(-100,100,-100,100);
}

void circle(float radius_x, float radius_y, int sides = 500)
{
    int i=0;
    float angle = 0.0;

    glBegin(GL_POLYGON);

    for(i = 0; i < sides; i++)
    {
        angle = 2 * PI * i / 100;
        glVertex2f (cos(angle) * radius_x,sin(angle) * radius_y);
    }
    glEnd();
}

void road()
{
    //main street
    glBegin(GL_POLYGON);
    glColor3f(0.55, .55, 0.55);
    glVertex2f(-100, -99);

    glColor3f(0.58, .58, 0.58);
    glVertex2f(-100, -55);

    glColor3f(0.43, .43, 0.43);
    glVertex2f(100, -55);

    glColor3f(0.404, .404, 0.392);
    glVertex2f(100,-99);
    glEnd();

    //street  shadow
    glBegin(GL_POLYGON);
    glColor3f(0.43, .43, 0.43);
    glVertex2f(-100, -99);

    glColor3f(0.53, .53, 0.53);
    glVertex2f(-100, -96);

    glColor3f(0.41, .41, 0.41);
    glVertex2f(100, -85);

    glColor3f(0.39, .39, 0.39);
    glVertex2f(100,-99);
    glEnd();

    //line1
    glBegin(GL_POLYGON);
    glColor3f(0.35, 0.35, 0.35);
    glVertex2f(-30, -65.8);
    glVertex2f(-55, -65.8);
    glVertex2f(-55, -66);
    glVertex2f(-30, -66);
    glEnd();

    //line2
    glBegin(GL_POLYGON);
    glColor3f(0.35, 0.35, 0.35);
    glVertex2f(-60, -60.7);
    glVertex2f(-94, -60.7);
    glVertex2f(-94, -61);
    glVertex2f(-60, -61);
    glEnd();

    //line3
    glBegin(GL_POLYGON);
    glColor3f(0.35, 0.35, 0.35);
    glVertex2f(-50, -80.7);
    glVertex2f(-64, -80.7);
    glVertex2f(-64, -81);
    glVertex2f(-50, -81);
    glEnd();

    //line4
    glBegin(GL_POLYGON);
    glColor3f(0.35, 0.35, 0.35);
    glVertex2f(85, -65.7);
    glVertex2f(55, -65.7);
    glVertex2f(55, -66);
    glVertex2f(85, -66);
    glEnd();

    //line5
    glBegin(GL_POLYGON);
    glColor3f(0.35, 0.35, 0.35);
    glVertex2f(10, -69.7);
    glVertex2f(0, -69.7);
    glVertex2f(0, -70);
    glVertex2f(10, -70);
    glEnd();

    //line6
    glBegin(GL_POLYGON);
    glColor3f(0.35, 0.35, 0.35);
    glVertex2f(45, -73.7);
    glVertex2f(15, -73.7);
    glVertex2f(15, -74);
    glVertex2f(45, -74);
    glEnd();

    //line7
    glBegin(GL_POLYGON);
    glColor3f(0.35, 0.35, 0.35);
    glVertex2f(-10, -83.7);
    glVertex2f(-35, -83.7);
    glVertex2f(-35, -84);
    glVertex2f(-10, -84);
    glEnd();

    //line8
    glBegin(GL_POLYGON);
    glColor3f(0.23, 0.23, 0.23);
    glVertex2f(70, -90.8);
    glVertex2f(40, -90.8);
    glVertex2f(40, -91);
    glVertex2f(70, -91);
    glEnd();

    //line9
    glBegin(GL_POLYGON);
    glColor3f(0.35, 0.35, 0.35);
    glVertex2f(-70, -83.5);
    glVertex2f(-100, -83.5);
    glVertex2f(-100, -84);
    glVertex2f(-70, -84);
    glEnd();
}

void background()
{
    //lower sky
    glBegin(GL_POLYGON);
    glColor3f(0.95, 0.878, 0.737);
    glVertex2f(100, 99);
    glVertex2f(-100, 99);
    glVertex2f(-100, -55);
    glVertex2f(100, -55);
    glEnd();

    //upper sky
    glBegin(GL_POLYGON);
    glColor3f(.84,.95,1);
    glVertex2f(100, 99);

    glColor3f(.84,.95,1);
    glVertex2f(-100, 99);

    glColor3f(0.95, 0.878, 0.737);
    glVertex2f(-100, 45);

    glColor3f(0.95, 0.878, 0.737);
    glVertex2f(100, 45);
    glEnd();

    //back mountains half1

    glBegin(GL_POLYGON);
    glColor4f(.65,.58,.46,.16);
    glVertex2f(-50, 60);
    glVertex2f(-100, -47);
    glVertex2f(-20, -47);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(.65,.58,.46,.08);
    glVertex2f(-30, 40);
    glVertex2f(-100, -47);
    glVertex2f(0, -47);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.81, 0.72, 0.58);
    glVertex2f(-100, -47);
    glVertex2f(-100, 15);
    glVertex2f(-80, 42);

    glVertex2f(-60, 17);
    glVertex2f(-40, 27);
    glVertex2f(-20, 17);

    glVertex2f(-7, 49);
    glVertex2f(17, -47);
    glEnd();



    //back mountains half2
    glBegin(GL_POLYGON);
    glColor4f(.65,.58,.46,.1);
    glVertex2f(2.7, 10);
    glVertex2f(17, -47);
    glVertex2f(40, -47);
    glVertex2f(10, 34);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.81, 0.72, 0.58);
    glVertex2f(-20, -47);
    glVertex2f(42, 50);
    glVertex2f(58, -47);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.81, 0.72, 0.58);
    glVertex2f(-20, -47);
    glVertex2f(42, 50);
    glVertex2f(58, -47);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.81, 0.72, 0.58);
    glVertex2f(58, -47);

    glVertex2f(100, -47);
    glVertex2f(100, 13);
    glVertex2f(77, 60);
    glVertex2f(58, 36);
    glVertex2f(49, 7);
    glEnd();

    //stone1
    glBegin(GL_POLYGON);
    glColor3f(.353, .353, .353);
    glVertex2f(-65, -55);
    glVertex2f(-88, -35);
    glVertex2f(-95, -55);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.4, .4, .4);
    glVertex2f(-75, -55);
    glVertex2f(-88, -35);
    glVertex2f(-95, -55);
    glEnd();

    //stone2
    glBegin(GL_POLYGON);
    glColor3f(.45, .45, .45);
    glVertex2f(-15, -30);
    glVertex2f(-18, -23);
    glVertex2f(-27, -20);
    glVertex2f(-35, -24);
    glVertex2f(-33, -36);
    glVertex2f(-20, -37);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.27, .27, .27);
    glVertex2f(-35, -24);
    glVertex2f(-37, -55);
    glVertex2f(-33, -36);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.31, .31, .31);
    glVertex2f(-33, -36);
    glVertex2f(-37, -55);
    glVertex2f(-30, -55);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.36, .36, .36);
    glVertex2f(-33, -36);
    glVertex2f(-30, -55);
    glVertex2f(-17, -55);
    glVertex2f(-20, -37);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.29, .29, .29);
    glVertex2f(-20, -37);
    glVertex2f(-17, -55);
    glVertex2f(-12, -55);
    glVertex2f(-15, -30);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.45, .45, .45);
    glVertex2f(-20, -37);
    glVertex2f(-17, -55);
    glVertex2f(-26, -55);
    glEnd();

    //stone3
    glBegin(GL_POLYGON);
    glColor3f(.353, .353, .353);
    glVertex2f(40, -50);
    glVertex2f(36, -35);
    glVertex2f(17, -38);
    glVertex2f(10, -50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.3, .3, .3);
    glVertex2f(40, -50);
    glVertex2f(36, -35);
    glVertex2f(36, -50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.33, .33, .33);
    glVertex2f(17, -38);
    glVertex2f(21, -38);
    glVertex2f(30, -50);
    glVertex2f(25, -50);
    glEnd();

    //stone4
    glBegin(GL_POLYGON);
    glColor3f(.353, .353, .353);
    glVertex2f(95, -55);
    glVertex2f(80, -28);
    glVertex2f(75, -40);
    glVertex2f(71, -44);
    glVertex2f(65, -55);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.4, .4, .4);
    glVertex2f(85, -55);
    glVertex2f(75, -40);
    glVertex2f(71, -44);
    glVertex2f(65, -55);
    glEnd();
}

void cloudModel1()
{
    glColor3f(1,1,1);

    //rectangle
    glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex2f(82, 80);
    glVertex2f(68, 80);
    glVertex2f(61, 70);
    glVertex2f(88, 70);
    glEnd();
    glPopMatrix();

    //Right
    glPushMatrix();
    glTranslatef(87, 77, 0);
    circle(5,7);
    glPopMatrix();

    //Left
    glPushMatrix();
    glTranslatef(62, 76, 0);
    circle(4,6);
    glPopMatrix();

    //Rest
    glPushMatrix();
    glTranslatef(66, 82, 0);
    circle(4,8);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(66, 82, 0);
    circle(4,8);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(72, 85, 0);
    circle(4,8);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(80, 82, 0);
    circle(6,8);
    glPopMatrix();
}

void cloudModel2()
{
    //left
    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(-30, 92, 0);
    circle(7,3);
    glPopMatrix();
    //right
    glPushMatrix();
    glTranslatef(-22, 92, 0);
    circle(9,4);
    glPopMatrix();
}

void cloudModel3()
{
    //left
    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(-80, 72, 0);
    circle(4,5);
    glPopMatrix();
    //right
    glPushMatrix();
    glTranslatef(-70, 70, 0);
    circle(4,5);
    glPopMatrix();
    //top
    glPushMatrix();
    glTranslatef(-75, 76, 0);
    circle(4,5);
    glPopMatrix();
    //down
    glPushMatrix();
    glTranslatef(-75, 70, 0);
    circle(5,5);
    glPopMatrix();
}

void cloudModel4()
{
    //left
    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(-50, 65, 0);
    circle(4,5);
    glPopMatrix();

    //right
    glPushMatrix();
    glTranslatef(-35, 65, 0);
    circle(3,4);
    glPopMatrix();

    //rest
    glPushMatrix();
    glTranslatef(-47, 68, 0);
    circle(3,5);
    glPopMatrix();

    //rest
    glPushMatrix();
    glTranslatef(-43, 70, 0);
    circle(3,5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-38, 68, 0);
    circle(3,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-45, 62, 0);
    circle(5,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-40, 63, 0);
    circle(4,5);
    glPopMatrix();
}

void show_cloud1()
{
    glPushMatrix();
    glTranslatef(c1,0,0);
    cloudModel1();
    glPopMatrix();
    if(c1<=100)
    {
        c1=c1+.005;
    }
    else
    {
        c1=-200;
    }
    glutPostRedisplay();
}

void show_cloud2()
{
    glPushMatrix();
    glTranslatef(c2,0,0);
    cloudModel2();
    glPopMatrix();
    if(c2<=150)
    {
        c2=c2+.007;
    }
    else
    {
        c2=-100;
    }
    glutPostRedisplay();
}

void show_cloud3()
{
    glPushMatrix();
    glTranslatef(c3,0,0);
    cloudModel3();
    glPopMatrix();
    if(c3<=200)
    {
        c3=c3+.009;
    }
    else
    {
        c3=-60;
    }
    glutPostRedisplay();
}

void show_cloud4()
{
    glPushMatrix();
    glTranslatef(c4,20,0);
    cloudModel3();
    glPopMatrix();
    if(c4<=200)
    {
        c4=c4+.01;
    }
    else
    {
        c4=-20;
    }
    glutPostRedisplay();
}

void show_cloud5()
{
    glPushMatrix();
    glTranslatef(c5,0,0);
    cloudModel4();
    glPopMatrix();
    if(c5<=150)
    {
        c5=c5+.007;
    }
    else
    {
        c5=-50;
    }
    glutPostRedisplay();
}

void sun()
{
    glPushMatrix();
    glColor4f(0.99,1,.57,.2);
    glTranslatef(50, 99, 0);
    glRotatef(180, 0,0, 0);
    circle(9,18,51);
    glPopMatrix();

    glPushMatrix();
    glColor4f(0.99,1,.57,.3);
    glTranslatef(50, 99, 0);
    glRotatef(180, 0,0, 0);
    circle(8,16,51);
    glPopMatrix();

    glPushMatrix();
    glColor4f(0.99,1,.57,.5);
    glTranslatef(50, 99, 0);
    glRotatef(180, 0,0, 0);
    circle(7,14,51);
    glPopMatrix();

    glPushMatrix();
    glColor4f(0.99,1,.57,.6);
    glTranslatef(50, 99, 0);
    glRotatef(180, 0,0, 0);
    circle(6,12,51);
    glPopMatrix();

    glPushMatrix();
    glColor4f(1,.99,.49,.8);
    glTranslatef(50, 99, 0);
    glRotatef(180, 0,0, 0);
    circle(5,10,51);
    glPopMatrix();
}

void cactus1()
{
    //body
    glPushMatrix();
    glColor3f(.33,.55,.42);
    glBegin(GL_POLYGON);
    glVertex2f(-53, -53);
    glVertex2f(-50, -53);
    glVertex2f(-49, -44);
    glVertex2f(-54.95, -44);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-52, -40, 0);
    circle(3.1,11);
    glPopMatrix();

    glColor3f(.15,.34,.16);
    glPointSize(2.5);
    glBegin(GL_POINTS);
    glVertex3f(-52,-45,0);
    glEnd();

    glColor3f(.15,.34,.16);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex3f(-50,-40,0);
    glEnd();

    glColor3f(.15,.34,.16);
    glPointSize(2.5);
    glBegin(GL_POINTS);
    glVertex3f(-50,-35,0);
    glEnd();

    glColor3f(.15,.34,.16);
    glPointSize(2.5);
    glBegin(GL_POINTS);
    glVertex3f(-53,-40,0);
    glEnd();

    glColor3f(.15,.34,.16);
    glPointSize(2.7);
    glBegin(GL_POINTS);
    glVertex3f(-51,-33,0);
    glEnd();

    glColor3f(.15,.34,.16);
    glPointSize(2.8);
    glBegin(GL_POINTS);
    glVertex3f(-51,-48,0);
    glEnd();

    glColor3f(.15,.34,.16);
    glPointSize(2.8);
    glBegin(GL_POINTS);
    glVertex3f(-52,-51,0);
    glEnd();

    glColor3f(.15,.34,.16);
    glPointSize(1.8);
    glBegin(GL_POINTS);
    glVertex3f(-52,-37,0);
    glEnd();

    //left top
    glPushMatrix();
    glColor3f(.33,.55,.37);
    glTranslatef(-57.2, -30, 0);
    glRotatef(200, 0, 0, 1);
    circle(3,5);
    glPopMatrix();

    glColor3f(.15,.34,.16);
    glPointSize(2.5);
    glBegin(GL_POINTS);
    glVertex3f(-58,-30,0);
    glEnd();

    //right top
    glPushMatrix();
    glColor3f(.33,.64,.42);
    glTranslatef(-48, -30, 0);
    glRotatef(150, 0, 0, 1);
    circle(2,3);
    glPopMatrix();

    glColor3f(.15,.34,.16);
    glPointSize(2.5);
    glBegin(GL_POINTS);
    glVertex3f(-49,-31,0);
    glEnd();

    //right top top
    glPushMatrix();
    glColor3f(.33,.68,.32);
    glTranslatef(-46, -25.4, 0);
    circle(1,2.5);
    glPopMatrix();

    //left top left top
    glPushMatrix();
    glColor3f(.33,.64,.42);
    glTranslatef(-62.3, -27, 0);
    glRotatef(70, 0, 0, 1);
    circle(2.4,3);
    glPopMatrix();

    //left top right top
    glPushMatrix();
    glColor3f(.33,.64,.42);
    glTranslatef(-58, -22, 0);
    glRotatef(0, 0, 0, 1);
    circle(1.5,3.5);
    glPopMatrix();

    glColor3f(.15,.34,.16);
    glPointSize(2.5);
    glBegin(GL_POINTS);
    glVertex3f(-58,-22.4,0);
    glEnd();


    //left top left top left top
    glPushMatrix();
    glColor3f(.33,.68,.32);
    glTranslatef(-64, -23, 0);
    glRotatef(160, 0, 0, 1);
    circle(1.5,3);
    glPopMatrix();

    glColor3f(.15,.34,.16);
    glPointSize(2.5);
    glBegin(GL_POINTS);
    glVertex3f(-64,-23,0);
    glEnd();
}

void cactus2()
{
    glPushMatrix();
    glColor3f(.32,.55,.41);
    glTranslatef(1, -46.17, 0);
    glRotatef(170, 0, 0, 1);
    circle(2,6);
    glPopMatrix();

    glPushMatrix();
    glColor3f(.3,.6,.42);
    glBegin(GL_POLYGON);
    glVertex2f(1, -52);
    glVertex2f(-2, -52);
    glVertex2f(-7, -40);
    glVertex2f(-3, -35.9);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(.3,.6,.42);
    glTranslatef(-5, -38, 0);
    glRotatef(20, 0, 0, 1);
    circle(2.5,7);
    glPopMatrix();

    glColor3f(.15,.34,.16);
    glPointSize(2.5);
    glBegin(GL_POINTS);
    glVertex3f(1,-47,0);
    glEnd();

    glColor3f(.15,.34,.16);
    glPointSize(2.2);
    glBegin(GL_POINTS);
    glVertex3f(-4,-44,0);
    glEnd();

    glColor3f(.15,.34,.16);
    glPointSize(2.6);
    glBegin(GL_POINTS);
    glVertex3f(-3,-45,0);
    glEnd();

    glColor3f(.15,.34,.16);
    glPointSize(2.3);
    glBegin(GL_POINTS);
    glVertex3f(-2.5,-40,0);
    glEnd();

    glColor3f(.15,.34,.16);
    glPointSize(2.4);
    glBegin(GL_POINTS);
    glVertex3f(-4.4,-39,0);
    glEnd();

    glColor3f(.15,.34,.16);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex3f(-4.2,-36,0);
    glEnd();

    glColor3f(.15,.34,.16);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex3f(-5.7,-34,0);
    glEnd();
}

void cactus3(){

    glColor3f(.3,.6,.42);
    glPushMatrix();
    //glRotatef(40, 0, 0, 1);
    glTranslatef(53.2, -42, 0);
    circle(5,3);
    glPopMatrix();

    glPushMatrix();
    glRotatef(6, 0, 0, 1);
    glTranslatef(53, -41, 0);
    circle(1.2,8);
    glPopMatrix();

    glPushMatrix();
    //glRotatef(40, 0, 0, 1);
    glTranslatef(48, -37, 0);
    circle(5,3);
    glPopMatrix();

    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(44, -31, 0);
    circle(1.2,8);
    glPopMatrix();


    glPushMatrix();
    glColor3f(.33,.55,.42);
    glBegin(GL_POLYGON);
    glVertex2f(50, -53);
    glVertex2f(53, -53);
    glVertex2f(53.2, -44);
    glVertex2f(48.7, -44);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(3, 0, 0, 1);
    glTranslatef(48.4, -40, 0);
    circle(2.7,12);
    glPopMatrix();

}

void tail_base()
{
    glPushMatrix();
    glColor3f(.671,.09,.961);
    glBegin(GL_POLYGON);
    glVertex2f(-11, -17);
    glVertex2f(-10, -18);
    glVertex2f(-9, -20);
    glVertex2f(-12, -22);
    glVertex2f(-15, -23);
    glEnd();
    glPopMatrix();
}

void full_tail()
{
    //tail base
    glColor3f(.671,.09,.961);
    //glColor3f(.671,.2,.7);
    glPushMatrix();
    glTranslatef(-30, -20, 0);
    glRotatef(120, 0, 0, 1);
    tail_base();
    glPopMatrix();

    //tail1
    //glColor3f(.671,.2,.7);
    glColor3f(.671,.09,.961);
    glPushMatrix();
    glTranslatef(-12, -15, 0);
    glRotatef(55, 0, 0, 1);
    circle(1.7,11);
    glPopMatrix();

    //tail2
    glColor3f(.671,.09,.961);
    glPushMatrix();
    glTranslatef(-20, -18, 0);
    glRotatef(90, 0, 0, 1);
    circle(1.4,8);
    glPopMatrix();

    //tail3
    glColor3f(.671,.09,.961);
    glPushMatrix();
    glTranslatef(-16.5, -15, 0);
    glRotatef(63, 0, 0, 1);
    circle(1.7,8);
    glPopMatrix();

    //tail4
    glColor3f(.671,.09,.961);
    glPushMatrix();
    glTranslatef(-20, -20, 0);
    glRotatef(120, 0, 0, 1);
    circle(1.2,6);
    glPopMatrix();

    //tail5
    glColor3f(.671,.09,.961);
    glPushMatrix();
    glTranslatef(-17, -20.4, 0);
    glRotatef(120, 0, 0, 1);
    circle(1.2,6);
    glPopMatrix();

    //tail6
    glColor3f(.671,.09,.961);
    glPushMatrix();
    glTranslatef(-13, -20.4, 0);
    glRotatef(120, 0, 0, 1);
    circle(1.2,6);
    glPopMatrix();

    //tail7
    glColor3f(.671,.09,.961);
    glPushMatrix();
    glTranslatef(-12, -22, 0);
    glRotatef(120, 0, 0, 1);
    circle(1.4,6);
    glPopMatrix();

    //tail8
    glColor3f(.671,.09,.961);
    glPushMatrix();
    glTranslatef(-9, -23.3, 0);
    glRotatef(115, 0, 0, 1);
    circle(1.6,6);
    glPopMatrix();

    //tail9
    glColor3f(.671,.09,.961);
    glPushMatrix();
    glTranslatef(-16, -17, 0);
    glRotatef(70, 0, 0, 1);
    circle(1.5,10);
    glPopMatrix();

    //tail10
    glColor3f(.671,.09,.961);
    glPushMatrix();
    glTranslatef(-11.5, -14, 0);
    glRotatef(230, 0, 0, 1);
    circle(.9,9);
    glPopMatrix();
}

void body1()
{
    /*glPushMatrix();
    glColor3f(.671,.09,.961);
    glBegin(GL_POLYGON);
    glVertex2f(7, -15);
    glVertex2f(8, -27);
    glVertex2f(5, -30);
    glVertex2f(-7, -23);
    glEnd();
    glPopMatrix();*/

    glPushMatrix();
    glColor3f(.671,.09,.961);
    glTranslatef(7.6, -21.7, 0);
    glRotatef(10, 0, 0, 1);
    circle(1.3,7);
    glPopMatrix();

    glPushMatrix();
    glColor3f(.671,.09,.961);
    glTranslatef(-.5, -26, 0);
    glRotatef(34, 0, 0, 1);
    circle(2.5,6);
    glPopMatrix();

    glPushMatrix();
    glColor3f(.671,.09,.961);
    glTranslatef(1, -19, 0);
    glRotatef(32, 0, 0, 1);
    circle(6.8,2.1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(.671,.09,.961);
    glTranslatef(4.3, -27, 0);
    glRotatef(20, 0, 0, 1);
    circle(5,5);
    glPopMatrix();
}

void body2()
{
    /*glPushMatrix();
    glColor3f(0.247,.102,.475);
    glBegin(GL_POLYGON);
    glVertex2f(5, -17);
    glVertex2f(4.5, -28);
    glVertex2f(-7.5, -23);
    glEnd();
    glPopMatrix();*/

    glColor3f(0.247,.102,.475);
    glPushMatrix();
    glTranslatef(6, -23, 0);
    glRotatef(0, 0, 0, 1);
    circle(1.5,5.5);
    glPopMatrix();

    glColor3f(0.247,.102,.475);
    glPushMatrix();
    glTranslatef(.5, -25.5, 0);
    glRotatef(60, 0, 0, 1);
    circle(4.1,6.4);
    glPopMatrix();

    glColor3f(0.247,.102,.475);
    glPushMatrix();
    glTranslatef(1.05, -20.5, 0);
    glRotatef(20, 0, 0, 1);
    circle(6.2,4);
    glPopMatrix();
}

void throat()
{

    glColor3f(.671,.09,.961);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex2f(14, 4);
    glVertex2f(13, 7);
    glVertex2f(10.1, -5);
    glVertex2f(11, -10);
    glEnd();
    glPopMatrix();

    glColor3f(.671,.09,.961);
    glPushMatrix();
    glTranslatef(8, -17, 0);
    glRotatef(77.5, 0, 0, 1);
    circle(15,.9);
    glPopMatrix();

    glColor3f(.671,.09,.961);
    glPushMatrix();
    glTranslatef(9, -14.6, 0);
    glRotatef(76, 0, 0, 1);
    circle(7.3,1);
    glPopMatrix();

}

void head_top_part()
{
    glColor3f(0.247,.102,.475);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex2f(15, 7);
    glVertex2f(10, 8);
    glVertex2f(12, 5);
    glEnd();
    glPopMatrix();
}

void head()
{
    glPushMatrix();
    glTranslatef(23, 2, 0);
    glRotatef(115, 0, 0, 1);
    head_top_part();
    glPopMatrix();

    glColor3f(0.247,.102,.475);
    glPushMatrix();
    glTranslatef(13.5, 6, 0);
    //glRotatef(0, 0, 0, 1);
    circle(2,4.7);
    glPopMatrix();

    //beak
    glColor3f(.99,.81,.42);
    glPushMatrix();
    glTranslatef(13.6, 3.8, 0);
    glRotatef(0, 0, 0, 1);
    circle(2,2.5);
    glPopMatrix();

    glColor3f(.99,.81,.42);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex2f(18, 4);
    glVertex2f(14, 5);
    glVertex2f(14, 2);
    glEnd();
    glPopMatrix();

    glColor3f(.9,.55,.2);
    glPushMatrix();
    glTranslatef(15.5,3.1, 0);
    glRotatef(100, 0, 0, 1);
    circle(.3,1.8);
    glPopMatrix();

    glColor3f(.9,.55,.2);
    glPushMatrix();
    glTranslatef(13.2,3.8, 0);
    glRotatef(45, 0, 0, 1);
    circle(.25,1);
    glPopMatrix();



    //head hair
    glColor3f(0.247,.102,.475);
    glPushMatrix();
    glTranslatef(7.5, 15.4, 0);
    glRotatef(40, 0, 0, 1);
    circle(.7,6);
    glPopMatrix();

    glColor3f(0.247,.102,.475);
    glPushMatrix();
    glTranslatef(8.6, 16, 0);
    glRotatef(29, 0, 0, 1);
    circle(.7,5);
    glPopMatrix();

    glColor3f(0.247,.102,.475);
    glPushMatrix();
    glTranslatef(7, 13, 0);
    glRotatef(70, 0, 0, 1);
    circle(1,7);
    glPopMatrix();

    glColor3f(0.247,.102,.475);
    glPushMatrix();
    glTranslatef(8, 10, 0);
    glRotatef(100, 0, 0, 1);
    circle(.8,6);
    glPopMatrix();
}

void right_leg_upper()
{
    glColor3f(.671,.09,.961);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex2f(9.2, -30);
    glVertex2f(7, -32);
    glVertex2f(9, -39);
    glVertex2f(10.2, -39);
    glEnd();
    glPopMatrix();
}

void finger()
{
    glColor3f(.82,.63,.35);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex2f(3, 1.5);
    glVertex2f(0, 1.5);
    glVertex2f(0, 0);
    glVertex2f(3, 0);
    glEnd();
    glPopMatrix();
}
void right_leg()
{
    glColor3f(.82,.63,.35);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex2f(10.1, -39);
    glVertex2f(9, -39);
    glVertex2f(16, -63);
    glVertex2f(17, -62);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(13.4,-63, 0);
    glRotatef(0, 0, 0, 1);
    finger();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(16,-63, 0);
    glRotatef(30, 0, 0, 1);
    finger();
    glPopMatrix();
}

void left_leg_upper()
{
    glColor3f(.671,.09,.961);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex2f(4.2, -30);
    glVertex2f(2, -30);
    glVertex2f(3, -37);
    glVertex2f(4.2, -38);
    glEnd();
    glPopMatrix();
}

void left_leg()
{
    glColor3f(.82,.63,.35);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex2f(4, -38);
    glVertex2f(3, -37);
    glVertex2f(2, -62);
    glVertex2f(3, -62);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-62, 0);
    glRotatef(0, 0, 0, 1);
    finger();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3,-62, 0);
    glRotatef(30, 0, 0, 1);
    finger();
    glPopMatrix();
}

void leg()
{
    glPushMatrix();
    glTranslatef(-1, 1, 0);
    //glRotatef(100, 0, 0, 1);
    right_leg_upper();
    right_leg();
    left_leg_upper();
    left_leg();
    glPopMatrix();
}

void eyes(){
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(14.5,9,0);
    glRotatef(15, 0, 0, 1);
    circle(.5,2.7);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(13.5,9,0);
    glRotatef(15, 0, 0, 1);
    circle(.55,3.2);
    glPopMatrix();

    glColor3f(0,0,0);
    glPointSize(3);
    glBegin(GL_POINTS);
    glVertex3f(13.5,9,0);
    glEnd();

    glColor3f(0,0,0);
    glPointSize(3);
    glBegin(GL_POINTS);
    glVertex3f(14.5,9,0);
    glEnd();
}

void road_runner()
{
    glPushMatrix();
    glTranslatef(runner_right,0,0);
    glRotatef(spin, 0, 1, 0);
    body1();
    full_tail();
    throat();
    leg();
    body2();
    head();
    eyes();
    glPopMatrix();
}
void _move(){
    if(flag == 1)
    {
        if(runner_right<=150)
        {
            runner_right=runner_right+move_speed*multiplier;
        }
        else
        {
            runner_right=-100;
        }
    }
    else if(flag == -1){
        if(runner_right>-100)
        {
            runner_right=runner_right-move_speed*multiplier;
        }
        else
        {
            runner_right=150;
        }
    }
}
void walk_runner()
{
    _move();
    glutIdleFunc(NULL);
    glutPostRedisplay();
}

void run_runner()
{
    _move();
    glutPostRedisplay();
}

void spin_runner()
{
    if(flag==1)
    {
        spin = 180;
        flag = -1;
    }
    else if(flag==-1)
    {
        spin = 0;
        flag = 1;
    }
    glutIdleFunc(NULL);
    glutPostRedisplay();
}

void keyboard_func(unsigned char key, int x, int y)
{

    switch (key)
    {
    case 'W':
    case 'w':
        glutIdleFunc(walk_runner);
        break;
    case 'R':
    case 'r':
        glutIdleFunc(run_runner);
        break;
    case 'S':
    case 's':
        glutIdleFunc(NULL);
        break;
    case 'N':
    case 'n':
        glutIdleFunc(spin_runner);
        break;
    case 'F':
    case 'f':
        multiplier*=2;
        break;
    case 'J':
    case 'j':
        multiplier=1;
        break;
    default:
        break;
    }
}


void mouse_func(int button, int state, int x, int y)
{
    switch (button) {
       case GLUT_LEFT_BUTTON:
          if (state == GLUT_DOWN){
            PlaySound("meep_meep.wav", NULL, SND_FILENAME| SND_ASYNC);
          }
          break;
       case GLUT_RIGHT_BUTTON:
          if (state == GLUT_DOWN)
    		PlaySound("meep_meep.wav", NULL, SND_FILENAME| SND_ASYNC);
          break;
       default:
          break;
    }
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    road();
    background();
    show_cloud1();
    show_cloud2();
    show_cloud3();
    show_cloud4();
    show_cloud5();
    sun();
    cactus1();
    cactus2();
    cactus3();
    road_runner();
    glFlush();

}

int main(int argc, char** argv)
{
    glutInitWindowSize(1330, 670);
    glutInitWindowPosition(15, 45);
    glutCreateWindow("ROAD RUNNER");
    initGL();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard_func);
    glutMouseFunc(mouse_func);
    glutMainLoop();
    return 0;
}
