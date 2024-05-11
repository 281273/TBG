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
    Font(const std::string& content,float x,float y);

    sf::Font font;
    sf::Text text;

    void LoadFont();
    void Init(const std::string& content,float x,float y);
    void draw(sf::RenderTarget& target) const;
private:

};


#endif //TBG_FONT_H
