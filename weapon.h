#pragma once

#define SPACE 50
#define NAME_LEN 30

int num_weapons;//�p��I�]�Z���ƶq

struct weapon//�Z�������e
{
    char name[NAME_LEN+1];//�Z���W�r
    int atk;//�Z���������O
}wep_inventory[SPACE];//�I�]���Z���x�s��m

extern char WEP_DATA[];//�Z���ɮת���m
int wep_amount;//�`�@���Z���ƶq
char **wep_list;//�`�@�s�b�X�تZ��

void print_wep();//�L�X�I�]�����Z��
void wear_wep(int index);//��W�Z��(�Z���s��)
void Getwepname();//�o��Ҧ��Z�����W�r
struct weapon *wep_init(char *b);//�Z�����e����l��


