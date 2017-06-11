#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 6

void move(int v[MAX], int a, int j);

int main(void)
{
    int v[MAX]={0};
    int i, j, a, aux;

    srand((unsigned)time(NULL));

    for(i=0; i<MAX; i++)
    {
        v[i] = rand() % 10;
        for(j=0; j<i; j++)
        {
            if(v[j]==v[i])
                v[i] = rand() % 10;
        }
    }

    printf("O valor inicial:\n");
    for(i=0; i<MAX; i++)
        printf("v[%d]  ->  %d \n", i, v[i]);

    for(i=0; i<MAX-1; i++)
    {
        for(j=i+1; j<MAX; j++)
        {
            if(v[j]<v[i])
            {
                a = i;
                do
                {
                    if(v[j]>v[a-1])
                    {
                        move(v[MAX], a, j);
                        break;
                    }
                    else
                    {
                        continue;
                    a--;
                    }
                }while(v[j]>v[a-1]);
            }
            else
                continue;
        }
    }
                    
    printf("O valor final:\n");
    for(i=0; i<MAX; i++)
        printf("v[%d]  ->  %d \n", i, v[i]);
    return 0;
}

void move(int v[MAX], int a, int j)
{
    int aux2;

    do /*Vai passando os valores para o lado até o fim do que ja foi visto até então*/
    {
        aux2 = v[a+1];
        v[a+1] = v[a];
        a++;
    }while(a<j);
    v[a]=v[j];

    return;
}
