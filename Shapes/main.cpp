#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the screen
    glPointSize(30);  // Set dot size
    glColor3f(1.0, 0.0, 0.0);  // Set dot color to red

    int x1=100,y1=200;
    int x2=200,y2=500;
    int dx,dy;
    float xinc,yinc;
    float x,y;
    int steps;

    // Slope
    int m=dy/dx;

    // Calculate Distance
    dx = abs(x2-x1);
    dy = abs(y2-y1);

    if(dx>dy)
    {
        steps=dx;
    }else{
        steps=dy;
    }

    xinc = dx / (float)steps;
    yinc = dy / (float)steps;
    x=x1;
    y=y1;
    glBegin(GL_POINTS);
        for(int i=0;i<=steps;i++){
            glVertex2f(x, y);
            x+=xinc;
            y+=yinc;

         }
         glEnd();
           // glVertex2f(0,0);  // Position the dot at the center
         glutSwapBuffers();  // Display the result


}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Dot");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
