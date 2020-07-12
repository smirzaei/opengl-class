#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

void draw_arc(int x, int y, float r, int start_angle, int end_angle) {
    int teta = start_angle;
    for (int i = start_angle; i <= end_angle; i++) {
        printf("i: %d - teta: %d\n",i ,teta);
        float x1 = x + r * cos(teta);
        float y1 = y + r * sin(teta);
        glBegin(GL_POINTS);
            glVertex2f(x1, y1);
        glEnd();
        teta = teta + 1;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    draw_arc(0, 0, 0.5, 0, 30);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("My first OpenGL window.");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}