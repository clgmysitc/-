#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "map.h"
#include "initmenu.h"
#include "event.h"
#include "weapon.h"
#include "armor.h"
#include "item.h"
#include "battlesysterm.h"
#include "menuingame.h"
#include <string.h>
#include "utils.h"
#include "character.h"


int main()
{
    srand(time(NULL));
    menu_init();
    int i;
    char code[5];
    int choose;
    Heroindex = 1;
    while(1)
    {

        situation();
        printf("\n============================================\n");
        printf("You can go to road :");
        for(i=1;i<=WIDTH;i++)
        {
            if(map[i][Heroindex]==1)
            {
                printf("%d  ", i);
            }
        }
        printf("\n");
        printf("if you want to open menu, enter 'm' .\n");
        scanf("%s", code);
        system("cls");
        situation();

        if(is_number(code))
        {
            choose = atoi(code);
            if(map[Heroindex][choose] == 1)
            {
                Herostep++;
                if(Herostep == 50)
                {
                    bossindex = rand() % WIDTH + 1;
                    attribute[bossindex] = 4;
                }
                Heroindex = choose;
                trigger_event(choose);
            }
            else
            {
                system("cls");
                printf("Wrong destination.\n");
                printf("\n===========================\n\n");
            }
        }

        else if(code[0]=='m')
        {
            menu_ingame();
        }
        else printf("Wrong command.\n");
    }
}

