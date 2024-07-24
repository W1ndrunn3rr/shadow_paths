#include "../lib/Entity.h"
#include <iostream>
#include <random>
#include <utility>

// Generator ilości obrażeń -Stackoverflow
int generateStat(int floor, int ceil) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> damage(floor, ceil);
  return int(damage(rng));
}

Player::Player() {
  damage = 0;
  level = 1;
  baseDamage = 5;
  maxDamage = 10;
  armor = 2;
  maxHealth = 35;
  currentHealth = maxHealth;
  potionsAmount = 1;
  potionLevel = 1;
  shardsAmount = 0;
  weaponLevel = 0;
  armorLevel = 0;
  goldAmount = 0;
  experiencePoints = 0;
  luck = 1;
  dexterity = 2;
  previousHealth = currentHealth;
}

void Player::takeDamage(int damagePoints) {
  previousHealth = currentHealth;
  if (generateStat(1 + dexterity, 100 - dexterity) == 50)
    return;
  else {
    previousHealth = currentHealth;
    currentHealth -= (damagePoints / armor);
  }
}

int Player::dealDamage() {
  if (!isDead()) {
    if (generateStat(luck, 100 - luck) == 50)
      damage = generateStat(baseDamage, maxDamage) * 2;
    else
      damage = generateStat(baseDamage, maxDamage);
    return damage;
  }
  return 0;
}

void Player::levelUp() {
  if (experiencePoints >= level * 50 && level < 10) {
    level++;
    baseDamage += 5;
    maxDamage += 5;
    armor += +1;
    maxHealth += 5;
    luck += 2;
    dexterity += 3;
    currentHealth = maxHealth;
    if (potionsAmount < potionLevel)
      for (int potionAdded = 0; potionAdded < potionLevel; potionAdded++)
        potionsAmount++;
  }
}

int Player::getLevel() const { return level; }

int Player::getPotions() const { return potionsAmount; }

void Player::weaponLevelUp() {
  weaponLevel++;
  baseDamage += 5;
  maxDamage += 5;
}

void Player::getPotion() { potionsAmount++; }

void Player::armorLevelUp() {
  armorLevel++;
  armor += 1;
}

void Player::gainGold(int gold) { goldAmount = goldAmount + gold; }

void Player::gainExp(int exp) { experiencePoints = experiencePoints + exp; }

int Player::getGold() const { return goldAmount; }

int Player::getWeaponLevel() const { return weaponLevel; }

int Player::getArmorLevel() const { return armorLevel; }

int Player::getShards() const { return shardsAmount; }

void Player::potionLevelUp() {
  potionLevel++;
  potionsAmount++;
  getPotions();
}

void Player::usePotion() {
  currentHealth += 10 * potionLevel;
  potionsAmount--;
}

int Player::getPotionsLevel() const { return potionLevel; }

int Player::getCurrentHealth() const { return currentHealth; }

bool Player::isDead() const {
  if (currentHealth <= 0)
    return true;
  if (currentHealth > 0)
    return false;
  return false;
}

void Player::setStats() { currentHealth = maxHealth; }

int Player::getExperiencePoints() const { return experiencePoints; }

int Player::getArmor() const { return armor; }

int Player::getMinDamage() const { return baseDamage; }

int Player::getMaxDamage() const { return maxDamage; }

void Player::gainShard(int shard) { shardsAmount = shardsAmount + shard; }

int Player::getMaxHealth() const { return maxHealth; }

void Player::setArmor(int armorPoints) { armor = armorPoints; }

int Player::getDexterity() const { return dexterity; }

int Player::getLuck() const { return luck; }

int Player::getDamageDone() const { return previousHealth - currentHealth; }

Enemy::Enemy(int arm, int maxHP, std::string name, int max, int min,
             Player &player, int criticalChance, int dex) {
  maxDamage = max + 10 * (player.getLevel() - 1);
  baseDamage = min + 10 * (player.getLevel() - 1);
  mobName = std::move(name);
  armor = arm + (player.getLevel() - 1);
  maxHealth = maxHP + 5 * (player.getLevel() - 1);
  luck = criticalChance + 2 * (player.getLevel() - 1);
  dexterity = dex + 3 * (player.getLevel() - 1);
  currentHealth = maxHealth;
}

std::string Enemy::getName() { return mobName; }
