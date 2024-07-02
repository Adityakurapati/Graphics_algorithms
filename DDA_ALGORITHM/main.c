#include <GL/glut.h>
#include <iostream>

int slopeType;
void drawLine() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    switch (slopeType) {
        case 1:  // Slope less than 1
            glVertex2f(0.1, 0.1);
            glVertex2f(0.9, 0.2);
            break;

        case 2:  // Slope greater than 1
            glVertex2f(0.1, 0.1);
            glVertex2f(0.9, 2.0);
            break;

        case 3:  // Slope equal to 1
            glVertex2f(0.1, 0.1);
            glVertex2f(0.9, 0.9);
            break;

        case 4:  // Slope equal to 0
            glVertex2f(0.1, 0.5);
            glVertex2f(0.9, 0.5);
            break;

        case 5:  // Slope equal to infinite
            glVertex2f(0.5, 0.1);
            glVertex2f(0.5, 0.9);
            break;

        default:
            std::cout << "Invalid slope type!\n";
            break;
    }

    glEnd();
    glFlush();
}

void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
            slopeType = key - '0';
            glutPostRedisplay();
            break;

        case 27:
            exit(0);
            break;

        default:
            std::cout << "Invalid input. Please enter 1, 2, 3, 4, or 5.\n";
            break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Console Line Drawer");
    glutInitWindowSize(1000, 1000);
    glutDisplayFunc(drawLine);
    glutKeyboardFunc(handleKeypress);
    glClearColor(0.0, 0.0, 0.0, 1.0);

    std::cout << "Choose a slope type:\n"
              << "1 - Slope less than 1\n"
              << "2 - Slope greater than 1\n"
              << "3 - Slope equal to 1\n"
              << "4 - Slope equal to 0\n"
              << "5 - Slope equal to infinite\n";

    glutMainLoop();
    return 0;
}
