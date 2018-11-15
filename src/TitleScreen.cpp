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
/*
    if( !menuSong.loadFromFile( "../Assets/Sounds/Ground_Break_Menu_01.wav" ) )
    {
        cout << "Font not found, title screen unable to load. Press 1 for single player, 2 for multiplayer" << endl;
        cout << "Player one control W-up S-down, Player two control I-up K-down" << endl;
        musicCanPlay = false;
    }
    else
    {
        music.setBuffer(menuSong);
    }
*/
    if( !keySound.loadFromFile( "../Assets/Sounds/keySound.wav" ) )
    {
        cout << "Font not found, title screen unable to load. Press 1 for single player, 2 for multiplayer" << endl;
        cout << "Player one control W-up S-down, Player two control I-up K-down" << endl;
        musicCanPlay = false;
    }
    else
    {
        sound.setBuffer(keySound);
    }
}


void TitleScreen::drawElementOption( float deltaTime )
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
    Option.setPosition(600,500);
    Option.setColor(sf::Color::Black);
    Start.setFont(GameFont);
    Start.setString("Start");
    Start.setPosition(200,500);
    Start.setColor(sf::Color::Black);
    TitleBackground.setPosition(75,25);
    fire.setFont(GameFont);
    fire.setString("Fire");
    fire.setPosition(200,500);
    fire.setColor(sf::Color::Red);
    fire.setOutlineColor( sf::Color( 0, 0, 0 ) );
    fire.setOutlineThickness(2);
    water.setFont(GameFont);
    water.setString("Water");
    water.setPosition(300,500);
    water.setColor(sf::Color::Blue);
    water.setOutlineColor( sf::Color( 0, 0, 0 ) );
    water.setOutlineThickness(2);
    earth.setFont(GameFont);
    earth.setString("Earth");
    earth.setPosition(400,500);
    earth.setColor(sf::Color(139,69,19));
    earth.setOutlineColor( sf::Color( 0, 0, 0 ) );
    earth.setOutlineThickness(2);
    air.setFont(GameFont);
    air.setString("Air");
    air.setPosition(500,500);
    air.setColor(sf::Color::White);
    air.setOutlineColor( sf::Color( 0, 0, 0 ) );
    air.setOutlineThickness(2);

    switch(elementSelected)
    {
    case 0:
        fire.setColor(sf::Color::Yellow);
        break;
    case 1:
        water.setColor(sf::Color::Yellow);
        break;
    case 2:
        earth.setColor(sf::Color::Yellow);
        break;
    case 3:
        air.setColor(sf::Color::Yellow);
        break;
    }
    window_ptr -> draw( fire );
    window_ptr -> draw( water );
    window_ptr -> draw( earth );
    window_ptr -> draw( TitleBackground );
    window_ptr -> draw( air );

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
        Start.setColor(sf::Color::Yellow);
        break;
    case 1:
        Option.setColor(sf::Color::Yellow);
        break;
    }
    window_ptr -> draw( TitleBackground );
    window_ptr -> draw( Option );
    window_ptr -> draw( Start );

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
    if(musicCanPlay)
    {
        sound.play();
    }
}
int  TitleScreen::getSelectedElement()
{
    return elementSelected;
}
void TitleScreen::setSelectedElement(int direction)
{
    if(elementSelected !=0 && direction < 0 )
    {
        elementSelected = elementSelected + direction;
    }
    else if( elementSelected != 3 && direction > 0)
    {
        elementSelected = elementSelected + direction;
    }
    if(musicCanPlay)
    {
        sound.play();
    }
}
int  TitleScreen::getSelected()
{
    return selected;
}
void TitleScreen::startMusic()
{
    if(musicCanPlay)
    {
        music.setVolume(10);
        music.setLoop(true);
        music.play();
    }
}
void TitleScreen::stopMusic()
{
    if(musicCanPlay)
    {
        music.stop();
        sound.stop();
    }
}
