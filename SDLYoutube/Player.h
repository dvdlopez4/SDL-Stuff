#include "Entity.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player : public Entity
{
public:
	Player(std::string File, SDL_Renderer* renderTarget, int x, int y, int w, int h);
	~Player();
	
	virtual void Draw();
	virtual void Update();
	// Set Functions
	virtual void SetY(int y) { playerPosition.y = y; }
	virtual void SetX(int x) { playerPosition.x = x; }
 
	// Get Functions
	virtual int GetX() { return playerPosition.x; }
	virtual int GetY() { return playerPosition.y; }

private:

	SDL_Texture* LoadTexture(std::string filePath, SDL_Renderer *renderTarget);
	SDL_Renderer* renderTarget;
	SDL_Rect playerRect;
	SDL_Rect playerPosition;
	SDL_Texture* Texture;
};

#endif 