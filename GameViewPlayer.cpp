
#include "GameViewPlayer.h"

using namespace std;

GameViewPlayer::GameViewPlayer (GameLogic* game, shared_ptr<sf::RenderWindow> &window_ptr)
{
    this -> game = game;
    this -> window_ptr = window_ptr;

}





void GameViewPlayer::checkKeyEvents(sf::Event Event,float deltaTime )
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
                        game -> setGameState(1);
                        game -> initiliaze();
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
                    game -> movePlayer('N',deltaTime);

                }
                if (Event.key.code == sf::Keyboard::S)
                {
                    game -> movePlayer('S',deltaTime);

                }
                if (Event.key.code == sf::Keyboard::D)
                {
                    game -> movePlayer('E',deltaTime);

                }
                if (Event.key.code == sf::Keyboard::A)
                {
                    game -> movePlayer('W',deltaTime);
                }
            }

        }

}





void GameViewPlayer::setTitleScreen(TitleScreen* screen)
{
    menu = screen;
}

void GameViewPlayer::update()
{
    window_ptr -> draw( game -> getPlayer());
}
