//#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>
#include "character.h"

#define L 1

void character::action(character *) {

}

void character::reflect() {

}

// Constructor of the class
schwertkampfer::schwertkampfer(int h, int l, int y) : character() {
    health=h;
    level=l;
    //x=y;
    this->x=y;

}

void schwertkampfer::action(schwertkampfer* c1, bogenschutze* c2, magier *c3, int c11, int c22, int c33) {
    int dist=10000, nearest=0, he=0;
    int flag=0, k=0; // to determine type of character to attack
    for (int i=0; i<c11; i++){
        //dist=std::min(dist, abs(c1[i].x-this->x));
        if (abs(c1[i].x-this->x)<=dist){
            nearest=c1[i].x;
            he=c1[i].health;
            dist=abs(c1[i].x-this->x);
            flag=1;
            k=i;
        }

    }
    for (int i=0; i<c22; i++){
        //dist=std::min(dist, abs(c2[i].x-this->x));
        if (abs(c2[i].x-this->x)<=dist){
            nearest=c2[i].x;
            he=c2[i].health;
            dist=abs(c2[i].x-this->x);
            flag=2;
            k=i;
        }
    }
    for (int i=0; i<c33; i++){
        //dist=std::min(dist, abs(c3[i].x-this->x));
        if (abs(c3[i].x-this->x)<=dist){
            nearest=c3[i].x;
            he=c3[i].health;
            dist=abs(c3[i].x-this->x);
            flag=3;
            k=i;
        }
    }
    std::cout << dist;

    if (dist<=L){
        if (flag==1){
            c1[k].health=c1[k].health-abs(c1[k].level-this->level);
        }
        if (flag==2){
            c2[k].health=c2[k].health-abs(c2[k].level-this->level);
        }
        if (flag==3){
            c3[k].health=c3[k].health-abs(c3[k].level-this->level);
        }
    }
    else{
        if (this->health>50){
            this->x=this->x+2*L*((int)abs(nearest-this->x)/(nearest-this->x));
        }
        else{
            this->x=this->x-2*L*((int)abs(nearest-this->x)/(nearest-this->x));
        }
    }


}

// Constructor of the class
bogenschutze::bogenschutze(int h, int l, int y) : character() {
    health=h;
    level=l;
    this->x=y;
}


void bogenschutze::action(schwertkampfer* c1, bogenschutze* c2, magier *c3, int c11, int c22, int c33) {
//TODO
}

// Constructor of the class
magier::magier(int h, int l, int y) : character() {
    health=h;
    level=l;
    this->x=y;
}
