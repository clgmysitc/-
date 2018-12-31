#pragma once

#define SPACE 50
#define NAME_LEN 30

int num_items;//背包內道具的數量

struct item//道具內容
{
    char name[NAME_LEN+1];//道具名稱
    int heal;//道具回復生命值的量
}item_inventory[SPACE];//背包中道具存放的位置

extern char ITEM_DATA[];//到具內容的位置

int item_amount;//所有道具數量
char **item_list;//道具名字存放處


void print_item();//印出背包中的道具名稱
struct item* item_init(char *b);//進行道具內容之初始化
void use_item(int index);//使用道具(道具編號)
void Getitemname();//得到所有道具的名字
