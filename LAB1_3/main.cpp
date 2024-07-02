#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

int x1, y1, x2, y2;

void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int pk = 2 * dy - dx;
    int x = x1, y = y1;

    glBegin(GL_POINTS);

    glVertex2i(x, y);

    while (x < x2) {
        x++;

        if (pk < 0) {
            pk = pk + 2 * dy;
        } else {
            y++;
            pk = pk + 2 * dy - 2 * dx;
        }

        glVertex2i(x, y);
    }

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0); // Set color to white

    drawLineBresenham(x1, y1, x2, y2);

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Set clear color to black
    gluOrtho2D(0, 500, 0, 500); // Set the coordinate system
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bresenham Line Drawing Algorithm");

    printf("Enter two end points of the line:\n");
    printf("Enter Point 1 (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter Point 2 (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
