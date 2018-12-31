#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "event.h"
#include "character.h"
#include "map.h"
#include "weapon.h"
#include "armor.h"
#include "item.h"
#include "battlesysterm.h"
#include "utils.h"
#include "menuingame.h"

void trigger_event(int mapindex)
{
    int i = rand() % 4;
    switch(attribute[mapindex])
    {
        case 0:ally_event();break;
        case 1:enemy_event();break;
        case 2:treasure_event();break;
        case 3:trap_event();break;
        case 4:boss_event();break;
    }
    while(i == attribute[mapindex])
    {
        i = rand() % 4;
    }
    attribute[mapindex] = i;
}

void ally_event()
{
    int random_atkmoney;
    int random_defmoney;
    int random_healmoney;
    int random_atk;
    int random_def;
    int random_heal;
    int random_alien;
    int index;
    char code[5];
    random_atkmoney = rand()% 50 + 10;
    random_defmoney = rand()% 50 + 10;
    random_healmoney = rand()% 50 + 10;
    random_atk = rand()% 20 + 5;
    random_def = rand()% 20 + 5;
    random_heal = rand()% 300 + 50 ;
    random_alien = rand() % alien_amount;



    while(1)
    {
        printf("\n=========================================\n\n");
        printf("you meet %s.\n", alien_list[random_alien]);
        printf("Option |  command |  cost.     | effect        |\n");
        printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");
        printf("talk   |enter '1' |            | know some news|\n");
        printf("heal   |enter '2' | %3d money  | add %3d hp    |\n", random_healmoney,random_heal);
        printf("atk    |enter '3' | %3d money  | add %3d atk   |\n", random_atkmoney,random_atk);
        printf("def    |enter '4' | %3d money  | add %3d def   |\n", random_defmoney,random_def);
        printf("exit   |enter '5' |            |               |\n");
        printf("enter command: ");
        scanf("%s", code);
        system("cls");
        if(code[0]=='5')
        {
            return;
        }

        else if( is_number(code)&& strlen(code)==1)
        {
            index = atoi(code);
            switch(index)
            {
                case 1:talkoption();break;
                case 2:
                if(Hero->money<random_healmoney)
                {
                    printf("you don't have enough money.\n");
                    break;
                }
                else
                {
                    Hero->hp+=random_heal;
                    Hero->money-=random_healmoney;
                    random_healmoney+=2;
                    situation();
                }
                break;
                case 3:
                if(Hero->money<random_atkmoney)
                {
                    printf("you don't have enough money.\n");
                }
                else
                {
                    Hero->atk+=random_atk;
                    Hero->money-=random_atkmoney;
                    random_atkmoney+=2;
                    situation();
                }
                break;
                case 4:
                if(Hero->money<random_defmoney)
                {
                    printf("you don't have enough money.\n");
                }
                else
                {
                    Hero->def+=random_def;
                    Hero->money-=random_defmoney;
                    random_defmoney +=2;
                    situation();
                }
                break;
            }
        }
        else printf("Wrong command.\n");
    }

}

void enemy_event()
{
    int Level = 0;
    int range = 0;
    int random_badguy = 0;
    int random_lose = 0;
    char code[5];
    int choice;

    Level = Hero->level /3;

    if(Level >= level_amount-1)
    {
        Level = level_amount-2;
    }

    if(Level>0)
    {
        range = Level;
        Level = rand() % range;
    }

    random_badguy = rand() % level_ch[Level];
    random_lose = rand() % 30 + 10;



    while(1)
    {
        memcpy(monster, all_character[Level][random_badguy], sizeof(character) );
        printf("\n============================================\n");
        printf("you encounter a %s monster!!!!!.\n", monster->name);
        printf("hp: %d\n", monster->hp);
        printf("atk: %d\n", monster->atk);
        printf("def: %d\n", monster->def);
        printf("\n\n");
        printf("if you want to talk, enter '1' .\n");
        printf("if you want to battle, enter '2' .\n");
        printf("if you want to escape enter '3',but you will lose %d hp.\n", random_lose);
        scanf("%s", code);
        system("cls");
        if( code[0]=='3'&& strlen(code)==1)
        {
            printf("your hero lose %d hp.\n", random_lose);
            Hero->hp -= random_lose;
            if(Hero->hp<=0)
            {
                printf("Game over.\n");
                exit(0);
            }

            else
            {
                printf("your hero left %d hp, because of escape.\n", Hero->hp);
            }

            return;
        }
        else if(is_number(code) && strlen(code)==1)
        {
            choice = atoi(code);
            if(choice==1)
            {
                printf("Let's battle.\n");
                printf("\n============================================\n");
                continue;
            }
            else if(choice==2)
            {
                battle_systerm();
                system("cls");
                return;
            }
            else if(choice==3)
            {
                return;
            }
        }
    }
}

void trap_event()
{
    int lost_money;
    int lost_hp;
    int i;
    lost_money =(Hero->money) *( (rand() % 11 + 10) )/100;
    lost_hp = (Hero->hp)*( rand() % 11 + 10) /100;
    printf("\n============================================\n");
    printf("You get trap!\n");
    printf("Enter '1' to lost %d money.\n", lost_money);
    printf("Enter '2' to lost %d hp.\n", lost_hp);
    printf("Enter wrong command will lost both hp and money.\n");
    printf("\n============================================\n");
    scanf("%d", &i);
    system("cls");
    if(i==1)
    {
        Hero->money-=lost_money;
        printf("\n============================================\n");
        printf("You remain %d money, because of trap.\n", Hero->money);

    }
    else if(i==2)
    {
        Hero->hp-=lost_hp;
        printf("\n============================================\n");
        printf("You remain %d hp, because of trap.\n", Hero->hp);
    }

    else
    {
        Hero->money-=lost_money;
        Hero->hp-=lost_hp;
        printf("\n============================================\n");
        printf("You remain %d hp, because of wrong command.\n", Hero->hp);
        printf("You remain %d money, because of wrong command.\n", Hero->money);
    }

}

void treasure_event()
{
    int i;
    int random;
    char a[]=".txt";
    char str[30];
    struct weapon* twep_save;
    struct armor* tarm_save;
    struct item* titem_save;
    i = rand() % 4;
    switch(i)
    {
        case 0:
        system("cls");
        printf("\n============================================\n");
        printf("you get a weapon!!!!!\n");
        random = rand() % wep_amount;
        strcpy(str,wep_list[random]);
        strcat(str,a);
        twep_save = wep_init(str);
        memcpy(&wep_inventory[num_weapons], twep_save, sizeof(struct weapon)) ;
        wep_inventory[num_weapons].atk+= rand() % 50;
        printf("you get %s !!!!!!\n", wep_inventory[num_weapons].name);
        printf("its atk is %d\n",wep_inventory[num_weapons].atk);
        printf("\n============================================\n");
        num_weapons++;
        free(twep_save);
        break;

        case 1:
        system("cls");
        random = rand() % 400;
        Hero->money+=random;
        printf("\n============================================\n");
        printf("you get %d money!!!!!!\n", random);
        printf("you have %d money now.\n", Hero->money);
        printf("\n============================================\n");
        break;

        case 2:
        system("cls");
        printf("\n============================================\n");
        printf("you get a armor!!!!!\n");
        random = rand() % arm_amount;
        strcpy(str,arm_list[random]);
        strcat(str,a);
        tarm_save = arm_init(str);
        memcpy( &arm_inventory[num_armors], tarm_save, sizeof(struct armor) ) ;
        arm_inventory[num_armors].def+= rand() % 50;
        printf("you get %s !!!!!!\n", arm_inventory[num_armors].name);
        printf("its def is %d\n",arm_inventory[num_armors].def);
        printf("\n============================================\n");
        num_armors++;
        free(tarm_save);
        break;

        case 3:
        system("cls");
        random = rand() % item_amount;
        strcpy(str,item_list[random]);
        strcat(str,a);
        titem_save = item_init(str);
        printf("\n============================================\n");
        printf("you get a item!!!!!!\n");
        memcpy( &item_inventory[num_items], titem_save, sizeof(struct item) );
        printf("you get %s !!!!!!!\n", item_inventory[num_items].name);
        printf("its heal is %d\n",item_inventory[num_items].heal);
        printf("\n============================================\n");
        num_items++;
        free(titem_save);
        break;
    }
}

void boss_event()
{
    int final_level;
    int random_boss1,random_boss2;
    char code[5];
    final_level = level_amount-1;
    random_boss1 = level_ch[final_level];
    random_boss2 = rand() % random_boss1;

    memcpy(monster, all_character[final_level][random_boss2], sizeof(character));
    printf("\n=================================\n\n");
    printf("you arrival the final destination!!!!!!.\n");
    printf("you encounter %s be your final test.\n",monster->name);
    printf("you can't escape.\n");
    printf("\n===================================\n\n");
    printf("if you want to talk, enter '1' to do it.\n");
    printf("if you want to battle, enter '2' to do it.\n");

    while(1)
    {
        scanf("%s",code);
        system("cls");
        if(strlen(code)==1)
        {
            if(code[0]=='1')
            {
                printf("%s you finally come here.\n", Hero->name);
                printf("Let's battle and you will lose.\n");
                printf("\n============================================\n");
                continue;
            }

            else if(code[0]=='2')
            {
                 battle_systerm();
                 break;
            }

            else printf("Wrong command.\n");
        }
        else
        printf("Wrong command.\n");
    }
    if(Hero->hp>0)
    {
        while(1)
        {
            printf("----------------------------------------------\n");
            printf("|                   You win!!!!                |\n");
            printf("|               Congraguation!!!!!             |\n");
            printf("----------------------------------------------\n");
            printf("enter '1' to continue the game.\n");
            printf("enter '2' to quit game.\n");
            scanf("%s", code);
            if(strlen(code)==1)
            {
                if(code[0]=='1')
                {
                    attribute[bossindex] = rand() % 4;
                    bossindex = rand()% WIDTH + 1;
                    attribute[bossindex] = 4;
                    system("cls");
                    return;
                }
                else if(code[0]=='2')
                {
                    exit(0);
                }
                else printf("Wrong command.\n");
            }
        }
    }
}

void talkoption()
{
    int trea_money;
    int boss_money;
    char code[5];
    trea_money = rand() % 30 + 40;
    boss_money = rand() % 200 + 300;
    printf("if you want some treasures,enter '1' and pay %d money to know.\n", trea_money);
    printf("if you want a information of boss, enter '2' and pay %d money to know.\n", boss_money);
    printf("if do nothing , enter '3' to quit.\n");

    while(1)
    {
        scanf("%s", code);
        system("cls");
        if(strlen(code)==1)
        {
            if(code[0]=='3')
            {
                return;
            }
            if(code[0]=='2')
            {
                if(Hero->money-boss_money>=0)
                {
                    printf("The boss is on %d", bossindex);
                    return;
                }

            }
            if(code[0]=='1')
            {
                if( (Hero->money-trea_money)>=0 )
                {
                    printf("the treasure in these road.\n");
                    for(int i=0; i<WIDTH ;i++)
                    {
                        if(attribute[i]==2)
                        {
                            printf("%d ", i);
                        }
                    }
                    return;
                }
                else
                {
                    printf("you don't have enough money.\n");
                    return;
                }
            }
        }
        else
        printf("Wrong command.\n");
    }
}
