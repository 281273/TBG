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
//    A constructor
    explicit Unit(const std::string& filename);
//    A destructor
    virtual ~Unit();

//    Function "LoadTexture" takes one argument and loads the texture file with the corresponding name
//    @param file a const std::string argument
    void LoadTexture(const std::string& filename);

//    Function "Init" sets textures and their position for units (overriten in child classes)
    virtual void Init();

//    Function "draw" takes one argument and uses it as a target for drawing (for example in window)
//    @param window a sf::RenderWindow& argument.
    void draw(sf::RenderWindow& window) const;

//    Function "SetHp" takes one argument and uses it to set it's value as aa updated hp stat
//    @param newhp an int argument
//    @returns updated hp value
    int SetHp(int newhp);

//    Function "GetHp"
//    @returns current hp value
    int GetHp() const;

//    Function "GetDmgMulti"
//    @returns current dmgmulti value
    int GetDmgMulti() const;

//    Function "getName"
//    @returns current name value
    std::basic_string<char> getName() const;

//    sf::Texture variable
//    responsible for containing the texture
    sf::Texture texture;

//    sf::Sprite variable
//    responsible for containing the sprite
    sf::Sprite sprite;
private:
//    int variable
//    containing current hp value. Used to for example : to check if unit is dead
    int hp;

//    int variable
//    containing current dmgmultivv value. Used to calculate dmg dealt to enemy unit
    int dmgmulti;

//    std::string variable
//    containing current name value. Used to display unit type/name for the player
    std::string name;

};


#endif //TBG_UNIT_H
