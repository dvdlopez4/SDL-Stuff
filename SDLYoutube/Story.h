#include "Scene.h"
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Story
{
public:
	Story(const string& file);

	void Display();
	void Choose(int Choice);
	bool isDone();
	string getStoryText() { return CurrentScene->StoryText; }
private:

	void ReadFile(const string& file); //helper function to populate Scenes

	string fileName;
	vector<Scene> Scenes;
	Scene* CurrentScene;
};