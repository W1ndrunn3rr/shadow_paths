#ifndef SHADOW_PATHS_GAMEVIEW_H
#define SHADOW_PATHS_GAMEVIEW_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Merchant.h"
#include "Quest.h"
#include "Boss.h"
#include "Music.h"

//! Klasa za pomocą której, wyświetlany jest ogólny widok gry
class GameView {
    sf::Font font;
    sf::Vector2i mousePosition;
    //Pomocnicza zmienna do odmierzania czasu
    sf::Time remainingTime;
    //Tekstury
    sf::Texture menu, firePlace, leftBar, background, blackSmith, alchemistTexture, characterP, NPC, NPCBar, QuestTheme, afterFightScreen,WTTG,hourGlass,
    banshee,goblinKing,abyssalWatchers,bansheeFightScreen,kingFightScreen,watchersFightScreen,darkRider, caveGoblin, mountainTroll, twilightAssassin, playerHealthBar, enemyHealthBar, bansheeFight
    , kingFight, watchersFight,attackTexture, blood,monsterAttackTexture,potion,bansheeSkill, kingSkill, watchersSkill,dungeonBackground;
    //Teksty wyświetlane na ekranie
    sf::Text title, playButton, optionButton, exitButton, fire, blacksmith, alchemist,
            coins, level, character, dungeon, stats1, stats2, bSword, bsGold, bArmor, baGold, aPotion, apGold, aUpgrade, auGold,
            questOne, duringQuest, afterFightCom,playerStats, enemyStats,playerDamage,enemyDamage,potionHealth, bossDamage;
    Player &player;
    Merchant &merchant;
    Quest &quest;
    Music &music;

    //!Metoda ustawia czcionki i teksty menu
    void setMenuFont(sf::RenderWindow &window);

public:
    //!Konstruktor klasy GameView
    GameView(Quest &quest, Player &player, Merchant &merchant,Music &music);
    //!Metoda odpowiada za wyświetlanie menu gry
    void drawMenu(sf::RenderWindow &window);

    //!Metoda odpowiada za wyświetlenie instrukcji do gry
    void drawHowToPlay(sf::RenderWindow &window);

    //!Metoda odpowiada za wyświetlanie paska wyboru w grze
    void drawLeftBar(sf::RenderWindow &window);

    //!Metoda odpowiada za wyświetlanie ogniska
    void drawFirePlace(sf::RenderWindow &window);

    //!Metoda odpowiada za wyświetlanie tła
    void drawBackground(sf::RenderWindow &window);

    //!Metoda ustawia czcionki i teksty w grze
    void setGameFont(sf::RenderWindow &window);

    //!Metoda odpowiada za wyświetlanie kowala
    void drawBlackSmith(sf::RenderWindow &window);

    //!Metoda odpowiada za wyświetlanie alchemistki
    void drawAlchemist(sf::RenderWindow &window);

    //!Metoda odpowiada za wyświetlanie postaci gracza i jej statystyk
    void drawCharacter(sf::RenderWindow &window);

    //!Metoda odpowiada za wyświetlanie postaci rycerza przy ognisku
    void drawNPC(sf::RenderWindow &window);

    //!Metoda odpowiada za wyświetlanie okna dialogowego z postacią
    void drawNpcBar(sf::RenderWindow &window);

    //!Metoda odpowiada za wyświetlanie nazwy zadania, jego treści, ilości złota i doświadczenia
    void drawQuestText(sf::RenderWindow &window);

    //!Metoda odpowiada za wyświetlanie tła zadania i licznika czasu
    void drawQuest(sf::RenderWindow &window);

    //!Metoda odpowiada za wyświetlanie komunikatu po walce
    void drawAfterFightCom(sf::RenderWindow &window);

    //!Metoda odpowiada za wyświetlanie widoku lochów
    void drawDungeon(sf::RenderWindow &window);

//! Metoda odpowiada za wyświetlanie i odświeżanie ekranu walki
    void drawFight(Enemy &enemy, sf::RenderWindow &window, BossType type,int mode);
//! Metoda odpowiada za wyświetlanie animacji ataku wroga
    void drawMonsterAttack(sf::RenderWindow &window, Enemy &enemy, BossType type);
//!Metoda odpowiada za animację picia mikstury
    void drawPotionDrink(sf::RenderWindow &window, Enemy &enemy, BossType type);
//! Metoda odpowiada za wyświetlanie animacji użycia umiejętności bossa
    void drawBossAbility(sf::RenderWindow &window, Boss &boss, BossType type);
//!Metoda odpowiada za animację i wyświetlanie ataku gracza
    //Napisane przy asyście chatu GPT
void drawPlayerAttack(sf::RenderWindow &window, float deltaTime, float initialPosX, Enemy &enemy, BossType type);
//! Metoda odpowiada za wyświetlanie ilości obrażeń otrzymanych przez przeciwnika
    void drawEnemyDamagePoints(sf::RenderWindow &window, Enemy &enemy,BossType type);

    //! Metoda opowiada za wyświetlanie ilości obrażeń otrzymanych przez gracza
    void drawPlayerDamagePoints(sf::RenderWindow &window, Enemy &enemy,BossType type);
};


#endif //SHADOW_PATHS_GAMEVIEW_H
