#include <iostream>
#include <math.h>
#include <time.h>
#include <GL/glut.h>

using namespace std;

void init(){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,640,0,480);
}

void bound_fill4(int x, int y, float* fillColor, float* bc){
    float color[3];
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,color);
    if((color[0]!=bc[0] || color[1]!=bc[1] || color[2]!=bc[2])&&(
     color[0]!=fillColor[0] || color[1]!=fillColor[1] || color[2]!=fillColor[2])){
        glColor3f(fillColor[0],fillColor[1],fillColor[2]);
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
        glFlush();
        bound_fill4(x+1,y,fillColor,bc);
        bound_fill4(x-2,y,fillColor,bc);
        bound_fill4(x,y+2,fillColor,bc);
        bound_fill4(x,y-2,fillColor,bc);

    }
}

void bound_fill8(int x, int y, float* fillColor, float* bc){
    float color[3];
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,color);
    if((color[0]!=bc[0] || color[1]!=bc[1] || color[2]!=bc[2])&&(
     color[0]!=fillColor[0] || color[1]!=fillColor[1] || color[2]!=fillColor[2])){
        glColor3f(fillColor[0],fillColor[1],fillColor[2]);
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
        glFlush();
        bound_fill8(x+1,y,fillColor,bc);
        bound_fill8(x+1,y+1,fillColor,bc);
        bound_fill8(x,y+1,fillColor,bc);
        bound_fill8(x-1,y+1,fillColor,bc);
        bound_fill8(x-1,y,fillColor,bc);
        bound_fill8(x-1,y-1,fillColor,bc);
        bound_fill8(x,y-1,fillColor,bc);
        bound_fill8(x+1,y-1,fillColor,bc);
    }
}

void world(){
    glLineWidth(3);
    glPointSize(2);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(150,100);
        glVertex2i(300,300);
        glVertex2i(450,100);
    glEnd();

    float bCol[] = {1,0,0};
    float color[] = {0,1,0};
    bound_fill8(300,150,color,bCol);
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Many Amaze Very GL WOW");
    glutDisplayFunc(world);
    init();
    glutMainLoop();
    return 0;
}
