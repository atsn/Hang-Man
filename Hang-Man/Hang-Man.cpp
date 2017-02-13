// Hang-Man.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <ctime>

using namespace std;

int main()
{

	int life = 6;
	bool gameover = false;
	srand(static_cast<unsigned int>(time(0)));
	bool corectGuess;
	vector<string> Words{ "NAME","LETTER","MAN","HERO","COMPUTER","LESSON","FROG","ACRES","ADULT","ADVICE","ARRANGEMENT","ATTEMPT","AUGUST","AUTUMN","BORDER","BREEZE","BRICK","CALM","CANAL","CASEY","CAST","CHOSE","CLAWS","COACH","CONSTANTLY","CONTRAST","COOKIES","CUSTOMS","DAMAGE","DANNY","DEEPLY","DEPTH","DISCUSSION","DOLL","DONKEY","EGYPT","ELLEN","ESSENTIAL","EXCHANGE","EXIST","EXPLANATION","FACING","FILM","FINEST","FIREPLACE","FLOATING","FOLKS","FORT","GARAGE","GRABBED","GRANDMOTHER","HABIT","HAPPILY","HEADING","HUNTER","ILLINOIS","IMAGE","INDEPENDENT","INSTANT","JANUARY","KIDS","LABEL","LEE","LUNGS","MANUFACTURING","MARTIN","MATHEMATICS","MELTED","MEMORY","MILL","MISSION","MONKEY","MOUNT","MYSTERIOUS","NEIGHBOURHOOD","NORWAY","NUTS","OCCASIONALLY","OFFICIAL","OURSELVES","PALACE","PENNSYLVANIA","PHILADELPHIA","PLATES","POETRY","POLICEMAN","POSITIVE","POSSIBLY","PRACTICAL","PRIDE","PROMISED","RECALL","RELATIONSHIP","REMARKABLE","REQUIRE","RHYME","ROCKY","RUBBED","RUSH","SALE","SATELLITES","SATISFIED","SCARED","SELECTION","SHAKE","SHAKING","SHALLOW","SHOUT","SILLY","SIMPLEST","SLIGHT","SLIP","SLOPE","SOAP","SOLAR","SPECIES","SPIN","STIFF","SWUNG","TALES","THUMB","TOBACCO","TOY","TRAP","TREATED","TUNE","UNIVERSITY","VAPOR","VESSELS","WEALTH","WOLF","ZOO" };
	string stringname = Words.at((rand() % Words.size()));
	vector<char> Vectorname;
	vector<char> Vector_;
	string YourGuesses;
	vector<char>::const_iterator myIterator;
	vector<char>::iterator myIterator_;
	char guess;

	for (auto letter : stringname)
	{
		Vectorname.push_back(letter);
		Vector_.push_back('_');
	}

	while (!gameover)
	{
		corectGuess = false;
		cout << "The word so far ";
		for (auto value : Vector_) cout << value;
		cout << "\nIncorect guesses Back: " << life << endl;;
		cout << "Please enter your guess \n" << endl;
		cin >> guess;
		guess = toupper(guess);

		if (YourGuesses.find(guess) == YourGuesses.npos)
		{
			YourGuesses.push_back(guess);
			myIterator_ = Vector_.begin();
			for (myIterator = Vectorname.begin(); myIterator != Vectorname.end(); ++myIterator)
			{
				if (*myIterator == guess)
				{
					*myIterator_ = *myIterator;
					corectGuess = true;
				}
				++myIterator_;
			}
			if (corectGuess) cout << "\nYour guess was correct";
			else { cout << "\nYour guess was wrong"; life--; };
		}
		else
		{
			YourGuesses.push_back(guess);
			cout << "You have alredy guessed that letter";
		}

		if (find(Vector_.begin(), Vector_.end(), '_') == Vector_.end() || life == 0)
		{
			gameover = true;
		}

		cout << "\n\n";

	}

	if (life == 0)
	{
		cout << "\nYou have no more guesses \nThe word was\n";
		for (auto value : Vectorname) { cout << value; }
	}
	else { cout << "\nComgratulations you guessed the word"; }
	cout << endl;
	return 0;
}
