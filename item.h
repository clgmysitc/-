#pragma once

#define SPACE 50
#define NAME_LEN 30

int num_items;//�I�]���D�㪺�ƶq

struct item//�D�㤺�e
{
    char name[NAME_LEN+1];//�D��W��
    int heal;//�D��^�_�ͩR�Ȫ��q
}item_inventory[SPACE];//�I�]���D��s�񪺦�m

extern char ITEM_DATA[];//��㤺�e����m

int item_amount;//�Ҧ��D��ƶq
char **item_list;//�D��W�r�s��B


void print_item();//�L�X�I�]�����D��W��
struct item* item_init(char *b);//�i��D�㤺�e����l��
void use_item(int index);//�ϥιD��(�D��s��)
void Getitemname();//�o��Ҧ��D�㪺�W�r
