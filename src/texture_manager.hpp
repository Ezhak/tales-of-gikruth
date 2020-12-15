#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class TextureManager {
  public:
    // constructor
    TextureManager() { }
    // translate an id into a reference
    sf::Texture& getRef(const std::string& texture);
    // add a texture from a file
    void loadTexture(const std::string& name, const std::string &filename);
  private:
    // array of textures used
    std::map<std::string, sf::Texture> textures;
};

#endif // TEXTURE_MANAGER_HPP
