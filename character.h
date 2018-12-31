#pragma once

typedef struct//角色內容
{
    int level;//等級
    char name[30];//名字
    char sex[10];//性別
    int hp;//生命
    int atk;//攻擊力
    int def;//防禦力
    int reh;//恢復力
    int exp;//經驗值
    int money;//錢
}character;

extern char BADCHAR_DATA[];//敵人內容儲存位置
extern char CHAR_DATA[];//儲存主角檔案路徑
char **name_list;//主角名字儲存位置
int Characteramount;//主角數量
character* Hero;//遊戲中的主角
character* monster;//遊戲中代表之敵人

struct weapon* wep_field;//主角的武器欄位
struct armor* arm_field;//主角的防具欄位

character* **all_character;//所有敵人以character的形式存放

int level_amount;//有幾個等級
int *level_ch;//每個等級有幾個角色

char **alien_list;//盟友名字儲存位置
int alien_amount;//盟友總共數量

character* ch_init(char *b);//主角內容初始化
character* badch_init(char *c);//敵人內容初始化
void GetCharacterName();//得到所有英雄名字
void Getallcharacter();//得到所有敵人的名字
void GetalienName();//得到所有盟友名字
