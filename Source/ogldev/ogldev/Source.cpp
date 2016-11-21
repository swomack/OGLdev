#include "glew.h"
#include "glut.h"
#include "window_manager.h"


window_manager window;

void render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glutSwapBuffers();
}


int main(int argc, char** argv)
{
	window.initialize_window(argv, argc);
	window.set_params(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH, 1024, 768, 50, 20);
	window.create_window("Tutorial 1");
	window.set_render_function(render);
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	window.start_message_loop();
}