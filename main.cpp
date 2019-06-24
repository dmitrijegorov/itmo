#include <iostream>
#include "character.h"

int main() {

    schwertkampfer schwertkampfer1(74, 1, 5), schwertkampfer2(74, 1, 15), schwertkampfer3(60, 2, 14);
    bogenschutze bogenschutze1(55, 2, 3), bogenschutze2(60, 4, 10);
    magier magier1(51, 5, 4), magier2(80, 3, 3);
    auto * c1= (schwertkampfer *)malloc(1 * sizeof(schwertkampfer));
    if (c1== nullptr)
        return -1;
    c1[0]=schwertkampfer2;
    auto * c2= (bogenschutze *)malloc(1 * sizeof(bogenschutze));
    if (c2== nullptr)
        return -1;
    c2[0]=bogenschutze1;
    auto * c3= (magier *)malloc(1 * sizeof(magier));
    if (c3== nullptr)
        return -1;
    c3[0]=magier1;
    schwertkampfer1.action(c1, c2, c3, 1, 1, 1);
    std :: cout << schwertkampfer1.x << "\n"<< schwertkampfer1.health <<"\n"<< schwertkampfer1.level << "\n";
    c2[0]=bogenschutze2;
    bogenschutze1.action(c1, c2, c3, 1, 1, 1);
    c3[0]=magier2;
    magier1.action(c1, c2, c3, 1, 1, 1);


    return 0;
}
