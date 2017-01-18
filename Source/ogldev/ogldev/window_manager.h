#pragma once

#include <string>
#include <functional>

class window_manager
{
public:
	window_manager();
	~window_manager();

	void initialize_window(char** argv, int argc);
	void set_params(unsigned int mode, unsigned int width, unsigned int height, int pos_x, int pos_y);

	void create_window(std::string text);

	void set_render_function(void (*func) (void));

	void set_idle_function(void(*func) (void));

	void start_message_loop();

private:
	unsigned int display_mode;
	unsigned int display_width;
	unsigned int display_height;
	int display_pos_x;
	int display_pos_y;
};
