#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <vector>

class Character {                       //общее описание класса
protected:
    int health=100, level, x;
    virtual Character* chooseCharToAct(std::vector<Character *> characters)=0;         //виртуальная функция выбора
    virtual void whereToGo(std::vector<Character *> characters)=0;             //виртуальная функция передвижения
    virtual void attack(Character* tar)=0;             //виртуальная функция атаки
public:
    void changeHealth(int x){health=x;}
    int getX(){return x;}
    int getHealth(){return health;}
    int getLevel(){return  level;}
    virtual void reflect(Character* c, int damage)=0;           //виртуальная функция защиты
    void action(std::vector<Character*> characters);       //виртуальная функция действия

    Character(int start_health, int start_level, int start_x): health(start_health), level(start_level), x(start_x){}     //черты героя
};


class Schwertkampfer: public Character{
protected:
    static float coeff;
    static const float reflection_coeff;
    Character* chooseCharToAct(std::vector<Character *> characters) override;            //виртуальная функция выбора
    void whereToGo(std::vector<Character *> characters) override;                //виртуальная функция передвижения
    void attack(Character* tar) override;                                //виртуальная функция атаки
public:
    void reflect(Character* c, int damage) override;        //виртуальная функция защиты

    Schwertkampfer(int start_health, int start_level, int start_x):  Character(start_health, start_level, start_x) {}
};


class bogenschutze : public Character{
protected:
    float coeff;
    static const float reflection_coeff;
    Character* chooseCharToAct(std::vector<Character *> characters) override;            //виртуальная функция выбора
    void whereToGo(std::vector<Character *> characters) override;                //виртуальная функция передвижения
    void attack(Character* tar) override;                                //виртуальная функция атаки
public:
    bogenschutze(int start_health, int start_level, int start_x):  Character(start_health, start_level, start_x) {}
    void reflect(Character* c, int damage) override;                //виртуальная функция защиты
//    void action(std::vector<character*> characters) override;           //виртуальная функция действия
};


class magier : public Character{
protected:
    float coeff;
    static const float reflection_coeff;
    Character* chooseCharToAct(std::vector<Character *> characters) override;            //виртуальная функция выбора
    void whereToGo(std::vector<Character *> characters) override;                //виртуальная функция передвижения
    void attack(Character* tar) override;                                //виртуальная функция атаки
public:
    magier(int start_health, int start_level, int start_x):  Character(start_health, start_level, start_x) {}
    void reflect(Character* c, int damage) override;            //виртуальная функция защиты

};

#endif //CHARACTER_H
