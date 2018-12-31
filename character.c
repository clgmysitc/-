#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "character.h"
#include "weapon.h"
#include "utils.h"

char CHAR_DATA[] = "character\\";
char BADCHAR_DATA[] ="badcharacter\\";

character* ch_init(char *b)//角色初始化
{
    character* a = (character*)malloc ( sizeof(character) );//(標記type) malloc ( sizeof(空間大小) )
    char path[30];

    strcpy(path,CHAR_DATA);//複製路徑
    strcat(path,b);//把路徑接在後頭

    FILE *fp;
    fp = fopen(path, "r");
    if(!fp)
    {
        printf("fail to open %s.\n", b);
    }
    fscanf(fp,"%d", &a->level);
    // fscanf(fp,"%s", a->name);
    while(getc(fp) != '\n');
    fgets(a->name, 30, fp);
    a->name[strlen(a->name)-1] = 0;
    fscanf(fp,"%s", a->sex);
    fscanf(fp,"%d", &a->hp);
    fscanf(fp,"%d", &a->atk);
    fscanf(fp,"%d", &a->def);
    fscanf(fp,"%d", &a->reh);

    fclose(fp);
    return a;
}

character* badch_init(char *d)
{
    character* c = (character*)malloc ( sizeof(character) );//(標記type) malloc ( sizeof(空間大小) )
    char path[30];

    strcpy(path,BADCHAR_DATA);//複製路徑
    strcat(path,d);//把路徑接在後頭

    FILE *fp;
    fp = fopen(path,"r");
    fscanf(fp, "%d", &c->level);
    // fscanf(fp,"%s", c->name);
    while(fgetc(fp) != '\n');
    fgets(c->name, 30, fp);
    c->name[strlen(c->name)-1] = '\0';
    fscanf(fp,"%d", &c->hp);
    fscanf(fp,"%d", &c->atk);
    fscanf(fp,"%d", &c->def);
    fscanf(fp,"%d", &c->exp);
    fscanf(fp,"%d", &c->money);

    fclose(fp);
    return c;
}

void GetCharacterName()
{
    FILE *fp;

    fp=fopen("character\\mainCharacter.txt","r");
    fscanf(fp,"%d", &Characteramount);//讀角色數量
    name_list = (char**) malloc( sizeof(char*) * Characteramount );//給予角色字串空間去儲存
    for(int i=0; i < Characteramount; i++)
    name_list[i] = (char* ) malloc( sizeof(char) * 20);

    fgets(name_list[0],20,fp);
    for(int i=0; i < Characteramount; i++)
    {
        fgets(name_list[i],20,fp);
        name_list[i][strlen(name_list[i])-1]='\0';
    }
    fclose(fp);
}

void Getallcharacter()
{
    FILE *fp;
    char bad_ch[20],a[]=".txt";

    fp=fopen("badcharacter\\mainCharacter.txt","r");
    fscanf(fp,"%d", &level_amount);//讀等級數量

    all_character = (character***) malloc( sizeof(character**) * level_amount );//給予角色字串空間去儲存

    level_ch = (int *) malloc ( sizeof(int) * level_amount);


    for(int i=0; i < level_amount; i++)
    {
        fscanf(fp,"%d", & level_ch[i]);
        all_character[i] = (character** ) malloc( sizeof(character*) * level_ch[i]);
        while(fgetc(fp) != '\n');
        for(int j=0; j < level_ch[i];j++)
        {
            fgets(bad_ch, 30, fp);
            bad_ch[strlen(bad_ch)-1]='\0';
            strcat(bad_ch,a);
            all_character[i][j] = badch_init(bad_ch);

        }
    }

    fclose(fp);

}

void GetalienName()
{
    FILE *fp;
    fp=fopen("alien\\mainCharacter.txt","r");
    fscanf(fp,"%d", &alien_amount);

    alien_list = (char**) malloc( sizeof(char*) * alien_amount );//給予角色字串空間去儲存
    for(int i=0; i < alien_amount; i++)
    alien_list[i] = (char* ) malloc( sizeof(char) * 20);

    fgets(alien_list[0],20,fp);

    for(int i=0; i < alien_amount; i++)
    {
        fgets(alien_list[i],20,fp);
    }
}
