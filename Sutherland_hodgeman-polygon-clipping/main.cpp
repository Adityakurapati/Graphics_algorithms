#include <GL/glut.h>
#include <vector>

struct Point {
  float x, y;
};

// Clip codes for each edge of the clipping window
enum ClipCode {
  INSIDE = 0,
  LEFT = 1,
  RIGHT = 2,
  BOTTOM = 4,
  TOP = 8
};

ClipCode GetClipCode(Point p, Point min, Point max) {
  ClipCode code = INSIDE;
  if (p.x < min.x) {
    code |= LEFT;
  } else if (p.x > max.x) {
    code |= RIGHT;
  }
  if (p.y < min.y) {
    code |= BOTTOM;
  } else if (p.y > max.y) {
    code |= TOP;
  }
  return static_cast<ClipCode>(code);
}


std::vector<Point> SutherlandHodgmanClip(std::vector<Point> polygon, Point min, Point max) {
  std::vector<Point> outputList;
  Point p1, p2, intersection;

for (std::vector<Point>::size_type i = 0; i < polygon.size(); i++) {
  ClipCode code1 = GetClipCode(polygon[i], min, max);
    ClipCode code2 = GetClipCode(polygon[(i + 1) % polygon.size()], min, max);

    // Trivial acceptance
    if ((code1 == INSIDE) && (code2 == INSIDE)) {
      outputList.push_back(polygon[i]);
      outputList.push_back(polygon[(i + 1) % polygon.size()]);
    } else if ((code1 & code2) == 0) {
      // Calculate intersection point
      if (code1 & LEFT) {
        intersection.x = min.x;
        intersection.y = polygon[i].y + (polygon[(i + 1) % polygon.size()].y - polygon[i].y) *
                          (min.x - polygon[i].x) / (polygon[(i + 1) % polygon.size()].x - polygon[i].x);
      } else if (code1 & RIGHT) {
        intersection.x = max.x;
        intersection.y = polygon[i].y + (polygon[(i + 1) % polygon.size()].y - polygon[i].y) *
                          (max.x - polygon[i].x) / (polygon[(i + 1) % polygon.size()].x - polygon[i].x);
      } else if (code1 & BOTTOM) {
        intersection.y = min.y;
        intersection.x = polygon[i].x + (polygon[(i + 1) % polygon.size()].x - polygon[i].x) *
                          (min.y - polygon[i].y) / (polygon[(i + 1) % polygon.size()].y - polygon[i].y);
      } else if (code1 & TOP) {
        intersection.y = max.y;
        intersection.x = polygon[i].x + (polygon[(i + 1) % polygon.size()].x - polygon[i].x) *
                          (max.y - polygon[i].y) / (polygon[(i + 1) % polygon.size()].y - polygon[i].y);
      }

      // Add intersection point
      if (code1 != INSIDE) {
        outputList.push_back(intersection);
      }
      // Add second point if it's inside
      if (code2 != INSIDE) {
        outputList.push_back(polygon[(i + 1) % polygon.size()]);
      }
    } else {
      // Reject polygon
    }
  }
  return outputList;
}

Point minClip = {-1.0f, -1.0f};
Point maxClip = {1.0f, 1.0f};
std::vector<Point> polygon = {{0.5f, 0.5f}, {1.5f, 0.5f}, {1.5f, -0.5f}, {-0.5f, -0.5f}, {-0.5f, 0.5f}};

void drawLine(Point p1, Point p2) {
  glBegin(GL_LINES);
  glVertex2f(p1.x, p1.y);
  glVertex2f(p2.x, p2.y);
  glEnd();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  // Clip the polygon
  std::vector<Point> clippedPolygon = SutherlandHodgmanClip(polygon, minClip, maxClip);

  // Draw clipping window
  glColor3f(1.0f, 0.0f, 0.0f); // Red for clipping window
  glBegin(GL_LINE_LOOP);
  glVertex2f(minClip.x, minClip.y);
  glVertex2f(maxClip.x, minClip.y);
  glVertex2f(maxClip.x, maxClip.y);
  glVertex2f(minClip.x, maxClip.y);
  glEnd();

  // Draw original polygon (optional)
  glColor3f(0.0f, 1.0f, 0.0f); // Green for original polygon
  for (int i = 0; i < polygon.size(); i++) {
    drawLine(polygon[i], polygon[(i + 1) % polygon.size()]);
  }

  // Draw clipped polygon
  glColor3f(0.0f, 0.0f, 1.0f); // Blue for clipped polygon
  for (int i = 0; i < clippedPolygon.size(); i++) {
    drawLine(clippedPolygon[i], clippedPolygon[(i + 1) % clippedPolygon.size()]);
  }

  glFlush();
}

void reshape(int width, int height) {
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-2.0f, 2.0f, -2.0f, 2.0f); // Adjust coordinates based on your needs
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Sutherland-Hodgman Polygon Clipping");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;
}

