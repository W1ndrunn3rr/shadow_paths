#ifndef SHADOW_PATHS_ENTITY_H
#define SHADOW_PATHS_ENTITY_H

#include <string>


//! Klasa opisuje postać gracza i jego statystyki
class Player {
    int potionsAmount;
    int shardsAmount;
    int weaponLevel;
    int armorLevel;
    int goldAmount;
    int potionLevel;
    int level;
    int experiencePoints;
protected:
    int damage;
    int baseDamage;
    int maxDamage;
    int armor;
    int maxHealth;
    int currentHealth;
    int luck;
    int dexterity;
    int previousHealth;
public:
    //!Konstruktor bazowy
    Player();

 //!Metoda zwraca poziom gracza
    int getLevel() const;
    //!Metoda zwraca złoto gracza
    int getGold() const;
    //!Metoda zwraca poziom broni gracza
    int getWeaponLevel() const;
    //!Metoda zwraca poziom pancerza gracza
    int getArmorLevel() const;
    //!Metoda zwraca ilość mikstur gracza
    int getPotions() const;
    //!Metoda zwraca ilość odłamków gracza
    int getShards() const;
    //!Metoda zwraca poziom mikstur gracza
    int getPotionsLevel() const;
    //!Metoda zwraca obecny poziom zdrowia gracza
    int getCurrentHealth() const;
    //!Metoda zwraca ilość punktów doświadczenia gracza
    int getExperiencePoints() const;
    //!Metoda zwraca minimalną ilość obrażeń gracza
    int getMinDamage() const;
    //!Metoda zwraca maksymalną ilość obrażeń gracza
    int getMaxDamage() const;
    //!Metoda zwraca wartość pancerza gracza
    int getArmor() const;
    //!Metoda zwraca maksymalne zdrowie gracza
    int getMaxHealth() const;
    //!Metoda zwraca ilość zręczności gracza
    int getDexterity() const;
    //!Metoda zwraca ilość szczęścia gracza
    int getLuck() const;
    //!Metoda zwraca otrzymane obrażenia przez gracza
    int getDamageDone() const;
    //!Modyfikacja ilości zdrowia
    void takeDamage(int damagePoints);
    //!Metoda zwraca ilość obrażeń
    int dealDamage();
    //!Metoda zwiększa poziom gracza
    void levelUp();
    //!Metoda zarządza ilością mikstur
    void getPotion();
    //!Metoda zarządza poziomem ulepszenia mikstury
    void potionLevelUp();

    //!Metoda zwiększa poziom miecza
    void weaponLevelUp();

    //!Metoda zwiększa poziom pancerza
    void armorLevelUp();

    //!Metoda zwiększa ilość złota o pewną ilość
    void gainGold(int gold);

    //!Metoda zwiększa ilość doświadczenia postaci
    void gainExp(int exp);

    //!Metoda zwiększa ilość odłamków o zadaną ilość
    void gainShard(int shard);

    //!Metoda używa miksturę, przywracając zdrowie
    void usePotion();

    //!Metoda aktualizuje statystyki gracza
    void setStats();

    //!Metoda modyfikuje pancerz gracza
    void setArmor(int armorPoints);

    //!Metoda sprawdza, czy postać żyje
    bool isDead() const;


};

//!Dziedziczna klasa, klasy Player - opisuje przeciwników
class Enemy : public Player {
protected:
    std::string mobName;
public:
    //!Konstruktor klasy Enemy
    Enemy(int arm, int maxHP, std::string name, int max, int min, Player &player, int criticalChance, int dex);

    //!Metoda zwraca nazwę przeciwnika
    std::string getName();


};

#endif //SHADOW_PATHS_ENTITY_H
