#pragma once

#define WIDTH 30

int map[WIDTH+1][WIDTH+1];//地圖
int Heroindex ;//英雄所在位置
int Herostep;//英雄的步數
int attribute[WIDTH+1];//地圖位置上所有的事件性質
int p[WIDTH+1];//
int bossindex;//魔王所在位置

void gamemap();//遊戲中的地圖
int root(int x);//尋找x團的代表 保證地圖連通性
void link(int x, int y);//將兩團合併成一團 保證地圖連通性
