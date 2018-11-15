#ifndef TITLESCREEN_H_INCLUDED
#define TITLESCREEN_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>
#include <string>
#include <string>
#include <sstream>
#include <iostream>
#include <memory>
#include <SFML/Audio.hpp>
using namespace std;
class TitleScreen
{
    private:
        int selected = 0;
        int elementSelected = 0;
        sf::Font GameFont;
        shared_ptr<sf::RenderWindow> window_ptr;
        sf::Text Option;
        sf::Text Start;
        sf::Text fire;
        sf::Text water;;
        sf::Text earth;
        sf::Text air;
        sf::Texture BackgroundTexture;
        sf::Sprite TitleBackground;
        sf::SoundBuffer menuSong;
        sf::SoundBuffer keySound;
        sf::Sound music;
        sf::Sound sound;
        bool firstSprite = true;
        bool musicCanPlay = true;
        float titleImage = 0;

	sf::Text walk_left;
	sf::Text walk_right;
	sf::Text walk_down;
	sf::Text walk_up;
	sf::Text shoot_left;
	sf::Text shoot_right;
	sf::Text shoot_down;
	sf::Text shoot_up;
	sf::Text special_1;
	sf::Text special_2;
	sf::Text special_3;
	sf::Text special_4;

	sf::Keyboard::Key walk_left_key = sf::Keyboard::A;
	sf::Keyboard::Key walk_right_key = sf::Keyboard::D;
	sf::Keyboard::Key walk_down_key = sf::Keyboard::S;
	sf::Keyboard::Key walk_up_key = sf::Keyboard::W;
	sf::Keyboard::Key shoot_left_key = sf::Keyboard::Left;
	sf::Keyboard::Key shoot_right_key = sf::Keyboard::Right;
	sf::Keyboard::Key shoot_down_key = sf::Keyboard::Down;
	sf::Keyboard::Key shoot_up_key = sf::Keyboard::Up;
	sf::Keyboard::Key special_1_key = sf::Keyboard::Num1;
	sf::Keyboard::Key special_2_key = sf::Keyboard::Num2;
	sf::Keyboard::Key special_3_key = sf::Keyboard::Num3;
	sf::Keyboard::Key special_4_key = sf::Keyboard::Num4;

	bool keybind_chosen = true;
	int keybindSelected = 0;
    public:
        TitleScreen();
        TitleScreen(shared_ptr<sf::RenderWindow> &window_ptr );
        void setSelected( int direction);
        int  getSelected();
        void setSelectedElement( int direction);
        int  getSelectedElement();
        void drawTitleScreen( float deltaTime );
        void drawElementOption( float deltaTime );
        void drawOptionsScreen( float deltaTime );
        int  getSelectedKeybind();
	void setSelectedKeybind( int direction );
        string keyToString(const sf::Keyboard::Key& key );
        void newKeybind(const sf::Keyboard::Key& key );
        void choosingKeybind();
        void startMusic();
        void stopMusic();
};

#endif // TITLESCREEN_H_INCLUDED
