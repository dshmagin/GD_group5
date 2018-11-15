#include "TitleScreen.h"

using namespace std;

OptionsScreen::OptionsScreen(shared_ptr<sf::RenderWindow> &window_ptr)
{

   this -> window_ptr = window_ptr;
   if( !GameFont.loadFromFile( "../Assets/Fonts/GROBOLD.ttf" ) )
    {
        cout << "Font not found, title screen unable to load. Press 1 for single player, 2 for multiplayer" << endl;
        cout << "Player one control W-up S-down, Player two control I-up K-down" << endl;
    }

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


void TitleScreen::drawOptionsScreen( float deltaTime )
{
    walk_left.setFont(GameFont);
    walk_right.setFont(GameFont);
    walk_down.setFont(GameFont);
    walk_up.setFont(GameFont);
    shoot_left.setFont(GameFont);
    shoot_right.setFont(GameFont);
    shoot_down.setFont(GameFont);
    shoot_up.setFont(GameFont);
    special_1.setFont(GameFont);
    special_2.setFont(GameFont);
    special_3.setFont(GameFont);
    special_4.setFont(GameFont);

    walk_left.setString("Walk Left: " + walk_left_key);
    walk_right.setString("Walk Right: " + walk_right_key);
    walk_down.setString("Walk Down: " + walk_down_key);
    walk_up.setString("Walk Up: " + walk_up_key);
    shoot_left.setString("Shoot Left: " + shoot_left_key);
    shoot_right.setString("Shoot Right: " + shoot_right_key);
    shoot_down.setString("Shoot Down: " + shoot_down_key);
    shoot_up.setString("Shoot Up: " + shoot_up_key);
    special_1.setString("Special 1: " + special_1_key);
    special_2.setString("Special 2: " + special_2_key);
    special_3.setString("Special 3: " + special_3_key);
    special_4.setString("Special 4: " + special_4_key);

    walk_left.setPosition(20, 300);
    walk_right.setPosition(40, 300);
    walk_down.setPosition(60, 300);
    walk_up.setPosition(80, 300);
    shoot_left.setPosition(100, 300);
    shoot_right.setPosition(120, 300);
    shoot_down.setPosition(140, 300);
    shoot_up.setPosition(160, 300);
    special_1.setPosition(180, 300);
    special_2.setPosition(200, 300);
    special_3.setPosition(220, 300);
    special_4.setPosition(240, 300);

    walk_left.setColor(sf::Color::Black);
    walk_right.setColor(sf::Color::Black);
    walk_down.setColor(sf::Color::Black);
    walk_up.setColor(sf::Color::Black);
    shoot_left.setColor(sf::Color::Black);
    shoot_right.setColor(sf::Color::Black);
    shoot_down.setColor(sf::Color::Black);
    shoot_up.setColor(sf::Color::Black);
    special_1.setColor(sf::Color::Black);
    special_2.setColor(sf::Color::Black);
    special_3.setColor(sf::Color::Black);
    special_4.setColor(sf::Color::Black);

    switch(keybindSelected)
    {
    case 0:
        walk_left.setColor(sf::Color::Yellow);
        break;
    case 1:
        walk_right.setColor(sf::Color::Yellow);
        break;
    case 2:
        walk_down.setColor(sf::Color::Yellow);
        break;
    case 3:
        walk_up.setColor(sf::Color::Yellow);
        break;
    case 4:
        shoot_left.setColor(sf::Color::Yellow);
        break;
    case 5:
        shoot_right.setColor(sf::Color::Yellow);
        break;
    case 6:
        shoot_down.setColor(sf::Color::Yellow);
        break;
    case 7:
        shoot_up.setColor(sf::Color::Yellow);
        break;
    case 8:
        special_1.setColor(sf::Color::Yellow);
        break;
    case 9:
        special_2.setColor(sf::Color::Yellow);
        break;
    case 10:
        special_3.setColor(sf::Color::Yellow);
        break;
    case 11:
        special_4.setColor(sf::Color::Yellow);
        break;
   }
    window_ptr -> draw( walk_left );
    window_ptr -> draw( walk_right );
    window_ptr -> draw( walk_down );
    window_ptr -> draw( walk_up );
    window_ptr -> draw( shoot_left );
    window_ptr -> draw( shoot_right );
    window_ptr -> draw( shoot_down );
    window_ptr -> draw( shoot_up );
    window_ptr -> draw( special_1 );
    window_ptr -> draw( special_2 );
    window_ptr -> draw( special_3 );
    window_ptr -> draw( special_4 );
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

int  TitleScreen::getKeybindSelected()
{
    return keybindSelected;
}

void TitleScreen::setSelectedKeybind(int direction)
{
    if(keybindSelected !=0 && direction < 0 )
    {
        keybindSelected += direction;
    }
    else if( keybindSelected != 11 && direction > 0)
    {
        keybindSelected += direction;
    }
    if(musicCanPlay)
    {
        sound.play();
    }
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
