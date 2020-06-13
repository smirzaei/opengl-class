#include <stdio.h>
#include <GL/glut.h>

void init() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}

void draw_line(float x1, float y1, float x2, float y2) {
    float diff = (x2-x1)/(y2-y1);
    printf("diff: %f\n", diff);
    float x = x1;
    float y = y1;
    
    float error = 0;

    while(x < x2) {
        error = error + diff;
        if (error >= 0.5) {
            y = y + 1;
            error = error - 1;
        }

        x = x + 1;
        glVertex2i(x, y);

        printf("x: %f, y: %f, error: %f\n", x, y, error);
    }
}

void display() {
    glBegin(GL_POINTS);
    draw_line(0,0, 500, 500);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenha's Line Algorithm");
    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}