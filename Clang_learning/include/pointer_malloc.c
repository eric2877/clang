//
//  pointer_unit.c
//  Clang_learning
//
//  Created by 刘洋 on 2020/12/31.
//
#include "pointer_unit.h"


void pointer_malloc(void)
{
    unsigned  long *pPrimes =NULL;
    unsigned  long trial =0;
    int total = 0;
    int count = 0;
    bool found = false;

    printf("How many primes woould you like - you'll get at least 4?");
    scanf("%d", &total);
    total = total > 4 ? total : 4;

    pPrimes = (unsigned long*)malloc(total*sizeof(unsigned long));
    
    *pPrimes = 2UL;
    *(pPrimes+1) = 3UL;
    *(pPrimes+2) = 5UL;
    trial = 5UL;
    count =3;

    while ( count < total )
    {
        trial += 2UL;
        for (int i =0; i < count; i++)
        {
            if (!(found = trial % *(pPrimes+i))) break;
        }
        if (found ) *(pPrimes + count++) = trial;
    }

    //Display all Primes
    for (int i = 0; i < total; i++)
    {
        printf("%5lu", *(pPrimes+i));
        if(!((i+1)%5))
        {
            printf("\n");
        }
    }
    printf("\n");
    free(pPrimes);
    pPrimes = NULL;
    return;
}
