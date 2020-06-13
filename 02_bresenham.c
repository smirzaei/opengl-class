#include <stdio.h>
#include <GL/glut.h>

void init() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}

void display() {
    
    float x_init = 1;
    float y_init = 1;

    float x_end = 600;
    float y_end = 450;

    float diff = (x_end-x_init)/(y_end-y_init);

    float x = x_init;
    float y = y_init;
    printf("diff: %f\n", diff);
    glBegin(GL_POINTS);
        float error = 0;

        while(x < x_end) {
            error = error + diff;
            if (error >= 0.5) {
                y = y + 1;
                error = error - 1;
            }

            x = x + 1;
            glVertex2i(x, y);

            printf("x: %f, y: %f, error: %f\n", x, y, error);
        }

    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
    glutCreateWindow("My first OpenGL window.");
    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}