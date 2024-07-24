#include "../lib/CombatController.h"
#include "../lib/Boss.h"
#include <random>

CombatController::CombatController(Player &p, GameView &view, Quest &quest)
    : player(p), quest(quest), view(view) {
  tourCounter = 0;
  difficultMultiplier = 1;
}

// Metodę razem z widokiem tworzyłem z użyciem chatu GPT (animacja lecącej
// strzały)
void CombatController::mobFight(Enemy &enemy, sf::RenderWindow &window,
                                BossType type) {
  // inicjacja początkowego czas lotu
  sf::Event event;
  while (window.pollEvent(event)) { // dodatkowa pętla ,żeby nie wyrzucało
                                    // komunikatu o braku odpowiedzi w programie
  }
  float deltaTime = 0.0f;
  while (!enemy.isDead() && !player.isDead()) {
    // inicjacja punktu początkowego
    float initialPosX = 250.0f;
    // sleepy dodane w celach zwiększenia czytelności
    sf::sleep(sf::seconds(1));
    if (!player.isDead()) {
      view.drawPlayerAttack(window, deltaTime, initialPosX, enemy, type);
      enemy.takeDamage(player.dealDamage());
      view.drawFight(enemy, window, type, 1);
      view.drawPlayerDamagePoints(window, enemy, type);
    }
    sf::sleep(sf::seconds(1));
    view.drawMonsterAttack(window, enemy, quest.getBoss());
    player.takeDamage(enemy.dealDamage());
    view.drawFight(enemy, window, type, 1);
    view.drawEnemyDamagePoints(window, enemy, type);
    sf::sleep(sf::seconds(1));
    if (player.getCurrentHealth() <= player.getMaxHealth() * 0.3 &&
        player.getPotions() >= 1 &&
        player.getMaxHealth() >=
            player.getCurrentHealth() + (10 * player.getPotionsLevel()) &&
        !player.isDead()) {
      view.drawPotionDrink(window, enemy, quest.getBoss());
      player.usePotion();
      view.drawFight(enemy, window, type, 1);
    }
  }
  tourCounter++;
}

void CombatController::questEnemyChoose(sf::RenderWindow &window,
                                        BossType type) {
  if (player.getLevel() > 5 && quest.getBoss() == BANSHEE) {
    difficultMultiplier = 2;
  } else if (player.getLevel() > 9 && quest.getBoss() == GOBLIN_KING) {
    difficultMultiplier = 2;
  } else {
    difficultMultiplier = 1;
  }
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> enemyNumber(1, 4);
  int caseNumber = int(enemyNumber(rng));
  if (caseNumber == 1) {
    Enemy darkRider(2, 25, "Dark Rider", 15 * difficultMultiplier,
                    9 * difficultMultiplier, player, 1, 2);
    mobFight(darkRider, window, type);
    return;
  }
  if (caseNumber == 2) {
    Enemy caveGoblin(1, 20, "Cave Goblin", 25 * difficultMultiplier,
                     20 * difficultMultiplier, player, 5, 5);
    mobFight(caveGoblin, window, type);
    return;
  }
  if (caseNumber == 3) {
    Enemy mountainTroll(2, 40, "Mountain Troll", 9 * difficultMultiplier,
                        7 * difficultMultiplier, player, 0,
                        0); // do modyfikacji (armor typu float)
    mobFight(mountainTroll, window, type);
    return;
  }
  if (caseNumber == 4) {
    Enemy twilightAssassin(2, 25, "Twilight Assassin", 20 * difficultMultiplier,
                           15 * difficultMultiplier, player, 4, 4);
    mobFight(twilightAssassin, window, type);
  }
}

void CombatController::bossFight(Boss &boss, sf::RenderWindow &window,
                                 BossType type) {
  sf::Event event;
  while (window.pollEvent(event)) {
  }
  int baseArmor = player.getArmor();
  float intPosX = 250.0f;
  float deltaTime = 0.0f;
  while (!boss.isDead() && !player.isDead()) {
    tourCounter++;
    sf::sleep(sf::seconds(1));
    view.drawPlayerAttack(window, deltaTime, intPosX, boss, type);
    boss.takeDamage(player.dealDamage());
    view.drawFight(boss, window, type, 1);
    view.drawPlayerDamagePoints(window, boss, type);
    sf::sleep(sf::seconds(1));
    if ((tourCounter % 3 == 0 && !boss.isDead() &&
         (type == BANSHEE || type == GOBLIN_KING)) ||
        (tourCounter % 5 == 0 && !boss.isDead() && type == ABYSSAL_WATCHERS)) {
      view.drawBossAbility(window, boss, type);
      boss.useAbility();
      view.drawFight(boss, window, type, 1);
      view.drawEnemyDamagePoints(window, boss, type);
      sf::sleep((sf::seconds((0.5f))));
    }
    view.drawMonsterAttack(window, boss, quest.getBoss());
    player.takeDamage(boss.dealDamage());
    view.drawFight(boss, window, type, 1);
    view.drawEnemyDamagePoints(window, boss, type);
    if (player.getCurrentHealth() <= player.getMaxHealth() * 0.3 &&
        player.getPotions() >= 1 &&
        player.getMaxHealth() >=
            player.getCurrentHealth() + (10 * player.getPotionsLevel()) &&
        !player.isDead()) {
      sf::sleep(sf::seconds(1));
      player.usePotion();
      view.drawPotionDrink(window, boss, type);
    }
  }
  player.setArmor(baseArmor);
}

void CombatController::bossChoice(sf::RenderWindow &window, BossType type) {
  if (type == BANSHEE) {
    Banshee banshee(5, 50, "Banshee", 55, 45, player, 5, 5);
    bossFight(banshee, window, type);
  } else if (type == GOBLIN_KING) {
    GoblinKing king(7, 100, "Goblin King", 50, 40, player, 20, 20);
    bossFight(king, window, type);
  } else if (type == ABYSSAL_WATCHERS) {
    AbyssalWatchers watchers(5, 40, "Abyssal Watchers", 100, 75, player, 5, 49);
    bossFight(watchers, window, type);
  }
}
