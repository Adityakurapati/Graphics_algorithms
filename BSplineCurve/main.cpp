
#include <GL/glut.h>
#include <cmath>

// Function to calculate a point on a Bezier curve
double bpsline_curve(float t, int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3, float &x, float &y) {
    int k = k;
    int t[]={};
    if(k>1){
        N[i][l] = (t-t[i])/(t[i+(k-1)]/(N[i+1   ,k-1]))
    }else if(k==1){
        u = t[i],t[i+1];
    }
}

// Function to draw the Bezier curve
void drawBsplineCurve(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {
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

