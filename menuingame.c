#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "initmenu.h"
#include "menuingame.h"
#include "character.h"
#include "map.h"
#include "armor.h"
#include "weapon.h"
#include "item.h"
#include "utils.h"

void openPackage()
{
    int packageindex;
    char code[5];
    printf("open weapon field enter '1'.\n");
    printf("open armor field enter '2'.\n");
    printf("open item field enter '3'.\n");
    printf("quit package, enter '4' to quit.\n");
    while(1)
    {
        scanf("%s", code);
        if(strlen(code)==1)
        {
            packageindex = atoi(code);
            if(packageindex==1)
            {
                print_wep();
                break;
            }
            else if(packageindex==2)
            {
                print_armor();
                break;
            }
            else if(packageindex==3)
            {
                print_item();
                break;
            }
            else if(packageindex==4)
            {
                return;
            }
            else
            {
                printf("Wrong command.\n");
                printf("\n=========================\n\n");
            }
        }
    }
}

void situation()
{
    printf("level: %d\n", Hero->level);
    printf("namd: %s\n", Hero->name);
    printf("sex: %s\n", Hero->sex);
    printf("hp: %d\n", Hero->hp);
    printf("atk: %d\n", Hero->atk);
    printf("def: %d\n", Hero->def);
    printf("reh: %d\n", Hero->reh);
    printf("exp: %d\n", Hero->exp);
    printf("money: %d\n",Hero->money);
    if(wep_field->atk == 0) printf("wep field: NULL.\n");
    else printf("wep field: %s\n", wep_field->name);
    if(arm_field->def == 0) printf("arm field: NULL.\n");
    else printf("arm field: %s\n", arm_field->name);
}

void openMap()
{
    for(int i=1; i<WIDTH ; i++)
    {
        for(int j=1; j<WIDTH ; j++)
            printf("%d ", map[i][j]);
        printf("\n");
    }
}

void Save()
{
    FILE *fp;
    int i, j;
    fp = fopen("record.txt", "w");

    for(i=1;i<=WIDTH;i++)
    {
        for(j=1;j<=WIDTH;j++)
        {
            fprintf(fp,"%d ", map[i][j]);
        }
    }

    for(i=1;i<=WIDTH;i++)
    {
        fprintf(fp,"%d ",attribute[i]);
    }

    fprintf(fp,"%d ",Heroindex);

    fprintf(fp,"%d\n", Hero->level);
    fprintf(fp,"%s\n", Hero->name);
    fprintf(fp,"%s\n", Hero->sex);
    fprintf(fp,"%d\n", Hero->hp);
    fprintf(fp,"%d\n", Hero->atk);
    fprintf(fp,"%d\n", Hero->def);
    fprintf(fp,"%d\n", Hero->reh);
    fprintf(fp,"%d\n", Hero->exp);
    fprintf(fp,"%d\n", Hero->money);
    fprintf(fp,"%s\n", wep_field->name);
    fprintf(fp,"%d\n", wep_field->atk);
    fprintf(fp,"%s\n", arm_field->name);
    fprintf(fp,"%d\n", arm_field->def);

    fprintf(fp,"%d\n", num_weapons);
    for(i=0;i<num_weapons;i++)
    {
        fprintf(fp,"%s\n",wep_inventory[i].name);
        fprintf(fp,"%d\n",wep_inventory[i].atk);
    }

    fprintf(fp,"%d\n", num_armors);
    for(i=0;i<num_armors;i++)
    {
        fprintf(fp,"%s\n",arm_inventory[i].name);
        fprintf(fp,"%d\n",arm_inventory[i].def);
    }

    fprintf(fp,"%d\n", num_items);
    for(i=0;i<num_items;i++)
    {
        fprintf(fp,"%s\n",item_inventory[i].name);
        fprintf(fp,"%d\n",item_inventory[i].heal);
    }
    fclose(fp);
}

void Load()
{
    FILE *fp;
    int i, j;
    fp=fopen("record.txt","r");

    for(i=1;i<=WIDTH;i++)
    {
        for(j=1;j<=WIDTH;j++)
        {
            fscanf(fp,"%d", &map[i][j]);
        }
    }

    for(i=1;i<=WIDTH;i++)
    {
        fscanf(fp,"%d", &attribute[i]);
    }

    fscanf(fp,"%d", &Heroindex);

    fscanf(fp,"%d", &Hero->level);
    while(fgetc(fp)!='\n');
    fgets(Hero->name,30,fp);
    Hero->name[strlen(Hero->name)-1]='\0';

    fgets(Hero->sex,30,fp);
    Hero->sex[strlen(Hero->sex)-1]='\0';

    fscanf(fp,"%d", &Hero->hp);
    fscanf(fp,"%d", &Hero->atk);
    fscanf(fp,"%d", &Hero->def);
    fscanf(fp,"%d", &Hero->reh);
    fscanf(fp,"%d", &Hero->exp);
    fscanf(fp,"%d", &Hero->money);
    while(fgetc(fp)!='\n');
    fgets(wep_field->name,30,fp);
    wep_field->name[strlen(wep_field->name)-1]='\0';

    fscanf(fp,"%d", &wep_field->atk);

    while(fgetc(fp)!='\n');
    fgets(arm_field->name,30,fp);
    arm_field->name[strlen(arm_field->name)-1]='\0';

    fscanf(fp,"%d", &arm_field->def);

    fscanf(fp,"%d", &num_weapons);
    for(i=0;i<num_weapons;i++)
    {
        while(fgetc(fp)!='\n');
        fgets(wep_inventory[i].name,30,fp);
        wep_inventory[i].name[ strlen(wep_inventory[i].name)-1 ]='\0';
        fscanf(fp,"%d",&wep_inventory[i].atk);
    }

    fscanf(fp,"%d", &num_armors);
    for(i=0;i<num_armors;i++)
    {
        while(fgetc(fp)!='\n');
        fgets(arm_inventory[i].name,30,fp);
        arm_inventory[i].name[ strlen(arm_inventory[i].name)-1 ]='\0';
        fscanf(fp,"%d",&arm_inventory[i].def);
    }

    fscanf(fp,"%d", &num_items);
    for(i=0;i<num_items;i++)
    {
        while(fgetc(fp)!='\n');
        fgets(item_inventory[i].name,30,fp);
        item_inventory[i].name[ strlen(item_inventory[i].name)-1 ]='\0';
        fscanf(fp,"%d",&item_inventory[i].heal);
    }
    fclose(fp);
}

void menu_ingame()
{
    int optionindex = 0;
    char code[5];

    while(1)
    {
        printf("\n=======================\n\n");
        printf("open package enter '1'.\n");
        printf("file save enter '2'.\n");
        printf("file load enter '3'.\n");
        printf("quit game enter '4'.\n");
        printf("back to game enter '5'.\n");

        scanf("%s", code);
        system("cls");
        if(strlen(code)==1 && is_number(code))
        {
            optionindex = atoi(code);

            if(optionindex==1)
            {
                openPackage();
                break;
            }

            else if(optionindex==2)
            {
                Save();
                break;
            }

            else if(optionindex==3)
            {
                Load();
                break;
            }

            else if(optionindex==4)
            {
                exit(0);
            }
            else if(optionindex==5)
            {
                return;
            }
            else printf("Wrong command.\n");
        }
        else printf("Wrong command.\n");
    }
}










