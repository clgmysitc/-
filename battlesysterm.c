#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "initmenu.h"
#include "battlesysterm.h"
#include "character.h"
#include "menuingame.h"
#include "event.h"
#include "item.h"
#include "levelsysterm.h"
#include "utils.h"

int quit = 0;

void battle_systerm()
{
    int battleindex = 0;
    char code[5], code1[5];

    while(1)
    {
        printf("\n");
        printf("name:%s\n", monster->name);
        printf("hp:%d\n", monster->hp);
        printf("atk:%d\n", monster->atk);
        printf("def:%d\n", monster->def);
        printf("\n============================================\n\n");
        situation();
        printf("\n============================================\n\n");
        printf("attack:enter '1'.\n");
        printf("skill:enter '2'.\n");
        printf("open item:enter '3'.\n");
        printf("escape:enter '4'.\n");

        scanf("%s",code);

        if(strlen(code)==1)
        {
            battleindex = atoi(code);
            switch(battleindex)
            {
                case 1:attack();break;
                case 2:skill();break;
                case 3:Package();break;
                case 4:escape();break;
                default:printf("Wrong command.\n");break;
            }

            if(battle_quit()!=2)
            {
                if(battle_quit() == -1)
                {
                    printf("Game over.\n");
                    exit(0);
                }

                else if(battle_quit() == 0)
                {
                    return;
                }
                else if(battle_quit() == 1)
                {
                    printf("\n");
                    printf("you win !!!!\n");
                    printf("you get %d exp.\n", monster->exp);
                    printf("you get %d money.\n", monster->money);
                    Hero->money += monster->money;
                    Hero->exp += monster->exp;
                    level_up();
                    printf("enter '1' to continue.\n");

                    while(1)
                    {
                        scanf("%s", code1);
                        system("cls");
                        if(strlen(code1)==1 && code1[0]=='1')
                        {
                            return;
                        }
                        else
                        printf("Wrong command.\n");
                    }
                }
            }
        }
        else printf("Wrong command.\n");
    }
}

void attack()
{
    char code[5];
    int hero_atk;
    hero_atk = Hero->atk - monster->def;

    if(hero_atk<=0)
    {
        printf("you do nothing to the %s.\n", monster->name);
        printf("\n============================================\n\n");
        monster_term();
    }
    else
    {
        monster->hp-=hero_atk;
        printf("you do %d damage to %s.\n", hero_atk, monster->name);
        if(monster->hp>0)
        {
            printf("\n============================================\n\n");
            monster_term();

        }
    }

    printf("enter '1' to continue.\n");
    while(1)
    {
        scanf("%s", code);
        system("cls");

        if(strlen(code)==1 && code[0]=='1')
        {
            return;
        }
        else printf("Wrong command.\n");
    }
}


void skill()
{
    int lose_hp1;
    int lose_hp2;
    char code[5];
    int index;
    int hero_atk;
    lose_hp1 = 30;
    lose_hp2 = rand()%30 + 50;
    hero_atk = Hero->atk - monster->def;

    if(hero_atk<=0)
    {

        printf("you do nothing to the %s.\n", monster->name);
        printf("\n============================================\n\n");
        monster_term();
    }

    while(1)
    {
        printf("if use 'double' attack, enter '1' and lose %d hp.\n", lose_hp1);
        printf("if use 'trible' attack, enter '2' and lose %d hp.\n", lose_hp2);
        printf("if don't use any skill '3' to quit .\n");
        scanf("%s", code);
        system("cls");
        if(strlen(code)==1)
        {
            index = atoi(code);

            if(index==1)
            {
                if(Hero->hp <= lose_hp1)
                {
                    printf("you can't use this skill.\n");
                    return;
                }

                else
                {
                    if(hero_atk<=0)
                    {
                        Hero->hp -= lose_hp1;
                        printf("you do nothing to %s.\n",monster->name);
                        printf("you left %d hp.\n", Hero->hp);
                        return;
                    }

                    else
                    {
                        Hero->hp -= lose_hp1;
                        monster->hp = monster->hp -(hero_atk)*2;
                        printf("you do %d damage.\n", Hero->atk*2);
                        printf("you left %d hp.\n", Hero->hp);
                        if(monster->hp>0)
                        {
                        printf("monster left %d hp.\n", monster->hp);
                        printf("\n============================================\n\n");
                        monster_term();
                        return;
                        }
                        else return;
                    }
                }
            }

            else if(index == 2)
            {
                if(Hero->hp<=lose_hp2)
                {
                    printf("you can't use this skill.\n");
                    return;
                }

                else
                {
                    if(hero_atk<=0)
                    {
                        Hero->hp -= lose_hp2;
                        printf("you do nothing to %s.\n", monster->name);
                        return;
                    }

                    else
                    {
                        Hero->hp -= lose_hp2;
                        monster->hp = monster->hp -(Hero->atk)*3;
                        printf("you do %d damage.\n", Hero->atk*3);

                        if(monster->hp>0)
                        {
                        printf("monster left %d hp.\n", monster->hp);
                        printf("\n============================================\n\n");
                        monster_term();
                        return;
                        }
                        else return;
                    }
                }
            }
            else if(index == 3)
            {
                return;
            }
            else printf("Wrong command.\n");
        }
        else
        printf("Wrong command.\n");
    }
}

void Package()
{
    print_item();
    return;
}

void escape()
{
    int random_lost;
    random_lost = monster->atk/2;
    system("cls");
    printf("you lose %d hp, because of escape.\n", random_lost);
    quit = 1;
    return;
}

void monster_term()
{
    int monster_damage;
    monster_damage = monster->atk - Hero->def;

    if(monster_damage<=0)
    {
        printf("the %s do nothing to you.\n", monster->name);
        return;
    }
    else
    {
        Hero->hp -= monster_damage;
        printf("you lose %d damage.\n", monster_damage);

        if(Hero->hp>0)
        {
            printf("you left %d hp.\n",Hero->hp);
            return;
        }
    }
}

int battle_quit()//判斷結束條件
{
    if(Hero->hp<=0) return -1;
    else if(quit == 1) return 0;
    else if(monster->hp <=0 ) return 1;
    else return 2;//未結束
}
