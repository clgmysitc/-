#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "character.h"


void gamemap()
{
    int i,j;
    int t;

    for(int i=1 ; i<=WIDTH ; i++) p[i] = i;


    for(i=1;i<=WIDTH;i++)
    {
        for(j=i+1;j<=WIDTH;j++)
        {
            t = rand()%10;
            if(t>4)
            {
                map[i][j]=1;
                map[j][i]=1;
                link(i, j);
            }
            else
            {
                map[i][j]=0;
                map[j][i]=0;
            }
        }
    }

    for(int i=1 ; i<=WIDTH ; i++)
    {
        for(int j=i+1 ; j<=WIDTH ; j++)
        {
            if(root(i) != root(j))
            {
                map[i][j] = map[j][i] = 1;
                link(i, j);
            }
        }
    }

    for(i=1;i<=WIDTH;i++)
    {
        attribute[i] = rand() % 4;
    }
}

int root(int x)
{
    return p[x]==x ? x : (p[x] = root(p[x]) );
}

void link(int x, int y)
{
    x = root(x);
    y = root(y);
    p[x] = y;
}
