#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

//Global Variables
float car1=-300;
float car2=900;
float cloudPos=0;
float cloudSpeed=0.1;
int lightState=2;
int isNight=0;
float starSpeed=0.05;
int moveStars=0;

float starX[50],starY[50];

//OBJ_01:Circle(Basic Shape Function)
void circle(float r, float cx,float cy)
{
    glBegin(GL_POLYGON);
    for(int i=0; i<=360; i++)
    {
        float a=i*3.1416/180;
        glVertex2f(cx+r*cos(a),cy+r*sin(a));
    }
    glEnd();
}

//OBJ_02:Sun/Moon
void sun_or_moon()
{
    if(!isNight)
    {
        glColor3ub(255,204,0);
        circle(35,800,430);
    }
    else
    {
        glColor3ub(230,230,250);
        circle(35,800,430);
    }
}
//OBJ_03:Cloud
void cloud(float x,float y)
{
    glColor3ub(255,255,255);
    circle(20,x,y);
    circle(25,x+20,y+10);
    circle(20,x+40,y);
    circle(18,x+60,y);
}
//OBJ_09:Window
void window(float x,float y)
{
    glColor3ub(255,255,200);
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    glVertex2f(x+20,y);
    glVertex2f(x+20,y+25);
    glVertex2f(x,y+25);
    glEnd();
}
//OBJ_07:Grass
void grass()
{
    glColor3ub(60,179,113);
    glBegin(GL_POLYGON);
    glVertex2f(0,90);
    glVertex2f(900,90);
    glVertex2f(900,110);
    glVertex2f(0,110);
    glEnd();
}

//OBJ_05:Road
void road()
{
    glColor3ub(70,70,70);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(900,0);
    glVertex2f(900,90);
    glVertex2f(0,90);
    glEnd();

    glColor3ub(255,255,255);
    for(int i=0; i<900; i+=60)
    {
        glBegin(GL_POLYGON);
        glVertex2f(i,40);
        glVertex2f(i+30,40);
        glVertex2f(i+30,50);
        glVertex2f(i,50);
        glEnd();
    }
}

//OBJ_08:Buildings
void buildings()
{
    glColor3ub(180,180,200);
    glBegin(GL_POLYGON);
    glVertex2f(50,90);
    glVertex2f(200,90);
    glVertex2f(200,350);
    glVertex2f(50,350);
    glEnd();

    for(int y=120; y<=320; y+=50)
    {
        window(70,y);
        window(120,y);
        window(170,y);
    }

    glColor3ub(160,160,180);
    glBegin(GL_POLYGON);
    glVertex2f(250,90);
    glVertex2f(420,90);
    glVertex2f(420,300);
    glVertex2f(250,300);
    glEnd();

    for(int y=120; y<=270; y+=50)
    {
        window(270,y);
        window(320,y);
        window(370,y);
    }

    glColor3ub(140,140,160);
    glBegin(GL_POLYGON);
    glVertex2f(460,90);
    glVertex2f(650,90);
    glVertex2f(650,330);
    glVertex2f(460,330);
    glEnd();

    for(int y=120; y<=300; y+=50)
    {
        window(480,y);
        window(530,y);
        window(580,y);
        window(630,y);
    }
}

//OBJ_10:Tree
void tree(float x,float scale)
{
    glColor3ub(139,69,19);
    glBegin(GL_POLYGON);
    glVertex2f(x,90);
    glVertex2f(x+20*scale,90);
    glVertex2f(x+20*scale,180*scale);
    glVertex2f(x,180*scale);
    glEnd();

    glColor3ub(0,150,0);
    circle(35*scale,x+10*scale,220*scale);
    circle(30*scale,x-10*scale,200*scale);
    circle(30*scale,x+30*scale,200*scale);
    circle(25*scale,x+10*scale,200*scale);
}
//OBJ_11:Traffic Light
void trafficLight()
{
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(760,90);
    glVertex2f(770,90);
    glVertex2f(770,260);
    glVertex2f(760,260);
    glEnd();

    glColor3ub(50,50,50);
    glBegin(GL_POLYGON);
    glVertex2f(740,260);
    glVertex2f(790,260);
    glVertex2f(790,360);
    glVertex2f(740,360);
    glEnd();

    if(!isNight)
    {
        if(lightState==0)
            glColor3ub(255,0,0);
        else
            glColor3ub(80,0,0);
        circle(12,765,335);

        if(lightState==1)
            glColor3ub(255,255,0);
        else
            glColor3ub(80,80,0);
        circle(12,765,305);

        if(lightState==2)
            glColor3ub(0,255,0);
        else
            glColor3ub(0,80,0);
        circle(12,765,275);
    }
    else
    {
        if(lightState==0)
            glColor3ub(255,0,0);
        else
            glColor3ub(50,0,0);
        circle(12,765,335);

        if(lightState==1)
            glColor3ub(255,255,0);
        else
            glColor3ub(50,50,0);
        circle(12,765,305);

        if(lightState==2)
            glColor3ub(0,255,0);
        else
            glColor3ub(0,50,0);
        circle(12,765,275);

    }
}

//OBJ_12:Car
void car(float pos,int r,int g, int b)
{
    glPushMatrix();
    glTranslatef(pos,0,0);

    glColor3ub(r,g,b);
    glBegin(GL_POLYGON);
    glVertex2f(100,30);
    glVertex2f(220,30);
    glVertex2f(220,65);
    glVertex2f(100,65);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(130,65);
    glVertex2f(190,65);
    glVertex2f(175,90);
    glVertex2f(145,90);
    glEnd();

    glColor3ub(20,20,20);
    glBegin(GL_POLYGON);
    glVertex2f(135,65);
    glVertex2f(150,65);
    glVertex2f(150,85);
    glVertex2f(140,85);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(150,65);
    glVertex2f(170,65);
    glVertex2f(165,85);
    glVertex2f(150,85);
    glEnd();

    glColor3ub(0,0,0);
    circle(10,130,30);
    circle(10,190,30);

    glPopMatrix();
}

//ANIM_01:Object and Scene Animation

void animate()
{

    float speedCar1=1.0;
    float speedCar2=0.8;

    if(lightState==2)
    {
        car1+=speedCar1;
        car2-=speedCar2;
    }

    if(car1>900.0)car1=-300.0f;
    if(car2<-300.0)car2=900.0f;

    cloudPos+=cloudSpeed;
    if(cloudPos>900.0f)cloudPos=-200.0f;
    if(isNight && moveStars)
    {
        for(int i=0; i<50; i++)
        {
            starX[i]-=starSpeed;
            if(starX[i]<0)
                starX[i]=900;
        }
    }
    glutPostRedisplay();
}

//ANIM_02:Traffic Light Timer
void timer(int v)
{
    lightState=(lightState+1)%3;
    glutTimerFunc(2500,timer,0);
}

//OBJ_04:Stars
void stars()
{
    glColor3ub(255,255,200);
    for(int i=0; i<50; i++)
    {
        circle(2,starX[i],starY[i]);
    }
}

//OBJ_06:Zebra Crossing
void zebraCrossing()
{

    glColor3ub(255,255,255);
    float starX=730;
    float starY=5;

    float width=10;
    float gap=5;
    float length=60;

    for(int i=0; i<6; i++)
    {

        glBegin(GL_POLYGON);
        glVertex2f(starX,starY+i*(width+gap));
        glVertex2f(starX+length,starY+i*(width+gap));
        glVertex2f(starX+length,starY+i*(width+gap)+width);
        glVertex2f(starX,starY+i*(width+gap)+width);
        glEnd();

    }

}
//ANIM_04:Display Function
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if(!isNight)
        glColor3ub(135,206,235);

    else
        glColor3ub(10,10,40);

    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(900,0);
    glVertex2f(900,500);
    glVertex2f(0,500);
    glEnd();

    sun_or_moon();

    if(isNight)
        stars();

    if(!isNight)
    {
        cloud(100+cloudPos,420);
        cloud(400+cloudPos,450);
        cloud(650+cloudPos,410);
    }

    if(!isNight)
        grass();
    else
    {
        glColor3ub(20,50,20);

        glBegin(GL_POLYGON);
        glVertex2f(0,90);
        glVertex2f(900,90);
        glVertex2f(900,110);
        glVertex2f(0,110);
        glEnd();

    }
    road();
    zebraCrossing();

    tree(10,1.2);
    tree(650,1.3);
    tree(400,1.4);
    tree(850,1.5);

    buildings();

    tree(200,0.85);
    tree(500,0.9);
    tree(750,0.7);

    trafficLight();

    car(car1,255,0,0);
    car(car2,0,0,255);

    glutSwapBuffers();
}

//ANIM_03:Keyboard Interaction
void keyboard(unsigned char key,int x,int y)
{
    if(key=='n'||key=='N')
    {
        isNight=!isNight;
    }
    glutPostRedisplay();
}

//ANIM_05:Mouse Interaction
void mouse(int button,int state,int x,int y)
{
    if(button==GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        cloudSpeed +=0.2;
        moveStars=1;
    }
    else if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
    {
        cloudSpeed-=0.2;
        if(cloudSpeed<0)
            cloudSpeed=0;

        moveStars=0;
    }
}

void init()
{

    glClearColor(1,1,1,1);
    gluOrtho2D(0,900,0,500);
}

int main(int argc,char** argv)
{
    srand(time(0));

    for(int i=0; i<50; i++)
    {
        starX[i]=rand()%900;
        starY[i]=200+rand()%300;
    }

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(900,500);
    glutCreateWindow("City View with Traffic Scene");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(animate);
    glutTimerFunc(2500,timer,0);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0 ;
}




