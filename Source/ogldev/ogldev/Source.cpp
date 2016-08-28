#include "glew.h"
#include "glut.h"

void render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glutSwapBuffers();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Create Window");

	glutDisplayFunc(render);
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	glutMainLoop();
}