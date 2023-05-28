//
// Created by omen on 28.04.23.
//

#ifndef SHADOW_PATHS_GAMECONTROLLER_H
#define SHADOW_PATHS_GAMECONTROLLER_H

#include "Merchant.h"
#include "Entity.h"
#include "GameView.h"
#include "Quest.h"

//!Status gry
enum GameStatus {
    MENU,
    IN_GAME,
    HTP,
    EXIT,
};

//!Lokacja w grze
enum GameLocation {
    BONFIRE,
    BLACKSMITH,
    ALCHEMIST,
    CHARACTER,
    DUNGEON,
};

//!Stan zadania (questa)
enum QuestLocation {
    NOT_IN_QUEST,
    CHOICE,
    IN_QUEST,
    COMPLETED
};

//! Status lokalizacji lochów
enum DungeonStatus {
    IN_DUNGEON,
    NOT_IN_DUNGEON,
    DUNGEON_COMPLETED
};

//! Klasa kontrolująca grę
class GameController {

    GameLocation location;
    GameStatus status;
    QuestLocation questLocation;
    DungeonStatus dgStatus;
    sf::Vector2i mousePosition;
    Player &player;
    Merchant &merchant;
    GameView &view;
    Quest &quest;
    bool isMouseClicked; //pomocniczy bool do eventów SFMLa

public:
    //!Konstruktor
    GameController(Player &player, Merchant &merchant, GameView &view, Quest &quest);

    //!Obsługa zdarzeń w trakcie gry
    void handleGameEvent(sf::Event &event, sf::RenderWindow &window);

    //!Obsługa widoku gry i ekranu
    void manageGameView(sf::RenderWindow &window);

};


#endif //SHADOW_PATHS_GAMECONTROLLER_H
