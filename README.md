# SHADOW PATHS

##  1.DESCRIPTION

**Shadow Paths** is inspired by the browser game Shakes & Fidget and falls within the idle RPG genre, reminiscent of the Dark Souls series. The game focuses on character creation and development through turn-based battles where the player only observes the action rather than directly participating.

The user can navigate through the game menu, which includes the following features:

- **Campfire**: Here, players can choose one of two tasks generated from a pool. These tasks involve waiting for a period (20 to 30 seconds) and then defeating an opponent. Upon completion, players receive experience points and gold, which are randomly generated within a specified range. Tasks are designed so that if one task awards more experience points, the other will provide more gold, and vice versa.

- **Smithy/Armory**: This area allows players to upgrade their weapons and armor.

- **Alchemist**: Players can purchase potions and enhance their levels.

- **Dungeons**: Players can face stronger opponents in the dungeons.

- **Character**: Here, players can view their character's statistics.

Players can spend their gold on upgrades or potion purchases. Additionally, crystals are a secondary currency earned by defeating enemies in the dungeons. Crystals can be exchanged for potion upgrades. 

The game is designed to scale with the player's level, meaning that as the player's level increases, so do the character's stats and the strength of enemies. The combat system is based on minimum and maximum damage values, with the actual damage dealt being randomly determined within this range. Actions alternate between the player and the opponent, with the player always going first. There is also a block value that reduces the amount of damage received. Enemies are randomly generated for each task.

Potions are used automatically during battles. If the player loses a battle, they are penalized by losing a portion of their gold.

## 2. REQUIREMENTS
- C++ compiler 
- SFML library
- CMake and make

To install SFML library on Linux, follow the instructions on the official website: https://www.sfml-dev.org/tutorials/2.5/start-linux.php

On windows you can install it following the instructions on the official website: https://www.sfml-dev.org/tutorials/2.5/start-vc.php and setting SFML in path :
```bash
C:\lib
```

If you are using a different path, you will need to change the path in the CMakeLists.txt file.

## 4.RUNNING THE GAME
To run the game, you need to compile the source code using CMake and make. Go to build directory and run the following commands:

```bash
cmake ..
make
./ShadowPaths
```
Hope you enjoy the game!

