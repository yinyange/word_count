#include "str.h"
int sameword(char *s, char *t)
{
    int i = 0;
    for(i = 0; s[i]!= '\0' && t[i]!= '\0'; ++i)
    {
        if(s[i]!= t[i])
        {
            return 0;
        }
    }
    if(s[i] == '\0' && t[i] == '\0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int copyword(char *s, char *t)
{
    int i = 0;
    for(i = 0; t[i] != '\0'; ++i)
    {
        s[i] = t[i];
    }
    return i;
}