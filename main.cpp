#include <iostream>
#include "character.h"

int main() {
    int numbOfChar;
    std::cout << "num = ";
    std::cin >> numbOfChar;     //считываем количество

    std::vector<Character *> characters;   //создание вектора количества "игроков"
    for (int i = 0; i < numbOfChar; i++) {                         //начинаем выполнять действия
        int coef = rand() % 3;
        if (coef == 0) {
            characters.push_back(new Schwertkampfer(100, rand() % 10, rand() % 20 - 10));
            std::cout << characters[i]->getX();
        } else if (coef == 1) {
            characters.push_back(new bogenschutze(100, rand() % 10, rand() % 20 - 10));
            std::cout << characters[i]->getX();
        } else {
            characters.push_back(new magier(100, rand() % 10, rand() % 20 - 10));
            std::cout << characters[i]->getX();
        }
    }
    //for (int j = 0; j < characters.size(); j++) {
    characters[0]->action(characters);
    //}
    return 0;
}

