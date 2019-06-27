#include <iostream>
#include <math.h>
#include <algorithm>
#include "character.h"

#define L 1 // distance constant


void Character::action(std::vector<Character*> characters) {        //последовательность выполнения команд
    std::cout<<22;
    Character *n=chooseCharToAct(characters);
    std::cout<<1;
    if(n!=nullptr)                                                    //проверка подходящего кандидата
        attack(n);                                                  //атака
    else
        whereToGo(characters);                                      //перемещение в случае невозможности атаки
}


Character* Schwertkampfer::chooseCharToAct(std::vector<Character *> characters){            //выбор мечника
    Character *nearest;
    if (!characters.empty()) nearest=characters[0];
    for(int i=1; i < characters.size(); i++){
        if(x-characters[i]->getX() < nearest->getX() && x-characters[i]->getX() < nearest->getX()&&abs(characters[i]->getX()-x)<=1){
            nearest=characters[i];
        }
    }
    return nearest;
}


void Schwertkampfer::attack(Character* tar){            //атака мечника
    int damage=(int)coeff*(abs(tar->getLevel()-this->level));
    tar->reflect(this,damage);
}


void Schwertkampfer::whereToGo(std::vector<Character *> characters){        //передвижение мечника
    Character* target=nullptr;
    if (!characters.empty()) target=characters[0];
    for(int i=1; i<characters.size(); i++){
        if(x-characters[i]->getX() < target->getX() && x-characters[i]->getX() < target->getX()){
            target=characters[i];
        }
    }
    if(health>50)
    {
        if(target->getX()>x)x=x+2L;
        else x=x-2L;
    }
    else if(target->getX()>x)x=x-2L;
    else x=x+2L;
}


Character* bogenschutze::chooseCharToAct(std::vector<Character *> characters){      //выбор лучника
    Character* target;
    if (!characters.empty()) target=characters[0];
    for(int i=1; i<characters.size(); i++){
        if(abs(characters[i]->getX()-x)>=4 && abs(characters[i]->getX()-x)<=10 && characters[i]->getHealth() < target->getHealth()){
            target=characters[i];
        }
    }
    return target;
}


void bogenschutze::attack(Character* tar){              //атака лучника
    int damage=(int)coeff*(abs(tar->getLevel()-this->level));
    tar->reflect(this,damage);
}



void bogenschutze::whereToGo(std::vector<Character *> characters){      //передвижение лучника
    Character* target=nullptr;
    if (!characters.empty()) target=characters[0];
    for(int i=1; i<characters.size(); i++)
    {
        if(x-characters[i]->getX() < target->getX() && x-characters[i]->getX() < target->getX()){
            target=characters[i];
        }
        //if(target->getX()>x)x=x+L;
        //else x=x-2L;
        if (abs(target->getX()-this->x)<=3*L){
            // backwards
            this->x=this->x-2*L*((int)abs(target->getX()-this->x)/(target->getX()-this->x));
        }
        else{
            // towards
            this->x=this->x+L*((int)abs(target->getX()-this->x)/(target->getX()-this->x));
        }
    }
}

Character* magier::chooseCharToAct(std::vector<Character *> characters){        //выбор мага
    Character* target;
    if (!characters.empty()) target=characters[0];
    for(int i=0; i<characters.size(); i++){
        if(abs(characters[i]->getX()-x)>=2 && abs(characters[i]->getX()-x)<=10 && characters[i]->getLevel() < target->getLevel()){
            target=characters[i];
        }
    }
    return target;
}

void magier::attack(Character* tar){            //атака мага

    int damage=(int)coeff*(abs(level));
    tar->reflect(this,damage);
}

void magier::whereToGo(std::vector<Character *> characters){        //передвижение мага
    Character* target=nullptr;
    if (!characters.empty()) target=characters[0];
    for(int i=1; i<characters.size(); i++){
        if(x-characters[i]->getX() < target->getX() && x-characters[i]->getX() < target->getX()){
            target=characters[i];
        }
        //if(target->getX()>x) x=x+3L;
        //else x=x-5L;
        if (target->getX()<=2*L){
            // backwards
                this->x=this->x-5*L*((int)abs(target->getX()-this->x)/(target->getX()-this->x));
        }
        else{
            // towards
                this->x=this->x+3*L*((int)abs(target->getX()-this->x)/(target->getX()-this->x));
        }
    }
}

const float magier::reflection_coeff = 0.1;
void magier::reflect(Character* c, int damage)                  //защита мага
{
    changeHealth(health-reflection_coeff*damage);
}

float Schwertkampfer::coeff=0.1;
const float Schwertkampfer::reflection_coeff = 0.3;
void Schwertkampfer::reflect(Character* c, int damage)          //защита мечника
{
    changeHealth(health-reflection_coeff*damage);
}

const float bogenschutze::reflection_coeff = 0.4;
void bogenschutze::reflect(Character* c, int damage)            //защита лучника
{
    changeHealth(health-reflection_coeff*damage);
}




