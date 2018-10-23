#ifndef TITLESCREEN_H_INCLUDED
#define TITLESCREEN_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class TitleScreen
{
    private:

        sf::Font GameFont;
        //sf::Text Title;
        //sf::Text SinglePlayer;
        //sf::Text MultiPlayer;
        sf::Texture BackgroundTexture;
        sf::Sprite TitleBackground;
        bool firstSprite = true;
        float enemyVal = 0;

    public:

        TitleScreen();

        void drawTitleScreen(sf::RenderWindow* window);
};

#endif // TITLESCREEN_H_INCLUDED
