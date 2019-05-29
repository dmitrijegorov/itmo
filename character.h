#ifndef CHARACTER_H
#define CHARACTER_H


class character {
public:
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
   void reflect(); //TODO

};
class bogenschutze : public character{
public:
    bogenschutze(int, int, int);
    void action(schwertkampfer*, bogenschutze*, magier*, int, int, int);
    void reflect();
};

class magier :public character{
public:
    magier(int, int, int);
    void action();
    void reflect();
};

#endif //CHARACTER_H
