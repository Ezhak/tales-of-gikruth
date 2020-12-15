#include <SFML/Graphics.hpp>

#include "game_state.hpp"
#include "game_state_class_menu.hpp"
#include "game_state_play.hpp"
#include "game_state_start.hpp"

GameStateClassMenu::GameStateClassMenu(Game* game, sf::Music* theme)
{
  this->startTheme = theme;

  this->game = game;
  sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
  this->view.setSize(pos);
  pos *= 0.5f;
  this->view.setCenter(pos);

  this->background.setTexture(this->game->texmgr.getRef("choose_class"));

  sf::RectangleShape shape;
  sf::Vector2f dimensions(180, 70);
  shape.setSize(dimensions);

  GuiEntry dino = GuiEntry("dragon_menu",
                           shape,
                           &this->game->texmgr.getRef("dragon_menu"),
                           &this->game->texmgr.getRef("dragon_highlight"),
                           &this->game->texmgr.getRef("dragon_press"));

  GuiEntry knight = GuiEntry("knight_menu",
                             shape,
                             &this->game->texmgr.getRef("knight_menu"),
                             &this->game->texmgr.getRef("knight_highlight"),
                             &this->game->texmgr.getRef("knight_press"));

  GuiEntry mage = GuiEntry("mage_menu",
                           shape,
                           &this->game->texmgr.getRef("mage_menu"),
                           &this->game->texmgr.getRef("mage_highlight"),
                           &this->game->texmgr.getRef("mage_press"));

  std::vector<GuiEntry> entries{ dino, knight, mage };

  Gui gui = Gui(dimensions, entries);
  gui.setPosition(pos);
  gui.setOrigin(181, 70);
  gui.show();

  this->guiSystem.emplace("menu", gui);

  this->spawnSoundBuffer.loadFromFile("assets/sound/spawn.wav");
}

void GameStateClassMenu::update(const sf::Time dt)
{

}

void GameStateClassMenu::handleInput() {
  sf::Event event;
  sf::Vector2f mousePos = this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window), this->view);

  while (this->game->window.pollEvent(event)) {
    switch (event.type) {
    // close the window
    case sf::Event::Closed:
      this->game->window.close();
      break;
    // highlight menu items
    case sf::Event::MouseMoved:
      this->guiSystem.at("menu").highlight(this->guiSystem.at("menu").getEntry(mousePos));
      break;
    // click on menu items
    case sf::Event::MouseButtonPressed:
      if (event.mouseButton.button == sf::Mouse::Left)
        this->guiSystem.at("menu").press(this->guiSystem.at("menu").getEntry(mousePos));
      break;
    // release menu items
    case sf::Event::MouseButtonReleased:
      if (event.mouseButton.button == sf::Mouse::Left) {
        this->sound.setBuffer(this->spawnSoundBuffer);
        std::string msg = this->guiSystem.at("menu").activate(mousePos);

        if (msg == "dragon_menu") {
          this->sound.play();
          this->startgame("dragon");
        }

        if (msg == "knight_menu") {
          this->sound.play();
          this->startgame("knight");
        }

        if (msg == "mage_menu") {
          this->sound.play();
          this->startgame("mage");
        }

      }
      break;
    // close the window (Escape)
    case sf::Event::KeyPressed:
      if (event.key.code == sf::Keyboard::Escape)
        this->game->window.close();
      break;
    default:
      break;
    }
  }

  return;
}

void GameStateClassMenu::draw(const sf::Time dt) {
  this->game->window.setView(this->view);

  this->game->window.clear(sf::Color::Black);
  this->game->window.draw(this->background);

  for (auto gui : this->guiSystem)
    this->game->window.draw(gui.second);

  return;
}

void GameStateClassMenu::startgame(std::string className) {
  this->startTheme->stop();
  this->game->pushState(new GameStatePlay(this->game, className));

  return;
}
