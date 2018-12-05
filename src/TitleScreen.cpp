#include "TitleScreen.h"
#include<iostream>
#include<fstream>

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

    keybinds[0] = walk_left_key;
    keybinds[1] = walk_right_key;
    keybinds[2] = walk_down_key;
    keybinds[3] = walk_up_key;
    keybinds[4] = shoot_left_key;
    keybinds[5] = shoot_right_key;
    keybinds[6] = shoot_down_key;
    keybinds[7] = shoot_up_key;
    keybinds[8] = special_1_key;
    keybinds[9] = special_2_key;
    keybinds[10] = special_3_key;
    keybinds[11] = special_4_key;
    //ofstream keybind_file("../Assets/keybinds.config");
    //for(int i = 0; i < 12; i++){
    //    keybind_file << keyToString(keybinds[i]) << '\n';
    //}
    //keybind_file << keybinds;
    //keybind_file.close();
    ifstream keybind_file("../Assets/keybinds.config");
    string keybind;
    if (keybind_file.is_open())
    {
        int i = 0;
        while ( getline (keybind_file, keybind) )
        {
            keybinds[i] = stringToKey(keybind);
            i++;
            cout << keybind << '\n';
        }
      keybind_file.close();
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
    water.setPosition(500,500);
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
    air.setPosition(300,500);
    air.setColor(sf::Color::White);
    air.setOutlineColor( sf::Color( 0, 0, 0 ) );
    air.setOutlineThickness(2);

    switch(elementSelected)
    {
    case 0:
        fire.setColor(sf::Color::Yellow);
        break;
    case 1:
        air.setColor(sf::Color::Yellow);
        break;
    case 2:
        earth.setColor(sf::Color::Yellow);
        break;
    case 3:
        water.setColor(sf::Color::Yellow);
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

    walk_left.setString("Walk Left: " + keyToString(keybinds[0]));
    walk_right.setString("Walk Right: " + keyToString(keybinds[1]));
    walk_down.setString("Walk Down: " + keyToString(keybinds[2]));
    walk_up.setString("Walk Up: " + keyToString(keybinds[3]));
    shoot_left.setString("Shoot Left: " + keyToString(keybinds[4]));
    shoot_right.setString("Shoot Right: " + keyToString(keybinds[5]));
    shoot_down.setString("Shoot Down: " + keyToString(keybinds[6]));
    shoot_up.setString("Shoot Up: " + keyToString(keybinds[7]));
    special_1.setString("Special 1: " + keyToString(keybinds[8]));
    special_2.setString("Special 2: " + keyToString(keybinds[9]));
    special_3.setString("Special 3: " + keyToString(keybinds[10]));
    special_4.setString("Special 4: " + keyToString(keybinds[11]));

    walk_left.setPosition(300, 30);
    walk_right.setPosition(300, 60);
    walk_down.setPosition(300, 90);
    walk_up.setPosition(300, 120);
    shoot_left.setPosition(300, 150);
    shoot_right.setPosition(300, 180);
    shoot_down.setPosition(300, 210);
    shoot_up.setPosition(300, 240);
    special_1.setPosition(300, 270);
    special_2.setPosition(300, 300);
    special_3.setPosition(300, 330);
    special_4.setPosition(300, 360);

    if(keybind_chosen){

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

void TitleScreen::drawWinScreen( float deltaTime ){
    win_or_lose.setFont(GameFont);
    score.setFont(GameFont);
    instruction.setFont(GameFont);
    win_or_lose.setColor(sf::Color::Black);
    score.setColor(sf::Color::Black);
    instruction.setColor(sf::Color::Black);

    win_or_lose.setString("YOU WIN");
    instruction.setString("Please press ESCAPE to return to the menu");
    score.setString("Score: ");

    win_or_lose.setPosition(200, 30);
    score.setPosition(200, 70);
    instruction.setPosition(200, 90);

    window_ptr -> draw(win_or_lose);
    window_ptr -> draw(score);
    window_ptr -> draw(instruction);
}


void TitleScreen::choosingKeybind()
{
    keybind_chosen = false;
    switch(keybindSelected)
    {
        case 0:
            walk_left.setColor(sf::Color::Red);
            break;
        case 1:
            walk_right.setColor(sf::Color::Red);
            break;
        case 2:
            walk_down.setColor(sf::Color::Red);
            break;
        case 3:
            walk_up.setColor(sf::Color::Red);
            break;
        case 4:
            shoot_left.setColor(sf::Color::Red);
            break;
        case 5:
            shoot_right.setColor(sf::Color::Red);
            break;
        case 6:
            shoot_down.setColor(sf::Color::Red);
            break;
        case 7:
            shoot_up.setColor(sf::Color::Red);
            break;
        case 8:
            special_1.setColor(sf::Color::Red);
            break;
        case 9:
            special_2.setColor(sf::Color::Red);
            break;
        case 10:
            special_3.setColor(sf::Color::Red);
            break;
        case 11:
            special_4.setColor(sf::Color::Red);
            break;
    }
}

void TitleScreen::newKeybind(const sf::Keyboard::Key& key )
{
    ofstream keybind_file("../Assets/keybinds.config");
    sf::Keyboard::Key *duplicate = std::find(std::begin(keybinds), std::end(keybinds), key);
    if(duplicate == std::end(keybinds)){
        keybinds[keybindSelected] = key;
        if(keybind_file.is_open()){
            for(int i = 0; i < (sizeof(keybinds) / sizeof(sf::Keyboard::Key)); i++){
                keybind_file << keyToString(keybinds[i]) << '\n';
            }
        }
    }
    switch(keybindSelected)
    {
        case 0:
            walk_left_key = key;
            break;
        case 1:
            walk_right_key = key;
            break;
        case 2:
            walk_down_key = key;
            break;
        case 3:
            walk_up_key = key;
            break;
        case 4:
            shoot_left_key = key;
            break;
        case 5:
            shoot_right_key = key;
            break;
        case 6:
            shoot_down_key = key;
            break;
        case 7:
            shoot_up_key = key;
            break;
        case 8:
            special_1_key = key;
            break;
        case 9:
            special_2_key = key;
            break;
        case 10:
            special_3_key = key;
            break;
        case 11:
            special_4_key = key;
            break;
    }
    keybind_chosen = true;
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

int  TitleScreen::getSelectedKeybind()
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

sf::Keyboard::Key TitleScreen::getKeybind(KB key){
    return keybinds[key];
}

//I'm sincerely sorry for this, for the record:
string TitleScreen::keyToString(const sf::Keyboard::Key& key )
{
    string ret;
    switch(key){
    case sf::Keyboard::A :

        ret="A";
        break;
    case sf::Keyboard::B :

        ret="B";
        break;
    case sf::Keyboard::C :

        ret="C";
        break;
    case sf::Keyboard::D :

        ret="D";
        break;
    case sf::Keyboard::E :

        ret="E";
        break;
    case sf::Keyboard::F :

        ret="F";
        break;
    case sf::Keyboard::G :

        ret="G";
        break;
    case sf::Keyboard::H :

        ret="H";
        break;
    case sf::Keyboard::I :

        ret="I";
        break;
    case sf::Keyboard::J :

        ret="J";
        break;
    case sf::Keyboard::K :

        ret="K";
        break;
    case sf::Keyboard::L :

        ret="L";
        break;
    case sf::Keyboard::M :

        ret="M";
        break;
    case sf::Keyboard::N :

        ret="N";
        break;
    case sf::Keyboard::O :

        ret="O";
        break;
    case sf::Keyboard::P :

        ret="P";
        break;
    case sf::Keyboard::Q :

        ret="Q";
        break;
    case sf::Keyboard::R :

        ret="R";
        break;
    case sf::Keyboard::S :

        ret="S";
        break;
    case sf::Keyboard::T :

        ret="T";
        break;
    case sf::Keyboard::U :

        ret="U";
        break;
    case sf::Keyboard::V :

        ret="V";
        break;
    case sf::Keyboard::W :

        ret="W";
        break;
    case sf::Keyboard::X :

        ret="X";
        break;
    case sf::Keyboard::Y :

        ret="Y";
        break;
    case sf::Keyboard::Z :

        ret="Z";
        break;
    case sf::Keyboard::Num0 :

        ret="Num0";
        break;
    case sf::Keyboard::Num1 :

        ret="Num1";
        break;
    case sf::Keyboard::Num2 :

        ret="Num2";
        break;
    case sf::Keyboard::Num3 :

        ret="Num3";
        break;
    case sf::Keyboard::Num4 :

        ret="Num4";
        break;
    case sf::Keyboard::Num5 :

        ret="Num5";
        break;
    case sf::Keyboard::Num6 :

        ret="Num6";
        break;
    case sf::Keyboard::Num7 :

        ret="Num7";
        break;
    case sf::Keyboard::Num8 :

        ret="Num8";
        break;
    case sf::Keyboard::Num9 :

        ret="Num9";
        break;
    case sf::Keyboard::Escape :

        ret="Escape";
        break;
    case sf::Keyboard::LControl :

        ret="LControl";
        break;
    case sf::Keyboard::LShift :

        ret="LShift";
        break;
    case sf::Keyboard::LAlt :

        ret="LAlt";
        break;
    case sf::Keyboard::LSystem :

        ret="LSystem";
        break;
    case sf::Keyboard::RControl :

        ret="RControl";
        break;
    case sf::Keyboard::RShift :

        ret="RShift";
        break;
    case sf::Keyboard::RAlt :

        ret="RAlt";
        break;
    case sf::Keyboard::RSystem :

        ret="RSystem";
        break;
    case sf::Keyboard::Menu :

        ret="Menu";
        break;
    case sf::Keyboard::LBracket :

        ret="LBracket";
        break;
    case sf::Keyboard::RBracket :

        ret="RBracket";
        break;
    case sf::Keyboard::SemiColon :

        ret="SemiColon";
        break;
    case sf::Keyboard::Comma :

        ret="Comma";
        break;
    case sf::Keyboard::Period :

        ret="Period";
        break;
    case sf::Keyboard::Quote :

        ret="Quote";
        break;
    case sf::Keyboard::Slash :

        ret="Slash";
        break;
    case sf::Keyboard::BackSlash :

        ret="BackSlash";
        break;
    case sf::Keyboard::Tilde :

        ret="Tilde";
        break;
    case sf::Keyboard::Equal :

        ret="Equal";
        break;
    case sf::Keyboard::Dash :

        ret="Dash";
        break;
    case sf::Keyboard::Space :

        ret="Space";
        break;
    case sf::Keyboard::Return :

        ret="Return";
        break;
    case sf::Keyboard::BackSpace :

        ret="BackSpace";
        break;
    case sf::Keyboard::Tab :

        ret="Tab";
        break;
    case sf::Keyboard::PageUp :

        ret="PageUp";
        break;
    case sf::Keyboard::PageDown :

        ret="PageDown";
        break;
    case sf::Keyboard::End :

        ret="End";
        break;
    case sf::Keyboard::Home :

        ret="Home";
        break;
    case sf::Keyboard::Insert :

        ret="Insert";
        break;
    case sf::Keyboard::Delete :

        ret="Delete";
        break;
    case sf::Keyboard::Add :

        ret="Add";
        break;
    case sf::Keyboard::Subtract :

        ret="Subtract";
        break;
    case sf::Keyboard::Multiply :

        ret="Multiply";
        break;
    case sf::Keyboard::Divide :

        ret="Divide";
        break;
    case sf::Keyboard::Left :

        ret="Left";
        break;
    case sf::Keyboard::Right :

        ret="Right";
        break;
    case sf::Keyboard::Up :

        ret="Up";
        break;
    case sf::Keyboard::Down :

        ret="Down";
        break;
    case sf::Keyboard::Numpad0 :

        ret="Numpad0";
        break;
    case sf::Keyboard::Numpad1 :

        ret="Numpad1";
        break;
    case sf::Keyboard::Numpad2 :

        ret="Numpad2";
        break;
    case sf::Keyboard::Numpad3 :

        ret="Numpad3";
        break;
    case sf::Keyboard::Numpad4 :

        ret="Numpad4";
        break;
    case sf::Keyboard::Numpad5 :

        ret="Numpad5";
        break;
    case sf::Keyboard::Numpad6 :

        ret="Numpad6";
        break;
    case sf::Keyboard::Numpad7 :

        ret="Numpad7";
        break;
    case sf::Keyboard::Numpad8 :

        ret="Numpad8";
        break;
    case sf::Keyboard::Numpad9 :

        ret="Numpad9";
        break;
    case sf::Keyboard::F1 :

        ret="F1";
        break;
    case sf::Keyboard::F2 :

        ret="F2";
        break;
    case sf::Keyboard::F3 :

        ret="F3";
        break;
    case sf::Keyboard::F4 :

        ret="F4";
        break;
    case sf::Keyboard::F5 :

        ret="F5";
        break;
    case sf::Keyboard::F6 :

        ret="F6";
        break;
    case sf::Keyboard::F7 :

        ret="F7";
        break;
    case sf::Keyboard::F8 :

        ret="F8";
        break;
    case sf::Keyboard::F9 :

        ret="F9";
        break;
    case sf::Keyboard::F10 :

        ret="F10";
        break;
    case sf::Keyboard::F11 :

        ret="F11";
        break;
    case sf::Keyboard::F12 :

        ret="F12";
        break;
    case sf::Keyboard::F13 :

        ret="F13";
        break;
    case sf::Keyboard::F14 :

        ret="F14";
        break;
    case sf::Keyboard::F15 :

        ret="F15";
        break;
    case sf::Keyboard::Pause :

        ret="Pause";
        break;
    case sf::Keyboard::KeyCount :

        ret="KeyCount";
        break;

    default:
        ret="Unknown";
        break;
    }
    return ret;
}

//Again, so sorry for this. I blame SFML's bad coding practice
sf::Keyboard::Key TitleScreen::stringToKey(const string string)
{
    sf::Keyboard::Key ret = sf::Keyboard::Unknown;
    if(string.compare("A") == 0){
        ret=sf::Keyboard::A;
    }
    if(string.compare("B") == 0){
        ret=sf::Keyboard::B;
    }
    if(string.compare("C") == 0){
        ret=sf::Keyboard::C;
    }
    if(string.compare("D") == 0){
        ret=sf::Keyboard::D;
    }
    if(string.compare("E") == 0){

        ret=sf::Keyboard::E;
    }
    if(string.compare("F") == 0){

        ret=sf::Keyboard::F;
    }
    if(string.compare("G") == 0){

        ret=sf::Keyboard::G;
    }
    if(string.compare("H") == 0){

        ret=sf::Keyboard::H;
    }
    if(string.compare("I") == 0){

        ret=sf::Keyboard::I;
    }
    if(string.compare("J") == 0){

        ret=sf::Keyboard::J;
    }
    if(string.compare("K") == 0){

        ret=sf::Keyboard::K;
    }
    if(string.compare("L") == 0){

        ret=sf::Keyboard::L;
    }
    if(string.compare("M") == 0){

        ret=sf::Keyboard::M;
    }
    if(string.compare("N") == 0){

        ret=sf::Keyboard::N;
    }
    if(string.compare("O") == 0){

        ret=sf::Keyboard::O;
    }
    if(string.compare("P") == 0){

        ret=sf::Keyboard::P;
    }
    if(string.compare("Q") == 0){

        ret=sf::Keyboard::Q;
    }
    if(string.compare("R") == 0){

        ret=sf::Keyboard::R;
    }
    if(string.compare("S") == 0){

        ret=sf::Keyboard::S;
    }
    if(string.compare("T") == 0){

        ret=sf::Keyboard::T;
    }
    if(string.compare("U") == 0){

        ret=sf::Keyboard::U;
    }
    if(string.compare("V") == 0){

        ret=sf::Keyboard::V;
    }
    if(string.compare("W") == 0){

        ret=sf::Keyboard::W;
    }
    if(string.compare("X") == 0){

        ret=sf::Keyboard::X;
    }
    if(string.compare("Y") == 0){

        ret=sf::Keyboard::Y;
    }
    if(string.compare("Z") == 0){

        ret=sf::Keyboard::Z;
    }
    if(string.compare("Num0") == 0){

        ret=sf::Keyboard::Num0;
    }
    if(string.compare("Num1") == 0){

        ret=sf::Keyboard::Num1;
    }
    if(string.compare("Num2") == 0){

        ret=sf::Keyboard::Num2;
    }
    if(string.compare("Num3") == 0){

        ret=sf::Keyboard::Num3;
    }
    if(string.compare("Num4") == 0){

        ret=sf::Keyboard::Num4;
    }
    if(string.compare("Num5") == 0){

        ret=sf::Keyboard::Num5;
    }
    if(string.compare("Num6") == 0){

        ret=sf::Keyboard::Num6;
    }
    if(string.compare("Num7") == 0){

        ret=sf::Keyboard::Num7;
    }
    if(string.compare("Num8") == 0){

        ret=sf::Keyboard::Num8;
    }
    if(string.compare("Num9") == 0){

        ret=sf::Keyboard::Num9;
    }
    if(string.compare("Escape") == 0){

        ret=sf::Keyboard::Escape;
    }
    if(string.compare("LControl") == 0){

        ret=sf::Keyboard::LControl;
    }
    if(string.compare("LShift") == 0){

        ret=sf::Keyboard::LShift;
    }
    if(string.compare("LAlt") == 0){

        ret=sf::Keyboard::LAlt;
    }
    if(string.compare("LSystem") == 0){

        ret=sf::Keyboard::LSystem;
    }
    if(string.compare("RControl") == 0){

        ret=sf::Keyboard::RControl;
    }
    if(string.compare("RShift") == 0){

        ret=sf::Keyboard::RShift;
    }
    if(string.compare("RAlt") == 0){

        ret=sf::Keyboard::RAlt;
    }
    if(string.compare("RSystem") == 0){

        ret=sf::Keyboard::RSystem;
    }
    if(string.compare("Menu") == 0){

        ret=sf::Keyboard::Menu;
    }
    if(string.compare("LBracket") == 0){

        ret=sf::Keyboard::LBracket;
    }
    if(string.compare("RBracket") == 0){

        ret=sf::Keyboard::RBracket;
    }
    if(string.compare("SemiColon") == 0){

        ret=sf::Keyboard::SemiColon;
    }
    if(string.compare("Comma") == 0){

        ret=sf::Keyboard::Comma;
    }
    if(string.compare("Period") == 0){

        ret=sf::Keyboard::Period;
    }
    if(string.compare("Quote") == 0){

        ret=sf::Keyboard::Quote;
    }
    if(string.compare("Slash") == 0){

        ret=sf::Keyboard::Slash;
    }
    if(string.compare("BackSlash") == 0){

        ret=sf::Keyboard::BackSlash;
    }
    if(string.compare("Tilde") == 0){

        ret=sf::Keyboard::Tilde;
    }
    if(string.compare("Equal") == 0){

        ret=sf::Keyboard::Equal;
    }
    if(string.compare("Dash") == 0){

        ret=sf::Keyboard::Dash;
    }
    if(string.compare("Space") == 0){

        ret=sf::Keyboard::Space;
    }
    if(string.compare("Return") == 0){

        ret=sf::Keyboard::Return;
    }
    if(string.compare("BackSpace") == 0){

        ret=sf::Keyboard::BackSpace;
    }
    if(string.compare("Tab") == 0){

        ret=sf::Keyboard::Tab;
    }
    if(string.compare("PageUp") == 0){

        ret=sf::Keyboard::PageUp;
    }
    if(string.compare("PageDown") == 0){

        ret=sf::Keyboard::PageDown;
    }
    if(string.compare("End") == 0){

        ret=sf::Keyboard::End;
    }
    if(string.compare("Home") == 0){

        ret=sf::Keyboard::Home;
    }
    if(string.compare("Insert") == 0){

        ret=sf::Keyboard::Insert;
    }
    if(string.compare("Delete") == 0){

        ret=sf::Keyboard::Delete;
    }
    if(string.compare("Add") == 0){

        ret=sf::Keyboard::Add;
    }
    if(string.compare("Subtract") == 0){

        ret=sf::Keyboard::Subtract;
    }
    if(string.compare("Multiply") == 0){

        ret=sf::Keyboard::Multiply;
    }
    if(string.compare("Divide") == 0){

        ret=sf::Keyboard::Divide;
    }
    if(string.compare("Left") == 0){

        ret=sf::Keyboard::Left;
    }
    if(string.compare("Right") == 0){

        ret=sf::Keyboard::Right;
    }
    if(string.compare("Up") == 0){

        ret=sf::Keyboard::Up;
    }
    if(string.compare("Down") == 0){

        ret=sf::Keyboard::Down;
    }
    if(string.compare("Numpad0") == 0){

        ret=sf::Keyboard::Numpad0;
    }
    if(string.compare("Numpad1") == 0){

        ret=sf::Keyboard::Numpad1;
    }
    if(string.compare("Numpad2") == 0){

        ret=sf::Keyboard::Numpad2;
    }
    if(string.compare("Numpad3") == 0){

        ret=sf::Keyboard::Numpad3;
    }
    if(string.compare("Numpad4") == 0){

        ret=sf::Keyboard::Numpad4;
    }
    if(string.compare("Numpad5") == 0){

        ret=sf::Keyboard::Numpad5;
    }
    if(string.compare("Numpad6") == 0){

        ret=sf::Keyboard::Numpad6;
    }
    if(string.compare("Numpad7") == 0){

        ret=sf::Keyboard::Numpad7;
    }
    if(string.compare("Numpad8") == 0){

        ret=sf::Keyboard::Numpad8;
    }
    if(string.compare("Numpad9") == 0){

        ret=sf::Keyboard::Numpad9;
    }
    if(string.compare("F1") == 0){

        ret=sf::Keyboard::F1;
    }
    if(string.compare("F2") == 0){

        ret=sf::Keyboard::F2;
    }
    if(string.compare("F3") == 0){

        ret=sf::Keyboard::F3;
    }
    if(string.compare("F4") == 0){

        ret=sf::Keyboard::F4;
    }
    if(string.compare("F5") == 0){

        ret=sf::Keyboard::F5;
    }
    if(string.compare("F6") == 0){

        ret=sf::Keyboard::F6;
    }
    if(string.compare("F7") == 0){

        ret=sf::Keyboard::F7;
    }
    if(string.compare("F8") == 0){

        ret=sf::Keyboard::F8;
    }
    if(string.compare("F9") == 0){

        ret=sf::Keyboard::F9;
    }
    if(string.compare("F10") == 0){

        ret=sf::Keyboard::F10;
    }
    if(string.compare("F11") == 0){

        ret=sf::Keyboard::F11;
    }
    if(string.compare("F12") == 0){

        ret=sf::Keyboard::F12;
    }
    if(string.compare("F13") == 0){

        ret=sf::Keyboard::F13;
    }
    if(string.compare("F14") == 0){

        ret=sf::Keyboard::F14;
    }
    if(string.compare("F15") == 0){

        ret=sf::Keyboard::F15;
    }
    if(string.compare("Pause") == 0){

        ret=sf::Keyboard::Pause;
    }
    if(string.compare("KeyCount") == 0){

        ret=sf::Keyboard::KeyCount;
    }
    return ret;
}
