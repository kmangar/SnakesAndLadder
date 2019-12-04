#include "PlaySideBar.h"

PlaySideBar::PlaySideBar() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();

	time.str("");


	mTitle = new Texture("titleboard.png");
	mTitle->Parent(this);
	mTitle->Pos(Vector2(490.0f, 50.0f));

	mTable = new Texture("FBoard.png");
	mTable->Parent(this);
	mTable->Pos(Vector2(468.0f, 427.0f));
	mTable->Scale(Vector2(.78f, .69f));


	mBestLabel = new Texture("Time", "emulator.ttf", 28, { 150, 0, 0 });//prints Best on the left corner
	mBestLabel->Parent(this);
	mBestLabel->Pos(Vector2(25.0f, 180.0f));

	mCurrentScoreBoard = new Scoreboard;
	mCurrentScoreBoard->Parent(this);
	mCurrentScoreBoard->Pos(Vector2(25.0f, 330.0f));

	mWin = new Texture("You Win!", "emulator.ttf", 28, { 150, 0, 0 });
	mWin->Parent(this);
	mWin->Pos(Vector2(-25000.0f, -50000.0f));

	mTime = new Texture("Time", "emulator.ttf", 28, { 150, 0, 0 });//prints Best on the left corner
	mTime->Parent(this);
	mTime->Pos(Vector2(-25000.0f, -38000.0f));

}

PlaySideBar::~PlaySideBar() {
	mTimer = NULL;
	mAudio = NULL;


	delete mBestLabel;
	mBestLabel = NULL;


	delete mTable;
	mTable = NULL;

	delete mTitle;
	mTitle = NULL;


}

void PlaySideBar::SetBestMove(int Score) {
	if (Score < getBest()) {
		setBest(Score);
	}
}

void PlaySideBar::SetCurrentMove(int Score) {
	mCurrentScoreBoard->Score(Score);
}

void PlaySideBar::youWin()
{
	mWin->Pos(Vector2(25.0f, 500.0f));
}

void PlaySideBar::startTimer()
{
	startTime = SDL_GetTicks();//intialize the current ticks 
	time << startTime;//puts the start time in the screen 
}

void PlaySideBar::endTimer()
{
	endTime = SDL_GetTicks() - startTime;//get the duration from the beganing the current 
	time.str("");//clears the screen 
	time << endTime / 1000 << "s";//milliseconds but we divide it by 1000 to get it in seconds 

}

Uint32 PlaySideBar::getTime()
{
	return endTime -= startTime;
}

int PlaySideBar::getBest()
{
	;
	return best;
}

void PlaySideBar::setBest(int b)
{
	best = b;
}

void PlaySideBar::Update() {

}

void PlaySideBar::Render() {

	mTitle->Render();
	mTable->Render();
	mBestLabel->Render();

	mCurrentScoreBoard->Render();

	mWin->Render();
	mTime->Render();
}