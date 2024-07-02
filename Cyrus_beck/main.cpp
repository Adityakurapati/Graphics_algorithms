#include <GL/glut.h>
#include <stdio.h>
#include <stdbool.h>

// Window coordinates
float xmin = 50, ymin = 50, xmax = 200, ymax = 200;

// Line coordinates
float x0, y0, x1, y1;

#define INSIDE 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

float dotProduct(float x1, float y1, float x2, float y2) {
    return x1 * x2 + y1 * y2;
}

void CyrusBeckLineClipAndDraw() {
    float dx = x1 - x0, dy = y1 - y0;

    float p[4] = {-dx, dx, -dy, dy};
    float q[4] = {x0 - xmin, xmax - x0, y0 - ymin, ymax - y0};

    float t1 = 0, t2 = 1;

    for (int i = 0; i < 4; ++i) {
        if (p[i] == 0) {
            if (q[i] < 0) {
                return; // Line is parallel to clipping edge and outside
            }
        } else {
            float t = q[i] / p[i];
            if (p[i] < 0 && t1 <= t) {
                t1 = t;
            } else if (p[i] > 0 && t2 >= t) {
                t2 = t;
            }
        }
    }

    if (t1 < t2) {
        float x_start = x0 + t1 * dx;
        float y_start = y0 + t1 * dy;
        float x_end = x0 + t2 * dx;
        float y_end = y0 + t2 * dy;

        glColor3f(0.0, 1.0, 0.0); // Green color for the clipped line
        glBegin(GL_LINES);
        glVertex2f(x_start, y_start);
        glVertex2f(x_end, y_end);
        glEnd();
    } else {
        printf("Line rejected\n");
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the rectangular clipping window
    glColor3f(1.0, 0.0, 0.0); // Red color for the window
    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin, ymin);
    glVertex2f(xmax, ymin);
    glVertex2f(xmax, ymax);
    glVertex2f(xmin, ymax);
    glEnd();

    // Draw the original unclipped line
    glColor3f(0.0, 0.0, 1.0); // Blue color for the original line
    glBegin(GL_LINES);
    glVertex2f(x0, y0);
    glVertex2f(x1, y1);
    glEnd();

    // Perform line clipping using Cyrus-Beck algorithm
    CyrusBeckLineClipAndDraw();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0); // White background
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 300.0, 0.0, 300.0);
}

int main(int argc, char **argv) {
    printf("Enter the coordinates of the line (x0 y0 x1 y1): ");
    scanf("%f %f %f %f", &x0, &y0, &x1, &y1);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Cyrus-Beck Line Clipping");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
