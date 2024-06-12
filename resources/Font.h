#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"

#include <iostream>
#include <string>

#ifndef TBG_FONT_H
#define TBG_FONT_H


class Font {
public:
//    A constructor
    Font(const std::string& content,float x,float y);

//    Function "draw" takes one argument and uses it as a target for drawing (for example in window)
//    @param window a sf::RenderWindow& argument.
    void draw(sf::RenderTarget& target) const;

private:
//    sf::Font variable
//    responsible for containing the font style
    sf::Font font;

//    sf::Text variable
//    responsible for containing the text value later used to display indicators
    sf::Text text;

//    Function "LoadFont"
//    responsible for loading the font file with the corresponding filename ( ARCADACLASSIC.TTF )
    void LoadFont();

//    Function "Init" takes three arguments and Initialize the text position
//    @param content a std::string containing the sentence we want to display later
//    @param x a float argument used to set position
//    @param y a float argument used to set position
    void Init(const std::string& content,float x,float y);
};


#endif //TBG_FONT_H
