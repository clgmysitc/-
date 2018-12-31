#pragma once

#define SPACE 50
#define NAME_LEN 30

int num_weapons;//計算背包武器數量

struct weapon//武器的內容
{
    char name[NAME_LEN+1];//武器名字
    int atk;//武器的攻擊力
}wep_inventory[SPACE];//背包內武器儲存位置

extern char WEP_DATA[];//武器檔案的位置
int wep_amount;//總共的武器數量
char **wep_list;//總共存在幾種武器

void print_wep();//印出背包內的武器
void wear_wep(int index);//穿上武器(武器編號)
void Getwepname();//得到所有武器的名字
struct weapon *wep_init(char *b);//武器內容的初始化


