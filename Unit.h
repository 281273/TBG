#ifndef TBG_UNIT_H
#define TBG_UNIT_H

#include <iostream>
#include <string>
#include <vector>


#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"

using namespace std;

class Unit {
public:
    float hp;
    float dmgmulti;
    string name;

    sf::Texture texture;
    sf::Sprite sprite;

    void LoadTexture(const string& filename);
    virtual void Init();
//    virtual void SetStats(int typenum);
    void draw(sf::RenderWindow& window) const;

    float SetHp(float newhp);
    float GetHp() const;
    float GetDmgMulti() const;
    const string &getName() const;

    Unit(const string& filename);
    ~Unit();

private:

};


#endif //TBG_UNIT_H
