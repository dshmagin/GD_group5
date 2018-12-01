#include <SFML/Graphics.hpp>
#include "GameLogic.h"
#include "TitleScreen.h"
#include "GameViewPlayer.h"
#include <memory>
#include "ProcessManager.h"

using namespace std;
int main(int argc, char** argv)
{
    float deltaTime;
    sf::Keyboard::Key keycode = sf::Keyboard::Unknown;
    bool need_key_value = false;
    sf::Clock clock;
    shared_ptr<sf::RenderWindow> window_ptr =make_shared<sf::RenderWindow>(sf::VideoMode(800,600,32), "Ground Break");
    shared_ptr<ProcessManager> pm  = make_shared<ProcessManager>();
    //shared_ptr<GameLogic> game  = make_shared<GameLogic>(window_ptr,pm);
    GameLogic* game = new GameLogic(window_ptr,pm);
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
        window_ptr->clear(sf::Color::White);

        while(window_ptr->pollEvent(Event))
        {
            if(Event.type == sf::Event::Closed)
	    {
                window_ptr->close();
	    }
	    else if(need_key_value && Event.type == sf::Event::KeyReleased)
	    {
		if(Event.key.code != sf::Keyboard::Return){
			keycode = Event.key.code;
		}
            }
        }

        need_key_value = gvp.checkKeyEvents( deltaTime, keycode);
        if(!need_key_value){
            keycode = sf::Keyboard::Unknown;
        }

        if( game -> getGameState() == 0 )
        {

            menu.drawTitleScreen(deltaTime);

        }
        if( game -> getGameState() == 1 )
        {
            menu.drawElementOption(deltaTime);
        }
        if( game -> getGameState() == 3 )
        {
	    menu.drawOptionsScreen(deltaTime);
        }

        if ( game -> getGameState() == 2 )
        {
            gvp.drawBg();
            if (!game->isPaused()) {
            	game -> update(deltaTime);
            	pm -> updateProcessList(deltaTime);
            }
            gvp.update(deltaTime);
        }
        window_ptr->display();
    }
    // Done.
    return 0;
}

