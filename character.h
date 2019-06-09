#ifndef CHARACTER_H
#define CHARACTER_H


class character {
public: //protected or private
    int health, level, x;
public:
    void action(character*);
    void reflect();

};

class bogenschutze;
class schwertkampfer;
class magier;

class schwertkampfer : public character{
public:
   schwertkampfer(int, int, int);
   void action(schwertkampfer*, bogenschutze*, magier*, int, int, int);
   /* arrays of objects and their appropriate sizes */
   /* array of objects that are available for interconnection (NOT include self.this) */
   void reflect(int, int);
   /*
    * call this method regarding to the player you are attempting to attack
    * int type = {1, 2, 3}, int value of health harm without coeff
   */

};
class bogenschutze : public character{
public:
    bogenschutze(int, int, int);
    void action(schwertkampfer*, bogenschutze*, magier*, int, int, int);
    void reflect(int, int);
};

class magier : public character{
public:
    magier(int, int, int);
    void action(schwertkampfer*, bogenschutze*, magier*, int, int, int);
    void reflect(int, int);
};

#endif //CHARACTER_H
