#include <SFML/Graphics.hpp>
#include "GameLogic.h"
#include "TitleScreen.h"
#include "GameViewPlayer.h"

int main(int argc, char** argv)
{

    GameLogic* game = new GameLogic();
    GameViewPlayer gvp = GameViewPlayer(game);
    TitleScreen menu = TitleScreen();

    // create main window
    sf::RenderWindow window(sf::VideoMode(800,600,32), "Hello World - SFML");

    // start main loop
    gvp.setTitleScreen(&menu);
    window.setFramerateLimit(60);
    int num =2;
    while(window.isOpen())
    {
        // process events
        sf::Event Event;
        window.clear(sf::Color::Green);
        while(window.pollEvent(Event))
        {
          // Exit

            gvp.checkKeyEvents(&window,Event);
            if(Event.type == sf::Event::Closed)
                window.close();
        }
        if( game -> getGameState() == 0 && num ==2)
        {

            menu.drawTitleScreen(&window);

        }

        window.display();
    }

    // Done.
    return 0;
}

