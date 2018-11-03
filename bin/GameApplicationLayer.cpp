#include <SFML/Graphics.hpp>
#include "GameLogic.h"
#include "TitleScreen.h"
#include "GameViewPlayer.h"
#include <memory>

using namespace std;
int main(int argc, char** argv)
{
    float deltaTime;
    sf::Clock clock;
    shared_ptr<sf::RenderWindow> window_ptr =make_shared<sf::RenderWindow>(sf::VideoMode(800,600,32), "Ground Break");
    GameLogic* game = new GameLogic(window_ptr);
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

        gvp.checkKeyEvents(deltaTime);
        while(window_ptr->pollEvent(Event))
        {
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
            game -> update(deltaTime);
        }

        window_ptr->display();
    }

    // Done.
    return 0;
}

