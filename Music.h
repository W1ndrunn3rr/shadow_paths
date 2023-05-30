#ifndef SHADOW_PATHS_MUSIC_H
#define SHADOW_PATHS_MUSIC_H

#include "SFML/Audio.hpp"

//! Klasa odpowiada za odtwarzanie dźwięków w czasie rozgrywki
class Music {
    sf::Music firePlace, blacksmith, alchemist, dungeon, sigh, click, clock, fight, afterFightCom
    , blood, arrow, monsterAttack, banshee, goblinKing, abyssalWatchers;
public:
    Music();

    //! Metoda odpowiada za odtwarzanie dźwięku ogniska
    void playFirePlace();

    //! Metoda odpowiada za odtwarzanie dźwięku kowala
    void playBlacksmith();

    //! Metoda odpowiada za odtwarzanie dźwięku alchemistki
    void playAlchemist();

    //! Metoda odpowiada za stopowanie dźwięku
    void playCharacter();

    //! Metoda odpowiada za odtwarzanie dźwięku lochów
    void playDungeon();

    //! Metoda odpowiada za odtwarzanie dźwięku westchnienia
    void playSigh();

    //! Metoda odpowiada za odtwarzanie dźwięku kliknięcia
    void playClick();

    //! Metoda odpowiada za odtwarzanie dźwięku zegara w czasie misji
    void playClock();

    //! Metoda odpowiada za odtwarzanie muzyki podczas walki
    void playFight();

    //! Metoda odpowiada za odtwarzanie dźwięku komunikatu po walce
    void playAfterFightCom();

    //! Metoda odpowiada za odtwarzanie dźwięku lecącej strzały
    void playArrow();

    //! Metoda odpowiada za odtwarzanie dźwięku krwi
    void playBlood();

    //! Metoda odpowiada za odtwarzanie dźwięku ataku potwora
    void playMonsterAttack();

    //! Metoda odpowiada za odtwarzanie dźwięku umiejętności bossa Banshee
    void playBanshee();

    //! Metoda odpowiada za odtwarzanie dźwięku umiejętności bossa Goblin King
    void playGoblinKing();

    //! Metoda odpowiada za odtwarzanie dźwięku umiejętności bossa Abyssal Watchers
    void playAbyssalWatchers();
};


#endif //SHADOW_PATHS_MUSIC_H
