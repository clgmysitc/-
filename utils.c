#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

int is_number(char *a)
{
    int all_digit = 1;
    for(int i=0;i<strlen(a);i++)
    {
        if(!isdigit(a[i]) )
        {
            all_digit = 0;
            break;
        }
    }
    return all_digit;
}