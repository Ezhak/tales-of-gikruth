#pragma once
#ifndef SOUND_HPP
#define SOUND_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Sound {
	private:
		sf::SoundBuffer _buffer;
		sf::Sound _fxSound;
	public:
		Sound() {};
		~Sound() {};
		void setSoundVolume(float vol) { _fxSound.setVolume(vol); };
		sf::SoundBuffer getBuffer() { return _buffer; };
		sf::Sound getSound() { return _fxSound; };
};

#endif SOUND_HPP