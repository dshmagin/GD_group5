#include "TitleScreen.h"

using namespace std;

TitleScreen::TitleScreen(shared_ptr<sf::RenderWindow> &window_ptr)
{

   this -> window_ptr = window_ptr;
   if( !GameFont.loadFromFile( "../Assets/Fonts/GROBOLD.ttf" ) )
    {
        cout << "Font not found, title screen unable to load. Press 1 for single player, 2 for multiplayer" << endl;
        cout << "Player one control W-up S-down, Player two control I-up K-down" << endl;
    }

    if( !BackgroundTexture.loadFromFile( "../Assets/Images/MenuSpriteSheet.png" ) )
        cout << "Background did not load" << endl;

    if( !menuSong.loadFromFile( "../Assets/Sounds/Ground_Break_Menu_01.wav" ) )
    {
        cout << "Font not found, title screen unable to load. Press 1 for single player, 2 for multiplayer" << endl;
        cout << "Player one control W-up S-down, Player two control I-up K-down" << endl;
    }
}

void TitleScreen::setSelected(int direction)
{
    if(selected !=0 && direction < 0 )
    {
        selected = selected + direction;
    }
    else if( selected != 1 && direction > 0)
    {
        selected = selected + direction;
    }
}

void TitleScreen::drawTitleScreen( float deltaTime )
{
    if( titleImage > 5 )
    {
        firstSprite = !firstSprite;
        titleImage = 0.0f;
    }


    titleImage += 0.02f *deltaTime;
    TitleBackground.setTexture( BackgroundTexture );
    if( firstSprite )
        TitleBackground.setTextureRect(sf::IntRect(0,0,750,450));

    else if( !firstSprite )
        TitleBackground.setTextureRect(sf::IntRect(0,450,750,450));

    Option.setFont(GameFont);
    Option.setString("Option");
    Start.setFont(GameFont);
    Start.setString("Start");
    Start.setPosition(200,500);
    Option.setPosition(600,500);
    TitleBackground.setPosition(75,25);
    Start.setColor(sf::Color::Black);
    Option.setColor(sf::Color::Black);

    switch(selected)
    {
    case 0:
        Start.setColor(sf::Color::Red);
        break;
    case 1:
        Option.setColor(sf::Color::Red);
        break;
    }
    window_ptr -> clear(sf::Color::White);
    window_ptr -> draw( TitleBackground );
    window_ptr -> draw( Option );
    window_ptr -> draw( Start );

}
int  TitleScreen::getSelected()
{
    return selected;
}
void TitleScreen::startMusic()
{
    sound.setBuffer(menuSong);
    sound.setLoop(true);
    sound.play();
}
void TitleScreen::stopMusic()
{
    sound.stop();

}
