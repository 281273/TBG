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
    explicit Unit(const std::string& filename);
    virtual ~Unit();

    //Loading the texture , set its properties (different positions for User and Pc)
    void LoadTexture(const std::string& filename);
    virtual void Init();

    //Displaying the object
    void draw(sf::RenderWindow& window) const;

    //Setters for Stats
    int SetHp(int newhp);

    //Getters for unit stats
    int GetHp() const;
    int GetDmgMulti() const;
    std::basic_string<char> getName() const;

    sf::Texture texture;
    sf::Sprite sprite;
private:
    //Stats of the Units
    int hp;
    int dmgmulti;
    std::string name;

};


#endif //TBG_UNIT_H
