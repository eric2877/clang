//
//  pointer_realloc.c
//  Clang_learning
//  动态分配内存
//  Created by 刘洋 on 2020/12/31.
//

#include "pointer_unit.h"
#define CAP_INCR 10

void pointer_realloc(void)
{
    unsigned long long *pPrimes =NULL;
    bool found = false;
    unsigned long long limit = 0ULL;
    int count = 0;
    size_t capacity = 10;
    
    printf("How many primes woould you like - you'll get at least 4?");
    scanf("%llu", &limit);
    
    limit = limit > 4 ? limit : 4;
    pPrimes = calloc((size_t) capacity, sizeof(unsigned long long));
    *pPrimes = 2ULL;
    *(pPrimes+1) = 3ULL;
    *(pPrimes+2) = 5ULL;
    count =3;
    unsigned long long *pTem = NULL;
    unsigned long long trial = *(pPrimes + 2);
    
    while(trial <= limit)
    {
        trial += 2ULL;
        for(int i=0; i < count; i++)
        {
            if(!(found = trial % *(pPrimes+i)))
            {
                break;
            }
        }
        if(found)
        {
            if(count == capacity)
            {
                capacity += CAP_INCR;
                pTem = realloc(pPrimes, capacity*sizeof(unsigned long long));
                if(!pTem)
                {
                    printf("Unfortunately memeory reallocation failded. \n");
                    free(pPrimes);
                    pPrimes = NULL;
                    return;
                }
//                free(pPrimes);
                pPrimes = pTem;
            }
            *(pPrimes + count++) = trial;
        }
    }
    
    printf("%d primes are found up to %llu: \n", count, limit);
    for(int i =0; i< count; ++i)
    {
        printf("%12llu", *(pPrimes+i));
        if(!((i+1) % 5))
        {
            printf("\n");
        }
    }
    
    printf("\n");
    free(pPrimes);
    pPrimes = NULL;   
    
    
}
