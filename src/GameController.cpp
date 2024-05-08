#include <vector>
#include <random>
#include <SFML/Window.hpp>
#include "GameController.h"

std::vector<int> GameController::getCurrentPosition() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && isPlayerMove) playerMove();
//    else if (!isPlayerMove) compMove();
    return fieldValues;
}

void GameController::playerMove() {
    sf::Vector2i position = sf::Mouse::getPosition(window);
    int index = fieldRenderer.getIndexByPosition((sf::Vector2f) position);
    fieldValues[index] = 1;
//    isPlayerMove = false;
}

void GameController::compMove() {
//    std::random_device rd;
//    std::mt19937 gen(rd());
//
//    std::uniform_int_distribution<> dist(0, 9);
//
//    int random_number = dist(gen);
//    fieldValues[random_number] = 2;
//    isPlayerMove = true;
}