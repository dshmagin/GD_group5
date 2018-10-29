#ifndef TITLESCREEN_H_INCLUDED
#define TITLESCREEN_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>
#include <string>
#include <string>
#include <sstream>
#include <iostream>
#include <memory>
#include <SFML/Audio.hpp>
using namespace std;
class TitleScreen
{
    private:
        int selected = 0;
        sf::Font GameFont;
        shared_ptr<sf::RenderWindow> window_ptr;
        sf::Text Option;
        sf::Text Start;
        sf::Texture BackgroundTexture;
        sf::Sprite TitleBackground;
        sf::SoundBuffer menuSong;
        sf::Sound sound;
        bool firstSprite = true;
        float titleImage = 0;

    public:
        TitleScreen();
        TitleScreen(shared_ptr<sf::RenderWindow> &window_ptr );
        void setSelected( int direction);
        int  getSelected();
        void drawTitleScreen( float deltaTime );
        void startMusic();
        void stopMusic();
};

#endif // TITLESCREEN_H_INCLUDED
