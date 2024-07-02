/*
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

int x_mid, y_mid, radius;

void drawEllipse() {
    int segments = 100; // Number of line segments to approximate the ellipse

    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);

    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * 3.1415926f * i / segments;
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);

        glVertex2f(x_mid + x, y_mid + y);
    }

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(2.0);

    drawEllipse();

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
}

void acceptInput() {
    printf("Enter X Coordinate Of Ellipse Center: ");
    scanf("%d", &x_mid);
    printf("Enter Y Coordinate Of Ellipse Center: ");
    scanf("%d", &y_mid);
    printf("Enter X Radius Of Ellipse: ");
    scanf("%d", &radius);
    printf("Enter Y Radius Of Ellipse: ");
    scanf("%d", &radius);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    acceptInput();

    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Ellipse Drawing");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
*/
