#include <algorithm>
#include <random>
#include <vector>
#include <SFML/Window.hpp>
#include "GameController.h"

std::vector<int> GameController::getCurrentPosition() {
    if (isGameOver()) {
        return fieldValues;
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && isPlayerMove) playerMove();
    else if (!isPlayerMove) compMove();
    return fieldValues;
}

void GameController::playerMove() {
    sf::Vector2i position = sf::Mouse::getPosition(window);
    int index = fieldRenderer.getIndexByPosition((sf::Vector2f) position);
    if (index >= 0 && fieldValues[index] == 0) {
        soundsController.playClickSound();
        fieldValues[index] = 1;
        if (isPlayerWinner()) {
            status = "You won!";
            gameOver = true;
        }
        isPlayerMove = false;
    }
}

void GameController::compMove() {
    int index = getRandomInteger(0, 8);

    if (fieldValues[index] == 0) {
        fieldValues[index] = 2;
        if (isCompWinner()) {
            status = "Comp won!";
            gameOver = true;
        }
        isPlayerMove = true;
    }
}

int GameController::getRandomInteger(int from, int to) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(from, to);
    return dist(gen);
}

bool GameController::isGameOver() {
    auto it = std::find(fieldValues.begin(), fieldValues.end(), 0);
    return it == fieldValues.end() || gameOver;
}

bool GameController::isPlayerWinner() {
    return checkForWinner(1);
}

bool GameController::isCompWinner() {
    return checkForWinner(2);
}

bool GameController::checkForWinner(int value) {
//    Check horizontals
    if (value == fieldValues[0] && value == fieldValues[1] && value == fieldValues[2]) return true;
    if (value == fieldValues[3] && value == fieldValues[4] && value == fieldValues[5]) return true;
    if (value == fieldValues[6] && value == fieldValues[7] && value == fieldValues[8]) return true;
//    Check verticals
    if (value == fieldValues[0] && value == fieldValues[3] && value == fieldValues[6]) return true;
    if (value == fieldValues[1] && value == fieldValues[4] && value == fieldValues[7]) return true;
    if (value == fieldValues[2] && value == fieldValues[5] && value == fieldValues[8]) return true;
//    Check Diagonals
    if (value == fieldValues[0] && value == fieldValues[4] && value == fieldValues[8]) return true;
    if (value == fieldValues[2] && value == fieldValues[4] && value == fieldValues[6]) return true;

    return false;
}

std::string GameController::getStatus() {
    return status;
}
