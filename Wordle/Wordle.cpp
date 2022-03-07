#include <iostream>
#include <string>
#include <vector>

#define FOREGROUND(color, text) "\x1B[" << static_cast<int>(color) << "m" << text << "\033[0m"
#define BACKGROUND(color, text) "\033[3;42;" << static_cast<int>(color) << "m" << text << "\033[0m"
using namespace std;

void theGame();
string getString();
void printWord(string input, string correctWord);


enum class ForegroundColor : int {
	Red = 31,
	Green = 32,
	Yellow = 33,
	BrightRed = 91,
	BrightGreen = 92,
	BrightYellow = 93,
	DarkBlue = 34
};

enum class BackgroundColor : int {
	Red = 41,
	Green = 42,
	Yellow = 43,
	BrightRed = 101,
	BrightGreen = 102,
	BrightYellow = 103,
	Gray = 100
};

int main()
{

	cout << FOREGROUND(ForegroundColor::BrightRed, "Hello world!") << endl;
	cout << BACKGROUND(BackgroundColor::BrightRed, "Hello world!") << endl;

	int input;
	cout << "-- Welcome to the game wordle --" << endl;
		do
		{
			cout << "[1] Start the game" << endl;
			cout << "[2] Quit" << endl;
			cin >> input;

			switch (input)
			{
			case 1: theGame(); break;
			case 2: cout << "Quit the game"; break;
			default: cout << "Not a valid input, try again." << endl; break;
			}
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		} while (input != 2);


}
void theGame()
{
	string input;
	int guesses = 0;

	string correctString = "hallo";
	cout << FOREGROUND(ForegroundColor::DarkBlue,"       Wordle") << endl;
	do
	{
		input = getString();
		printWord(input, correctString);

		guesses++;

	} while (input != correctString && guesses != 6); // what way sould i write? input != correctString or input.compare(correctString)

	if (input == correctString )
	{
		cout << "You found the right word: " << correctString << endl;
	}
	else
	{
		cout << "You did not find the right word. The right word was: " << correctString << endl;
	}

	cout << "End of game" << endl;
	
	

}
string getString() // send in list of strings
{
	string inputStr;
	vector<string> listOfWords = {"hella", "hallo", "hejd�"};

	while (1)
	{
		cin >> inputStr;
		if (inputStr.size() > 5) // check if the input is a real word or not(fix). Checks if the input is more then 5 chars long
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Not valid, try again!" << endl;
		}
		else 
		{
			break;
		}
	}
	return inputStr;
}

void printWord(string input, string correctWord) // hallo // hallo
{
	for (int i = 0; i < input.length(); i++)  
	{
		if (input[i] == correctWord[i])
		{
			cout << BACKGROUND(BackgroundColor::Green, input[i]);
		}
		else
		{
			bool letterIsYellow = false;
			for (int j = 0; j < input.length(); j++)
			{
				if (input[i] == correctWord[j])
				{
					letterIsYellow = true;
					break;
				}
			}
			
			if (letterIsYellow)
			{
				cout << BACKGROUND(BackgroundColor::Yellow, input[i]);
			}
			else
			{
				cout << BACKGROUND(BackgroundColor::Gray, input[i]);
			}
		}
	}
	cout << endl;
}

