#pragma once
#ifndef MUSIC_HPP
#define MUSIC_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Music
{
private:
	sf::Music _music;
public:
	Music() {};
	~Music() {};

	void setMusicVolume(float vol) { _music.setVolume(vol); };
};

#endif // MUSIC_HPP
