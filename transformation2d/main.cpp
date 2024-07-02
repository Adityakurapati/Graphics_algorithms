#include <stdio.h>
#include <stdlib.h>
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <math.h>
#include <ctype.h>

float tx, ty, sx, sy, theta = 50;
int vertex, shx, shy;
float xd[10], yd[10], X1[10], Y1[10];
float WXMax = 600, WXMin = 100, WYMax = 600, WYMin = 100;
float VXMax = 800, VXMin = 600, VYMax = 800, VYMin = 200, VX[10], VY[10], VX1[10], VY1[10];

float SX, SY, TX, TY;

// Global flag to track OpenGL context initialization
int initialized = 0;

void initt() {
    glClearColor(0, 0, 0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1000, 1000, -1000, 1000);
}

void translation() {
    int i;
    for (i = 1; i <= vertex; i++) {
        X1[i] = xd[i] + tx;
        Y1[i] = yd[i] + ty;
    }
}

void scaling() {
    float xh[10], yh[10];
    int i = 1;

    for (i = 1; i <= vertex; i++) {
        xh[i] = xd[i] - xd[1];
        yh[i] = yd[i] - yd[1];
    }

    for (i = 1; i <= vertex; i++) {
        xh[i] = xh[i] * sx;
        yh[i] = yh[i] * sy;
    }
    for (i = 1; i <= vertex; i++) {
        X1[i] = xh[i] + 2 * xd[1];
        Y1[i] = yh[i] + yd[1];
    }
}

void rotation() {
    float t, xh[10], yh[10];
    int i;
    t = -1 * (theta * 3.14 / 180);
    double coss = cos(t);
    double sinn = sin(t);

    for (i = 1; i <= vertex; i++) {
        xh[i] = xd[i] - xd[1];
        yh[i] = yd[i] - yd[1];

        xh[i] = (xh[i] * coss) - (yh[i] * sinn);
        yh[i] = (xh[i] * sinn) + (yh[i] * coss);

        X1[i] = xh[i] + xd[1];
        Y1[i] = yh[i] + yd[1];
    }
}

void shearing() {
    int i;
    for (i = 0; i < vertex; i++) {
        X1[i] = xd[i] + shx * yd[i];
        Y1[i] = yd[i] + shy * xd[i];
    }
}

void reflection() {
    int i;
    for (i = 0; i < vertex; i++) {
        Y1[i] = -yd[i];
        X1[i] = -xd[i];
    }
}

void worldWindow() {
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);
    if (vertex == 2) {
        glBegin(GL_LINES);
        for (i = 1; i <= vertex; i++) {
            glVertex2f(xd[i], yd[i]);
        }
    } else {
        glBegin(GL_POLYGON);
        for (i = 1; i <= vertex; i++) {
            glVertex2f(xd[i], yd[i]);
        }
    }
    glEnd();
    glColor3f(1.0, 0.0, 1.0);
    if (vertex == 2) {
        glBegin(GL_LINES);
        for (i = 1; i <= vertex; i++) {
            glVertex2f(X1[i], Y1[i]);
        }
    } else {
        glBegin(GL_POLYGON);
        for (i = 1; i <= vertex; i++) {
            glVertex2f(X1[i], Y1[i]);
        }
    }
    glEnd();
    glutSwapBuffers();
    glFlush();
}

void viewPort() {
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);
    if (vertex == 2) {
        glBegin(GL_LINES);
        for (i = 1; i <= vertex; i++) {
            glVertex2f(VX[i], VY[i]);
        }
    } else {
        glBegin(GL_POLYGON);
        for (i = 1; i <= vertex; i++) {
            glVertex2f(VX[i], VY[i]);
        }
    }
    glEnd();
    glColor3f(1.0, 0.0, 1.0);
    if (vertex == 2) {
        glBegin(GL_LINES);
        for (i = 1; i <= vertex; i++) {
            glVertex2f(VX1[i], VY1[i]);
        }
    } else {
        glBegin(GL_POLYGON);
        for (i = 1; i <= vertex; i++) {
            glVertex2f(VX1[i], VY1[i]);
        }
    }
    glEnd();
    glutSwapBuffers();
    glFlush();
}

void operation(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':
            printf("Enter translation factors (tx ty): ");
            scanf("%f %f", &tx, &ty);
            translation();
            break;
        case 'b':
            printf("Enter scaling factors (sx sy): ");
            scanf("%f %f", &sx, &sy);
            scaling();
            break;
        case 'c':
            printf("Enter rotation angle (in degrees): ");
            scanf("%f", &theta);
            rotation();
            break;
        case 'd':
            reflection();
            break;
        case 'e':
            printf("Enter shearing factors (shx shy): ");
            scanf("%d %d", &shx, &shy);
            shearing();
            break;
        default:
            printf("Invalid input.\n");
            return;
    }
    // Check if OpenGL context is initialized before calling glutPostRedisplay()
    if (initialized) {
        glutPostRedisplay();
    }
}

int main(int argc, char **argv) {
    int i;

    // Initialize GLUT
    glutInit(&argc, argv);

    printf("ENTER NO. OF VERTICES (max=10):\n");
    scanf("%d", &vertex);
    if (vertex < 2 || vertex > 10) {
        printf("Invalid Input. Exiting...\n");
        exit(0);
    }

    for (i = 1; i <= vertex; i++) {
        printf("Enter coordinates (x, y) for vertex %d:\n", i);
        scanf("%f %f", &xd[i], &yd[i]);
    }

    printf("Enter transformation technique:\n");
    printf("a. Translation\n");
    printf("b. Scaling\n");
    printf("c. Rotation\n");
    printf("d. Reflection (X-axis)\n");
    printf("e. Shearing \n");

    char choice;
    scanf(" %c", &choice);
    operation(choice,0,0); // Passing 0, 0 as additional arguments for compatibility

    // Create first window
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WXMax - WXMin, WYMax - WYMin);
    glutInitWindowPosition(WXMin, WYMin);
    glutCreateWindow("2D TRANSFORMATION ");
    initt();
    glutDisplayFunc(worldWindow);
    glutKeyboardFunc(operation);

    // Set the initialized flag to true after creating the first window
    initialized = 1;

    // Create second window
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(VXMax - VXMin, VYMax - VYMin);
    glutInitWindowPosition(VXMin, VYMin);
    glutCreateWindow("OpenGL - View Port Transformation");
    initt();
    glutDisplayFunc(viewPort);
    glutMainLoop();
    return 0;
}
