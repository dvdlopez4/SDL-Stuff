#include "Player.h"

Player::Player(std::string File, SDL_Renderer* renderTarget, int x, int y, int w, int h)
{
	this->renderTarget = renderTarget;
	Texture = LoadTexture(File, renderTarget);
	SDL_QueryTexture(Texture, nullptr, nullptr, &playerRect.w, &playerRect.h);
	playerPosition.x = x;
	playerPosition.y = y;
	playerPosition.w = w;
	playerPosition.h = h;
}

Player::~Player()
{
	renderTarget = nullptr; // Renderer may still be in use let main take care of that
	SDL_DestroyTexture(Texture);
	Texture = nullptr;
}

SDL_Texture* Player::LoadTexture(std::string filePath, SDL_Renderer *renderTarget)
{
	SDL_Texture *texture = nullptr;
	SDL_Surface *surface = IMG_Load(filePath.c_str());

	if (surface == nullptr)
		std::cout << "Error" << std::endl;
	else
	{
		texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		if (texture == nullptr)
			std::cout << "Error" << std::endl;
	}

	SDL_FreeSurface(surface);

	return texture;
}

void Player::Draw()
{
	SDL_RenderCopy(renderTarget, Texture, &playerRect, &playerPosition);
}

void Player::Update()
{
	if (playerPosition.x >= 300)
		SDL_SetTextureColorMod(Texture, 255, 0, 0);
	else
		SDL_SetTextureColorMod(Texture, 255, 255, 255);
}