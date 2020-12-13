#include "game.hpp"
#include "game_state_start.hpp"
#include "SFML/Audio.hpp"

int main() {
    Game game;

    sf::Music gameTheme;
    gameTheme.openFromFile("assets/music/menu.wav");
    gameTheme.setVolume(30.f);
    gameTheme.play();
    gameTheme.setLoop(true);

    game.pushState(new GameStateStart(&game));
    game.gameLoop();

    return 0;
}
