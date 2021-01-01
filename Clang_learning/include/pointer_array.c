//
//  pointer_array.c
//  Clang_learning
//
//  Created by 刘洋 on 2020/12/31.
//

#include "pointer_unit.h"
#include <string.h>
#define BUF_LEN 100
#define INIT_STR_EXT 50
#define WORDS_INCR 5

void pointer_array(void)
{
    char delimiters[] =" \n\".,;:!?)(";
    char buf[BUF_LEN];
    size_t str_size = INIT_STR_EXT;
    char *pStr = malloc(str_size);
    *pStr = '\0';
    
    printf("Enter some prose with up to %d characters per line.\nTerminate input by entering an empty line: \n", BUF_LEN);
    
    //Read mutiple lines of prose from the keyboard
    while(true)
    {
        fgets(buf, BUF_LEN , stdin);
        if(buf[0] == '\n') break;
        if(strnlen(pStr, str_size) + strnlen(buf, BUF_LEN) + 1 > str_size)
        {
            str_size += 100;
            pStr = realloc(pStr, str_size);
        }
        if(strncat(pStr, buf, strnlen(buf, BUF_LEN)))
        {
            printf("Something's wrong. String concatenation failed.\n");
            return;
        }
    }
}

