#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>

#ifndef ENTITY_H
#define ENTITY_H

class Entity
{
public:
	virtual void Draw() = 0;
	virtual void Update() = 0;

	virtual void SetX(int x) = 0;
	virtual void SetY(int y) = 0;

	virtual int  GetX() = 0;
	virtual int  GetY() = 0;
};

#endif