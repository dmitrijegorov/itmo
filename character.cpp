//#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>
#include "character.h"

#define L 1 // distance constant
#define reflection_coeff 0.5 // blocking reflection

void character::action(character *) {

}

void character::reflect() {

}

// Constructor of the class
character::character() {
    health=0;
    level=0;
    //x=y;
    this->x=0;
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
    std::cout <<"dist = "<< dist <<"\n";

    if (dist<=L){
        if (flag==1){
            // c1[k].health=c1[k].health-abs(c1[k].level-this->level);
            c1[k].reflect(1, abs(c1[k].level-this->level));
        }
        if (flag==2){
            c2[k].reflect(1, abs(c2[k].level-this->level));
            // c2[k].health=c2[k].health-abs(c2[k].level-this->level);
        }
        if (flag==3){
            c3[k].reflect(1, abs(c3[k].level-this->level));
            // c3[k].health=c3[k].health-abs(c3[k].level-this->level);
        }
    }
    else{
        if (this->health>50){
            // towards
            this->x=this->x+2*L*((int)abs(nearest-this->x)/(nearest-this->x));
        }
        else{
            // backwards
            this->x=this->x-2*L*((int)abs(nearest-this->x)/(nearest-this->x));
        }
    }
}

void schwertkampfer::reflect(int type, int value) {
    if (type==1){
        this->health= (int)(this->health-reflection_coeff*value);
    }
    if (type==2){
        this->health= (int)(this->health-reflection_coeff*value);
    }
    if (type==3){
        this->health= (int)(this->health-value);
    }
}

// Constructor of the class
bogenschutze::bogenschutze(int h, int l, int y) : character() {
    health=h;
    level=l;
    this->x=y;
}

void bogenschutze::action(schwertkampfer* c1, bogenschutze* c2, magier *c3, int c11, int c22, int c33) {
    /*
     * first we are attacking, then moving, so
     * actions are attack or/and move
     */
    int health_min=10000, nearest=0, he=0, dist=0;
    int flag1=0, k1=0; // to determine type of nearest character
    int flag=0, k=0; // to determine type of character to attack
    for (int i=0; i<c11; i++){
        //dist=std::min(dist, abs(c1[i].x-this->x));
        if ((c1[i].health)<=health_min &&
        abs(c1[i].x-this->x)<=10*L &&
        abs(c1[i].x-this->x)>=4*L){
            he=c1[i].health; // optional
            health_min=abs(c1[i].health-this->health);
            flag=1;
            k=i;
        }
        if (abs(c1[i].x)<=nearest) {
            nearest = c1[i].x;
            flag1=1;
            k1=i;
        }

    }
    for (int i=0; i<c22; i++){
        //dist=std::min(dist, abs(c2[i].x-this->x));
        if ((c2[i].health)<=health_min &&
            abs(c2[i].x-this->x)<=10*L &&
            abs(c2[i].x-this->x)>=4*L){
            he=c2[i].health;
            health_min=abs(c2[i].health-this->health);
            flag=2;
            k=i;
        }
        if (abs(c2[i].x)<=nearest) {
            nearest = c2[i].x;
            flag1=2;
            k1=i;
        }
    }
    for (int i=0; i<c33; i++){
        //dist=std::min(dist, abs(c3[i].x-this->x));
        if ((c3[i].health)<=health_min &&
            abs(c3[i].x-this->x)<=10*L &&
            abs(c3[i].x-this->x)>=4*L){
            he=c3[i].health;
            health_min=abs(c3[i].health-this->health);
            flag=3;
            k=i;
        }
        if (abs(c3[i].x)<=nearest) {
            nearest = c3[i].x;
            flag1=3;
            k1=i;
        }
    }
    std::cout << health_min;

    // attempt to attack
    if (flag==1){
        c1[k].reflect(2, abs(c1[k].level-this->level));
    }
    if (flag==2){
        c2[k].reflect(2, abs(c2[k].level-this->level));
    }
    if (flag==3){
        c3[k].reflect(2, abs(c3[k].level-this->level));
    }

    if (abs(nearest-this->x)<=3*L){
        // backwards
        if (flag1==1){
            this->x=this->x-2*L*((int)abs(nearest-this->x)/(nearest-this->x));
        }
        if (flag1==2){
            this->x=this->x-2*L*((int)abs(nearest-this->x)/(nearest-this->x));
        }
        if (flag1==3){
            this->x=this->x-2*L*((int)abs(nearest-this->x)/(nearest-this->x));
        }
    }
    else{
        // towards
        if (flag1==1){
            this->x=this->x+L*((int)abs(nearest-this->x)/(nearest-this->x));
        }
        if (flag1==2){
            this->x=this->x+L*((int)abs(nearest-this->x)/(nearest-this->x));
        }
        if (flag1==3){
            this->x=this->x+L*((int)abs(nearest-this->x)/(nearest-this->x));
        }
    }
}

void bogenschutze::reflect(int type, int value) {
    if (type==1){
        this->health= (int)(this->health-reflection_coeff*value);

    }
    if (type==2){
        this->health= (int)(this->health-reflection_coeff*value);
    }
    if (type==3){
        this->health= (int)(this->health-value);

    }
}

// Constructor of the class
magier::magier(int h, int l, int y) : character() {
    health=h;
    level=l;
    this->x=y;
}

void magier::action(schwertkampfer* c1, bogenschutze* c2, magier *c3, int c11, int c22, int c33) {
    int level_min=10000, nearest=0, he=0, dist=0;
    int flag1=0, k1=0; // nearest character
    int flag=0, k=0; // to determine type of character to attack
    for (int i=0; i<c11; i++){
        //dist=std::min(dist, abs(c1[i].x-this->x));
        if (abs(c1[i].level)<=level_min &&
            abs(c1[i].x-this->x)<=10*L &&
            abs(c1[i].x-this->x)>=2*L){
            he=c1[i].health;
            level_min=abs(c1[i].level);
            flag=1;
            k=i;
        }
        if (abs(c1[i].x)<=nearest) {
            nearest = c1[i].x;
            flag1=1;
            k1=i;
        }

    }
    for (int i=0; i<c22; i++){
        //dist=std::min(dist, abs(c2[i].x-this->x));
        if (abs(c2[i].level)<=level_min &&
            abs(c2[i].x-this->x)<=10*L &&
            abs(c2[i].x-this->x)>=2*L){
            he=c2[i].health;
            level_min=abs(c2[i].level);
            flag=2;
            k=i;
        }
        if (abs(c2[i].x)<=nearest) {
            nearest = c2[i].x;
            flag1=2;
            k1=i;
        }
    }
    for (int i=0; i<c33; i++){
        //dist=std::min(dist, abs(c3[i].x-this->x));
        if (abs(c3[i].level)<=level_min &&
            abs(c3[i].x-this->x)<=10*L &&
            abs(c3[i].x-this->x)>=2*L){
            he=c3[i].health;
            level_min=abs(c3[i].level);
            flag=3;
            k=i;
        }
        if (abs(c3[i].x)<=nearest) {
            nearest = c3[i].x;
            flag1=3;
            k1=i;
        }
    }
    std::cout << level_min;

    // attempt to attack
    if (flag==1){
        c1[k].reflect(3, abs(this->level));
    }
    if (flag==2){
        c2[k].reflect(3, abs(this->level));
    }
    if (flag==3){
        c3[k].reflect(3, abs(this->level));
    }

    if (nearest<=2*L){
        // backwards
        if (flag1==1){
            this->x=this->x-5*L*((int)abs(nearest-this->x)/(nearest-this->x));
        }
        if (flag1==2){
            this->x=this->x-5*L*((int)abs(nearest-this->x)/(nearest-this->x));
        }
        if (flag1==3){
            this->x=this->x-5*L*((int)abs(nearest-this->x)/(nearest-this->x));
        }
    }
    else{
        // towards
        if (flag1==1){
            this->x=this->x+3*L*((int)abs(nearest-this->x)/(nearest-this->x));
        }
        if (flag1==2){
            this->x=this->x+3*L*((int)abs(nearest-this->x)/(nearest-this->x));
        }
        if (flag1==3){
            this->x=this->x+3*L*((int)abs(nearest-this->x)/(nearest-this->x));
        }
    }
}

void magier::reflect(int type, int value) {
    if (type==1){
        this->health= (int)(this->health-value);
    }
    if (type==2){
        this->health= (int)(this->health-reflection_coeff*value);
    }
    if (type==3){
        this->health= (int)(this->health-reflection_coeff*value);
    }
}

