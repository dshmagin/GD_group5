
#include "GameViewPlayer.h"

using namespace std;

GameViewPlayer::GameViewPlayer (GameLogic* game, shared_ptr<sf::RenderWindow> &window_ptr)
{
    this -> game = game;
    this -> window_ptr = window_ptr;

}





void GameViewPlayer::checkKeyEvents(sf::Event Event, float deltaTime )
{
   // cout<<"GAME STATE: "<<Event.key.code<<" here"<<sf::Keyboard::A<<endl;
        if( game -> getGameState() == 0 )
        {
            if (Event.type == sf::Event::KeyPressed)
            {
                if (Event.key.code == sf::Keyboard::A)
                {
                    cout << "the A key was pressed" << endl;
                    menu -> setSelected(-1);

                }
                if (Event.key.code == sf::Keyboard::D)
                {
                    menu -> setSelected(1);
                    cout << "the D key was pressed" << endl;

                }
                if (Event.key.code == sf::Keyboard::Return)
                    if( menu -> getSelected() == 0 )
                    {
                        menu -> stopMusic();
                        game -> setGameState(1);
                        game -> initialize();
                        cout<< game -> getGameState()<<endl;
                    }
            }

        }
        if( game -> getGameState() == 1 )
        {
            game-> player.movement.x =0.0f;
            game-> player.movement.y =0.0f;
            if (Event.type == sf::Event::KeyPressed)
            {
                if (Event.key.code == sf::Keyboard::W)
                {
                    game -> setDirection('N',deltaTime);
                }
                if (Event.key.code == sf::Keyboard::S)
                {
                    game -> setDirection('S',deltaTime);
                }
                if (Event.key.code == sf::Keyboard::D)
                {
                    game -> setDirection('E',deltaTime);
                }
                if (Event.key.code == sf::Keyboard::A)
                {
                    game -> setDirection('W',deltaTime);
                }

                if (Event.key.code == sf::Keyboard::UP)
                {
                    game -> playerAttack('N',deltaTime);
                }

                if (Event.key.code == sf::Keyboard::DOWN)
                {
                    game -> playerAttack('S',deltaTime);
                }

                if (Event.key.code == sf::Keyboard::LEFT)
                {
                    game -> playerAttack('E',deltaTime);
                }

                if (Event.key.code == sf::Keyboard::RIGHT)
                {
                    game -> playerAttack('W',deltaTime);
                }
            }
            if(Event.type == sf::Event::KeyReleased)
            {
                game -> idle();
            }

        }

}





void GameViewPlayer::setTitleScreen(TitleScreen* screen)
{
    menu = screen;
}

void GameViewPlayer::update(float deltaTime)
{
    game -> update(deltaTime);
    window_ptr -> draw( game -> getPlayer());
}
