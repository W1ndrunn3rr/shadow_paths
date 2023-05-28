
#ifndef SHADOW_PATHS_MERCHANT_H
#define SHADOW_PATHS_MERCHANT_H

#include "Entity.h"


//! Klasa reprezentuje handlarza
class Merchant {
 int weaponGoldRequired;
 int armorGoldRequired;
 int potionGoldRequired;
 int shardsRequired;
 Player &player;
public:
    //!Konstruktor bazowy
    explicit Merchant(Player &p);
    //!Metoda ulepsza łuk, poprzez zwiększenie poziomu łuku klasy Player
    void upgradeWeapon();
    //!Metoda ulepsza zbroję, poprzez zwiększenie poziomu zbroi klasy Player
    void upgradeArmor();
    //!Metoda zwiększa ilość mikstur klasy Player, w zamian za złoto
    void buyPotion();
    //!Metoda zwiększa poziom mikstur klasy Player, w zamian za odłamki
    void upgradePotion();
    //!Metoda zwraca ilość złota potrzebną do ulepszenia łuku
    int getBowGoldRequired() const;
//!Metoda zwraca ilość złota potrzebną do ulepszenia zbroi
    int getArmorGoldRequired() const;

};


#endif //SHADOW_PATHS_MERCHANT_H
