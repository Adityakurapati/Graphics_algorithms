/*

#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

int x,y;
p10 = r*y^2 - r * x ^2*r*y^2 + 1/4r*x^2;

void drawEllipse(x,y){
    while(dx<dy){
        drawEllipse(x,y);
        if(p10 <0){
            x = x+1;
            dx = (2*r*y^2)*x;
            p1 = p10 + 2r*y^2*x + r*y^2;
        }else{
            x = x + 1;
            y = y - 1;
            dx = (2*x^2 * y )*x;
        }
    }
    while(dx>= dy){
        drawEllipse(x,y);
        p20 = r*y^2(x+(1/2))^2  + r*x^2 (y-1)^2 -(r*x^2) * (r*y^2)
        while(y>0){
            drawEllipse(x,y);
            if(p2>0){
                x = x;
                y = y - 1;
                dy = 2*r^2 *x^2*y;
                p2 = p2 - dy - r*x^2;
            }else if(p2 <= 0){
                x = x + 1;
                y = y - 1;
                dy = dy - 2*r*x^2;
                dx = dx + 2*r*y^2;
                p2 = p2 + dx-dy +(r*x^2
            }
        }


    }
}


void plotCirclePoints(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x_mid + x, y_mid + y);
    glVertex2i(x_mid - x, y_mid + y);
    glVertex2i(x_mid + x, y_mid - y);
    glVertex2i(x_mid - x, y_mid - y);
    glVertex2i(x_mid + y, y_mid + x);
    glVertex2i(x_mid + y, y_mid - x);
    glVertex2i(x_mid - y, y_mid + x);
    glVertex2i(x_mid - y, y_mid - x);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0);
    glPointSize(2.0);

    int x = 0;
    int y = radius;
    int p = 1 - radius;

    while (x <= y) {
        plotCirclePoints(x, y);
        if (p < 0) {
            p += 2 * x + 1;
        } else {
            p += 2 * (x - y) + 1;
            y--;
        }
        x++;
    }

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
}

void acceptInput() {
    printf("Enter X Coordinate Of Circle : ");
    scanf("%d", &x_mid);
    printf("Enter Y Coordinate Of Circle : ");
    scanf("%d", &y_mid);
    printf("Enter Radius Of Circle : ");
    scanf("%d", &radius);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    acceptInput();

    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Circle");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


*/
