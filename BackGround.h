#ifndef TBG_BACKGROUND_H
#define TBG_BACKGROUND_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include <string>

using namespace std;

class BackGround {
public:
    void LoadTexture(const string& filename);
    void draw(sf::RenderWindow& window) const;
    void Init(float x,float y);

    sf::Texture texture;
    sf::Sprite sprite;

    BackGround(const string& filename,float x,float y);
private:

};


#endif //TBG_BACKGROUND_H
