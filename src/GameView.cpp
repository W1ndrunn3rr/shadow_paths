#include "../lib/GameView.h"

void GameView::drawMenu(sf::RenderWindow &window) {
  setMenuFont(window);
  sf::Sprite Menu(menu);
  window.draw(Menu);
  window.draw(playButton);
  window.draw(optionButton);
  window.draw(exitButton);
  window.draw(title);
}

void GameView::drawHowToPlay(sf::RenderWindow &window) {
  sf::Sprite howToPlay(WTTG);
  howToPlay.setPosition(0, 0);
  window.draw(howToPlay);
}

void GameView::setMenuFont(sf::RenderWindow &window) {
  mousePosition = sf::Mouse::getPosition(window);
  playButton.setFont(font);
  playButton.setCharacterSize(100);
  playButton.setFillColor(sf::Color::White);
  playButton.setString("Play");
  playButton.setPosition(550, 280);
  if (mousePosition.x > 550 && mousePosition.x < 770 && mousePosition.y > 280 &&
      mousePosition.y < 407)
    playButton.setFillColor(sf::Color{0, 128, 0});

  optionButton.setFont(font);
  optionButton.setCharacterSize(100);
  optionButton.setFillColor(sf::Color::White);
  optionButton.setString("How to play");
  optionButton.setPosition(375, 425);
  if (mousePosition.x > 450 && mousePosition.x < 828 && mousePosition.y > 425 &&
      mousePosition.y < 547)
    optionButton.setFillColor(sf::Color{128, 128, 0});

  exitButton.setFont(font);
  exitButton.setCharacterSize(90);
  exitButton.setFillColor(sf::Color::White);
  exitButton.setString("Exit");
  exitButton.setPosition(550, 580);
  if (mousePosition.x > 550 && mousePosition.x < 728 && mousePosition.y > 580 &&
      mousePosition.y < 671)
    exitButton.setFillColor(sf::Color{128, 0, 0});

  title.setFont(font);
  title.setCharacterSize(150);
  title.setFillColor(sf::Color{128, 0, 128});
  title.setString("Shadow Paths");
  title.setPosition(110, 50);
}

GameView::GameView(Quest &quest, Player &player, Merchant &merchant,
                   Music &music)
    : player(player), merchant(merchant), quest(quest), music(music) {
  if (!menu.loadFromFile("../Assets/menuBackground.jpeg"))
    std::cout << "ERROR_1";
  if (!font.loadFromFile("../Assets/font.ttf"))
    std::cout << "ERROR_2";
  if (!firePlace.loadFromFile("../Assets/fireplace.jpeg"))
    std::cout << "ERROR_3";
  if (!leftBar.loadFromFile("../Assets/leftBar.jpeg"))
    std::cout << "ERROR_4";
  if (!background.loadFromFile("../Assets/background.jpg"))
    std::cout << "ERROR_5";
  if (!blackSmith.loadFromFile("../Assets/blacksmith.jpeg"))
    std::cout << "ERROR_6";
  if (!alchemistTexture.loadFromFile("../Assets/alchemist.jpg"))
    std::cout << "ERROR_7";
  if (!characterP.loadFromFile("../Assets/character.jpg"))
    std::cout << "ERROR_8";
  if (!NPC.loadFromFile("../Assets/NPC.png"))
    std::cout << "ERROR_9";
  if (!NPCBar.loadFromFile("../Assets/bar1.png"))
    std::cout << "ERROR_10";
  if (!QuestTheme.loadFromFile("../Assets/Quest.jpeg"))
    std::cout << "ERROR_11";
  if (!afterFightScreen.loadFromFile("../Assets/paper.png"))
    std::cout << "ERROR_12";
  if (!WTTG.loadFromFile("../Assets/wttg.jpg"))
    std::cout << "ERROR_13";
  if (!hourGlass.loadFromFile("../Assets/hourglass.png"))
    std::cout << "ERROR_14";
  if (!banshee.loadFromFile("../Assets/banshee.jpg"))
    std::cout << "ERROR_15";
  if (!goblinKing.loadFromFile("../Assets/goblinKIng.jpg"))
    std::cout << "ERROR_16";
  if (!abyssalWatchers.loadFromFile("../Assets/abyssalWatchers.jpg"))
    std::cout << "ERROR_17";
  if (!font.loadFromFile("../Assets/font.ttf"))
    std::cout << "ERROR_18";
  if (!bansheeFightScreen.loadFromFile("../Assets/bansheeFight.jpg"))
    std::cout << "ERROR_19";
  if (!kingFightScreen.loadFromFile("../Assets/kingFight.jpg"))
    std::cout << "ERROR_20";
  if (!watchersFightScreen.loadFromFile("../Assets/watchersFight.jpg"))
    std::cout << "ERROR_21";
  if (!playerHealthBar.loadFromFile("../Assets/HPBAR.png"))
    std::cout << "ERROR_22";
  if (!enemyHealthBar.loadFromFile("../Assets/HPBAR.png"))
    std::cout << "ERROR_23";
  if (!darkRider.loadFromFile("../Assets/darkRider.jpg"))
    std::cout << "ERROR_24";
  if (!caveGoblin.loadFromFile("../Assets/caveGoblin.jpg"))
    std::cout << "ERROR_25";
  if (!mountainTroll.loadFromFile("../Assets/mountainTroll.jpg"))
    std::cout << "ERROR_26";
  if (!twilightAssassin.loadFromFile("../Assets/twilightAssassin.jpg"))
    std::cout << "ERROR_27";
  if (!attackTexture.loadFromFile("../Assets/attack.png"))
    std::cout << "ERROR_28";
  if (!blood.loadFromFile("../Assets/blood.png"))
    std::cout << "ERROR_30";
  if (!monsterAttackTexture.loadFromFile("../Assets/claw.png"))
    std::cout << "ERROR_31";
  if (!potion.loadFromFile("../Assets/potion.png"))
    std::cout << "ERROR_32";
  if (!bansheeSkill.loadFromFile("../Assets/bansheeSkill.png"))
    std::cout << "ERROR_33";
  if (!kingSkill.loadFromFile("../Assets/kingAttack.png"))
    std::cout << "ERROR_34";
  if (!watchersSkill.loadFromFile("../Assets/watchersSkill.png"))
    std::cout << "ERROR_35";
  if (!font.loadFromFile("../Assets/font.ttf"))
    std::cout << "ERROR_36";
  if (!bansheeFight.loadFromFile("../Assets/bansheeFight.jpg"))
    std::cout << "ERROR_37";
  if (!kingFight.loadFromFile("../Assets/kingFight.jpg"))
    std::cout << "ERROR_38";
  if (!watchersFight.loadFromFile("../Assets/watchersFight.jpg"))
    std::cout << "ERROR_39";
  if (!playerHealthBar.loadFromFile("../Assets/HPBAR.png"))
    std::cout << "ERROR_40";
  if (!enemyHealthBar.loadFromFile("../Assets/HPBAR.png"))
    std::cout << "ERROR_41";
  if (!darkRider.loadFromFile("../Assets/darkRider.jpg"))
    std::cout << "ERROR_42";
  if (!caveGoblin.loadFromFile("../Assets/caveGoblin.jpg"))
    std::cout << "ERROR_43";
  if (!mountainTroll.loadFromFile("../Assets/mountainTroll.jpg"))
    std::cout << "ERROR_44";
  if (!twilightAssassin.loadFromFile("../Assets/twilightAssassin.jpg"))
    std::cout << "ERROR_45";
  if (!attackTexture.loadFromFile("../Assets/attack.png"))
    std::cout << "ERROR_46";
  if (!blood.loadFromFile("../Assets/blood.png"))
    std::cout << "ERROR_47";
  if (!monsterAttackTexture.loadFromFile("../Assets/claw.png"))
    std::cout << "ERROR_48";
  if (!potion.loadFromFile("../Assets/potion.png"))
    std::cout << "ERROR_49";
  if (!bansheeSkill.loadFromFile("../Assets/bansheeSkill.png"))
    std::cout << "ERROR_50";
  if (!kingSkill.loadFromFile("../Assets/kingAttack.png"))
    std::cout << "ERROR_51";
  if (!watchersSkill.loadFromFile("../Assets/watchersSkill.png"))
    std::cout << "ERROR_52";
  if (!dungeonBackground.loadFromFile("../Assets/dungeonBackground.jpg"))
    std::cout << "ERROR_53";
}

void GameView::drawFirePlace(sf::RenderWindow &window) {
  sf::Sprite firePit(firePlace);
  firePit.setPosition(384, -300);
  window.draw(firePit);
}

void GameView::drawLeftBar(sf::RenderWindow &window) {
  sf::Sprite bar(leftBar);
  bar.setPosition(40, 150);
  bar.setScale(0.2, 0.12);
  for (int i = 0; i < 5; i++) {
    bar.setPosition(40, float(150 + i * 130));
    window.draw(bar);
  }
  setGameFont(window);
  window.draw(fire);
  window.draw(blacksmith);
  window.draw(alchemist);
  window.draw(character);
  window.draw(dungeon);
  window.draw(coins);
  window.draw(level);
}

void GameView::drawBackground(sf::RenderWindow &window) {
  sf::Sprite bcg(background);
  bcg.setPosition(0, 0);
  window.draw(bcg);
}

void GameView::setGameFont(sf::RenderWindow &window) {
  mousePosition = sf::Mouse::getPosition(window);
  fire.setFont(font);
  fire.setCharacterSize(50);
  fire.setFillColor(sf::Color::White);
  fire.setString("Bonfire");
  fire.setPosition(110, 180);
  if (mousePosition.x > 55 && mousePosition.x < 347 && mousePosition.y > 162 &&
      mousePosition.y < 262)
    fire.setFillColor(sf::Color{128, 0, 128});

  blacksmith.setFont(font);
  blacksmith.setCharacterSize(50);
  blacksmith.setFillColor(sf::Color::White);
  blacksmith.setString("Blacksmith");
  blacksmith.setPosition(60, 310);
  if (mousePosition.x > 55 && mousePosition.x < 347 && mousePosition.y > 292 &&
      mousePosition.y < 392)
    blacksmith.setFillColor(sf::Color{128, 0, 128});

  alchemist.setFont(font);
  alchemist.setCharacterSize(50);
  alchemist.setFillColor(sf::Color::White);
  alchemist.setString("Alchemist");
  alchemist.setPosition(70, 440);
  if (mousePosition.x > 55 && mousePosition.x < 347 && mousePosition.y > 422 &&
      mousePosition.y < 522)
    alchemist.setFillColor(sf::Color{128, 0, 128});

  character.setFont(font);
  character.setCharacterSize(50);
  character.setFillColor(sf::Color::White);
  character.setString("Character");
  character.setPosition(75, 570);
  if (mousePosition.x > 55 && mousePosition.x < 347 && mousePosition.y > 552 &&
      mousePosition.y < 652)
    character.setFillColor(sf::Color{128, 0, 128});

  dungeon.setFont(font);
  dungeon.setCharacterSize(50);
  dungeon.setFillColor(sf::Color::White);
  dungeon.setString("Dungeon");
  dungeon.setPosition(85, 700);
  if (mousePosition.x > 55 && mousePosition.x < 347 && mousePosition.y > 682 &&
      mousePosition.y < 782)
    dungeon.setFillColor(sf::Color{128, 0, 128});

  coins.setFont(font);
  coins.setCharacterSize(30);
  coins.setFillColor(sf::Color::White);
  coins.setString(std::to_string(player.getGold()));
  coins.setPosition(210, 15);

  level.setFont(font);
  level.setCharacterSize(30);
  level.setFillColor(sf::Color::White);
  level.setString(std::to_string(player.getLevel()));
  level.setPosition(210, 85);
}

void GameView::drawBlackSmith(sf::RenderWindow &window) {
  sf::Sprite bcS(blackSmith);
  bcS.setPosition(384, 0);
  window.draw(bcS);

  bSword.setFont(font);
  bSword.setCharacterSize(30);
  bSword.setFillColor(sf::Color::White);
  bSword.setString("Bow level: " + std::to_string(player.getWeaponLevel()));
  bSword.setPosition(950, 650);

  bsGold.setFont(font);
  bsGold.setCharacterSize(30);
  bsGold.setFillColor(sf::Color::White);
  if (player.getWeaponLevel() < 5)
    bsGold.setString("Gold required: " +
                     std::to_string(merchant.getBowGoldRequired()));

  bsGold.setPosition(950, 700);
  if (player.getGold() >= merchant.getBowGoldRequired() &&
      player.getWeaponLevel() < 5)
    bsGold.setFillColor(sf::Color::Green);
  else
    bsGold.setFillColor(sf::Color::Red);

  bArmor.setFont(font);
  bArmor.setCharacterSize(30);
  bArmor.setFillColor(sf::Color::White);
  bArmor.setString("Armor level: " + std::to_string(player.getArmorLevel()));
  bArmor.setPosition({440, 650});

  baGold.setFont(font);
  baGold.setCharacterSize(30);
  baGold.setFillColor(sf::Color::White);
  if (player.getArmorLevel() < 5)
    baGold.setString("Gold required: " +
                     std::to_string(merchant.getArmorGoldRequired()));
  baGold.setPosition(440, 700);
  if (player.getGold() >= merchant.getArmorGoldRequired() &&
      player.getArmorLevel() < 5)
    baGold.setFillColor(sf::Color::Green);
  else
    baGold.setFillColor(sf::Color::Red);

  window.draw(bSword);
  window.draw(bsGold);
  window.draw(bArmor);
  window.draw(baGold);
}

void GameView::drawAlchemist(sf::RenderWindow &window) {
  sf::Sprite alchemistSprite(alchemistTexture);
  alchemistSprite.setPosition(384, 0);
  window.draw(alchemistSprite);

  aPotion.setFont(font);
  aPotion.setCharacterSize(30);
  aPotion.setFillColor(sf::Color::White);
  aPotion.setString("Max potions: " +
                    std::to_string(1 * player.getPotionsLevel()));
  aPotion.setPosition(950, 650);

  apGold.setFont(font);
  apGold.setCharacterSize(30);
  apGold.setFillColor(sf::Color::White);
  apGold.setString("Shards required: " +
                   std::to_string(player.getPotionsLevel()));
  apGold.setPosition(950, 700);
  if (player.getShards() >= player.getPotionsLevel())
    apGold.setFillColor(sf::Color::Green);
  else
    apGold.setFillColor(sf::Color::Red);

  aUpgrade.setFont(font);
  aUpgrade.setCharacterSize(30);
  aUpgrade.setFillColor(sf::Color::White);
  aUpgrade.setString("Potions : " + std::to_string(player.getPotions()));
  aUpgrade.setPosition({440, 650});

  auGold.setFont(font);
  auGold.setCharacterSize(30);
  auGold.setFillColor(sf::Color::White);
  auGold.setString("Gold required: 5");
  auGold.setPosition(440, 700);
  if (player.getGold() >= 5 && player.getPotionsLevel() > player.getPotions())
    auGold.setFillColor(sf::Color::Green);
  else
    auGold.setFillColor(sf::Color::Red);

  window.draw(aPotion);
  window.draw(apGold);
  window.draw(aUpgrade);
  window.draw(auGold);
}

void GameView::drawCharacter(sf::RenderWindow &window) {
  sf::Sprite characterSprite(characterP);
  characterSprite.setPosition(384, 0);

  stats1.setFont(font);
  stats1.setCharacterSize(30);
  stats1.setFillColor(sf::Color::White);
  stats1.setString(
      "Health : " + std::to_string(player.getCurrentHealth()) + "\n\n" +
      "Armor: " + std::to_string(player.getArmor()) +
      "                               "
      "\n\n" +
      "Damage: " + std::to_string(player.getMinDamage()) + "-" +
      std::to_string(player.getMaxDamage()) + "~(" +
      std::to_string((player.getMaxDamage() + player.getMinDamage()) / 2) +
      ")" +
      "\n\n"
      "Sword level: " +
      std::to_string(player.getWeaponLevel()));

  stats2.setFont(font);
  stats2.setCharacterSize(30);
  stats2.setFillColor(sf::Color::White);
  stats2.setString(
      "Experience points: " + std::to_string(player.getExperiencePoints()) +
      "\n\n" + "Shards: " + std::to_string(player.getShards()) + "\n\n" +
      "Potions: " + std::to_string(player.getPotions()) +
      "\n\n"
      "Armor level: " +
      std::to_string(player.getArmorLevel()));

  stats1.setPosition(460, 450);
  stats2.setPosition(825, 450);

  window.draw(characterSprite);
  window.draw(stats1);
  window.draw(stats2);
}

void GameView::drawNPC(sf::RenderWindow &window) {
  sf::Sprite npc(NPC);
  npc.setPosition(800, 200);
  npc.setScale(0.6, 0.6);
  window.draw(npc);
}

void GameView::drawNpcBar(sf::RenderWindow &window) {
  sf::Sprite npcBar(NPCBar);
  npcBar.setPosition(240, 166);
  npcBar.setScale(0.7, 0.7);
  window.draw(npcBar);
}

void GameView::drawQuestText(sf::RenderWindow &window) {
  questOne.setFont(font);
  questOne.setCharacterSize(17);
  questOne.setFillColor(sf::Color::White);
  questOne.setString(
      quest.getQuestName() + '\n' + '\n' + quest.getQuestContent() + "\n" +
      "Gold: " + std::to_string(quest.getGoldAmount()) + "        " +
      "Experience: " + std::to_string(quest.getExpAmount()));
  questOne.setPosition(399, 598);
  window.draw(questOne);
}

// Funkcja napisana za pomocą chatu GPT
void GameView::drawQuest(sf::RenderWindow &window) {
  float angle = 2;
  sf::Sprite questBackground(QuestTheme), hrGlass(hourGlass);
  sf::Time countdownTime = sf::seconds(
      float(quest.getDuration())); // do zmiany na quest.getDuration();
  sf::Text countdownText("", font, 70);
  countdownText.setFillColor(sf::Color::White);
  countdownText.setPosition(425, 600);
  hrGlass.setOrigin((sf::Vector2f)hourGlass.getSize() / 2.f);
  hrGlass.setPosition(640, 400);
  sf::Clock clock;
  while (countdownTime.asSeconds() >= 0) {
    sf::Time elapsed = clock.restart();
    countdownTime -= elapsed;

    int remainingSeconds = static_cast<int>(countdownTime.asSeconds());
    std::string countdownString =
        "Time left: " + std::to_string(remainingSeconds);
    countdownText.setString(countdownString);
    window.clear();
    window.draw(questBackground);
    window.draw(countdownText);
    window.draw(hrGlass);
    window.display();
    hrGlass.rotate(angle);
  }
}

void GameView::drawAfterFightCom(sf::RenderWindow &window) {
  sf::Sprite afterFSC(afterFightScreen);
  afterFSC.setPosition(0, 0);

  afterFightCom.setFont(font);
  afterFightCom.setCharacterSize(20);
  afterFightCom.setFillColor(sf::Color::Black);
  if (quest.getStatus() == LOST) {
    afterFightCom.setString("Your efforts have been in vain, \n"
                            "and in the face of danger,\n"
                            " we have lost the battle. \n"
                            "We must gather our strength\n"
                            " and devise a new strategy \n"
                            "to overcome our adversaries. \n"
                            "\n                    - 10 gold");
    afterFightCom.setPosition(490, 204);
  } else if (quest.getStatus() == WON && quest.getEnemy() == BOSS) {
    afterFightCom.setString(
        "Your heroic deeds have yielded the desired \n"
        " outcome! We have emerged victorious in \n"
        "our quest,and our success will be \n"
        "recorded in the chronicles. We are proud\n"
        " of your courage and determination!\n"
        "\n You gain: \n\n 100 gold \n\n 100 experience points \n\n " +
        std::to_string(1 * quest.getBoss()) + "  " + "shards");
    afterFightCom.setPosition(412, 204);
  } else if (quest.getEnemy() == MOB && quest.getStatus() == WON) {
    afterFightCom.setString("Your heroic deeds have yielded the desired \n"
                            " outcome! We have emerged victorious in \n"
                            "our quest,and our success will be \n"
                            "recorded in the chronicles. We are proud\n"
                            " of-You gain: \n\n" +
                            std::to_string(quest.getGoldAmount()) + " gold" +
                            "\n\n" + std::to_string(quest.getExpAmount()) +
                            " experience points");
    afterFightCom.setPosition(412, 204);
  }

  window.draw(afterFSC);
  window.draw(afterFightCom);
}

void GameView::drawDungeon(sf::RenderWindow &window) {
  sf::Sprite bansheeSprite(banshee), kingSprite(goblinKing),
      watchersSprite(abyssalWatchers), backgroundSprite(dungeonBackground);
  bansheeSprite.setPosition(384, 0);
  kingSprite.setPosition(384, 0);
  watchersSprite.setPosition(384, 0);
  backgroundSprite.setPosition(384, 0);
  if (quest.getBoss() == BANSHEE) {
    window.draw(bansheeSprite);
  } else if (quest.getBoss() == GOBLIN_KING) {
    window.draw(kingSprite);
  } else if (quest.getBoss() == ABYSSAL_WATCHERS) {
    window.draw(watchersSprite);
  } else if (quest.getBoss() == CLEARED)
    window.draw(backgroundSprite);
}

// Funkcja wyświetla tło walki (portrety, statystyki, oraz pasek zdrowia)
void GameView::drawFight(Enemy &enemy, sf::RenderWindow &window, BossType type,
                         int mode) {
  if (mode == 1)
    window.clear();

  unsigned int enemyChoice, playerChoice;
  sf::Sprite fightOne(bansheeFight), fightTwo(kingFight),
      fightThree(watchersFight);

  // Statystyki gracza
  playerStats.setFont(font);
  playerStats.setCharacterSize(30);
  playerStats.setFillColor(sf::Color::White);
  playerStats.setString(
      "          " + std::to_string(player.getCurrentHealth()) + "/" +
      std::to_string(player.getMaxHealth()) + "\n\n" + "DAMAGE : " +
      std::to_string((player.getMinDamage() + player.getMaxDamage()) / 2) +
      "\n\n" + "ARMOR: " + std::to_string(player.getArmor()) + "\n\n" +
      "DEXTERITY: " + std::to_string(player.getDexterity()) + "\n\n" +
      "LUCK: " + std::to_string(player.getLuck()));
  playerStats.setPosition(230, 462);

  // Statystyki przeciwnika
  enemyStats.setFont(font);
  enemyStats.setCharacterSize(30);
  enemyStats.setFillColor(sf::Color::White);
  enemyStats.setString(
      "          " + std::to_string(enemy.getCurrentHealth()) + "/" +
      std::to_string(enemy.getMaxHealth()) + "\n\n" + "DAMAGE : " +
      std::to_string((enemy.getMinDamage() + enemy.getMaxDamage()) / 2) +
      "\n\n" + "ARMOR: " + std::to_string(enemy.getArmor()) +
      "\n\n"
      "DEXTERITY: " +
      std::to_string(enemy.getDexterity()) + "\n\n" +
      "LUCK: " + std::to_string(enemy.getLuck()));
  enemyStats.setPosition(825, 462);

  // Wyświetlanie pasków zdrowia
  sf::RectangleShape enemyHPBar(sf::Vector2f(236, 69.16));
  enemyHPBar.setPosition(825, 440);
  enemyHPBar.setTexture(&enemyHealthBar);
  sf::Vector2u enemyBarSize = enemyHealthBar.getSize();

  enemyBarSize.y /= 6;

  sf::RectangleShape playerHPBar(sf::Vector2f(236, 69.16));
  playerHPBar.setPosition(225, 440);
  playerHPBar.setTexture(&playerHealthBar);
  sf::Vector2u playerBarSize = playerHealthBar.getSize();
  playerBarSize.y /= 6;

  // Wybór bossa
  if (type == BANSHEE) {
    window.draw(fightOne);
  } else if (type == GOBLIN_KING) {
    window.draw(fightTwo);
  } else if (type == ABYSSAL_WATCHERS) {
    window.draw(fightThree);
  }

  // Wyświetlanie pasków zdrowia (zoptymalizowane przy pomocy chatu GPT)
  float enemyHealthRatio = static_cast<float>(enemy.getCurrentHealth()) /
                           float(enemy.getMaxHealth());
  float playerHealthRatio = static_cast<float>(player.getCurrentHealth()) /
                            float(player.getMaxHealth());

  if ((enemyHealthRatio >= 0.0 && enemyHealthRatio < 0.16) ||
      enemyHealthRatio < 0)
    enemyChoice = 0;
  else if (enemyHealthRatio < 0.32)
    enemyChoice = 1;
  else if (enemyHealthRatio < 0.48)
    enemyChoice = 2;
  else if (enemyHealthRatio < 0.64)
    enemyChoice = 3;
  else if (enemyHealthRatio < 0.80)
    enemyChoice = 4;
  else
    enemyChoice = 5;

  if ((playerHealthRatio >= 0.0 && playerHealthRatio < 0.16) ||
      playerHealthRatio < 0)
    playerChoice = 0;
  else if (playerHealthRatio < 0.32)
    playerChoice = 1;
  else if (playerHealthRatio < 0.48)
    playerChoice = 2;
  else if (playerHealthRatio < 0.64)
    playerChoice = 3;
  else if (playerHealthRatio < 0.80)
    playerChoice = 4;
  else
    playerChoice = 5;

  enemyHPBar.setTextureRect(sf::IntRect(
      0, static_cast<int>(2 + enemyBarSize.y * enemyChoice),
      static_cast<int>(enemyBarSize.x), static_cast<int>(enemyBarSize.y)));
  playerHPBar.setTextureRect(sf::IntRect(
      0, static_cast<int>(2 + playerBarSize.y * playerChoice),
      static_cast<int>(enemyBarSize.x), static_cast<int>(enemyBarSize.y)));

  // Wybór przeciwnika
  if (enemy.getName() == "Dark Rider") {
    sf::Sprite dRider(darkRider);
    dRider.setPosition(0, 0);
    window.draw(dRider);
  }
  if (enemy.getName() == "Cave Goblin") {
    sf::Sprite cGoblin(caveGoblin);
    cGoblin.setPosition(0, 0);
    window.draw(cGoblin);
  }
  if (enemy.getName() == "Mountain Troll") {
    sf::Sprite mTroll(mountainTroll);
    mTroll.setPosition(0, 0);
    window.draw(mTroll);
  }
  if (enemy.getName() == "Twilight Assassin") {
    sf::Sprite tAssassin(twilightAssassin);
    tAssassin.setTexture(twilightAssassin);
    tAssassin.setPosition(0, 0);
    window.draw(tAssassin);
  }
  // Wyświetlanie sprite'ów
  window.draw(enemyHPBar);
  window.draw(playerHPBar);
  window.draw(playerStats);
  window.draw(enemyStats);
  if (mode == 1)
    window.display();
}

// Funkcja napisana za pomocą Chatu GPT -obsługa animacji ataku gracza (strzały)
// i wyświetlanie na ekranie
void GameView::drawPlayerAttack(sf::RenderWindow &window, float deltaTime,
                                float initialPosX, Enemy &enemy,
                                BossType type) {

  sf::Sprite attackSprite(attackTexture), bloodSprite(blood);
  attackSprite.setPosition(initialPosX, 236.0f);
  bloodSprite.setPosition(896, 216);

  // Obsługa animacji strzały
  float speed = 700.0f;
  float targetX = 640.0f;
  bool reachedTarget = false;
  sf::Clock clock;
  music.playArrow();
  while (!reachedTarget) {
    float movement = speed * deltaTime;
    attackSprite.move(movement, 0);
    window.clear();
    drawFight(enemy, window, type, 2);
    // Wyświetlanie animacji ataku metodą clear & display
    if (!player.isDead()) {
      window.draw(attackSprite);
      if (attackSprite.getPosition().x >= targetX) {
        reachedTarget = true;
        for (int i = 0; i <= 255; i += 15) {
          window.clear();
          drawFight(enemy, window, type, 2);
          if (i != 255) {
            music.playBlood();
            window.draw(attackSprite);
            window.draw(bloodSprite);
          }
          attackSprite.setColor(sf::Color(255, 255, 255, 255 - i));
          bloodSprite.setColor(sf::Color(255, 255, 255, 255 - i));
          window.display();
          sf::sleep(sf::milliseconds(10));
          window.draw(bloodSprite);
        }
      }
      window.display();

      deltaTime = clock.restart().asSeconds();
    }
  }
}

void GameView::drawEnemyDamagePoints(sf::RenderWindow &window, Enemy &enemy,
                                     BossType type) {

  // Obrażenia przeciwnika
  if (!enemy.isDead()) {
    window.clear();
    enemyDamage.setFont(font);
    enemyDamage.setCharacterSize(40);
    enemyDamage.setFillColor(sf::Color::Red);
    enemyDamage.setPosition(320, 190);
    enemyDamage.setString(std::to_string(player.getDamageDone()));
    drawFight(enemy, window, type, 2);
    window.draw(enemyDamage);
    window.display();
  }
}

void GameView::drawPlayerDamagePoints(sf::RenderWindow &window, Enemy &enemy,
                                      BossType type) {
  if (!player.isDead()) {
    window.clear();
    // Obrażenia gracza
    playerDamage.setFont(font);
    playerDamage.setCharacterSize(40);
    playerDamage.setFillColor(sf::Color::Red);
    playerDamage.setPosition(940, 190);
    playerDamage.setString(std::to_string(enemy.getDamageDone()));
    drawFight(enemy, window, type, 2);
    window.draw(playerDamage);
    window.display();
  }
}

// Funkcja wyświetla animacje ataku wroga (pazury)
void GameView::drawMonsterAttack(sf::RenderWindow &window, Enemy &enemy,
                                 BossType type) {
  sf::Sprite monsterAttack(monsterAttackTexture);
  monsterAttack.setPosition(230, 130);

  // Obsługa animacji (również metoda clear & draw)
  if (!enemy.isDead() && !player.isDead()) {
    for (int i = 0; i <= 250; i += 10) {
      window.clear();
      drawFight(enemy, window, type, 2);
      music.playMonsterAttack();
      if (i != 250) {
        window.draw(monsterAttack);
      }
      monsterAttack.setColor(sf::Color(255, 255, 255, 255 - i));
      window.display();
      sf::sleep(sf::milliseconds(10));
    }
  }
}

void GameView::drawPotionDrink(sf::RenderWindow &window, Enemy &enemy,
                               BossType type) {
  sf::Sprite hpPotion(potion);
  hpPotion.setPosition(380, 120);
  potionHealth.setFont(font);
  potionHealth.setCharacterSize(40);
  potionHealth.setFillColor(sf::Color::Green);
  potionHealth.setPosition(350, 150);
  potionHealth.setString('+' + std::to_string((10)));
  // Obsługa animacji
  if (!player.isDead()) {
    for (int i = 0; i <= 255; i += 15) {
      window.clear();
      drawFight(enemy, window, type, 2);
      if (i != 255) {
        window.draw(hpPotion);
        window.draw(potionHealth);
      }
      hpPotion.setColor(sf::Color(255, 255, 255, sf::Uint8(255 - i)));
      potionHealth.setFillColor(sf::Color(0, 255, 0, sf::Uint8(255 - i)));
      hpPotion.rotate(float(-i) / 110);
      window.display();
      sf::sleep(sf::milliseconds(20));
    }
  }
}

void GameView::drawBossAbility(sf::RenderWindow &window, Boss &boss,
                               BossType type) {

  sf::Sprite bansheeSkillSprite(bansheeSkill);
  bansheeSkillSprite.setPosition(685, 10);

  sf::Sprite kingSkillSprite(kingSkill);
  kingSkillSprite.setPosition(175, -5);

  sf::Sprite watchersSkillSprite(watchersSkill);
  watchersSkillSprite.setPosition(575, 500);
  watchersSkillSprite.setScale(1.5, 1.5);
  watchersSkillSprite.setOrigin((sf::Vector2f)watchersSkill.getSize() / 2.f);

  bossDamage.setFont(font);
  bossDamage.setCharacterSize(40);
  bossDamage.setFillColor(sf::Color::Red);
  bossDamage.setPosition(320, 190);

  if (type == BANSHEE)
    bossDamage.setString(
        std::to_string(player.getGold() / 2 * player.getArmor()));
  if (type == GOBLIN_KING)
    bossDamage.setString(
        std::to_string(player.getGold() / 2 * player.getArmor()));
  if (type == ABYSSAL_WATCHERS)
    bossDamage.setString(std::to_string(player.getCurrentHealth() * 1000));

  // Obsługa animacji
  if (!player.isDead()) {
    for (int i = 0; i <= 255; i += 5) {
      window.clear();
      drawFight(boss, window, type, 2);
      if (i != 255) {
        if (type == BANSHEE) {
          music.playBanshee();
          window.draw(bansheeSkillSprite);
        } else if (type == GOBLIN_KING) {
          music.playGoblinKing();
          window.draw(kingSkillSprite);
        } else if (type == ABYSSAL_WATCHERS) {
          music.playAbyssalWatchers();
          window.draw(watchersSkillSprite);
        }
        window.draw(bossDamage);
        bansheeSkillSprite.setColor(sf::Color(255, 255, 255, 255 - i));
        kingSkillSprite.setColor(sf::Color(255, 255, 255, 255 - i));
        watchersSkillSprite.setColor(sf::Color(255, 255, 255, 255 - i));
        bossDamage.setFillColor(sf::Color(255, 0, 0, 255 - i));
        watchersSkillSprite.rotate(1);
        window.display();
        sf::sleep(sf::milliseconds(20));
      }
    }
  }
}
