#include <iostream>
#include <GL/glut.h>

using namespace std;

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 640, 0, 480);
}

void drawSquare() {
    glColor3f(1, 0, 0); // Red color for the square
    glBegin(GL_LINE_LOOP);
    glVertex2i(150, 100);
    glVertex2i(450, 100);
    glVertex2i(450, 400);
    glVertex2i(150, 400);
    glEnd();
}

void scanlineFillSquare(int y, float* fillColor) {
    glBegin(GL_POINTS);
    for (int x = 150; x <= 450; ++x) {
        glColor3fv(fillColor);
        glVertex2i(x, y);
    }
    glEnd();
    glFlush();
}

void fillSquare(float* fillColor) {
    for (int y = 100; y <= 400; ++y) {
        scanlineFillSquare(y, fillColor);
    }
}

void world() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawSquare();

    float color[] = { 0, 0, 1 }; // Fill color (blue)
    fillSquare(color);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Scanline Fill Algorithm in OpenGL");
    glutDisplayFunc(world);
    init();
    glutMainLoop();
    return 0;
}
