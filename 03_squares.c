#include <stdio.h>
#include <GL/glut.h>

void init() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}

void draw_squares(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int m) {
    float n = 0.0f;

    printf("===============================================\n");

    for (int i = 0; i < m; i++)
    {
        glBegin(GL_LINE_LOOP);
        float a = n/m;
        printf("Alpha: %f / %d = %f\n", n, m, a);

        float _x1 = x1 + a * (x2 - x1);
        float _y1 = y1 + a * (y2 - y1);
        printf("_x1: %f, _y1: %f\n", _x1, _y1);
        glVertex2f(_x1, _y1);
        
        float _x2 = x2 + a * (x3 - x2);
        float _y2 = y2 + a * (y3 - y2);
        printf("_x2: %f, _y2: %f\n", _x2, _y2);
        glVertex2f(_x2, _y2);

        float _x3 = x3 + a * (x4 - x3);
        float _y3 = y3 + a * (y4 - y3);
        printf("_x3: %f, _y3: %f\n", _x3, _y3);
        glVertex2f(_x3, _y3);

        float _x4 = x4 + a * (x1 - x4);
        float _y4 = y4 + a * (y1 - y4);
        printf("_x4: %f, _y4: %f\n", _x4, _y4);
        glVertex2f(_x4, _y4);
        glEnd();

        n = n + 1;
    }

    printf("===============================================\n");
}

void display() {
    
    draw_squares(100, 100, 400, 100, 400, 400, 100, 400, 8);
    
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
    glutCreateWindow("Squares");
    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}