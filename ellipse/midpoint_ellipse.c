/*
#include <stdio.h>

#include <GL/glut.h>
#include <math.h>

int x_mid, y_mid, a, b;

void plotEllipsePoints(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x_mid + x, y_mid + y);
    glVertex2i(x_mid - x, y_mid + y);
    glVertex2i(x_mid + x, y_mid - y);
    glVertex2i(x_mid - x, y_mid - y);
    glEnd();
}

void drawEllipse() {
    int x = 0;
    int y = b;
    int p = pow(b, 2) - pow(a, 2) * b + 0.25 * pow(a, 2);

    int two_a_squared = 2 * pow(a, 2);
    int two_b_squared = 2 * pow(b, 2);

    while (two_b_squared * x < two_a_squared * y) {
        plotEllipsePoints(x, y);
        if (p < 0) {
            p += two_b_squared * (2 * x + 3);
        } else {
            p += two_b_squared * (2 * x + 3) + two_a_squared * (2 - 2 * y);
            y--;
        }
        x++;
    }

    p = two_b_squared * pow(x + 0.5, 2) + two_a_squared * pow(y - 1, 2) - two_a_squared * two_b_squared;

    while (y >= 0) {
        plotEllipsePoints(x, y);
        if (p > 0) {
            p += two_a_squared * (3 - 2 * y);
        } else {
            p += two_b_squared * (2 * x + 2) + two_a_squared * (3 - 2 * y);
            x++;
        }
        y--;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0);
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
    printf("Enter Semi-Major Axis (a): ");
    scanf("%d", &a);
    printf("Enter Semi-Minor Axis (b): ");
    scanf("%d", &b);
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
