#include "../lib/GameController.h"
#include "../lib/CombatController.h"
#include <SFML/Graphics.hpp>

// Funkcja zoptymalizowana przy pomocy chatu GPT
void GameController::handleGameEvent(sf::Event &event,
                                     sf::RenderWindow &window) {

  if (event.type == sf::Event::MouseButtonReleased) {
    if (event.mouseButton.button == sf::Mouse::Left) {
      isMouseClicked = false;
    }
  }
  mousePosition = sf::Mouse::getPosition(window);

  if (event.type == sf::Event::MouseButtonPressed && !isMouseClicked) {
    if (event.mouseButton.button == sf::Mouse::Left) {
      if (status == MENU) {
        if (getMenuMousePosition() == PLAY_POSITION) {
          music.playFirePlace();
          status = IN_GAME;
        } else if (getMenuMousePosition() == HOW_TO_PLAY_POSITION) {
          music.playClick();
          status = HTP;
        } else if (getMenuMousePosition() == EXIT_POSITION) {
          music.playClick();
          status = EXIT;
        }
      }

      if (status == HTP &&
          getMenuMousePosition() == HOW_TO_PLAY_EXIT_POSITION) {
        music.playClick();
        status = MENU;
      }
      if (status == IN_GAME) {
        if (getInGameMenuMousePosition() == BONFIRE_POSITION) {
          music.playFirePlace();
          location = BONFIRE;
        } else if (getInGameMenuMousePosition() == BLACKSMITH_POSITION) {
          location = BLACKSMITH;
          questLocation = NOT_IN_QUEST;
          music.playBlacksmith();
        } else if (getInGameMenuMousePosition() == ALCHEMIST_POSITION) {
          location = ALCHEMIST;
          questLocation = NOT_IN_QUEST;
          music.playAlchemist();
        } else if (getInGameMenuMousePosition() == DUNGEON_POSITION) {
          questLocation = NOT_IN_QUEST;
          location = DUNGEON;
          music.playDungeon();
        } else if (getInGameMenuMousePosition() == CHARACTER_POSITION) {
          location = CHARACTER;
          questLocation = NOT_IN_QUEST;
          music.playCharacter();
        } else if (getInGameMenuMousePosition() == EXIT_IN_GAME_POSITION) {
          music.playClick();
          music.playCharacter();
          status = MENU;
          location = BONFIRE;
        }

        if (location == BLACKSMITH) {

          if (getBlacksmithMousePosition() == ARMOR_UPGRADE_POSITION) {
            music.playClick();
            merchant.upgradeArmor();
            isMouseClicked = true;
          } else if (getBlacksmithMousePosition() == WEAPON_UPGRADE_POSITION) {
            music.playClick();
            merchant.upgradeWeapon();
            isMouseClicked = true;
          }

        } else if (location == ALCHEMIST) {
          if (getAlchemistMousePosition() == POTION_BUY_POSITION) {
            music.playClick();
            merchant.buyPotion();
            isMouseClicked = true;
          }
          if (getAlchemistMousePosition() == POTION_UPGRADE_POSITION) {
            music.playClick();
            merchant.upgradePotion();
            isMouseClicked = true;
          }
        }

        if (location == BONFIRE && getNPCMousePosition() == CHOOSE_POSITION &&
            quest.getBoss() != CLEARED) {
          questLocation = CHOICE;
          music.playSigh();
        }

        if (questLocation == CHOICE) {
          if (getNPCMousePosition() == CLOSE_POSITION) {
            music.playClick();
            questLocation = NOT_IN_QUEST;
          }

          if (getNPCMousePosition() == ACCEPT_POSITION) {
            music.playClick();
            questLocation = IN_QUEST;
          }
        } else if (questLocation == COMPLETED &&
                   getNPCMousePosition() == CLOSE_POSITION) {
          music.playClick();
          questLocation = NOT_IN_QUEST;
          music.playFirePlace();
        }

        if (location == DUNGEON &&
            getDungeonMousePosition() == DUNGEON_FIGHT_POSITION &&
            dgStatus == NOT_IN_DUNGEON && quest.getBoss() != CLEARED) {
          dgStatus = IN_DUNGEON;
          music.playClick();
        }

        if (location == DUNGEON && dgStatus == DUNGEON_COMPLETED &&
            getDungeonMousePosition() == DUNGEON_LEFT_POSITION) {
          music.playClick();
          dgStatus = NOT_IN_DUNGEON;
        }
      }
    }
  }
}

GameController::GameController(Player &player, Merchant &merchant,
                               GameView &view, Quest &quest, Music &music)
    : player(player), merchant(merchant), view(view), quest(quest),
      music(music) {
  questLocation = NOT_IN_QUEST;
  status = MENU;
  location = BONFIRE;
  dgStatus = NOT_IN_DUNGEON;
  isMouseClicked = false;
}

void GameController::manageGameView(sf::RenderWindow &window) {
  if (status == MENU)
    view.drawMenu(window);
  if (status == EXIT)
    window.close();
  if (status == HTP)
    view.drawHowToPlay(window);
  if (status == IN_GAME) {
    view.drawBackground(window);
    view.drawLeftBar(window);
    if (location == BONFIRE) {
      view.drawFirePlace(window);
      if (questLocation == NOT_IN_QUEST && quest.getBoss() != CLEARED)
        view.drawNPC(window);
      else if (questLocation == CHOICE) {
        view.drawNpcBar(window);
        view.drawQuestText(window);
      } else if (questLocation == IN_QUEST) {
        music.playClock();
        view.drawQuest(window);
        CombatController combat(player, view, quest);
        music.playFight();
        combat.questEnemyChoose(window, quest.getBoss());
        quest.handleQuest();
        questLocation = COMPLETED;
        music.playAfterFightCom();
      } else if (questLocation == COMPLETED) {
        view.drawAfterFightCom(window);
      }
    }

    if (location == BLACKSMITH)
      view.drawBlackSmith(window);

    if (location == ALCHEMIST)
      view.drawAlchemist(window);

    if (location == CHARACTER)
      view.drawCharacter(window);

    if (location == DUNGEON) {
      if (dgStatus == NOT_IN_DUNGEON) {
        view.drawDungeon(window);
      } else if (dgStatus == IN_DUNGEON) {
        CombatController combat(player, view, quest);
        music.playFight();
        combat.bossChoice(window, quest.getBoss());
        quest.handleDungeonFight();
        dgStatus = DUNGEON_COMPLETED;
        music.playAfterFightCom();
      } else if (dgStatus == DUNGEON_COMPLETED) {
        view.drawAfterFightCom(window);
      }
    }
  }
}

MenuMousePosition GameController::getMenuMousePosition() const {
  if (mousePosition.x > 550 && mousePosition.x < 770 && mousePosition.y > 280 &&
      mousePosition.y < 407)
    return PLAY_POSITION;
  else if (mousePosition.x > 450 && mousePosition.x < 828 &&
           mousePosition.y > 425 && mousePosition.y < 547)
    return HOW_TO_PLAY_POSITION;
  else if (mousePosition.x > 550 && mousePosition.x < 728 &&
           mousePosition.y > 580 && mousePosition.y < 671)
    return EXIT_POSITION;
  else if (mousePosition.x > 1138 && mousePosition.x < 1242 &&
           mousePosition.y > 650 && mousePosition.y < 780)
    return HOW_TO_PLAY_EXIT_POSITION;

  return DEFAULT_POSITION;
}

InGameMenuMousePosition GameController::getInGameMenuMousePosition() const {
  if (mousePosition.x > 55 && mousePosition.x < 347) {
    if (mousePosition.y > 162 && mousePosition.y < 262)
      return BONFIRE_POSITION;
    else if (mousePosition.y > 292 && mousePosition.y < 392)
      return BLACKSMITH_POSITION;
    else if (mousePosition.y > 422 && mousePosition.y < 522) {
      return ALCHEMIST_POSITION;
    } else if (mousePosition.y > 652 && mousePosition.y < 752) {
      return DUNGEON_POSITION;
    } else if (mousePosition.y > 549 && mousePosition.y < 649) {
      return CHARACTER_POSITION;
    } else if (mousePosition.x > 325 && mousePosition.x < 378 &&
               mousePosition.y > 72 && mousePosition.y < 139)
      return EXIT_IN_GAME_POSITION;
  }
  return DEFAULT_IN_GAME_POSITION;
}

BlacksmithMousePosition GameController::getBlacksmithMousePosition() const {
  if (mousePosition.x > 470 && mousePosition.x < 639 && mousePosition.y > 468 &&
      mousePosition.y < 629) {
    return ARMOR_UPGRADE_POSITION;
  } else if (mousePosition.x > 1018 && mousePosition.x < 1194 &&
             mousePosition.y > 457 && mousePosition.y < 628) {
    return WEAPON_UPGRADE_POSITION;
  }
  return DEFAULT_BLACKSMITH_POSITION;
}

AlchemistMousePosition GameController::getAlchemistMousePosition() const {
  if (mousePosition.x > 470 && mousePosition.x < 639 && mousePosition.y > 468 &&
      mousePosition.y < 629) {
    return POTION_BUY_POSITION;
  } else if (mousePosition.x > 1018 && mousePosition.x < 1194 &&
             mousePosition.y > 457 && mousePosition.y < 628) {
    return POTION_UPGRADE_POSITION;
  }
  return DEFAULT_ALCHEMIST_POSITION;
}

NPCMousePosition GameController::getNPCMousePosition() const {

  if (mousePosition.x > 909 && mousePosition.x < 1280 &&
      mousePosition.y > 219 && mousePosition.y < 668) {
    return CHOOSE_POSITION;
  } else if ((mousePosition.x > 393 && mousePosition.x < 444 &&
              mousePosition.y > 534 && mousePosition.y < 586) ||
             (mousePosition.x > 595 && mousePosition.x < 688 &&
              mousePosition.y > 525 && mousePosition.y < 618)) {
    return CLOSE_POSITION;
  } else if (mousePosition.x > 1142 && mousePosition.x < 1280 &&
             mousePosition.y > 734 && mousePosition.y < 800) {
    return ACCEPT_POSITION;
  }
  return NPC_DEFAULT_POSITION;
}

DungeonPosition GameController::getDungeonMousePosition() const {
  if (mousePosition.x > 773 && mousePosition.x < 894 && mousePosition.y > 649 &&
      mousePosition.y < 762) {
    return DUNGEON_FIGHT_POSITION;
  }

  if (mousePosition.x > 595 && mousePosition.x < 688 && mousePosition.y > 525 &&
      mousePosition.y < 618)
    return DUNGEON_LEFT_POSITION;

  return DUNGEON_DEFAULT_POSITION;
}
