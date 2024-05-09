#include <string>
#include <SFML/Audio/Sound.hpp>
#include "SoundsController.h"

#include "iostream"
#include "SFML/Audio/SoundBuffer.hpp"

void SoundsController::playSound(std::string soundPath) {
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(soundPath)) {
        std::cout << "Error of loading sound file" << std::endl;
    }

    sf::Sound sound;
    sound.setVolume(10.f);
    sound.setBuffer(buffer);
    sound.play();
}

void SoundsController::playClickSound() {
    std::cout << "Before sound" << std::endl;
    playSound("assets/click-sound.wav");
    std::cout << "After sound" << std::endl;
}

void SoundsController::playGameOverSound() {
    playSound("assets/game-over-sound.wav");
}
