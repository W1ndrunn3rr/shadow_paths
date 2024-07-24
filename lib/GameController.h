#ifndef SHADOW_PATHS_GAMECONTROLLER_H
#define SHADOW_PATHS_GAMECONTROLLER_H

#include "Merchant.h"
#include "Entity.h"
#include "GameView.h"
#include "Quest.h"
#include "Music.h"
//! Enum pozycyjny do sprawdzania pozycji kursora w menu poprzez getterach
enum MenuMousePosition {
    PLAY_POSITION,
    HOW_TO_PLAY_POSITION,
    HOW_TO_PLAY_EXIT_POSITION,
    EXIT_POSITION,
    DEFAULT_POSITION
};

//! Enum pozycyjny do sprawdzania pozycji kursora w grze poprzez gettery
enum InGameMenuMousePosition{
    BONFIRE_POSITION,
    BLACKSMITH_POSITION,
    ALCHEMIST_POSITION,
    CHARACTER_POSITION,
    DUNGEON_POSITION,
    DEFAULT_IN_GAME_POSITION,
    EXIT_IN_GAME_POSITION
};

//! Enum pozycyjny do sprawdzania pozycji kursora na ekranie kowala
enum BlacksmithMousePosition{
    ARMOR_UPGRADE_POSITION,
    WEAPON_UPGRADE_POSITION,
    DEFAULT_BLACKSMITH_POSITION
};

//! Enum pozycyjny do sprawdzania pozycji kursora na ekranie alchemistki
enum AlchemistMousePosition{
    POTION_BUY_POSITION,
    POTION_UPGRADE_POSITION,
    DEFAULT_ALCHEMIST_POSITION
};

//! Enum pozycyjny do sprawdzania pozycji NPC i wyboru zadania
enum NPCMousePosition{
    CHOOSE_POSITION,
    CLOSE_POSITION,
    ACCEPT_POSITION,
    NPC_DEFAULT_POSITION
};

//! Enum pozycyjny do sprawdzenia pozycji na ekranie lochów
enum DungeonPosition{
    DUNGEON_FIGHT_POSITION,
    DUNGEON_LEFT_POSITION,
    DUNGEON_DEFAULT_POSITION
};

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
    Music &music;
    bool isMouseClicked; //pomocniczy bool do eventów SFMLa

public:
    //!Konstruktor
    GameController(Player &player, Merchant &merchant, GameView &view, Quest &quest,Music &music);

    //!Obsługa zdarzeń w trakcie gry
    void handleGameEvent(sf::Event &event, sf::RenderWindow &window);

    //!Obsługa widoku gry i ekranu
    void manageGameView(sf::RenderWindow &window);

    //! Getter pozycji w menu
    MenuMousePosition getMenuMousePosition() const;
    //! Getter pozycji w grze
    InGameMenuMousePosition getInGameMenuMousePosition() const;
    //! Getter pozycji na ekranie kowala
    BlacksmithMousePosition getBlacksmithMousePosition() const;
    //! Getter pozycji na ekranie alchemistki
    AlchemistMousePosition getAlchemistMousePosition() const;
    //! Getter pozycji na ekranie NPC i zadania
    NPCMousePosition getNPCMousePosition() const;
    //! Getter pozycji na ekranie zadania
    DungeonPosition getDungeonMousePosition() const;

};


#endif //SHADOW_PATHS_GAMECONTROLLER_H
