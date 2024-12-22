#include "../boolean.h"
#include <stdio.h>

void strcpyHomemade(char* dest, const char* source) {
    int i = 0;
    while (source[i] != '\0')
    {
        dest[i] = source[i];
        i++;
    }

    dest[i] = source[i];
}

int Uppercased_Char(int num)
{
    if (num >= 'a' && num <= 'z')
    {
        return (num - 32);
    }

    return num;
}

int isStringEqual(const char* s1, const char* s2) {
    int i = 0;
    while(s1[i] != '\0' || s2[i] != '\0') {
        if(s1[i] != s2[i]) return 0;
        ++i;
    }
    return 1;
}

boolean is_same_string(const char str1[], const char str2[])
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        // printf("%d %d %d\n", i, Uppercased_Char(str1[i]), Uppercased_Char(str2[i]));
        if (Uppercased_Char(str1[i]) != Uppercased_Char(str2[i]))
        {
            return false;
        }
        i++;
        // printf("%d %d\n", str1[i] == '\0', str2[i] == '\0');
        // printf("%d\n",i);
    }
    // puts("asbabvdyuedceiducbdjsbcsia");
    // return (str1[i] == '\0' && str2[i] == '\0');
    return true;
}

// int strlenHomemade(const char* s) {
//     int i = 0;
//     while(s[i] != '\0') ++i;
//     return i;
// }

// void concat(char* dest, const char* s) {
//     dest = dest + strlenHomemade(dest);
//     while(*s) *dest++ = *s++;
//     *dest = *s;
// }

