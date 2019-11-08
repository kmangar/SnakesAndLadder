#include "Board.h"
#include <time.h>      
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace std::chrono;


Board::Board() {
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();

	//puts the x postioin into the listx
	listX = new float[1];
	listX[0] = 312.3;
	
	//puts the y postioin into the listy
	listY = new float[1];
	listY[0] = 212.32; 

	matrix = new int[1];// intialize matrix to hold 9 numbers
	moves = 1;


	//here we are loading the numbers into their respective texture name
	mOne = new Texture("1.png");
	mOne->Parent(this);
	mOne->Pos(Vector2(listX[0], listY[0]));
	mOne->setter(1);//we didn't use it will get rid of it in the future. 
	mOne->Scale(Vector2(0.2f, 0.2f));

	mTwo = new Texture("2.png");
	mTwo->Parent(this);
	mTwo->setter(2);
	mTwo->Pos(Vector2(listX[0], listY[0]));
	mTwo->Scale(Vector2(0.2f, 0.2f));

	mThree = new Texture("3.png");
	mThree->Parent(this);
	mThree->setter(3);
	mThree->Pos(Vector2(listX[0], listY[0]));
	mThree->Scale(Vector2(0.1f, 0.1f));

	mFour = new Texture("4.png");
	mFour->Parent(this);
	mFour->setter(4);
	mFour->Pos(Vector2(listX[0], listY[0]));
	mFour->Scale(Vector2(0.1f, 0.1f));

	mFive = new Texture("5.png");
	mFive->Parent(this);
	mFive->setter(5);
	mFive->Pos(Vector2(listX[0], listY[0]));
	mFive->Scale(Vector2(0.1f, 0.1f));

	mSix = new Texture("6.png");
	mSix->Parent(this);
	mSix->setter(6);
	mSix->Pos(Vector2(listX[0], listY[0]));
	mSix->Scale(Vector2(0.1f, 0.1f));

}

Board::~Board() {
	mTimer = NULL;
	mInput = NULL;

	delete mOne;
	mOne = NULL;

	delete mTwo;
	mTwo = NULL;

	delete mThree;
	mThree = NULL;

	delete mFour;
	mFour = NULL;

	delete mFive;
	mFive = NULL;

	delete mSix;
	mSix = NULL;

	delete mSeven;
	mSeven = NULL;

	delete mEight;
	mEight = NULL;

	delete mEmpty;
	mEmpty = NULL;

}
int Board::Shuffle() {
	
	int value;
	srand((unsigned)time(0));
	
	value = (rand() % (6) + 1);//(rand() % 6 + 1) --> random number from 1 to 6
	matrix[0] = value;
	
	return value; 

}



void Board::output()
{

		switch (Shuffle())
		{//prints the postion at i. if its that case
		case 1:
		{
			mOne->Pos(Vector2(listX[0], listY[0]));
			mOne->Render();
			
			break;
		}
		case 2:
		{
			mTwo->Pos(Vector2(listX[0], listY[0]));
			mTwo->Render();
			
			break;
		}
		case 3:
		{
			mThree->Pos(Vector2(listX[0], listY[0]));
			mThree->Render();
			
			break;
		}
		case 4:
		{
			mFour->Pos(Vector2((listX[0], listY[0])));
			mFour->Render();
			
			break;
		}
		case 5:
		{
			mFive->Pos(Vector2(listX[0], listY[0]));
			mFive->Render();
			
			break;
		}
		case 6:
		{
			mSix->Pos(Vector2(listX[0], listY[0]));
			mSix->Render();
			break;
		}
		}
}

void Board::shift(char m)// take in user input and shift the proper number into the blank spot
{
	int temp;

	if (m == 'w') // move number up into blank spot
	{
		for (int i = 0; i < 6; i++)
		{
			if (matrix[i] == 0)
			{
				temp = matrix[i + 3];
				matrix[i + 3] = matrix[i];
				matrix[i] = temp;
				return;
			}
		}
	}
	if (m == 's') // move number down into blank spot
	{
		for (int i = 3; i < 9; i++)
		{
			if (matrix[i] == 0)
			{
				temp = matrix[i - 3];
				matrix[i - 3] = matrix[i];
				matrix[i] = temp;
				return;
			}
		}
	}
	if (m == 'a') // move number left into blank spot
	{
		for (int i = 0; i < 9; i++)
		{
			if (matrix[i] == 0 && (i + 1) % 3 != 0)
			{
				temp = matrix[i + 1];
				matrix[i + 1] = matrix[i];
				matrix[i] = temp;
				return;
			}
		}
	}
	if (m == 'd') // move number right into blank spot
	{
		for (int i = 0; i < 9; i++)
		{
			if (matrix[i] == 0 && i % 3 != 0)
			{
				temp = matrix[i - 1];
				matrix[i - 1] = matrix[i];
				matrix[i] = temp;
				return;
			}
		}
	}
}


bool Board::newGame()
{
	

	return true;
}

int Board::getMoves()
{
	return moves;
}

void Board::Update() {
	if (mInput->KeyPressed(SDL_SCANCODE_DOWN))
	{
		shift('s');
		output();
		moves++;//update the move when user presses down 
	}

}

void Board::Render() {
	//render the numbers to the screen 
	output();

	
}