#ifndef TITLESCREEN_H_INCLUDED
#define TITLESCREEN_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class TitleScreen
{
    private:
        int selected = 0;
        sf::Font GameFont;
        //sf::Text Title;
        sf::Text Option;
        sf::Text Start;
        sf::Texture BackgroundTexture;
        sf::Sprite TitleBackground;
        bool firstSprite = true;
        float enemyVal = 0;

    public:
        void setSelected( int direction);
        TitleScreen();

        void drawTitleScreen(sf::RenderWindow* window);
};

#endif // TITLESCREEN_H_INCLUDED
