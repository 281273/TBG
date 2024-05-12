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

    //Loading the texture , set its properties (different positions for User and Pc)
    void LoadTexture(const std::string& filename);
    virtual void Init();

    //Displaying the object
    void draw(sf::RenderWindow& window) const;

    //Setters for Stats
    float SetHp(float newhp);

    //Getters for unit stats
    float GetHp() const;
    float GetDmgMulti() const;
    const std::string &getName() const;

    sf::Texture texture;
    sf::Sprite sprite;
private:
    //Stats of the Units
    float hp;
    float dmgmulti;
    std::string name;

};


#endif //TBG_UNIT_H
