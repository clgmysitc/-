#pragma once

#define WIDTH 30

int map[WIDTH+1][WIDTH+1];//�a��
int Heroindex ;//�^���Ҧb��m
int Herostep;//�^�����B��
int attribute[WIDTH+1];//�a�Ϧ�m�W�Ҧ����ƥ�ʽ�
int p[WIDTH+1];//
int bossindex;//�]���Ҧb��m

void gamemap();//�C�������a��
int root(int x);//�M��x�Ϊ��N��
void link(int x, int y);//
