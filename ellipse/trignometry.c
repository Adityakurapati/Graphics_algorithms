#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

void drawEllipse(int xc, int yc, int rx, int ry) {
    glBegin(GL_POINTS);

    for (int i = 0; i < 360; ++i) {
        float theta = i * M_PI / 180.0;
        int x = xc + static_cast<int>(rx * cos(theta));
        int y = yc + static_cast<int>(ry * sin(theta));

        glVertex2i(x, y);
    }

    glEnd();
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

    yc = yc + 10;
    xc = xc - 35;
    rx = rx / 3;
    ry = ry / 5;
    drawEllipse(xc, yc, rx, ry);

    xc = xc + rx + 30;
    drawEllipse(xc, yc, rx, ry);

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
    glutCreateWindow("Trigonometry Ellipse Drawing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}








/*#include <GL/glut.h>
#include <iostream>

using namespace std;

void drawEllipse(int xc, int yc, int rx, int ry) {
    int p1 = (b1*b1) - (a1*a1) * (b1) + 0.25 * (a1*a1);
    while(fx<fy){
        setPixel(x1,y1);
        x++;
        fx = fx + ((b1*b1)*2);
        if(p1<0){
            p1 = p1 + fx + (b1*b1);
        }else{
        y = y-1;
        fy = fy - ((a1*a1)*2);
        p1 = p1 + fx + ((b1*b1)*2);
        }
        p1 = (b1*b1)*(x+0.5)*(x+0.5)+(a1*a1)*(y-1)*(y-1)-(a1*a1)*(b1*b1);
        while(y2>0){
            y=y-1;
            fy = fx - ((a1*a1)*2);
            if(p1>=0){
                p1 = p1 - fx+((a1*a1)*2);
            }else{
            x = x +1;
            fx = fx + ((b1*b1)*2);
            p1 = p1 +fx -fy -((a1*a1));
            }
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

    yc = yc+10;
    xc= xc-35;
    rx = rx/3;
    ry = ry/5;
    drawEllipse(xc, yc, rx, ry);

    xc= xc+rx+30;
    drawEllipse(xc, yc, rx, ry);

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

*/
