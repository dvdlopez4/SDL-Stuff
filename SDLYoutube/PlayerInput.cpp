#include "PlayerInput.h"

void PlayerInput::HandleInput(const Uint8* KeyState, Entity* e)
{
	if (KeyState[SDL_SCANCODE_D])
		e->SetX(e->GetX() + 5);
	else if (KeyState[SDL_SCANCODE_A])
		e->SetX(e->GetX() - 5);
	else if (KeyState[SDL_SCANCODE_W])
		e->SetY(e->GetY() - 5);
	else if (KeyState[SDL_SCANCODE_S])
		e->SetY(e->GetY() + 5);

		
}