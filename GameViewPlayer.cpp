
#include "GameViewPlayer.h"

using namespace std;

GameViewPlayer::GameViewPlayer (GameLogic* game)
{
    this -> game = game;

}





void GameViewPlayer::checkKeyEvents( sf::RenderWindow* window,sf::Event Event )
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
            }
        }

}





void GameViewPlayer::setTitleScreen(TitleScreen* screen)
{
    menu = screen;
}
