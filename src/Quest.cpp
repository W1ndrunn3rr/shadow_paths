#include "../lib/Quest.h"
#include <random>

// Generatory złota, czasu i doświadczenia oraz zadań -również zapożyczone ze
// Stackoverflow
int generateGold(Player &player) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> goldRandom(
      5 * player.getLevel(), 10 * player.getLevel());
  int gold = static_cast<int>(goldRandom(rng));
  return gold;
}

int generateTime() {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> timeRandom(10, 15);
  int time = static_cast<int>(timeRandom(rng));
  return time;
}

int generateExp(Player &player) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> expRandom(
      20 + 5 * player.getLevel(), 35 + 5 * player.getLevel());
  int exp = static_cast<int>(expRandom(rng));
  return exp;
}

void Quest::generateQuest() {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> number(1, 5);
  int questNumber = static_cast<int>(number(rng));

  switch (questNumber) {
  case 1:
    questName = "Grave Robber";
    questContent =
        "As a brave knight-errant, I have an interesting proposition for you.\n"
        "It is said that during the great war between the heretics and the "
        "sacrilegious, "
        "led by a priest \n"
        "of the mythical god Cthulhu, the Dark Axe of Cthulhu was lost. "
        "I believe it is still out there, \n"
        "waiting to be found. I need someone with your skills "
        "to go out and retrieve it for me.\n"
        " Of course, I am willing to pay handsomely for your efforts.\n";
    break;
  case 2:
    questName = "In the mountains of madness";
    questContent =
        "Greetings, noble knight! I am a royal guard, and I require your "
        "assistance in a matter of utmost \n"
        "urgency. "
        "Our convoy was attacked on the road, and we lost a valuable shipment "
        "of goods. \n"
        "I need you to accompany me back to the site of the attack and "
        "retrieve the stolen\n"
        " cargo. "
        " Your reward will be generous if you help me in this quest..\n"
        "Will you assist me in this mission, brave adventurer?\n";
    break;
  case 3:
    questName = "The Devil doesn't bargain";
    questContent =
        "Greetings, brave traveler. I have a task for a skilled mercenary such "
        "as yourself.\n "
        "Within the treacherous Cursed Caves, a beast has made its lair and "
        "terrorizes nearby villages.\n"
        " I require your services to locate and eliminate the beast in "
        "exchange for a handsome reward.\n"
        " You will face many dangers on your journey, including traps and "
        "fierce monsters.\n"
        "Will you accept this challenge and rid the land of this menace?\n";
    break;
  case 4:
    questName = "Symbol of Royalty";
    questContent =
        "Greetings, brave adventurer. I have a task for you, should you choose "
        "to accept it.\n "
        "The King's signet ring has been stolen and we need it back. \n"
        " We need you to track down the thief, retrieve the stolen ring, and "
        "bring him to justice. \n"
        "The King is offering a generous reward for the successful completion "
        "of this mission. \n"
        "Do you have what it takes to accomplish this challenging task?\n";
    break;
  case 5:
    questName = "Tower of Torment";
    questContent = "Hail, gallant traveler! I am a berserk from the east, and "
                   "I have a task that requires your skills.\n"
                   " This monster has "
                   "made a pact with the sorcerer and threatens our land."
                   " I need you to enter \n"
                   "the tower "
                   "and slay the "
                   "creature to stop the evil from spreading. In exchange,\n "
                   "I will reward you generously. "
                   "Are you up for the challenge?\n";
    break;
  default:
    break;
  }
}

Quest::Quest(Player &player) : player(player) {
  state = LOST;
  eType = MOB;
  type = BANSHEE;
  if (player.getLevel() < 10)
    expAmount = generateExp(player);
  else
    expAmount = 0;
  goldAmount = generateGold(player);
  duration = generateTime();
  generateQuest();
}

void Quest::finishQuest(const std::string &fight) {
  if (fight == "MOB") {
    player.gainGold(goldAmount);
    player.gainExp(expAmount);
  } else if (fight == "BOSS") {
    player.gainGold(100);
    if (player.getLevel() < 10)
      expAmount = generateExp(player);
    else
      expAmount = 0;
  }
  player.levelUp();
}

void Quest::handleQuest() {
  if (!player.isDead()) {
    finishQuest("MOB");
    state = WON;
  } else {
    player.gainGold(-10);
    state = LOST;
  }
  updateQuest();
  player.setStats();
  eType = MOB;
}

std::string Quest::getQuestName() { return questName; }

std::string Quest::getQuestContent() { return questContent; }

void Quest::updateQuest() {
  goldAmount = generateGold(player);
  if (player.getLevel() < 10)
    expAmount = generateExp(player);
  else
    expAmount = 0;
  duration = generateTime();
  generateQuest();
}

int Quest::getGoldAmount() const { return goldAmount; }

int Quest::getExpAmount() const { return expAmount; }

int Quest::getDuration() const { return duration; }

int Quest::getStatus() const { return state; }

void Quest::handleDungeonFight() {
  if (!player.isDead()) {
    finishQuest("BOSS");
    player.gainShard(1 + type);
    if (type == BANSHEE)
      type = GOBLIN_KING;
    else if (type == GOBLIN_KING)
      type = ABYSSAL_WATCHERS;
    else if (type == ABYSSAL_WATCHERS)
      type = CLEARED;
    state = WON;
  } else if (player.isDead()) {
    player.gainGold(-10);
    state = LOST;
  }
  player.setStats();
  eType = BOSS;
}

BossType Quest::getBoss() const { return type; }

EnemyType Quest::getEnemy() const { return eType; }
