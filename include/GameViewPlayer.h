#ifndef GAMEVIEW_H
#define GAMEVIEW_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "TitleScreen.h"
#include "GameLogic.h"
#include <string>
#include <sstream>
#include <iostream>
#include <memory>

using namespace std;

class GameViewPlayer
{
    private:
    //AI Movements
        TitleScreen* menu;
	sf::Sound sound;
	sf::SoundBuffer basicAttackSound;
        sf::Texture fireBg;
        sf::Texture waterBg;
        sf::Texture earthBg;
        sf::Texture airBg;
        sf::RectangleShape background;
        sf::Texture elementalText;
        sf::Texture UIText;
        sf::CircleShape elementalIcon;
        sf::CircleShape airShieldIcon;
        sf::CircleShape itemIcon;
        sf::RectangleShape UIIcon;
        sf::View playerView;
        GameLogic* game;
        float elementalAttack;
        int  currentBckg;
        int  currentLevel ;
        int   bckgTextNum;
        int   spellAssetCol = 0;
        int   itemsAssetsCol = 2;
        int   spellTextNum;
        int   spellTextCdNum = 1;
        int   spellIconSize = 8;
        float inputTimer = 0;
        float bckgW = 2400.0f;
        float bckgH = 1800.0f;
        float screenW = 800.0f;
        float screenH = 600.0;
        float textureSize = 32.0f;
        float itemTextureSize = 32.0f;
        float playerW = 64.0f;
        float playerH = 128.0f;
        float camXview = bckgW/2;
        float camYview = bckgH/2;
        float camMoveSpeed = 0.3f;
        bool movingX;
        bool movingY;
        bool hasTextureLoaded = true;
        bool chooseElement = false;
        shared_ptr<sf::RenderWindow> window_ptr;
        bool wait = false;
        //AbilityBar abilityBar;
        bool transition_started;
	sf::RectangleShape transitionBox1;
	sf::RectangleShape transitionBox2;

    public:

        GameViewPlayer(){};
        GameViewPlayer(GameLogic* game, shared_ptr<sf::RenderWindow> &window_ptr);
        bool checkKeyEvents( float deltaTime, sf::Keyboard::Key keycode);
        void setTitleScreen(TitleScreen* screen);
        void update(float deltaTime);
        void drawBg();
        void setBackgroundTexture(int background);
        void drawTransition(float deltaTime);
        void centerView();
};

#endif






