#include "window.h"
#include <iostream>

bool Window::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cerr << "SDL Failed to initialize window.\n";
		return 0;
	}

	_window = SDL_CreateWindow(
		_title.c_str(), 
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		_width, _height,
		0);

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC);

	if (_window == nullptr)
	{
		std::cerr << "SDL failed to create a window\n";
		return 0;
	}
	if (_renderer == nullptr)
	{
		std::cerr << "SDL failed to create renderer\n";
		return 0;
	}
	return true;
}

void Window::pollEvents()
{
	SDL_Event event_;
	if (SDL_PollEvent(&event_))
	{
		switch (event_.type)
		{
			case SDL_QUIT:
				_closed = true;
			break;

			default:
			break;
		}
	}
}

void Window::clear() const
{
	SDL_SetRenderDrawColor(_renderer, 0, 0, 255, 255);
	SDL_RenderClear(_renderer);

	SDL_Rect rect;

	rect.w = 120;
	rect.h = 150;
	rect.x = _width / 2 - (rect.w / 2);
	rect.y = _height / 2 - (rect.h / 2);

	SDL_SetRenderDrawColor(_renderer, 255, 255, 0, 255);
	SDL_RenderFillRect(_renderer, &rect);

	SDL_RenderPresent(_renderer);
}