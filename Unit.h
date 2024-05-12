#ifndef TBG_UNIT_H
#define TBG_UNIT_H

#include <iostream>
#include <string>
#include <vector>


#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"

class Unit {
public:
    Unit(const std::string& filename);
    ~Unit();

    void LoadTexture(const std::string& filename);
    virtual void Init();

    void draw(sf::RenderWindow& window) const;

    float SetHp(float newhp);
    float GetHp() const;
    float GetDmgMulti() const;
    const std::string &getName() const;

    sf::Texture texture;
    sf::Sprite sprite;
private:
    float hp;
    float dmgmulti;
    std::string name;



};


#endif //TBG_UNIT_H
