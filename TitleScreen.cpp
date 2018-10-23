#include "TitleScreen.h"

using namespace std;

TitleScreen::TitleScreen()
{

    if( !GameFont.loadFromFile( "../Assets/Fonts/GROBOLD.ttf" ) )
    {
        cout << "Font not found, title screen unable to load. Press 1 for single player, 2 for multiplayer" << endl;
        cout << "Player one control W-up S-down, Player two control I-up K-down" << endl;
    }

    if( !BackgroundTexture.loadFromFile( "../Assets/Images/MenuSpriteSheet.png" ) )
        cout << "Background did not load" << endl;
}

void TitleScreen::drawTitleScreen( sf::RenderWindow* window )
{
    if( enemyVal > .5 )
    {
        firstSprite = !firstSprite;
        enemyVal = 0.0f;
    }


    enemyVal += 0.02f;
    TitleBackground.setTexture( BackgroundTexture );
    if( firstSprite )
        TitleBackground.setTextureRect(sf::IntRect(0,0,750,450));

    else if( !firstSprite )
        TitleBackground.setTextureRect(sf::IntRect(0,450,750,450));

    cout<<"Value: "<<enemyVal<<endl;
    TitleBackground.setPosition(75,25);
    window -> draw( TitleBackground );
    //window -> display();
}
