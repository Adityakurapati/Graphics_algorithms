#include <GL/glut.h>
#include <iostream>
#include <cmath>

// Global variables for shape and transformation parameters
int numPoints = 0;
int shapePoints[10][2]; // Maximum 10 points for the shape
int transformationChoice = 0;
float transformationParam1 = 0.0f;
float transformationParam2 = 0.0f;

// Function to draw the shape based on given points
void drawShape() {
    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white
    glBegin(GL_POLYGON);
    for (int i = 0; i < numPoints; ++i) {
        glVertex2f(shapePoints[i][0], shapePoints[i][1]);
    }
    glEnd();
}

// Function to perform scaling transformation
void performScaling() {
    glScalef(transformationParam1, transformationParam2, 1.0f);
}

// Function to perform translation transformation
void performTranslation() {
    glTranslatef(transformationParam1, transformationParam2, 0.0f);
}

// Function to perform rotation transformation
void performRotation() {
    glRotatef(transformationParam1, 0.0f, 0.0f, 1.0f); // Rotate around Z-axis
}

// Function to perform shearing transformation
// Function to perform shearing transformation
void performShearing() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    GLfloat shearingMatrix[16] = {
        1.0f, transformationParam1, 0.0f, 0.0f,
        transformationParam2, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
    glMultMatrixf(shearingMatrix);
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
    drawShape();
    glutSwapBuffers();
}

// Keyboard callback function
void keyboard(unsigned char key, int x, int y) {
    switch(key) {
        case '1':
            transformationChoice = 1; // Scaling
            std::cout << "Enter scaling parameters (x y): ";
            std::cin >> transformationParam1 >> transformationParam2;
            glutPostRedisplay();
            break;
        case '2':
            transformationChoice = 2; // Translation
            std::cout << "Enter translation parameters (x y): ";
            std::cin >> transformationParam1 >> transformationParam2;
            glutPostRedisplay();
            break;
        case '3':
            transformationChoice = 3; // Rotation
            std::cout << "Enter rotation angle (degrees): ";
            std::cin >> transformationParam1;
            transformationParam1 = fmod(transformationParam1, 360.0f); // Ensure angle is within [0, 360)
            glutPostRedisplay();
            break;
        case '4':
            transformationChoice = 4; // Shearing
            std::cout << "Enter shearing parameters (xy yx): ";
            std::cin >> transformationParam1 >> transformationParam2;
            glutPostRedisplay();
            break;
        default:
            break;
    }
}

// Initialize OpenGL settings
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100.0f, 100.0f, -100.0f, 100.0f); // Set the coordinate system
    glMatrixMode(GL_MODELVIEW);
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("2D Shape Transformation");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    std::cout << "Enter the number of points for the shape: ";
    std::cin >> numPoints;
    std::cout << "Enter the points (x y): ";
    for (int i = 0; i < numPoints; ++i) {

    std::cout << "Enter the points For "<<i<<" (x y): ";
        std::cin >> shapePoints[i][0] >> shapePoints[i][1];
    }

    glutMainLoop();

    return 0;
}
