#pragma once

#define SPACE 50
#define NAME_LEN 30

int num_armors;//計算背包防具數量

struct armor//防具的內容
{
    char name[NAME_LEN+1];//防具名字
    int def;//防具的防禦力
}arm_inventory[SPACE];//背包內的防具儲存位置

extern char ARM_DATA[];//防具的內容位置
char **arm_list;//防具名稱儲存位置
int arm_amount;//總共存在幾種防具

void print_armor();//背包中印出防具名稱
void wear_arm(int index);//使用防具(背包防具的編號)
void Getarmname();//得到所有防具的名字
struct armor* arm_init(char *b);//進行防具內容的初始化
