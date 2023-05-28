#ifndef SHADOW_PATHS_BOSS_H
#define SHADOW_PATHS_BOSS_H

#include "Entity.h"

//!Klasa dziedziczna po klasie Enemy i jej pochodne (reprezentacja Bossów)
class Boss : public Enemy {
protected:
    Player &player;
public:
    Boss(int arm, int maxHP, const std::string& name, int max, int min, Player &player, int criticalChance, int dex);

    //!Funkcja wirtualna umożliwia użycie umiejętności indywidualnej dla każdego bossa
    //Funkcja jest nieużywana (zmiana zaproponowana przez CLiona :) )
    __attribute__((unused)) virtual void useAbility();

};

class Banshee : public Boss {
public:
    Banshee(int arm, int maxHP, const std::string& name, int max, int min, Player &player, int criticalChance, int dex);

    void useAbility() override;
};

class GoblinKing : public Boss {
public:
    GoblinKing(int arm, int maxHP, const std::string& name, int max, int min, Player &player, int criticalChance, int dex);

    void useAbility() override;
};

class AbyssalWatchers : public Boss {
public:
    AbyssalWatchers(int arm, int maxHP, const std::string& name, int max, int min, Player &player, int criticalChance, int dex);

    void useAbility() override;
};

#endif //SHADOW_PATHS_BOSS_H
