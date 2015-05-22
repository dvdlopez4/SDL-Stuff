#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>
#include "Player.h"
#include "PlayerInput.h"
#include "Story.h"


int main(int argc, char* argv[])
{

	SDL_Window *window = nullptr;
	SDL_Renderer *renderTarget = nullptr;

	const Uint8* KeyState;
	PlayerInput pi;
	Story story("test.txt");
	
	// Initialize both video and sound
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	if (TTF_Init() < 0)
		std::cout << "Error: " << TTF_GetError() << std::endl;
	
	int imgFlags = IMG_INIT_PNG;
	if (IMG_Init(imgFlags) != imgFlags)
		std::cout << "Error: " << IMG_GetError() << std::endl;

	// Create Window
	window = SDL_CreateWindow("SDL CodingMadeEasy", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 768, SDL_WINDOW_SHOWN);

	// Create Renderer
	renderTarget = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	// Music Stuff
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		std::cout << "Error " << Mix_GetError() << std::endl;
	Mix_Music *bgm = Mix_LoadMUS("8-bit-music.mp3");
	Mix_Chunk *soundEffect = Mix_LoadWAV("sound.wav");
	

	//Text Stuff
	std::string SomeText = "Hello World! This is my first game!";
	TTF_Font* font = TTF_OpenFont("Moms_typewriter.ttf", 18);
	SDL_Color color = { 144, 77, 255, 255 };
	SDL_Surface *textSurface = TTF_RenderText_Solid(font, story.getStoryText().c_str(), color);
	SDL_Texture *Text = SDL_CreateTextureFromSurface(renderTarget, textSurface);
	SDL_Rect textRect;

	textRect.x = textRect.y = 100;
	SDL_QueryTexture(Text, nullptr, nullptr, &textRect.w, &textRect.h);
	SDL_FreeSurface(textSurface);
	textSurface = nullptr;

	// Initial starting color
	SDL_SetRenderDrawColor(renderTarget, 0, 0, 0x55, 0x00); 

	bool isRunning = true;
	SDL_Event ev;
	Player p1("FemaleKnight.png", renderTarget, 0, 0, 600, 600);
	Player p2("Test.png", renderTarget, 330, 400, 64, 64);
	
	Entity *e[2];

	e[0] = &p1;
	e[1] = &p2;

	KeyState = SDL_GetKeyboardState(nullptr);

	// Main Game Loop
	while (isRunning)
	{
		while (SDL_PollEvent(&ev) != 0)
		{
			// Getting events
			if (ev.type == SDL_QUIT)
				isRunning = false;
			else if (ev.type == SDL_KEYDOWN)
			{
				switch (ev.key.keysym.sym)
				{
				case SDLK_p:
					if (!Mix_PlayingMusic())
						Mix_PlayMusic(bgm, -1);
					else if (Mix_PausedMusic())
						Mix_ResumeMusic();
					else
						Mix_PauseMusic(); 
					break;
				case SDLK_h:
					Mix_HaltMusic();
					break;
				case SDLK_1:
					story.Choose(1);
					textSurface = TTF_RenderText_Solid(font, story.getStoryText().c_str(), color);
					Text = SDL_CreateTextureFromSurface(renderTarget, textSurface);
					SDL_QueryTexture(Text, nullptr, nullptr, &textRect.w, &textRect.h);
					SDL_FreeSurface(textSurface);
					textSurface = nullptr;
					break;
				case SDLK_2:
					story.Choose(2);
					textSurface = TTF_RenderText_Solid(font, story.getStoryText().c_str(), color);
					Text = SDL_CreateTextureFromSurface(renderTarget, textSurface);
					SDL_QueryTexture(Text, nullptr, nullptr, &textRect.w, &textRect.h);
					SDL_FreeSurface(textSurface);
					textSurface = nullptr;
					break;
				case SDLK_3:
					story.Choose(3);
					textSurface = TTF_RenderText_Solid(font, story.getStoryText().c_str(), color);
					Text = SDL_CreateTextureFromSurface(renderTarget, textSurface);
					SDL_QueryTexture(Text, nullptr, nullptr, &textRect.w, &textRect.h);
					SDL_FreeSurface(textSurface);
					textSurface = nullptr;
					break;
				}
			}
		}
			
		pi.HandleInput(KeyState, e[0]);

		e[0]->Update();
		e[1]->Update();
		SDL_RenderClear(renderTarget);
		e[0]->Draw();
		e[1]->Draw();


		// Render text
		SDL_RenderCopy(renderTarget, Text, nullptr, &textRect);
		SDL_RenderPresent(renderTarget);
	}
	// End of Game Loop


	// House keeping
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderTarget);
	TTF_CloseFont(font);
	Mix_FreeMusic(bgm);
	Mix_FreeChunk(soundEffect);

	bgm = nullptr;
	soundEffect = nullptr;
	window = nullptr;
	renderTarget = nullptr;
	Text = nullptr;

	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

	return 0;
}