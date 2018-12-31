#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "menuingame.h"
#include "armor.h"
#include <string.h>
#include "character.h"
#include "utils.h"
char ARM_DATA[] = "armor\\";

void print_armor()
{
    int i;
    char code[5];
    int index;
    printf("Armor sort\tArmor name\tArmor atk\t\n");
    printf("\n==================================================\n\n");
    if(num_armors == 0)
    {
        printf("your armor field is empty\n");
        printf("\n");
        printf("enter 'q' to leave.\n");
        while(1)
        {
            scanf("%s", code);
            system("cls");
            if(code[0]=='q')
            {
                return;
            }
            else printf("Wrong command.\n");
        }
    }

    else
    {
         for(i = 0; i < num_armors ;i++)
        {
            printf("%5d\t",i);
            printf("\t%9s",arm_inventory[i].name);
            printf("\t%5d\n",arm_inventory[i].def);
        }

        printf("\n");

        printf("if want to leave, enter 'q'.\n");
        printf("wear armor enter its armor sort.\n");
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
                wear_arm(index);
                break;
            }
            else printf("Wrong command.\n");
        }
    }
}

void wear_arm(int index)//TODOS: 與wear_wep相同
{
    char name[20];
    int tdef;
    if(index < 0 || index >= num_armors)
    {
        printf("Wrong command.\n");
        return;
    }
    else if(arm_field->def != 0)
    {

        strcpy(name, arm_field->name);
        tdef = arm_field->def;
        Hero->def += arm_inventory[index].def - tdef;

        strcpy(arm_field->name, arm_inventory[index].name);
        arm_field->def = arm_inventory[index].def;

        strcpy(arm_inventory[index].name,name);
        arm_inventory[index].def = tdef;
    }

    else
    {
        strcpy(arm_field->name,arm_inventory[index].name);
        arm_field->def = arm_inventory[index].def;
        Hero->def += arm_inventory[index].def;

        if(num_armors == 1)
        {
            num_armors--;
            return;
        }

        else
        {
            for(int i = index+1; i<num_armors; i++)
            {
                strcpy(arm_inventory[i-1].name,arm_inventory[i].name);
                arm_inventory[i-1].def = arm_inventory[i].def;
            }
            num_armors--;
        }
    }

}
struct armor* arm_init(char *b)//TODOS: 與ch_init類似
{
    struct armor* a = (struct armor*)malloc ( sizeof(struct armor) );//(標記type) malloc ( sizeof(空間大小) )
    char path[30];

    strcpy(path,ARM_DATA);//複製路徑
    strcat(path,b);//把路徑接在後頭

    FILE *fp;
    fp = fopen(path,"r");
    fgets(a->name,30,fp);
    a->name[strlen(a->name)-1]=0;
    fscanf(fp,"%d", &a->def);

    fclose(fp);
    return a;

}

void Getarmname()
{
    FILE *fp;

    fp=fopen("armor\\armname.txt","r");
    fscanf(fp,"%d", &arm_amount);//讀防具數量
    arm_list = (char**) malloc( sizeof(char*) * arm_amount );//給予防具字串空間去儲存
    for(int i=0; i < arm_amount ; i++)
    arm_list[i] = (char* ) malloc( sizeof(char) * 20);

    while(getc(fp)!='\n');

    for(int i=0; i < arm_amount; i++)
    {
        fgets(arm_list[i],20,fp);
        arm_list[i][strlen(arm_list[i])-1]=0;
    }
    fclose(fp);

}
