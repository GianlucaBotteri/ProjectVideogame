#ifndef PROJECTVIDEOGAME_HERO_H
#define PROJECTVIDEOGAME_HERO_H

#include <string>
#include <list>
#include "Subject.h"
#include "Character.h"

class Hero : public Character, public Subject {
public:

    Hero(int lifeP, int strngth, int energy, std::string name, int mon, int lvl, int exp) :
            Character(lifeP, strngth, energy), name(name), money(mon), heroLevel(lvl), exp(exp) {
        rect.setSize(sf::Vector2f(64, 64));
        rect.setPosition(150, 0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 64, 0, 64, 64));
    }

    ~Hero() { }

    void useWeapon(sf::RenderWindow& window);

    /*
    int levelUp();

    virtual void useWeapon(Character &tmpEnemy);

    virtual void useSpecial(Character &tmpEnemy);

    virtual void useScroll(Character &tmpEnemy);

    */

    void update();

    void moveSprite(const int* level);

    bool collidesUp(const int* level);

    bool collidesDown(const int* level);

    bool collidesLeft(const int* level);

    bool collidesRight(const int* level);

    bool checkCollision(int tile);

    virtual void subscribe(Observer* o) override;
    virtual void unsubscribe(Observer* o) override;
    virtual void notify(sf::Sprite& heartsSprite) override;


    bool outOfbounds(Direction direction);


    int getMoney() const {
        return money;
    }

    void setMoney(int money) {
        Hero::money = money;
    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Hero::name = name;
    }

    int getHeroLevel() const {
        return heroLevel;
    }

    void setHeroLevel(int heroLevel) {
        Hero::heroLevel = heroLevel;
    }

    int getExp() const {
        return exp;
    }

    void setExp(int exp) {
        Hero::exp = exp;
    }

    Direction getDirection() const {
        return direction;
    }

    void setDirection(Direction direction) {
        Hero::direction = direction;
    }


    bool isHasSword() const {
        return hasSword;
    }

    void setHasSword(bool hasSword) {
        Hero::hasSword = hasSword;
    }

private:
    std::string name;
    int money, heroLevel, exp;
    bool hasSword = false;
    int maxCounter = 2;
    std::list <Observer*> observers;
};

#endif //PROJECTVIDEOGAME_HERO_H
