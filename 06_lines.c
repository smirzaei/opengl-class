#include <stdio.h>
#include <GL/glut.h>

void draw(float x1, float y1, float x2, float y2, int n) {
    float p = x2 - x1;
    float q = y2 - y1;
    float a = 1;
    

    for (int i = 1; i <= n; i++) {
        x2 = x1 + a * p;
        y2 = y1 + a * q;
        a = a + (1.0/3.0);

        float x3 = x2 + a * q;
        float y3 = y2 - a * p;
        a = a + (1.0/3.0);

        float x4 = x3 - a * p;
        float y4 = y3 - a * q;
        a = a + (1.0/3.0);

        float x5 = x4 - a * q;
        float y5 = y4 + a * p;
        a = a + (1.0/3.0);

        printf("Line %d: (%f, %f) (%f, %f) (%f, %f) (%f, %f)\n", i, x2, y2, x3, y3, x4, y4, x5, y5);

        glBegin(GL_LINE_STRIP);
            glVertex2f(x1, y1);
            glVertex2f(x2, y2);
            glVertex2f(x3, y3);
            glVertex2f(x4, y4);
            glVertex2f(x5, y5);
        glEnd();

        x1 = x5;
        y1 = y5;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    draw(200, 250, 250, 300, 3);

    glFlush();
}

void init() {
    //glClearColor(1.0, 1.0, 1.0, 1.0);
    //glColor3f(0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Lines.");
    glutDisplayFunc(display);
    init();
    glutMainLoop();

    return 0;
}