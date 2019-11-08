#include "PlaySideBar.h"

PlaySideBar::PlaySideBar() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();

	best = 999;
	time.str("");

	mBackground = new Texture("black.png");
	mBackground->Parent(this);
	mBackground->Pos(Vector2(12.0f, 280.0f));
	mBackground->Scale(Vector2(12.0f, 280.0f));

	mTitle = new Texture("titleboard.png");
	mTitle->Parent(this);
	mTitle->Pos(Vector2(490.0f, 50.0f));

	mTable = new Texture("FBoard.png");
	mTable->Parent(this);
	mTable->Pos(Vector2(402.0f, 357.0f));
	mTable->Scale(Vector2(.99f, .901826484f));


	mBestLabel = new Texture("Time", "emulator.ttf", 28, { 150, 0, 0 });//prints Best on the left corner
	mBestLabel->Parent(this);
	mBestLabel->Pos(Vector2(25.0f, 180.0f));

	mBestScoreBoard = new Texture(time.str().c_str(), "emulator.ttf", 28, { 150, 0, 0 });
	mBestScoreBoard->Parent(this);
	mBestScoreBoard->Pos(Vector2(25.0f, 230.0f));

	mCurrentLabel = new Texture("Moves", "emulator.ttf", 28, { 150, 0, 0 });//prints Current on the middle left corner
	mCurrentLabel->Parent(this);
	mCurrentLabel->Pos(Vector2(25.0f, 280.0f));

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

	delete mBackground;
	mBackground = NULL;

	delete mBestLabel;
	mBestLabel = NULL;

	delete mCurrentLabel;
	mCurrentLabel = NULL;

	delete mBestScoreBoard;
	mBestScoreBoard = NULL;

	delete mTable;
	mTable = NULL;

	delete mTitle;
	mTitle = NULL;

	delete mCurrentLabel;
	mCurrentLabel = NULL;

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

	mBestScoreBoard = new Texture(time.str().c_str(), "emulator.ttf", 32, { 230, 230, 230 });//prints the time using emulator font
	mBestScoreBoard->Parent(this);
	mBestScoreBoard->Pos(Vector2(25.0f, 230.0f));
}

Uint32 PlaySideBar::getTime()
{
	return endTime -= startTime;
}

int PlaySideBar::getBest()
{
	return best;
}

void PlaySideBar::setBest(int b)
{
	best = b;
}

void PlaySideBar::Update() {

}

void PlaySideBar::Render() {

	mBackground->Render();
	mTitle->Render();
	mTable->Render();
	mBestLabel->Render();
	mBestScoreBoard->Render();

	mCurrentLabel->Render();
	mCurrentScoreBoard->Render();

	mWin->Render();
	mTime->Render();
}