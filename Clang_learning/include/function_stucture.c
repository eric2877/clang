//
//  function_stucture.c
//  Clang_learning
//
//  Created by 刘洋 on 2021/1/10.
//

#include "function_stucture.h"
#define BUF_LEN 256
#define INIT_NSTR 2
#define NSTR_INCR 2

void sort_str_fun(void)
{
    size_t pS_size = INIT_NSTR;
    char** ps = calloc(pS_size, sizeof(char));
    if(!ps)
    {
        printf("Failed to allocate memory!");
        return;
    }
    
    char** pTemp = NULL;
    size_t str_count = 0;
    char* pStr =NULL;
    printf("Enter one string per line. Press Enter to end:\n");
    while((pStr = str_in())!= NULL)
    {
        pS_size += NSTR_INCR;
        if(str_count == pS_size)
        {
            
        }
    }
    
}
