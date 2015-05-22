#include "InputHandler.h"

#ifndef PLAYERINPUT_H
#define PLAYERINPUT_H

class PlayerInput : public InputHandler
{
public:
	virtual void HandleInput(const Uint8* KeyState, Entity* e);

};

#endif