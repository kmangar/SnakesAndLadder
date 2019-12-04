#ifndef _BOARD_H
#define _BOARD_H
#include "Timer.h"
#include "Texture.h"
#include "InputManager.h"
#include "Scoreboard.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace QuickSDL;
using namespace std;

class Board : public GameEntity {

private:
	Timer* mTimer;
	InputManager* mInput;

	//texture which would hold the numbers png file 
	Texture* mOne;;
	Texture* mTwo;
	Texture* mThree;
	Texture* mFour;
	Texture* mFive;
	Texture* mSix;
	Texture* purpule;;
	Texture* yellow;
	Texture* blue;
	Texture* red;
	Texture* dice;

	//holds the numer
	int* matrix;
	float* listX;//holds the x postion 
	float* listY;//holds the y postion 
	int moves;//tracks the movement and increment it to show on the play screen 


public:
	//function called here but will be implemented in the cpp 
	Board();//constructors 
	~Board();

	int Shuffle();//shuffle the dice 
	
	void output();//output the dice 
	
	bool newGame();

	bool containsValue(vector<int> list, int value);


	void shift(char m);

	int getMoves();

	void Swap();

	void Update();

	void Render();
};

#endif // !_PLAYSIDEBAR_H