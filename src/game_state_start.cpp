#include <SFML/Graphics.hpp>

#include "game_state.hpp"
#include "game_state_class_menu.hpp"
#include "game_state_play.hpp"
#include "game_state_start.hpp"

GameStateStart::GameStateStart(Game* game)
{
  this->game = game;
  sf::Vector2f position = sf::Vector2f(this->game->window.getSize());
  this->view.setSize(position);
  position *= 0.5f;
  this->view.setCenter(position);

  this->background.setTexture(this->game->texmgr.getRef("menu_background"));

  sf::RectangleShape shape;
  sf::Vector2f dimensions(363, 70);
  shape.setSize(dimensions);

  GuiEntry start = GuiEntry("start_game",
                            shape, 
                            &this->game->texmgr.getRef("start"),
                            &this->game->texmgr.getRef("start_highlight"),
                            &this->game->texmgr.getRef("start_press"));

  GuiEntry hiscore = GuiEntry("hiscores",
                            shape,
                            &this->game->texmgr.getRef("hiscores"),
                            &this->game->texmgr.getRef("hiscores_highlight"),
                            &this->game->texmgr.getRef("hiscores_press"));

  GuiEntry quit = GuiEntry("quit_game",
                            shape,
                            &this->game->texmgr.getRef("quit"),
                            &this->game->texmgr.getRef("quit_highlight"),
                            &this->game->texmgr.getRef("quit_press"));

  std::vector<GuiEntry> entries{start, hiscore, quit};

  Gui gui = Gui(dimensions, entries);
  gui.setPosition(position);
  gui.setOrigin(181, 155);
  gui.show();

  this->guiSystem.emplace("menu", gui);

  this->startTheme.openFromFile("assets/music/menu.wav");
  this->startTheme.setLoop(true);
  this->startTheme.play();

  this->clickSoundBuffer.loadFromFile("assets/sound/click.wav");
}

void GameStateStart::draw(const sf::Time dt)
{
  this->game->window.setView(this->view);

  this->game->window.clear(sf::Color::Black);
  this->game->window.draw(this->background);

  for(auto gui : this->guiSystem)
    this->game->window.draw(gui.second);

  return;
}

void GameStateStart::handleInput()
{
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
        this->sound.setBuffer(this->clickSoundBuffer);
        std::string msg = this->guiSystem.at("menu").activate(mousePos);

        if (msg == "start_game") {
          this->sound.play();
          this->startgame();
        }

        else if (msg == "hiscores") {
          this->sound.play();
          this->hiscores();
        }

        else if (msg == "quit_game") {
          this->sound.play();
          this->game->window.close();
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

void GameStateStart::update(const sf::Time dt)
{
}

void GameStateStart::hiscores() {

}

void GameStateStart::startgame() {
  this->game->pushState(new GameStateClassMenu(this->game, &this->startTheme));

  return;
}
