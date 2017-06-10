#include <stdio.h>

#define MAX 6
int main(void)
{
    int v[MAX]={0};
    int i, j,  aux;

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
            if(v[i]>v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
            else
                continue;
        }
    }
    for(i=0; i<MAX; i++)
        printf("O vetor %d  -> %d \n", i, v[i]);

    return 0;
}

/*Metodo alternativo*/
/*Faz a ordem crescente mas por meio da pozicao (indices)*/
/*int main(void)
  {
  int v[MAX]={5,6,2,4,1,3};
  int id[MAX]={4,2,5,3,0,1}; /*Posicao onde os vetores de v[] estao, em ordem crescente*/
/*int i;

  for(i=0; i<MAX; i++)
  printf("%d, ", v[id[i]]);*/  /*v[id[0]] -> v[4] -> 1*/
/*return 0;
  }*/
