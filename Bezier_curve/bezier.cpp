
#include <GL/glut.h>
#include <cmath>

// Function to calculate a point on a Bezier curve
void bezier_curve(float t, int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3, float &x, float &y) {
    x = (float)(x0 * pow((1-t),3) + x1 * 3 * pow((1-t),2) * t + x2 * 3 * (1-t) * pow(t,2) + x3 * pow(t,3));
    y = (float)(y0 * pow((1-t),3) + y1 * 3 * pow((1-t),2) * t + y2 * 3 * (1-t) * pow(t,2) + y3 * pow(t,3));
}

// Function to draw the Bezier curve
void drawBezierCurve(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {
    glBegin(GL_LINE_STRIP);
    for(float t = 0; t <= 1; t += 0.0001) {
        float x, y;
        bezier_curve(t, x0, y0, x1, y1, x2, y2, x3, y3, x, y);
        glVertex2f(x, y);
    }
    glEnd();
}

// Function to display
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the Bezier curve
    glColor3f(1.0, 1.0, 1.0); // Set line color to white
    drawBezierCurve(100, 200, 100, 300, 200, 300, 200, 200);
    drawBezierCurve(200, 200, 200, 100,300, 100, 300, 200);

    glFlush(); // Flush the buffer
}

int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bezier Curve Drawing");

    // Set up the display function
    glutDisplayFunc(display);

    // Set the window's background color
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // Set up the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);

    // Enter the GLUT event loop
    glutMainLoop();

    return 0;
}

