#include "lib/Entity.h"
#include "lib/GameController.h"
#include "lib/GameView.h"
#include "lib/Music.h"
#include "lib/Quest.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main() {
  Player player;
  Merchant merchant(player);
  Quest quest(player);
  Music music;
  GameView view(quest, player, merchant, music);
  GameController controller(player, merchant, view, quest, music);
  sf::RenderWindow window(sf::VideoMode(1280, 800), "Shadow Paths",
                          sf::Style::Titlebar);
  window.setVerticalSyncEnabled(false);
  window.setFramerateLimit(60);
  while (window.isOpen()) {
    sf::Event event{};
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    window.clear();
    controller.handleGameEvent(event, window);
    controller.manageGameView(window);
    window.display();
  }

  return 0;
}
