//
//  pointer_exercise.c
//  Clang_learning
//
//  Created by 刘洋 on 2021/1/6.
//

#include "pointer_unit.h"
#define BUF_LEN 256

void pointer_calculater(void)
{
    char buf[BUF_LEN];
    char op = 0;
    size_t index = 0;   //Index of the current character in buf
    size_t to = 0;      //To index for copying buf to itself
    size_t buf_length = 0; //Length of the string in buff
    
    double result =0.0;
    double number = 0.0;
    
    printf("To use this calculator, enter any expression whit or without white spaces\n");
    printf("Na expression may include the operators");
    printf("+,-,*,/,%% or ^(raise to a power).");
    printf("\nUse = at the beginning of a line to operate on the ");
    printf("result of the previous calculation.\n");
    
    char* ptr = NULL;
    char* endPtr = NULL;
    
    while (true) {
        ptr = fgets(buf, BUF_LEN, stdin);
        if(!ptr)
        {
            printf("Error reading input. \n");
        }
        
        if(strcmp(buf, "quit\n") == 0) break;
        buf_length = strnlen(buf, BUF_LEN);
        buf[--buf_length] =(int)"\0";
        
        // delete white space
        for(index=0, to =0; index <= buf_length; index++)
        {
            if( buf[index] != ' ')
            {
                buf[to++] = buf[index];
            }
        }
        
        // recount length
        buf_length = strnlen(buf, buf_length);
        
        index = 0;
        if(buf[index] == '=')
        {
            endPtr = buf + ++index;
        } else{
            result = strtod(buf+index, &endPtr);
        }
        
        
        while(*endPtr != '\0')
        {
            op = *endPtr;
            number = strtod(endPtr + 1, &endPtr);
            switch (op) {
                case '+':
                    result += number;
                    break;
                case '-':
                    result -= number;
                    break;
                case '*':
                    result *= number;
                    break;
                case '/':
                    result /= number;
                    break;
                case '%':
                    if(number == 0LL)
                    {
                        printf("输入错误");
                    }
                    else
                    {
                        result = (double)((long long)result % (long long)number);
                    }
                default:
                    break;
            }
        }
        
        printf("%.2lf\n", result);
        
    }
}
