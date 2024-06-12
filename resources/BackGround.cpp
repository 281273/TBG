#include "BackGround.h"

BackGround::BackGround(const std::string& filename,float x,float y){
    LoadTexture(filename);
    Init(x,y);
};

//Loading textures from files
void BackGround::LoadTexture(const std::string& filename){
    if (!texture.loadFromFile("../sprites/"+filename+".png")) {
        std::cerr << "Texture error player \n";
    }
}

//Setting texture and position
void BackGround::Init(float x,float y){
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
}

//Displaying
void BackGround::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

