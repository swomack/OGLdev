#include "window_manager.h"
#include "glut.h"
#include <iostream>

using namespace std;

window_manager::window_manager()
{

}

window_manager::~window_manager()
{
}

void window_manager::initialize_window(char ** argv, int argc)
{
	glutInit(&argc, argv);
}

void window_manager::set_params(unsigned int mode,unsigned int width, unsigned int height, int pos_x, int pos_y)
{
	display_mode = mode;
	display_width = width;
	display_height = height;
	display_pos_x = pos_x;
	display_pos_y = pos_y;
}

void window_manager::create_window(string text)
{
	glutInitDisplayMode(display_mode);
	glutInitWindowSize(display_width, display_height);
	glutInitWindowPosition(display_pos_x, display_pos_y);
	glutCreateWindow(text.c_str());
}

void window_manager::set_render_function(void(*func) (void))
{
	glutDisplayFunc(func);
}

void window_manager::set_idle_function(void(*func)(void))
{
	glutIdleFunc(func);
}

void window_manager::start_message_loop()
{
	glutMainLoop();
}
