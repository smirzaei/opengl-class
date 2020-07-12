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

void top_menu(int val) {
    printf("Top menu clicked: %d\n", val);
    if (val == 1) {
        exit(0);
    }
}

void color_menu(int val) {
    printf("Color menu selected: %d\n", val);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Menu.");
    glutDisplayFunc(display);

    int sub_menu = glutCreateMenu(color_menu);
    glutAddMenuEntry("Red", 1);
    glutAddMenuEntry("Green", 2);
    glutAddMenuEntry("Blue", 3);
    glutCreateMenu(top_menu);
    
    glutAddSubMenu("Change color", sub_menu);
    glutAddMenuEntry("Exit", 1);

    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();

    return 0;
}
