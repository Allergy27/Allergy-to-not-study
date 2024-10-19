#include <string.h>

#ifndef ORGNISE_H
#define ORGNISE_H

typedef struct TeamMember {
    int num;
    char name[20];
    char weapon[20];
    int attack;
    int defence;
    int price;
    int health;
    int coin;
}Member;

Member new_member(int num, char *name, char *weapon, int attack, int defence, int price, int health, int coin) {
    Member qwq;
    qwq.num = num;
    strcpy(qwq.name, name);
    strcpy(qwq.weapon, weapon);
    qwq.attack = attack;
    qwq.defence = defence;
    qwq.price = price;
    qwq.health = health;
    qwq.coin = coin;
    return qwq;
}

typedef struct GoodItem {
    int num;
    char name[20];
    int price;
    int attack;
    int defence;
    int health;
}Item;

Item new_item(int num, char *name,int price, int attack, int defence, int health) {
    Item qwq;
    qwq.num = num;
    strcpy(qwq.name, name);
    qwq.price = price;
    qwq.attack = attack;
    qwq.defence = defence;
    qwq.health = health;
    return qwq;
}

#endif /* ORGNISE_H */