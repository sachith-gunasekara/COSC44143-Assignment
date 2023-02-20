#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <stdio.h>

void bresenhamLine(float x1, float y1, float x2, float y2) {
    float dx = abs(x2 - x1);
    float dy = abs(y2 - y1);
    float twoDy = 2 * dy;
    float p = twoDy - dx;
    float twoDyMinusDx = 2 * (dy - dx);
    float x, y;

    float m = (y2 - y1) / (x2 - x1);

    if (m < 0 || m > 1) {
        return;
    }
    else {
        /* Determine which endpoint to use as start position */
        if (x1 > x2) {
            x = x2;
            y = y2;
            x2 = x1;
        }
        else {
            x = x1;
            y = y1;
        }

        glBegin(GL_POINTS);
        glVertex2i(x, y);

        while (x < x2) {
            x++;
            if (p < 0) {
                p += twoDy;
            }
            else {
                y++;
                p += twoDyMinusDx;
            }
            glVertex2i(x, y);
        }
        glEnd();
    }
}

void initializeView(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Bresenham Line", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Initialize GLEW */
    if (glewInit() != GLEW_OK)
        return -1;

    initializeView();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        bresenhamLine(10, 145, 180, 200);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
