
#include "GameViewPlayer.h"

using namespace std;

GameViewPlayer::GameViewPlayer (GameLogic* game, shared_ptr<sf::RenderWindow> &window_ptr)
{
    if( !bckgText.loadFromFile( "../Assets/Images/Earth.png" ) )
        cout << "Cannot load background " << endl;

    this -> game = game;
    this -> window_ptr = window_ptr;

}





void GameViewPlayer::checkKeyEvents( float deltaTime )
{

        if( game -> getGameState() == 0 )
        {

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    menu -> setSelected(-1);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    menu -> setSelected(1);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
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
        if( game -> getGameState() == 1 )
        {
            movingX = false;
            movingY = false;

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    movingY = true;
                    game -> setDirection('N',deltaTime);

                    sf::Vector2f vect(game -> getPlayerCoord());

                    if ((vect.y + playerH/2) < ((bckgH - screenH/2) - playerH) && ((vect.y + playerH/2) > (screenH/2 + playerH)))
                    {
                        window_ptr -> setView(playerView);
                        playerView.move(0, -camMoveSpeed *deltaTime);
                    }


                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    movingY = true;
                    sf::Vector2f vect(game -> getPlayerCoord());
                    game -> setDirection('S',deltaTime);

                    if ((vect.y + playerH/2) < ((bckgH - screenH/2) - playerH) && ((vect.y + playerH/2) > (screenH/2 + playerH)))
                    {
                        playerView.move(0, camMoveSpeed *deltaTime);
                        window_ptr -> setView(playerView);
                    }

                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    movingX = true;
                    sf::Vector2f vect(game -> getPlayerCoord());
                    game -> setDirection('E',deltaTime);

                    if ((vect.x + playerW/2) < ((bckgW - screenW/2) - playerW) && ((vect.x + playerW/2) > (screenW/2 + playerW)))
                    {
                        playerView.move( camMoveSpeed * deltaTime,0 );
                        window_ptr -> setView(playerView);
                    }


                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    movingX = true;
                    sf::Vector2f vect(game -> getPlayerCoord());
                    game -> setDirection('W',deltaTime);
                    if ((vect.x + playerW/2) < ((bckgW - screenW/2) - playerW) && ((vect.x + playerW/2) > (screenW/2 + playerW)))
                    {
                        playerView.move( -camMoveSpeed * deltaTime ,0 );
                        window_ptr -> setView(playerView);
                    }
                }



                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    game -> createPlayerAttack('N',deltaTime);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    game -> createPlayerAttack('S',deltaTime);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    game -> createPlayerAttack('W',deltaTime);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    game -> createPlayerAttack('E',deltaTime);
                }



            if(movingX == false && movingY == false)
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
    window_ptr -> draw( game -> getAttack());
}
