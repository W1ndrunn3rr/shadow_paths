#include <SFML/Graphics.hpp>
#include "GameController.h"
#include "CombatController.h"

//Funkcja zoptymalizowana przy pomocy chatu GPT
void GameController::handleGameEvent(sf::Event &event, sf::RenderWindow &window) {
    if (event.type == sf::Event::MouseButtonReleased) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            isMouseClicked = false;
        }
    }

    mousePosition = sf::Mouse::getPosition(window);

    if (event.type == sf::Event::MouseButtonPressed && !isMouseClicked) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (status == MENU) {
                if (mousePosition.x > 550 && mousePosition.x < 770 && mousePosition.y > 280 && mousePosition.y < 407)
                    status = IN_GAME;
                else if (mousePosition.x > 450 && mousePosition.x < 828 && mousePosition.y > 425 &&
                         mousePosition.y < 547)
                    status = HTP;
                else if (mousePosition.x > 550 && mousePosition.x < 728 && mousePosition.y > 580 &&
                         mousePosition.y < 671)
                    status = EXIT;
            } else if (status == HTP && mousePosition.x > 1138 && mousePosition.x < 1242 && mousePosition.y > 650 &&
                       mousePosition.y < 780) {
                player.levelUp();
                status = MENU;
            } else if (status == IN_GAME) {
                if (mousePosition.x > 55 && mousePosition.x < 347) {
                    if (mousePosition.y > 162 && mousePosition.y < 262)
                        location = BONFIRE;
                    else if (mousePosition.y > 292 && mousePosition.y < 392) {
                        location = BLACKSMITH;
                        questLocation = NOT_IN_QUEST;
                    } else if (mousePosition.y > 422 && mousePosition.y < 522) {
                        location = ALCHEMIST;
                        questLocation = NOT_IN_QUEST;
                    } else if (mousePosition.y > 652 && mousePosition.y < 752) {
                        questLocation = NOT_IN_QUEST;
                        location = DUNGEON;
                    } else if (mousePosition.y > 549 && mousePosition.y < 649) {
                        location = CHARACTER;
                        questLocation = NOT_IN_QUEST;
                    }
                }

                if (mousePosition.x > 325 && mousePosition.x < 378 && mousePosition.y > 72 && mousePosition.y < 139) {
                    status = MENU;
                    location = BONFIRE;
                }

                if (location == BLACKSMITH) {
                    if (mousePosition.x > 470 && mousePosition.x < 639 && mousePosition.y > 468 &&
                        mousePosition.y < 629) {
                        merchant.upgradeArmor();
                        isMouseClicked = true;
                    }
                    if (mousePosition.x > 1018 && mousePosition.x < 1194 && mousePosition.y > 457 &&
                        mousePosition.y < 628) {
                        merchant.upgradeWeapon();
                        isMouseClicked = true;
                    }
                }

                if (location == ALCHEMIST) {
                    if (mousePosition.x > 470 && mousePosition.x < 639 && mousePosition.y > 468 &&
                        mousePosition.y < 629) {
                        merchant.buyPotion();
                        isMouseClicked = true;
                    }
                    if (mousePosition.x > 1018 && mousePosition.x < 1194 && mousePosition.y > 457 &&
                        mousePosition.y < 628) {
                        merchant.upgradePotion();
                        isMouseClicked = true;
                    }
                }

                if (location == BONFIRE && mousePosition.x > 909 && mousePosition.x < 1280 && mousePosition.y > 219 &&
                    mousePosition.y < 668) {
                    questLocation = CHOICE;
                }

                if (location == DUNGEON && mousePosition.x > 773 && mousePosition.x < 894 && mousePosition.y > 649 &&
                    mousePosition.y < 762 && dgStatus == NOT_IN_DUNGEON) {
                    dgStatus = IN_DUNGEON;
                }

                if (location == DUNGEON && dgStatus == DUNGEON_COMPLETED && mousePosition.x > 595 &&
                    mousePosition.x < 688 &&
                    mousePosition.y > 525 && mousePosition.y < 618)
                    dgStatus = NOT_IN_DUNGEON;

                if (questLocation == CHOICE) {
                    if (mousePosition.x > 393 && mousePosition.x < 444 && mousePosition.y > 534 &&
                        mousePosition.y < 586) {
                        questLocation = NOT_IN_QUEST;
                    }
                    if (mousePosition.x > 1142 && mousePosition.x < 1280 && mousePosition.y > 734 &&
                        mousePosition.y < 800) {
                        questLocation = IN_QUEST;
                    }
                } else if (questLocation == COMPLETED && mousePosition.x > 595 && mousePosition.x < 688 &&
                           mousePosition.y > 525 && mousePosition.y < 618) {
                    questLocation = NOT_IN_QUEST;
                }
            }
        }
    }
}


GameController::GameController(Player &player, Merchant &merchant, GameView &view, Quest &quest) : player(player),
                                                                                                   merchant(merchant),
                                                                                                   view(view),
                                                                                                   quest(quest) {
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
            if (questLocation == NOT_IN_QUEST)
                view.drawNPC(window);
            else if (questLocation == CHOICE) {
                view.drawNpcBar(window);
                view.drawQuestText(window);
            } else if (questLocation == IN_QUEST) {
                view.drawQuest(window);
                CombatController combat(player, view, quest);
                combat.questEnemyChoose(window, quest.getBoss());
                quest.handleQuest();
                questLocation = COMPLETED;
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


        if (location == BONFIRE) {
            view.drawFirePlace(window);
            if (questLocation == NOT_IN_QUEST)
                view.drawNPC(window);
            else if (questLocation == CHOICE) {
                view.drawNpcBar(window);
                view.drawQuestText(window);
            } else if (questLocation == IN_QUEST) {
                view.drawQuest(window);
                CombatController combat(player, view, quest);
                combat.questEnemyChoose(window, quest.getBoss());
                quest.handleQuest();
                questLocation = COMPLETED;
            } else if (questLocation == COMPLETED) {
                view.drawAfterFightCom(window);
            }
        }

        if (location == DUNGEON) {
            if (dgStatus == NOT_IN_DUNGEON) {
                view.drawDungeon(window);
            } else if (dgStatus == IN_DUNGEON) {
                CombatController combat(player, view, quest);
                combat.bossChoice(window, quest.getBoss());
                quest.handleDungeonFight();
                view.drawAfterFightCom(window);
                dgStatus = DUNGEON_COMPLETED;
            } else if (dgStatus == DUNGEON_COMPLETED) {
                view.drawAfterFightCom(window);
            }
        }
    }

}





