
#include "../lib/Boss.h"

__attribute__((unused)) void Boss::useAbility() {}

Boss::Boss(int arm, int maxHP, const std::string &name, int max, int min,
           Player &player, int criticalChance, int dex)
    : Enemy(arm, maxHP, name, max, min, player, criticalChance, dex),
      player(player) {
  armor = arm;
  maxHealth = maxHP;
  mobName = name;
  maxDamage = max;
  baseDamage = min;
  currentHealth = maxHP;
  luck = criticalChance;
  dexterity = dex;
}

Banshee::Banshee(int arm, int maxHP, const std::string &name, int max, int min,
                 Player &player, int criticalChance, int dex)
    : Boss(arm, maxHP, name, max, min, player, criticalChance, dex) {

  maxDamage = max + player.getArmor();
  baseDamage = min + player.getArmor();
}

void Banshee::useAbility() {
  player.takeDamage(player.getArmor() * player.getArmor());
}

GoblinKing::GoblinKing(int arm, int maxHP, const std::string &name, int max,
                       int min, Player &player, int criticalChance, int dex)
    : Boss(arm, maxHP, name, max, min, player, criticalChance, dex) {}

void GoblinKing::useAbility() {
  player.takeDamage(player.getGold() * player.getArmor());
  if (player.getGold() / 2 > 0)
    player.gainGold(player.getGold() / 2);
}

AbyssalWatchers::AbyssalWatchers(int arm, int maxHP, const std::string &name,
                                 int max, int min, Player &player,
                                 int criticalChance, int dex)
    : Boss(arm, maxHP, name, max, min, player, criticalChance, dex) {}

void AbyssalWatchers::useAbility() {
  player.takeDamage(player.getCurrentHealth() * 1000);
}
