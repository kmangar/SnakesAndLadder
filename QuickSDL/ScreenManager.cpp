#include "ScreenManager.h"
#include "PlayScreen.h"

ScreenManager* ScreenManager::sInstance = NULL;

ScreenManager*ScreenManager::Instance(){
     if (sInstance == NULL)
          sInstance = new ScreenManager();

     return sInstance;
}

void ScreenManager::Release() {
     delete sInstance;
     sInstance = NULL;

}
ScreenManager::ScreenManager() {
     mInput = InputManager::Instance();
     
     mStartScreen = new StartScreen();
     mPlayScreen = new PlayScreen();
     mCurrentScreen = start;

}
ScreenManager::~ScreenManager() {
     mInput = NULL;
     
     delete mStartScreen;
     mStartScreen = NULL;

     delete mPlayScreen;
     mPlayScreen = NULL;
}

void ScreenManager::Update() {
     switch (mCurrentScreen) {

     case start:
          mStartScreen->Update();
          if (mInput->KeyPressed(SDL_SCANCODE_RETURN)) {//once enter key is pressed reset the animation and go to the play screen
               mCurrentScreen = play;
               mStartScreen->ResetAnimation();
          }
          break;
     
     case play:
          mPlayScreen->Update();
          if (mInput->KeyPressed(SDL_SCANCODE_ESCAPE)) {//once ESC key is pressed go to the menu
               mCurrentScreen = start;
          }

          break;
     }
}
void ScreenManager::Render() {
     switch (mCurrentScreen) {

     case start:
          mStartScreen->Render();
          
          break;
     case play:
          mPlayScreen->Render();

          break;
     }
}