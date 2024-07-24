#include "../lib/Merchant.h"

Merchant::Merchant(Player &p) : player(p) {
  weaponGoldRequired = 25;
  armorGoldRequired = 25;
  potionGoldRequired = 5;
  shardsRequired = player.getPotionsLevel();
}

void Merchant::upgradeWeapon() {
  if (player.getGold() >= weaponGoldRequired && player.getWeaponLevel() < 5) {
    player.weaponLevelUp();
    player.gainGold(-weaponGoldRequired);
    weaponGoldRequired = 25 + 25 * player.getWeaponLevel();
  }
}

void Merchant::upgradeArmor() {
  if (player.getGold() >= armorGoldRequired && player.getArmorLevel() < 5) {
    player.armorLevelUp();
    player.gainGold(-armorGoldRequired);
    armorGoldRequired = 25 + 25 * player.getArmorLevel();
  }
}

void Merchant::buyPotion() {
  if (player.getGold() >= potionGoldRequired &&
      (player.getPotions() < 1 * player.getPotionsLevel())) {
    player.getPotion();
    player.gainGold(-potionGoldRequired);
  }
}

void Merchant::upgradePotion() {
  if (player.getShards() >= shardsRequired) {
    player.potionLevelUp();
    player.gainShard(-shardsRequired);
    shardsRequired = player.getPotionsLevel();
  }
}

int Merchant::getBowGoldRequired() const { return weaponGoldRequired; }

int Merchant::getArmorGoldRequired() const { return armorGoldRequired; }
