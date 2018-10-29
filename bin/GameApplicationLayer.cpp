#include <SFML/Graphics.hpp>
#include "GameLogic.h"
#include "TitleScreen.h"
#include "GameViewPlayer.h"
#include <memory>

int main(int argc, char** argv)
{

    float deltaTime;
    sf::Clock clock;
    shared_ptr<sf::RenderWindow> window_ptr =make_shared<sf::RenderWindow>(sf::VideoMode(800,600,32), "Hello World - SFML");
    GameLogic* game = new GameLogic();
    GameViewPlayer gvp = GameViewPlayer(game, window_ptr);
    TitleScreen menu = TitleScreen(window_ptr);
    // create main window
    // start main loop
    gvp.setTitleScreen(&menu);
    window_ptr->setFramerateLimit(60);
    menu.startMusic();
    while(window_ptr->isOpen())
    {
        deltaTime = clock.getElapsedTime().asMicroseconds()/1000.0f;
        clock.restart();
        // process events
        sf::Event Event;
        window_ptr->clear(sf::Color::Green);

        while(window_ptr->pollEvent(Event))
        {
          // Exit

            gvp.checkKeyEvents(Event,deltaTime);
            if(Event.type == sf::Event::Closed)
                window_ptr->close();
        }
        if( game -> getGameState() == 0 )
        {

            menu.drawTitleScreen(deltaTime);


        }

        if ( game -> getGameState() == 1 )
        {

            gvp.update(deltaTime);
        }

        window_ptr->display();
    }

    // Done.
    return 0;
}

