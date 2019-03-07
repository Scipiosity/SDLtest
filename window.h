#pragma once

#include <string>
#include "SDL/include/SDL.h"

class Window
{
	public:
	Window(const std::string & title, int width, int height)
	{
		_title = title;
		_width = width;
		_height = height;

		_closed = !init();
	}
	
	~Window()
	{
		SDL_DestroyWindow(_window);
		SDL_DestroyRenderer(_renderer);
		SDL_Quit();
	}

	inline bool isClosed() const { return _closed; }

	void clear() const;

	void pollEvents();

	private:
	std::string _title;
	int _width = 800;
	int _height = 400;

	bool _closed = false;

	bool init();

	SDL_Window * _window = nullptr;
	SDL_Renderer * _renderer = nullptr;
};