#include "Story.h"


Story::Story(const string& file)
	:CurrentScene(nullptr)
{
	ReadFile(file);
	CurrentScene = &Scenes[0];
}

void Story::Display()
{
	if (CurrentScene != nullptr)
		CurrentScene->Display();
}

void Story::Choose(int Choice)
{
	if ((size_t)Choice <= CurrentScene->Paths.size() && Choice > 0)
	{
		Choice = CurrentScene->Paths[Choice - 1];
		CurrentScene = &(Scenes[Choice]);
	}
	if (Choice >= Scenes.size() || Choice <= 0)
		CurrentScene = nullptr;
}

bool Story::isDone()
{
	if (CurrentScene == nullptr)
		return true;
	else
		return false;
}

void Story::ReadFile(const string& file)
{
	string temp,
		WholeString,		// Holds whole line of text
		stringPosition;

	stringstream StringConverter; // converting string into integer
	ifstream in;
	int pos = 0;
	Scene scene; // Temporary Scene object for placing into vector
	string::iterator itr; // For scanning through each line of text


	in.open(file.c_str());
	while (!in.eof())
	{
		temp = "";
		scene = Scene(); // Reset scene to empty
		getline(in, WholeString);
		itr = WholeString.begin();

		while (*itr != ':') // Obtain the story text up to the ':'
		{
			temp += *itr;
			itr++;
		}

		scene.StoryText = temp;
		itr++;

		while (itr != WholeString.end()) // Get the options and option text
		{
			stringPosition = "";
			temp = "";

			while (itr != WholeString.end() && *itr != ',')
			{
				if ((char)*itr > 47 && (char)*itr < 58) // numbers are added to a separate string
					stringPosition += *itr;
				else
					temp += *itr;
				itr++;
			}

			StringConverter << stringPosition;
			StringConverter >> pos; // convert into integer

			StringConverter.clear();

			// Fill in necessary info for each scene object
			scene.Paths.push_back(pos);
			scene.Choices.push_back(temp);

			if (itr == WholeString.end())
				break;
			itr++;
		}
		Scenes.push_back(scene); // Scenes are then amassed into a vector of Scenes
	}
	in.close();
}