#ifndef TBG_BACKGROUND_H
#define TBG_BACKGROUND_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include <string>


class BackGround {
public:
    BackGround(const std::string& filename,float x,float y);

    //Function responsible for loading textures to the given frame , drawing them on the screen, setting their properties
    void draw(sf::RenderWindow& window) const;

private:
    sf::Texture texture;
    sf::Sprite sprite;

    void LoadTexture(const std::string& filename);
    void Init(float x,float y);
};


#endif //TBG_BACKGROUND_H
