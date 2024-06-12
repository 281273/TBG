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
//    A constructor
    BackGround(const std::string& filename,float x,float y);

//    Function "draw" takes one argument and uses it as a target for drawing (for example in window)
//    @param window a sf::RenderWindow& argument.
    void draw(sf::RenderWindow& window) const;

private:
//    sf::Texture variable
//    responsible for containing the texture
    sf::Texture texture;

//    sf::Sprite variable
//    responsible for containing the sprite
    sf::Sprite sprite;

//    Function "LoadTexture" takes one argument and loads the texture file with the corresponding name
//    @param file a const std::string argument
    void LoadTexture(const std::string& filename);

//    Function "Init" takes two arguments and Initialize the sprite position
//    @param x a float argument used to set position
//    @param y a float argument used to set position
    void Init(float x,float y);
};


#endif //TBG_BACKGROUND_H
