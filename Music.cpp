#include <iostream>
#include "Music.h"

Music::Music() {
    if (!firePlace.openFromFile("/Shadow_Paths/WAVS/campfire.wav"))
        std::cout << "ERROR";
    firePlace.setLoop(true);
    firePlace.setVolume(200);

    if (!blacksmith.openFromFile("/Shadow_Paths/WAVS/blacksmith.wav"))
        std::cout << "ERROR";
    blacksmith.setLoop(true);
    blacksmith.setVolume(5);

    if (!alchemist.openFromFile("/Shadow_Paths/WAVS/alchemist.wav"))
        std::cout << "ERROR";
    alchemist.setLoop(true);
    alchemist.setVolume(5);

    if (!dungeon.openFromFile("/Shadow_Paths/WAVS/dungeon.wav"))
        std::cout << "ERROR";
    dungeon.setLoop(true);
    dungeon.setVolume(150);

    if (!sigh.openFromFile("/Shadow_Paths/WAVS/sigh.wav"))
        std::cout << "ERROR";

    if (!click.openFromFile("/Shadow_Paths/WAVS/click.wav"))
        std::cout << "ERROR";

    if (!clock.openFromFile("/Shadow_Paths/WAVS/clock.wav"))
        std::cout << "ERROR";

    clock.setVolume(25);

    if (!fight.openFromFile("/Shadow_Paths/WAVS/fight.wav"))
        std::cout << "ERROR";
    fight.setVolume(15);

    if (!afterFightCom.openFromFile("/Shadow_Paths/WAVS/afterFightCom.wav"))
        std::cout << "ERROR";
    afterFightCom.setVolume(25);

    if (!arrow.openFromFile("/Shadow_Paths/WAVS/Assets/arrow.wav"))
        std::cout << "ERROR";
    arrow.setVolume(50);

    if (!blood.openFromFile("/Shadow_Paths/WAVS/Assets/blood.wav"))
        std::cout << "ERROR";
    blood.setVolume(15);

    if (!monsterAttack.openFromFile("/Shadow_Paths/WAVS/Assets/monsterAttack.wav"))
        std::cout << "ERROR";

    if (!banshee.openFromFile("/Shadow_Paths/WAVS/banshee.wav"))
        std::cout << "ERROR";

    if (!goblinKing.openFromFile("/Shadow_Paths/WAVS/goblinKing.wav"))
        std::cout << "ERROR";

    if (!abyssalWatchers.openFromFile("/Shadow_Paths/WAVS/abyssalWatchers.wav"))
        std::cout << "ERROR";


}

void Music::playFirePlace() {
    playClick();
    clock.stop();
    afterFightCom.stop();
    blacksmith.stop();
    dungeon.stop();
    alchemist.stop();
    firePlace.play();
}

void Music::playBlacksmith() {
    playClick();
    firePlace.stop();
    alchemist.stop();
    dungeon.stop();
    blacksmith.play();

}

void Music::playAlchemist() {
    playClick();
    firePlace.stop();
    blacksmith.stop();
    dungeon.stop();
    alchemist.play();
}

void Music::playCharacter() {
    playClick();
    firePlace.stop();
    blacksmith.stop();
    alchemist.stop();
    dungeon.stop();
}

void Music::playDungeon() {
    playClick();
    sf::sleep(sf::seconds(0.1));
    click.stop();
    firePlace.stop();
    blacksmith.stop();
    alchemist.stop();
    dungeon.play();
}

void Music::playSigh() {
    playClick();
    sigh.play();
}

void Music::playClick() {
    click.stop();
    click.play();
    afterFightCom.stop();
}

void Music::playClock() {
    clock.stop();
    firePlace.stop();
    clock.play();
}

void Music::playFight() {
    dungeon.stop();
    clock.stop();
    fight.play();

}

void Music::playAfterFightCom() {
    fight.stop();
    afterFightCom.play();

}

void Music::playArrow() {
    blood.stop();
    banshee.stop();
    goblinKing.stop();
    abyssalWatchers.stop();
    arrow.play();
}

void Music::playBlood() {
    arrow.stop();
    blood.play();
}

void Music::playMonsterAttack() {
    monsterAttack.stop();
    monsterAttack.play();
}

void Music::playBanshee() {
    banshee.play();
}

void Music::playGoblinKing() {
    goblinKing.play();

}

void Music::playAbyssalWatchers() {
    abyssalWatchers.play();
}

