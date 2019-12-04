#ifndef _HOWTOPLAY_H
#define _HOWTOPLAY_H

#include "Texture.h"
#include "InputManager.h"
#include "PlaySideBar.h"
using namespace QuickSDL;

class HowToPlay : public GameEntity {

private:
     
     InputManager* mInput;

	 Texture* mScreen;
    
public:
     HowToPlay();
     ~HowToPlay();

     void Update();

     void Render();


};

#endif