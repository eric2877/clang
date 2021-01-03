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
        // if input string is larger than pStr, then resize pStr loc.
        if(strnlen(pStr, str_size) + strnlen(buf, BUF_LEN) + 1 > str_size)
        {
            str_size += 100;
            pStr = realloc(pStr, str_size);
        }
        if(!(strncat(pStr, buf, strnlen(buf, BUF_LEN))))
        {
            printf("Something's wrong. String concatenation failed.\n");
            return;
        }
    }
    
    //Find and list all the words in the prose
    size_t maxWords = 10;
    int word_count = 0;
    size_t word_length = 0;
    char** pWords = calloc(maxWords,sizeof(char*));
    int*   pnWord = calloc(maxWords, sizeof(int));
    
    char* ptr = NULL;
    char* pWord = strtok_r(pStr, delimiters, &ptr);
    bool new_word;
    while(pWord)
    {
        new_word = true;
        // Check for existing word
        for(int i = 0 ; i< word_count; ++i)
        {
            if( *(pWords + i) != NULL && strcmp(pWord, pWords[i]) == 0)
            {
                ++(pnWord[i]);
                new_word = false;
                break;
            }
        }
        
        if(new_word)
        {
            if( word_count == maxWords)
            {
                maxWords += WORDS_INCR;
                pWords = realloc(pWords, maxWords * sizeof(char*));
            }
            word_length = (ptr - pWord)*sizeof(char*);
            // 复制string到新分配的内存中
//            *(pWords + word_count) = calloc(word_length, sizeof(char));
//            strcpy(*(pWords + word_count), pWord);
            *(pWords + word_count) = pWord;
            *(pnWord + word_count++) = 1;
        }
        
        pWord = strtok_r(NULL, delimiters, &ptr);
    }
    
    //output the words and counts
    for(int i = 0; i < word_count; ++i)
    {
        printf(" %s %3d", pWords[i], pnWord[i] );
        if((i+1)%4==0) printf("\n");
    }
    
    printf("\n");
    free(pWords);
    free(pnWord);
    free(pStr);
    pWords = NULL;
    pStr = NULL;
    pnWord = NULL;
    
    
}

