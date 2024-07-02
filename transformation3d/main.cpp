#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

#define MAX_VERTICES 10

int vertex;
float tx, ty, tz, sx, sy, sz, thetaX, thetaY, thetaZ, shxy, shxz, shyx, shyz, shzx, shzy;
float xd[MAX_VERTICES], yd[MAX_VERTICES], zd[MAX_VERTICES];
float X1[MAX_VERTICES], Y1[MAX_VERTICES], Z1[MAX_VERTICES];

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void translation() {
    for (int i = 0; i < vertex; i++) {
        X1[i] = xd[i] + tx;
        Y1[i] = yd[i] + ty;
        Z1[i] = zd[i] + tz;
    }
}

void scaling() {
    for (int i = 0; i < vertex; i++) {
        X1[i] = xd[i] * sx;
        Y1[i] = yd[i] * sy;
        Z1[i] = zd[i] * sz;
    }
}

void rotation() {
    float thetaRadX = thetaX * 3.14159265 / 180.0;
    float thetaRadY = thetaY * 3.14159265 / 180.0;
    float thetaRadZ = thetaZ * 3.14159265 / 180.0;

    for (int i = 0; i < vertex; i++) {
        float x = xd[i];
        float y = yd[i];
        float z = zd[i];

        X1[i] = x * cos(thetaRadX) - y * sin(thetaRadX);
        Y1[i] = x * sin(thetaRadX) + y * cos(thetaRadX);
        Z1[i] = z;

        x = X1[i];
        z = Z1[i];

        X1[i] = x * cos(thetaRadY) + z * sin(thetaRadY);
        Y1[i] = Y1[i];
        Z1[i] = -x * sin(thetaRadY) + z * cos(thetaRadY);

        x = X1[i];
        y = Y1[i];

        X1[i] = x * cos(thetaRadZ) - y * sin(thetaRadZ);
        Y1[i] = x * sin(thetaRadZ) + y * cos(thetaRadZ);
        Z1[i] = Z1[i];
    }
}

void shearing() {
    for (int i = 0; i < vertex; i++) {
        X1[i] = xd[i] + shxy * yd[i] + shxz * zd[i];
        Y1[i] = yd[i] + shyx * xd[i] + shyz * zd[i];
        Z1[i] = zd[i] + shzx * xd[i] + shzy * yd[i];
    }
}

void reflection() {
    for (int i = 0; i < vertex; i++) {
        X1[i] = -xd[i];
        Y1[i] = -yd[i];
        Z1[i] = -zd[i];
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);
    glLoadIdentity();

    gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    if (vertex == 2) {
        glBegin(GL_LINES);
    } else {
        glBegin(GL_POLYGON);
    }

    for (int i = 0; i < vertex; i++) {
        glVertex3f(xd[i], yd[i], zd[i]);
    }

    glEnd();

    glColor3f(1.0, 0.0, 1.0);

    if (vertex == 2) {
        glBegin(GL_LINES);
    } else {
        glBegin(GL_POLYGON);
    }

    for (int i = 0; i < vertex; i++) {
        glVertex3f(X1[i], Y1[i], Z1[i]);
    }

    glEnd();
    glutSwapBuffers();
}

void operation(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':
            printf("Enter translation factors (tx ty tz): ");
            scanf("%f %f %f", &tx, &ty, &tz);
            translation();
            break;
        case 'b':
            printf("Enter scaling factors (sx sy sz): ");
            scanf("%f %f %f", &sx, &sy, &sz);
            scaling();
            break;
        case 'c':
            printf("Enter rotation angles (thetaX thetaY thetaZ): ");
            scanf("%f %f %f", &thetaX, &thetaY, &thetaZ);
            rotation();
            break;
        case 'd':
            reflection();
            break;
        case 'e':
            printf("Enter shearing factors (shxy shxz shyx shyz shzx shzy): ");
            scanf("%f %f %f %f %f %f", &shxy, &shxz, &shyx, &shyz, &shzx, &shzy);
            shearing();
            break;
        default:
            printf("Invalid input.\n");
            return;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);

    printf("ENTER NO. OF VERTICES (max=10):\n");
    scanf("%d", &vertex);

    if (vertex < 2 || vertex > MAX_VERTICES) {
        printf("Invalid Input. Exiting...\n");
        exit(0);
    }

    for (int i = 0; i < vertex; i++) {
        printf("Enter coordinates (x, y, z) for vertex %d:\n", i + 1);
        scanf("%f %f %f", &xd[i], &yd[i], &zd[i]);
    }

    printf("Enter transformation technique:\n");
    printf("a. Translation\n");
    printf("b. Scaling\n");
    printf("c. Rotation\n");
    printf("d. Reflection\n");
    printf("e. Shearing\n");

    char choice;
    scanf(" %c", &choice);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("3D Transformation ");
    glEnable(GL_DEPTH_TEST);

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(operation);
    glutMainLoop();

    return 0;
}
