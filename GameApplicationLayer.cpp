#include <SFML/Graphics.hpp>
#include "GameLogic.h"
#include "TitleScreen.h"
#include "GameViewPlayer.h"
#include <memory>

int main(int argc, char** argv)
{

    shared_ptr<sf::RenderWindow> window_ptr =make_shared<sf::RenderWindow>(sf::VideoMode(800,600,32), "Hello World - SFML");
    GameLogic* game = new GameLogic();
    GameViewPlayer gvp = GameViewPlayer(game, window_ptr);
    TitleScreen menu = TitleScreen(window_ptr);
    // create main window
    // start main loop
    gvp.setTitleScreen(&menu);
    window_ptr->setFramerateLimit(60);
    int num =2;
    while(window_ptr->isOpen())
    {
        // process events
        sf::Event Event;
        window_ptr->clear(sf::Color::Green);

        while(window_ptr->pollEvent(Event))
        {
          // Exit

            gvp.checkKeyEvents(Event);
            if(Event.type == sf::Event::Closed)
                window_ptr->close();
        }

        if( game -> getGameState() == 0 && num ==2)
        {

            menu.drawTitleScreen();

        }


        window_ptr->display();
    }

    // Done.
    return 0;
}

