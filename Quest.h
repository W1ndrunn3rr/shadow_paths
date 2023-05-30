#ifndef SHADOW_PATHS_QUEST_H
#define SHADOW_PATHS_QUEST_H

#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include<ctime>
#include "Entity.h"
#include "SFML/Graphics.hpp"

//! Status stoczonej walki
enum battleFought {
    WON,
    LOST
};

//! Rodzaj bossa
enum BossType {
    BANSHEE,
    GOBLIN_KING,
    ABYSSAL_WATCHERS,
    CLEARED
};

//! Typ przeciwnika
enum EnemyType {
    MOB,
    BOSS
};

//!Klasa reprezentująca zadania i po części zarządzająca nagrodami
class Quest {
    int goldAmount;
    int expAmount;
    int duration = 0;
    std::string questName;
    std::string questContent;
    Player &player;
    battleFought state;
    BossType type;
    EnemyType eType;

    //!Metoda generuje zadania spośród czterech możliwych
    void generateQuest();

    //!Metoda zakańcza zadanie i zależnie od wyniku walki modyfikuje ilości złota i doświadczenia gracza
    void finishQuest(const std::string& fight);

    //!Metoda uaktualnia zadanie
    void updateQuest();

public:
    //!Konstruktor
    explicit Quest(Player &player);


    //! Metoda zwraca nazwę zadania
    std::string getQuestName();

//! Metoda zwraca treść zadania
    std::string getQuestContent();

    //!Metoda zarządza zadaniem
    void handleQuest();


    //!Metoda zarządza walką z bossem
    void handleDungeonFight();

//! Metoda zwraca ilość złota za zadanie
    int getGoldAmount() const;


//! Metoda zwraca ilość doświadczenia za zadanie
    int getExpAmount() const;

//! Metoda zwraca czas zadania
    int getDuration() const;

//! Metoda zwraca status zadania
    int getStatus() const;

//! Metoda zwraca rodzaj bossa
    BossType getBoss() const;

//! Metoda zwraca rodzaj przeciwnika
    EnemyType getEnemy() const;
};


#endif