#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Scene
{
public:
	string StoryText;
	vector<string> Choices;
	vector<int> Paths;
	
	void Display()
	{
		cout << StoryText << endl;
		for (size_t i = 0; i < Choices.size(); ++i)
			cout << i + 1 << ": " << Choices[i] << endl;
	}

	int getPath(int num) { return Paths[num - 1]; }
};

