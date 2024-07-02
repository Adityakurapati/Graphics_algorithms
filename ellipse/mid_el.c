
#include <GL/glut.h>
#include <iostream>

using namespace std;

void drawEllipse(int xc, int yc, int rx, int ry) {
    int x = 0, y = ry;
    int rx2 = rx * rx;
    int ry2 = ry * ry;
    int tworx2 = 2 * rx2;
    int twory2 = 2 * ry2;
    int p;
    int px = 0;
    int py = tworx2 * y;

    // Region 1
    p = ry2 - (rx2 * ry) + (0.25 * rx2);
    while (px < py) {
        x++;
        px += twory2;
        if (p < 0)
            p += ry2 + px;
        else {
            y--;
            py -= tworx2;
            p += ry2 + px - py;
        }
        glBegin(GL_POINTS);
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc - x, yc - y);
        glEnd();
    }


    p = ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2;
    while (y > 0) {
        y--;
        py -= tworx2;
        if (p > 0)
            p += rx2 - py;
        else {
            x++;
            px += twory2;
            p += rx2 - py + px;
        }
        glBegin(GL_POINTS);
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc - x, yc - y);
        glEnd();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    int xc, yc, rx, ry;
    cout << "Enter center coordinates:(x,y) ";
    cin >> xc >> yc;

    cout << "Enter x-radius: ";
    cin >> rx;

    cout << "Enter y-radius: ";
    cin >> ry;

    drawEllipse(xc, yc, rx, ry);
    xc =

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Midpoint Ellipse Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

