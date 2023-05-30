#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Entity.h"
#include "Quest.h"
#include "GameView.h"
#include "GameController.h"
#include "Music.h"


int main() {
    Player player;
    Merchant merchant(player);
    Quest quest(player);
    Music music;
    GameView view(quest, player, merchant,music);
    GameController controller(player, merchant, view, quest,music);
    sf::RenderWindow window(sf::VideoMode(1280, 800), "Shadow Paths", sf::Style::Titlebar);
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
