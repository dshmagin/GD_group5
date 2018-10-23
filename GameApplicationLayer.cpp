#include <SFML/Graphics.hpp>
#include "GameLogic.h"
#include "TitleScreen.h"

int main(int argc, char** argv)
{

    GameLogic* game = new GameLogic();
    TitleScreen menu = TitleScreen();

    // create main window
    sf::RenderWindow window(sf::VideoMode(800,600,32), "Hello World - SFML");

    // start main loop
    window.setFramerateLimit(60);
    int num =2;
    while(window.isOpen())
    {
        // process events
        sf::Event Event;
        window.clear();
        while(window.pollEvent(Event))
        {
          // Exit
          if(Event.type == sf::Event::Closed)
            window.close();
        }
        if( game -> getGameState() == 0 && num ==2)
        {

            menu.drawTitleScreen(&window);
        }

        // clear screen and fill with blue

        // display
        window.display();
    }

    // Done.
    return 0;
}

