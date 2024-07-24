#ifndef SHADOW_PATHS_COMBATCONTROLLER_H
#define SHADOW_PATHS_COMBATCONTROLLER_H
#include "Entity.h"
#include "Boss.h"
#include "GameView.h"
#include "SFML/Graphics.hpp"
#include "Quest.h"


//! Klasa służy do obsługi systemu walki
class CombatController {
    Player &player;
    Quest &quest;
    GameView &view;
    int tourCounter;
    int difficultMultiplier;

    //!Metoda obsługuje system walki i odpowiada za wyświetlanie jej przebiegu
    void mobFight(Enemy &enemy, sf::RenderWindow &window, BossType type);

    //!Metoda obsługuje system walki z bossem
    void bossFight(Boss &boss, sf::RenderWindow &window,BossType type);


public:
    //Konstruktor klasy CombatController
    explicit CombatController(Player &p, GameView &view, Quest &quest);

    //!Metoda służy do losowania i wyboru jednego z czterech przeciwników
    void questEnemyChoose(sf::RenderWindow &window,BossType type);

    //!Metoda służy do przydzielania odpowiedniego bossa, po pokonaniu poprzedniego
    void bossChoice(sf::RenderWindow &window, BossType type);

};


#endif //SHADOW_PATHS_COMBATCONTROLLER_H
