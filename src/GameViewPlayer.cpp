
#include "GameViewPlayer.h"

using namespace std;

GameViewPlayer::GameViewPlayer (GameLogic* game, shared_ptr<sf::RenderWindow> &window_ptr)
{
    if( !bckgText.loadFromFile( "../Assets/Images/earth.png" ) )
        cout << "Cannot load background " << endl;

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
                        bckgText.setRepeated(true);
                        background.setSize(sf::Vector2f(bckgW,bckgH));
                        playerView.reset(sf::FloatRect(bckgW/2,bckgH/2,screenW,screenH));
                        background.setTextureRect(sf::IntRect(bckgPixSize,bckgPixSize,bckgW,bckgH));
                        background.setTexture(&bckgText);
                        window_ptr -> setView(playerView);
                        menu -> stopMusic();
                        game -> setGameState(1);
                        game -> initiliaze(bckgW, bckgH, screenW, screenH, bckgPixSize, playerW, playerH);
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
    window_ptr -> draw(background);
    window_ptr -> draw( game -> getPlayer());
}
