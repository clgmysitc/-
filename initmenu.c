#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "character.h"
#include "initmenu.h"
#include "map.h"
#include <ctype.h>
#include "armor.h"
#include "weapon.h"
#include "item.h"
#include "battlesysterm.h"
#include "utils.h"
#include "menuingame.h"

void menu_init()//遊戲選單
{
    char command[5];

    monster = (character*)malloc( sizeof(character) );
    wep_field = (struct weapon*)malloc( sizeof(struct weapon));
    arm_field = (struct armor*)malloc(sizeof( struct armor));

    while(1)
    {
        printf("\t\tWelcome Tianlong Ba Bu\n");
        printf("\n=============================================================\n\n");
        printf("\t|     Enter 'n' or 'N':  New Game        |\n");
        printf("\t|     Enter 'l' or 'L':  Load the file   |\n");
        printf("\t|     Enter 'q' of 'Q':  Quit Game       |\n");
        printf("\n=============================================================\n\n");
        scanf("%s", command);
        system("cls");
        if(strlen(command)==1)
        {
            if(command[0]=='n'||command[0]=='N')
            {

                if(!CharacterChoose())
                    continue;
                StartNewGame();
                break;
            }
            else if(command[0]=='l'||command[0]=='L')
            {
                LoadGame();
                break;
            }
            else if(command[0]=='q'||command[0]=='Q')
            {
                exit(0);
            }
            else printf("Wrong command.\n");
        }
        else printf("Wrong command.\n");
    }
    return;
}

int CharacterChoose()//選擇角色
{
    int Index;
    char code[5];
    int YesorNo = 0;
    GetCharacterName();

    while(1)
    {
        printf("\n============================================\n");
        printf("you can check the character information first.\n");
        printf("\n============================================\n");
        printf("if choose 'A tz' enter '1'.\n");
        printf("if choose 'Duan Yu' enter '2'.\n");
        printf("if choose 'Mu Wan Ching' enter '3'.\n");
        printf("if choose 'Shiu ju' enter '4'.\n");
        printf("if choose 'Xiao Feng' enter '5'.\n");
        printf("if back to menu , enter 'q'.\n");

        scanf("%s", code);
        system("cls");
        if(strlen(code)==1 && code[0]=='q')
        {
            return 0;
        }
        else if(strlen(code)==1&&is_number(code))
        {
            Index = atoi(code);
            YesorNo = Characterinform(Index-1);
            if(YesorNo) return 1;
        }
        else printf("Wrong command.\n");
    }

}

void StartNewGame()//初始化
{
    Getallcharacter();
    Getwepname();
    Getarmname();
    Getitemname();
    GetalienName();
    gamemap();
    wep_field->atk = 0;
    arm_field->def = 0;
}

void LoadGame()
{
    StartNewGame();
    Hero = (character*)malloc( sizeof(character) );
    Load();
}

int Characterinform(int Index)//角色選擇時的資料
{
    printf("You select %s.\n", name_list[Index]);
    printf("\n============================================\n");
    char str[30], a[] = ".txt";
    char code[5];
    FILE *fp;
    fp=fopen("Hero.txt","w");
    character* detail;

    strcpy(str, name_list[Index]);
    strcat(str,a); //決定角色的資料為何

    detail = ch_init(str);

    printf("level: %d\n", detail->level);
    printf("name: %s\n", detail->name);
    printf("sex: %s\n", detail->sex);
    printf("hp: %d\n", detail->hp);
    printf("atk: %d\n", detail->atk);
    printf("def: %d\n", detail->def);
    printf("reh: %d\n", detail->reh);
    printf("\n============================================\n");
    printf("if want to back enter 'q'\n");
    printf("if want to choose enter 'y'\n");
    scanf("%s",code);
    system("cls");
    while(1)
    {
        if(strlen(code)==1)
        {
            if(code[0]=='q')
            {
                free(detail);
                fclose(fp);
                return 0;
            }

            else if(code[0]=='y')
            {
                Hero = detail;

                fprintf(fp,"%d", Hero->level);
                fprintf(fp,"%s", Hero->name);
                fprintf(fp,"%s", Hero->sex);
                fprintf(fp,"%d", Hero->hp);
                fprintf(fp,"%d", Hero->atk);
                fprintf(fp,"%d", Hero->def);
                fprintf(fp,"%d", Hero->reh);
                Hero->money = 0;
                Hero->exp = 0;
                fclose(fp);

                return 1;
            }
            else
                printf("Wrong command.\n");
        }
        else  printf("Wrong command.\n");
    }
}

