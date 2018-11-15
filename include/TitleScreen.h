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
        int elementSelected = 0;
        sf::Font GameFont;
        shared_ptr<sf::RenderWindow> window_ptr;
        sf::Text Option;
        sf::Text Start;
        sf::Text fire;
        sf::Text water;;
        sf::Text earth;
        sf::Text air;
        sf::Texture BackgroundTexture;
        sf::Sprite TitleBackground;
        sf::SoundBuffer menuSong;
        sf::SoundBuffer keySound;
        sf::Sound music;
        sf::Sound sound;
        bool firstSprite = true;
        bool musicCanPlay = true;
        float titleImage = 0;

    public:
        TitleScreen();
        TitleScreen(shared_ptr<sf::RenderWindow> &window_ptr );
        void setSelected( int direction);
        int  getSelected();
        void setSelectedElement( int direction);
        int  getSelectedElement();
        void drawTitleScreen( float deltaTime );
        void drawElementOption( float deltaTime );
        void startMusic();
        void stopMusic();
};

#endif // TITLESCREEN_H_INCLUDED
