#include <stdio.h>
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
        glVertex2f(-0.5, -0.5);
        glVertex2f(-0.5, 0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(0.5, -0.5);
    glEnd();

    glFlush();
}

void mouse(int button, int state, int x, int y) {
    // Button:
    // GLUT_LEFT_BUTTON
    // GLUT_MIDDLE_BUTTON
    // GLUT_RIGHT_BUTTON

    // State:
    // GLUT_DOWN
    // GLUT_UP

    printf("Button: %d - State: %d @ (%d,%d)\n", button, state, x, y);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Mouse.");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();

    return 0;
}