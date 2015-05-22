#include "Entity.h"

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

class InputHandler
{
public:
	virtual void HandleInput(const Uint8 *KeyState, Entity* e) = 0;

};
#endif