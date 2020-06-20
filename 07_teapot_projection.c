#include <stdio.h>
#include <GL/glut.h>

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3ub(0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4.0, 4.0, -4.0, 4.0, -4.0, 4.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz
    // center is where the eye is looking at.
    //gluLookAt(0.0, 3.0, 2.0, 0.0, -2.0, 1.0, 0.0, 1.0, 0.0);
    gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0);
    glutWireTeapot(2.0);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
    glutCreateWindow("Teapot.");
    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}