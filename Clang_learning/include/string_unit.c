//
//  string_unit.c
//  Clang_learning
//
//  Created by 刘洋 on 2020/12/31.
//

#include "string_unit.h"

void str_concat(void)
{
    char str1[100] =" destination string array is this, ";
    char str2[] = "source string array is added.";
    strncat(str1, str2, strnlen(str2, 40));
    printf("%s", str1);
}

void str_copy(void)
{
    char str1[30] = "this is the first string,";
    char str2[] = "this is the second string";
    char str3[50] = "";
    printf("first string length is %zu, first array length %zd \n", strnlen(str1, sizeof(str1)), sizeof(str1));
    printf("second string length is %lu, second array length %zd \n", strlen(str2), sizeof(str2));
    strncpy(str3, str2, 50);
    printf("%s", str3);
}

void str_search(void)
{
    // string search needs pointer
    char str1[] ="This is the destination string, questions";
    char ch = 'q';
    char *pGot_char = NULL;
    // 这里返回的是一个指针类型
    pGot_char = strchr(str1, ch);
    // 输出时可以根据指针的标识符
    printf("search char q find %s \n", pGot_char);

    char str2[]= "string";
    pGot_char = strnstr(str1, str2, 40);
     printf("search str 'string' find %s \n", pGot_char);

}
