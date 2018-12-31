#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "menuingame.h"
#include "weapon.h"
#include "ctype.h"
#include <string.h>
#include "character.h"
#include "utils.h"
char WEP_DETA[] = "weapon\\";

void print_wep()
{
    int i;
    char code[5];
    int index;
    printf("Weapon sort\tWeapon name\tWeapon atk\t\n");
    printf("\n==================================================\n\n");
    if(num_weapons == 0)
    {
        printf("your weapon field is empty\n");
        printf("\n");
        printf("enter 'q' to leave.\n");
        scanf("%s", code);
        system("cls");
        if(code[0]=='q')
        {
            return;
        }
        else printf("Wrong command.\n");
    }

    else
    {
         for(i = 0; i < num_weapons ;i++)
        {
            printf("%5d\t",i);
            printf("\t%9s",wep_inventory[i].name);
            printf("\t%5d\n",wep_inventory[i].atk);
        }

        printf("\n");

        printf("if want to leave, enter 'q'.\n");
        printf("wear weapon enter its weapon sort.\n");
    }

    while(1)
    {
        scanf("%s", code);
        system("cls");
        if(code[0]=='q' && strlen(code)==1)
        {
            return;
        }

        else if( is_number(code) )
        {
            index = atoi(code);
            wear_wep(index);
            break;
        }
        else printf("Wrong command.\n");
    }
}

void wear_wep(int index)
{
    char name[20];
    int tatk = 0;
    if(index < 0 || index >= num_weapons)
    {
        printf("Wrong command.\n");
        return;
    }
    else if(wep_field->atk != 0)
    {
        strcpy(name, wep_field->name);
        tatk = wep_field->atk;
        Hero->atk += wep_inventory[index].atk - tatk;

        strcpy(wep_field->name, wep_inventory[index].name);
        wep_field->atk = wep_inventory[index].atk;

        strcpy(wep_inventory[index].name,name);
        wep_inventory[index].atk = tatk;
    }

    else
    {
        strcpy(wep_field->name,wep_inventory[index].name);
        wep_field->atk = wep_inventory[index].atk;
        Hero->atk += wep_inventory[index].atk;

        if(num_weapons==1)
        {
            num_weapons--;
            return;
        }
        else
        {
            for(int i = index+1; i<num_weapons; i++)
            {
                strcpy(wep_inventory[i-1].name,wep_inventory[i].name);
                wep_inventory[i-1].atk = wep_inventory[i].atk;
            }
            num_weapons--;
        }
    }
}

struct weapon *wep_init(char *b)//TODOS: 與ch_init類似
{
    struct weapon* a = (struct weapon*)malloc ( sizeof(struct weapon) );//(標記type) malloc ( sizeof(空間大小) )
    char path[30];

    strcpy(path,WEP_DETA);//複製路徑
    strcat(path,b);//把路徑接在後頭

    FILE *fp;
    fp = fopen(path,"r");
    fgets(a->name,30,fp);
    a->name[strlen(a->name)-1]=0;
    fscanf(fp,"%d", &a->atk);

    fclose(fp);
    return a;

}

void Getwepname()
{
    FILE *fp;

    fp=fopen("weapon//wepname.txt","r");
    fscanf(fp,"%d", &wep_amount);//讀武器數量
    wep_list = (char**) malloc( sizeof(char*) * wep_amount );//給予武器字串空間去儲存
    for(int i=0; i < wep_amount ; i++)
        wep_list[i] = (char* ) malloc( sizeof(char) * 30);

    fgets(wep_list[0], 30, fp);

    for(int i=0; i < wep_amount; i++)
    {
        fgets(wep_list[i], 30, fp);
        wep_list[i][strlen(wep_list[i])-1]=0;
    }

    fclose(fp);
}


