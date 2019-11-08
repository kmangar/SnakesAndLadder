#include "HowToPlay.h"

HowToPlay::HowToPlay()
{
	mInput = InputManager::Instance();

	mScreen = new Texture("howtoplay2.png");//loads the png to the mscreen Texture 
	mScreen->Parent(this);
	mScreen->Pos(Vector2(450.0f, 400.0f));
}

HowToPlay::~HowToPlay()
{
	mInput = NULL;

	delete mScreen;
	mScreen = NULL;
}

void HowToPlay::Update()
{

}

void HowToPlay::Render()
{
	mScreen->Render();//renders the png to the screen 
}