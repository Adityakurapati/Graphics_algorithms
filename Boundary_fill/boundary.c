



/*
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

#define WIDTH 640
#define HEIGHT 480

// Color buffer to store pixel colors
int colorBuffer[WIDTH][HEIGHT];

// Polygon vertices
int polygonVertices[][2] = {{100, 100}, {200, 100}, {200, 200}, {150, 250}, {100, 200}};
int numPolygonVertices = 5;

// Function to check if a point (x, y) is inside or on the polygon
int isInsidePolygon(int x, int y) {
    int i, j, c = 0;
    for (i = 0, j = numPolygonVertices - 1; i < numPolygonVertices; j = i++) {
        if (((polygonVertices[i][1] > y) != (polygonVertices[j][1] > y)) &&
            (x < (polygonVertices[j][0] - polygonVertices[i][0]) * (y - polygonVertices[i][1]) /
                     (polygonVertices[j][1] - polygonVertices[i][1]) + polygonVertices[i][0])) {
            c = !c;
        }
    }
    return c;
}

// Function to get pixel color at (x, y) within the polygon
int getPixel(int x, int y) {
    if (isInsidePolygon(x, y)) {
        return colorBuffer[x][y];
    } else {
        return -1; // Return a value indicating outside the polygon
    }
}

// Function to set pixel color at (x, y) within the polygon
void putPixel(int x, int y, int color) {
    if (isInsidePolygon(x, y)) {
        colorBuffer[x][y] = color;
    }
}

// Function to draw the polygon
void drawPolygon() {
    glColor3d(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numPolygonVertices; ++i) {
        glVertex2i(polygonVertices[i][0], polygonVertices[i][1]);
    }
    glEnd();
}

// Function to perform boundary fill using 4-connected neighbors
void boundary_fill4(int x, int y, int fillColor, int borderColor) {
    int c;
    c = getPixel(x, y);
    if (c != fillColor && c != borderColor) {
        putPixel(x, y, fillColor);
        boundary_fill4(x + 1, y, fillColor, borderColor);
        boundary_fill4(x, y + 1, fillColor, borderColor);
        boundary_fill4(x - 1, y, fillColor, borderColor);
        boundary_fill4(x, y - 1, fillColor, borderColor);
    }
}

static void resize(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

static void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the polygon
    drawPolygon();

    // Call boundary fill algorithm within the polygon
    boundary_fill4(150, 150, 2, 1);

    glutSwapBuffers();
}

static void key(unsigned char key, int x, int y) {
    switch (key) {
    case 27:
    case 'q':
        exit(0);
        break;
    }
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutCreateWindow("Polygon and Boundary Fill");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);

    glClearColor(1, 1, 1, 1);

    glutMainLoop();

    return EXIT_SUCCESS;
}


 /*
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

static int slices = 16;
static int stacks = 16;

void getPixel(int x,int y,int color){
    glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,color)

}
void setPixel(int x,int y)
void boundary_fill4(int x,int y,int color,int color1){
    int c;
    c =getPixel(x,y);
    if(c!=color && c!= color1){
        putPixel(x,y,color);
        fill4(x+1,y,color,color1);
        fill4(x,y+1,color,color1);
        fill4(x-1,y,color,color1);
        fill4(x,y-1,color,color1);
    }
}
void boundary_fill8(int x,int y,int color,int color1){
    int c;
    c =getPixel(x,y);
    if(c!=color && c!= color1){
        putPixel(x,y,color);
        fill8(x+1,y,color,color1);
        fill8(x+1,y+1,color,color1);
        fill8(x,y+1,color,color1);
        fill8(x-1,y+1,color,color1);
        fill8(x-1,y,color,color1);
        fill8(x-1,y-1,color,color1);
        fill8(x,y-1,color,color1);
        fill8(x+1,y-1,color,color1);
    }
}

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);

    glPushMatrix();
        glTranslated(-2.4,1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutSolidCone(1,1,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(2.4,1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutSolidTorus(0.2,0.8,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-2.4,-1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutWireSphere(1,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,-1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutWireCone(1,1,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(2.4,-1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutWireTorus(0.2,0.8,slices,stacks);
    glPopMatrix();

    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case '+':
            slices++;
            stacks++;
            break;

        case '-':
            if (slices>3 && stacks>3)
            {
                slices--;
                stacks--;
            }
            break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return EXIT_SUCCESS;
}
*/
