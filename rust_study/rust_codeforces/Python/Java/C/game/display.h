#include <stdio.h>
#include "orgnise.h"
#ifndef DISPLAY_H
#define DISPLAY_H

#define teamAll 2
#define itemAll 2

Member mem[teamAll];
Item itm[itemAll];

int chooseMember;
int itemInitFlag = 1;


Member start() {
    // 可以在此添加人物角色，记得修改teamAll的大小
    mem[0] = new_member(1, "周芷若", "倚天剑", 18, 6, 300, 200, 300);
    mem[1] = new_member(2, "张无忌", "屠龙刀", 20, 8, 400, 300, 100);
    // ----------------
    int _, i;
    printf("请输入账号:");
    scanf("%d", &_);
    printf("请输入密码:");
    scanf("%d", &_);
    printf("序号\t姓名\t武器\t攻击力\t防御力\t价格\t血量\t金币\n");
    for(i = 0;i < teamAll;++i) printf("%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n", mem[i].num, mem[i].name, mem[i].weapon, mem[i].attack, mem[i].defence, mem[i].price, mem[i].health, mem[i].coin);
    printf("请选择扮演角色:");
    scanf("%d", &chooseMember);
    while(0 >= chooseMember || teamAll < chooseMember) {
        printf("输入有误, 重新输入:");
        scanf("%d", &chooseMember);
    }
    printf("**********欢迎%s进入新手村***********\n", mem[--chooseMember].name);
    return mem[chooseMember];
}

int initGoods() {
    //初始化商品
    itm[0] = new_item(1, "金创药", 100, 0, 0, 150);
    itm[1] = new_item(2, "云南药", 200, 0, 0, 250);
    itemInitFlag = 0;
    return 0;
}

Member buy() {
    int i, choose_num;
    if(itemInitFlag)initGoods();

    printf("序号\t商品名\t单价\t攻击\t防御\t血\n");
    for(i = 0;i < itemAll;++i) printf("%d\t%s\t%d\t%d\t%d\t%d\n", itm[i].num, itm[i].name,itm[i].price, itm[i].attack, itm[i].defence,itm[i].health);

    printf("请输入要购买的商品的序号:");
    scanf("%d", &choose_num);
    while(0 >= choose_num || itemAll < choose_num) {
        printf("输入有误, 重新输入:");
        scanf("%d", &choose_num);
    }
    if(mem[chooseMember].coin >= itm[--choose_num].price) {
        mem[chooseMember].coin -= itm[choose_num].price;
        mem[chooseMember].attack += itm[choose_num].attack;
        mem[chooseMember].defence += itm[choose_num].defence;
        mem[chooseMember].health += itm[choose_num].health;
        printf("你购买了%s,%d金币,攻击力提升%d点,防御力提升%d点,血量提升%d点!\n", itm[choose_num].name, itm[choose_num].price, itm[choose_num].attack, itm[choose_num].defence, itm[choose_num].health);
    }
    else printf("穷鬼,打怪挣钱去吧,这个地方不适合你!\n");
    return mem[chooseMember];
}

int choose() {
    int choice;
    printf("1.购物\n2.出村打怪\n");
    scanf("%d", &choice);
    return choice - 1;
}

#endif