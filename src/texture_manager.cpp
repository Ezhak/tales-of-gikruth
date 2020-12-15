#include <map>
#include <SFML/Graphics.hpp>
#include <string>

#include "texture_manager.hpp"

sf::Texture& TextureManager::getRef(const std::string& texture)
{
  return this->textures.at(texture);
}

void TextureManager::loadTexture(const std::string& name, const std::string& filename)
{
  // load the texture
  sf::Texture tex;
  tex.loadFromFile(filename);

  // add it to the list of textures
  this->textures[name] = tex;

  return;
}
