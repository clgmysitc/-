#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "menuingame.h"
#include "weapon.h"
#include <string.h>
#include "character.h"
#include "item.h"
#include "utils.h"

char ITEM_DATA[]="item\\";

void print_item()
{
    int i;
    char code[5];
    int item_index;
    printf("Item sort\tItem name\t Item heal\t\n");
    printf("\n==================================================\n\n");
    if(num_items==0)
    {
        printf("your Item field is empty");
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
    for(i = 0; i<num_items ;i++)
    {
        printf("%5d\t",i);
        printf("\t%9s",item_inventory[i].name);
        printf("\t%5d\n",item_inventory[i].heal);
    }

    printf("\n");
    printf("if want to leave, enter 'q' .\n");
    printf("use item, enter its item sort.\n");

    while(1)
    {
        scanf("%s", code);
        system("cls");
        if(strlen(code)==1)
        {
            if(code[0]=='q')
            {
                return;
            }
            else if(is_number(code))
            {
                item_index = atoi(code);
                use_item(item_index);
                return;
            }
        }
        else if(is_number(code))
        {
            item_index = atoi(code);
            use_item(item_index);
            return;
        }
        else printf("Wrong command.\n");
    }
}

struct item* item_init(char *b)
{
    struct item* a = (struct item*)malloc ( sizeof(struct item) );//(標記type) malloc ( sizeof(空間大小) )
    char path[30];

    strcpy(path,ITEM_DATA);//複製路徑
    strcat(path,b);//把路徑接在後頭

    FILE *fp;
    fp = fopen(path,"r");

    fgets(a->name,30,fp);
    a->name[strlen(a->name)-1]=0;
    fscanf(fp,"%d", &a->heal);

    fclose(fp);
    return a;
}

void use_item(int index)
{

    if(index < 0 || index >= num_items)
    {
        printf("Wrong command.\n");
        return;
    }

    else
    {
        Hero->hp += item_inventory[index].heal;

        if(num_items == 1)
        {
            num_items--;
            return;
        }

        else
        {
            for(int i = index+1; i<num_items; i++)
            {
                strcpy(item_inventory[i-1].name,item_inventory[i].name);
                item_inventory[i-1].heal = item_inventory[i].heal;
            }
            num_items--;
        }

        printf("your hp is %d now.\n", Hero->hp);
        return;
    }
}

void Getitemname()
{
    FILE *fp;

    fp=fopen("item\\itemname.txt","r");
    fscanf(fp,"%d", &item_amount);//讀數量
    item_list = (char**) malloc( sizeof(char*) * item_amount );//給予字串空間去儲存
    for(int i=0; i < item_amount ; i++)
    item_list[i] = (char* ) malloc( sizeof(char) * 30);

    while(getc(fp)!='\n');
    for(int i=0; i < item_amount; i++)
    {
        fgets(item_list[i],30,fp);
        item_list[i][strlen(item_list[i])-1]=0;
    }
    fclose(fp);


}
