#include <GL/gl.h>
#include<GL/glu.h>
#include <Gl/glut.h>
#include <math.h>

void display();
void reshape(int, int);
void road();
void field();
void boat();
void walkside();
void sky();
void clouds();
void hills();
void ship();
void stand();
void timer(int);
void timer2(int);

void init (){
    glClearColor(0.263, 0.808, 0.837, 1.0);
}

int main(int argc, char**argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(1166, 568);

    glutCreateWindow("River Side View");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    glutTimerFunc(0, timer2, 0);
    init();

    //PlaySound("a.way", NULL, );
    glutMainLoop();
}

float x_position_boat = 0.0;
float x_position_cloud = -10.0;
int state = 1;

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    //draw

    road();
    field();
    walkside();

    sky();
    clouds();
    hills();
    ship();

    boat();
    stand();

    glutSwapBuffers();
}

void reshape(int w, int h){
    glViewport(0,0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
}

void road(){
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(10.0,0.0);
    glVertex2f(10.0,-6);
    glVertex2f(7.0,-10.0);
    glVertex2f(-0.5,-10.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.329,0.03123,0);
    glVertex2f(10.0, -0.1);
    glVertex2f(10.0,-0.5);
    glVertex2f(0.1,-10.0);
    glVertex2f(-0.4,-10.0);
    glEnd();

    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(0.909,0.855,0);
    glVertex2f(10.0, -0.8);
    glVertex2f(0.6,-10.0);
    glEnd();

    glBegin(GL_LINES);
    //glColor3f(0.909,0.855,0);
    glVertex2f(10.0, -3.1);
    glVertex2f(3.6,-10.0);
    glEnd();

    glBegin(GL_LINES);
    //glColor3f(0.909,0.855,0);
    glVertex2f(10.0, -5.6);
    glVertex2f(6.5,-10.0);
    glEnd();
}

void field(){
    glBegin(GL_POLYGON);
    glColor3f(0,0.75,0);
    glVertex2f(-10.0,-10.0);
    glVertex2f(-0.5,-10.0);
    glVertex2f(10.0,0.0);
    glVertex2f(10.0,2.0);
    glVertex2f(-10.0,-1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0.95,0);
    glVertex2f(10.0,2.0);
    glVertex2f(10.0,1.6);
    glVertex2f(-10.0,-2);
    glVertex2f(-10.0,-1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0.45,0);
    glVertex2f(-7.0,-10.0);
    glVertex2f(-0.5,-10.0);
    glVertex2f(10.0,0.0);
    glVertex2f(10.0,1.6);
    glVertex2f(9.3,1.45);
    glEnd();
}

void boat(){

    glTranslatef(9, 4.3, 0.0);

    glBegin(GL_POLYGON);
    glColor3f(0.329,0.03123,0);
    glVertex2f(x_position_boat,0.0);
    glVertex2f(x_position_boat + 2.0, 0.0);
    glVertex2f(x_position_boat + 2.8, 1.1);
    glVertex2f(x_position_boat -1.3,1.1);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex2f(x_position_boat,0.0);
    glVertex2f(x_position_boat + 2.0, 0.0);
    glVertex2f(x_position_boat+ 2.8, 1.1);
    glVertex2f(x_position_boat -1.3,1.1);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.329,0.03123,0);
    glVertex2f(x_position_boat + 0.75, 1.1);
    glVertex2f(x_position_boat+ 0.75, 3);
    glEnd();

    glLineWidth(1);
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,1);
    glVertex2f(x_position_boat-1.0,1.1);
    glVertex2f(x_position_boat-0.2, 1.1);
    glVertex2f(x_position_boat+0.75, 3);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(x_position_boat-1.0,1.1);
    glVertex2f(x_position_boat-0.2, 1.1);
    glVertex2f(x_position_boat+0.75, 3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.922,0.863,0.175);  // Yellow Hut on boat
    glVertex2f(x_position_boat+ 0.77, 1.125);
    glVertex2f(x_position_boat+ 0.77, 1.95);
    glVertex2f(x_position_boat+ 2.0, 1.95);
    glVertex2f(x_position_boat + 2.0, 1.125);
    glEnd();
}

void walkside(){
    glBegin(GL_TRIANGLES);
    glColor3f(0.637, 0.6601, 0.6875);
    glVertex2f(10.0,-6);
    glVertex2f(7.0,-10.0);
    glVertex2f(10.0, -10.0);
    glEnd();
}

void sky(){
    glBegin(GL_POLYGON);
    glColor3f(0.773, 0.973, 0.988);
    glVertex2f(10.0, 10.0);
    glVertex2f(10.0, 6.5);
    glVertex2f(-10.0, 6.5);
    glVertex2f(-10.0, 10.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.922,0.863,0.175);
    float radious = 0.8;
    for(float i=0; i< 2*3.1416; i += 3.1416/20)
        glVertex2f(6+ cos(i) * radious, 9+ sin(i)*radious);

    glColor3f(1,0.75,0.269);
    radious = 0.6;
    for(float i=0; i< 2*3.1416; i += 3.1416/10)
        glVertex2f(6+cos(i) * radious, 9+sin(i)*radious);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3f(1, 0.6328, 0.1797);
    radious = 0.6;
    for(float i=0; i< 2*3.1416; i += 3.1416/10)
        glVertex2f(6+cos(i) * radious, 9+sin(i)*radious);
    glEnd();

}

void clouds(){
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);

    float radious = 0.5;
    for(float i=0; i< 2*3.1416; i += 3.1416/20)
        glVertex2f(x_position_cloud-0.5+cos(i) * radious, 9+ sin(i)*radious);

    radious = 0.8;
    for(float i=0; i< 2*3.1416; i += 3.1416/20)
        glVertex2f(x_position_cloud+cos(i) * radious, 9+ sin(i)*radious);


    radious = 0.5;
    for(float i=0; i< 2*3.1416; i += 3.1416/20)
        glVertex2f(x_position_cloud+0.5+cos(i) * radious, 9+ sin(i)*radious);
    glEnd();

    glBegin(GL_POLYGON);

    radious = 0.8;
    for(float i=0; i< 2*3.1416; i += 3.1416/20)
        glVertex2f(x_position_cloud+3.5+cos(i) * radious, 8+ sin(i)*radious);

    radious = 0.5;
    for(float i=0; i< 2*3.1416; i += 3.1416/20)
        glVertex2f(x_position_cloud+2.5+cos(i) * radious, 8+ sin(i)*radious);
    glEnd();


}

void hills(){

    // Back 1st Triangle from left
    glBegin(GL_TRIANGLES);
    glColor3f(0,0.9,0);
    glVertex2f(-9.5, 6.5);
    glVertex2f(-4.5, 6.5);
    glVertex2f(-6, 8.1);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0,0.8,0);
    glVertex2f(-9.3, 6.5);
    glVertex2f(-4.6, 6.5);
    glVertex2f(-6.1, 7.9);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0,0.6,0);
    glVertex2f(-9.1, 6.5);
    glVertex2f(-4.7, 6.5);
    glVertex2f(-6.2, 7.7);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0,0.4,0);
    glVertex2f(-8.9, 6.5);
    glVertex2f(-4.8, 6.5);
    glVertex2f(-6.3, 7.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0,0.30,0);
    glVertex2f(-9.1, 6.5);
    glVertex2f(-4.9, 6.5);
    glVertex2f(-6.4, 7.3);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0,0.10,0);
    glVertex2f(-9.1, 6.5);
    glVertex2f(-4.9, 6.5);
    glVertex2f(-6.4, 7.1);
    glEnd();
    // End Back 1st Triangle from left

    // large back middle triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0,0.9,0);
    glVertex2f(-5, 6.5);
    glVertex2f(4, 6.5);
    glVertex2f(0, 8.5);
    glEnd();

    // sub triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0,0.8,0);
    glVertex2f(-4.8, 6.5);
    glVertex2f(3.8, 6.5);
    glVertex2f(-0.05, 8.3);
    glEnd();

    // sub triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0,0.7,0);
    glVertex2f(-4.6, 6.5);
    glVertex2f(3.6, 6.5);
    glVertex2f(-0.10, 8.1);
    glEnd();

    // sub triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0,0.6,0);
    glVertex2f(-4.4, 6.5);
    glVertex2f(3.4, 6.5);
    glVertex2f(-0.15, 7.9);
    glEnd();

    // sub triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0,0.4,0);
    glVertex2f(-4.2, 6.5);
    glVertex2f(3.2, 6.5);
    glVertex2f(-0.20, 7.7);
    glEnd();

    // sub triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0,0.3,0);
    glVertex2f(-4, 6.5);
    glVertex2f(3, 6.5);
    glVertex2f(-0.25, 7.5);
    glEnd();

    // sub triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0,0.15,0);
    glVertex2f(-3.8, 6.5);
    glVertex2f(2.8, 6.5);
    glVertex2f(-0.20, 7.3);
    glEnd();
    //End Large Back Middle Triangle

    // Front 2nd Triangle from left
    glBegin(GL_TRIANGLES);
    glColor3f(0,0.9,0);
    glVertex2f(-7, 6.5);
    glVertex2f(-2, 6.5);
    glVertex2f(-4, 8.2);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0,0.8,0);
    glVertex2f(-6.8, 6.5);
    glVertex2f(-2.2, 6.5);
    glVertex2f(-4, 7.9);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0,0.7,0);
    glVertex2f(-6.6, 6.5);
    glVertex2f(-2.4, 6.5);
    glVertex2f(-4, 7.6);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0,0.6,0);
    glVertex2f(-6.4, 6.5);
    glVertex2f(-2.6, 6.5);
    glVertex2f(-4, 7.3);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0,0.5,0);
    glVertex2f(-6.2, 6.5);
    glVertex2f(-2.8, 6.5);
    glVertex2f(-4, 7);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0,0.4,0);
    glVertex2f(-6, 6.5);
    glVertex2f(-3, 6.5);
    glVertex2f(-4, 6.7);
    glEnd();
    // END Front 2nd Triangle from left

    // Front 1st Triangle from left
    glBegin(GL_TRIANGLES);
    glColor3f(0,0.9,0);
    glVertex2f(-10.0, 6.5);
    glVertex2f(-6.9, 6.5);
    glVertex2f(-10.0, 8);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0,0.8,0);
    glVertex2f(-10.0, 6.5);
    glVertex2f(-7.1, 6.5);
    glVertex2f(-10.0, 7.7);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0,0.7,0);
    glVertex2f(-10.0, 6.5);
    glVertex2f(-7.3, 6.5);
    glVertex2f(-10.0, 7.4);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0,0.6,0);
    glVertex2f(-10.0, 6.5);
    glVertex2f(-7.5, 6.5);
    glVertex2f(-10.0, 7.1);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0,0.5,0);
    glVertex2f(-10.0, 6.5);
    glVertex2f(-7.3, 6.5);
    glVertex2f(-10.0, 6.8);
    glEnd();
    // END Front 1st Triangle from left
}

void ship(){

    //this is the lower boat ship panel
    glBegin(GL_POLYGON);
    glColor3f(0.328,0.03125,0);
    glVertex2f(-9.40, 1.4);
    glVertex2f(-9.0, 0.4);
    glVertex2f(-4.0, 0.8);
    glVertex2f(-3, 2);
    glEnd();

    //this is the upper middle box with light red
    glBegin(GL_POLYGON);
    glColor3f(0.6289,0.1367,0);
    glVertex2f(-4.6, 1.85);
    glVertex2f( -4,3.4);
    glVertex2f(-4.6, 3.8);
    glVertex2f( -5.4,2.5);
    glEnd();

    // Upper right corridor of the ship
    glBegin(GL_POLYGON);
    glColor3f(0.6289,0.1367,0);
    glVertex2f( -4,3.4);
    glVertex2f(-4.6, 3.8);
    glVertex2f(-2, 4);
    glVertex2f(-1.5, 3.8);
    glEnd();

    // Right middle Red panel
    glBegin(GL_POLYGON);
    glColor3f(0.328,0.03125,0);
    glVertex2f(-1.5, 3.8);
    glVertex2f(-3, 2);
    glVertex2f(-4.6, 1.85);
    glVertex2f( -4,3.4);
    glEnd();

    // Left middle Red Panel
    glBegin(GL_POLYGON);
    glColor3f(0.328,0.03125,0);
    glVertex2f(-10, 2.8);
    glVertex2f(-9.40, 1.4);
    glVertex2f(-8.3, 1.4);
    glVertex2f(-8.8, 2.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.328,0.03125,0);
    glVertex2f(-10, 2.8);
    glVertex2f(-9.6, 2.8);
    glVertex2f(-9.6, 3.1);
    glEnd();

    // middle corridor with light red
    glBegin(GL_POLYGON);
    glColor3f(0.6289,0.1367,0);
    glVertex2f(-4.6, 1.85);
    glVertex2f( -5.4,2.5);
    glVertex2f(-8.15, 2.2);
    glVertex2f(-8.35, 1.5);  // from this point I draw the left upper corridor
    glEnd();

    // link the middle corridor with left base
    glBegin(GL_POLYGON);
    glColor3f(0.6289,0.1367,0);
    glVertex2f(-8.35, 1.5);
    glVertex2f(-8.15, 2.2);
    glVertex2f(-8.7, 3.1);
    glVertex2f(-8.8, 3.1);
    glVertex2f(-8.8, 2.8);
    glEnd();

    // back white building on th ship
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(-8.8, 2.8);
    glVertex2f(-9.4, 2.8);
    glVertex2f(-9.4, 4.8);
    glVertex2f(-8.8, 4.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.8,0.8,0.8);
    glVertex2f(-9.4, 2.8);
    glVertex2f(-9.4, 4.8);
    glVertex2f(-9.6, 4.3);
    glVertex2f(-9.6, 2.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-8.9, 3.2);
    glVertex2f(-9.3, 3.2);
    glVertex2f(-9.3, 3.6);
    glVertex2f(-8.9, 3.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-8.9, 4);
    glVertex2f(-9.3, 4);
    glVertex2f(-9.3, 4.4);
    glVertex2f(-8.9, 4.4);
    glEnd();

    // End  back white building on th ship
}

void stand(){

    glTranslatef(-8.5, -4.2, 0.0);

    glBegin(GL_POLYGON);
    glColor3f(0.1797, 0.2422, 1);
    glVertex2f(-3.0, -1);
    glVertex2f(-2.0, -1);
    glVertex2f(-1.7, -2);
    glVertex2f(-2.7, -2);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(-2.8, -1.2);
    glVertex2f(-2.8, 6);
    glVertex2f(-2.15, -1.2);
    glVertex2f(-2.15, 6);

    glVertex2f(-1.9, -1.9);
    glVertex2f(-1.9, 5.8);
    glVertex2f(-2.6, -1.9);
    glVertex2f(-2.6, 5.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-3.0, 6);
    glVertex2f(-2.0, 6);
    glVertex2f(-1.6, 5.4);
    glVertex2f(-2.6, 5.4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.0586, 1);
    glVertex2f(-1.7, -2);
    glVertex2f(-2.7, -2);
    glVertex2f(-2.7, -2.4);
    glVertex2f(-1.7, -2.4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.0586, 1);
    glVertex2f(-2.7, -2);
    glVertex2f(-2.7, -2.4);
    glVertex2f(-3.0, -1.4);
    glVertex2f(-3.0, -1);
    glEnd();


}

void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, 0);
    switch (state){
        case 1: if (x_position_boat > -17.5)
                    x_position_boat -= 0.01;
                else
                    state = -1;
                break;
        case -1: if (x_position_boat < -2)
                    x_position_boat += 0.01;
                else
                    state = 1;
    }
}

void timer2(int){
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer2, 0);
    x_position_cloud += 0.008;
}
