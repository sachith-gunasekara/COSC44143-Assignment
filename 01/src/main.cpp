#include <GL/glew.h>
#include <GLFW/glfw3.h>

void drawLine(float x1, float y1, float x2, float y2) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
	glFlush();
}

void initializeView(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int main(void) {
	if (!glfwInit())
		return -1;

	GLFWwindow* window = glfwCreateWindow(640, 480, "COSC 44143 - Assignment 01 | Line Drawing with OpenGL Routine functions", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glewInit();

	initializeView();

	float x1 = 180, y1 = 15, x2 = 10, y2 = 145;
	while (!glfwWindowShouldClose(window)) {
		drawLine(x1, y1, x2, y2);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}