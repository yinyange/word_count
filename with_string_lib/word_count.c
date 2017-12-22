#include <stdio.h>
#include <string.h>
#define MAXLINE 100
#define LENGTH 10
#define N 10
    
int main()
{
    char wordtable[MAXLINE][LENGTH] = {0};
    size_t count[MAXLINE] = {0};
    char* input[N] = {"go", "go", "go", "hi", "go", "world","apple", "hi", "hi", "hi"};
    int tablecount = 0;
    int inputindex = 0;
    
    for(int inputindex = 0; inputindex < N; ++inputindex)
    {
        char* currentword = input[inputindex];
        int i = 0;
        for(; i < tablecount; ++i)
        {
            if(strcmp(currentword, wordtable[i]) == 0)
            {
                break;
            }
        }
        if(i < tablecount)
        {
            ++count[i];
        }
        else
        {
            strcpy(wordtable[tablecount], currentword);
            ++tablecount;
            ++count[i];
        }
    }
    for(int i = 0; i < tablecount; ++i)
    {
        printf("%3d, %s\n", count[i], wordtable[i]);
    }
    printf("\n");
    
    int printedcount = N + 1;
    int maxcount = 0;
    for(int a = 0; a < tablecount; ++a)
    {
        for(int d = 0;d < tablecount; ++d)
        {
            
            if(maxcount < count[d] && count[d] < printedcount)
            {
                maxcount = count [d];
            }
        }
        printedcount = maxcount;
        for(int b = 0; b < tablecount; ++b)
        {
            if(count[b] == printedcount)
            {
                printf("%5d, %s\n", count[b], wordtable[b]);
            }
        }
        maxcount = 0;
    }
}
