#pragma once

#define SPACE 50
#define NAME_LEN 30

int num_armors;//�p��I�]����ƶq

struct armor//���㪺���e
{
    char name[NAME_LEN+1];//����W�r
    int def;//���㪺���m�O
}arm_inventory[SPACE];//�I�]���������x�s��m

extern char ARM_DATA[];//���㪺���e��m
char **arm_list;//����W���x�s��m
int arm_amount;//�`�@�s�b�X�ب���

void print_armor();//�I�]���L�X����W��
void wear_arm(int index);//�ϥΨ���(�I�]���㪺�s��)
void Getarmname();//�o��Ҧ����㪺�W�r
struct armor* arm_init(char *b);//�i�樾�㤺�e����l��
