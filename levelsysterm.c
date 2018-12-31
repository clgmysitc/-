#include <stdio.h>
#include "levelsysterm.h"
#include "character.h"


void level_up()
{
    expup = (Hero->level*20) + 30;
    while(Hero->exp >= expup)
    {
        printf("you level up!!!!\n");
        Hero->exp-=expup;
        Hero->level++;
        Hero->hp += 250;
        Hero->atk+=20;
        Hero->def+=20;
        Hero->reh+=20;
    }
}
