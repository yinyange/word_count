#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 10

struct term
{
    char* text;
    size_t count;
    struct term* next;
};

typedef struct term Word;

// print all the words in the linked list 
void wordprint(Word *p)
{
    if (p != NULL) 
    {
        printf("%3d  %s\n", p->count, p->text);
        wordprint(p->next);
    }
}

// add a new word into the linked list
Word *addword(Word *p, char *w)
{
    if (p == NULL) 
    { 
        p = malloc(sizeof(Word)); 
        p->text = w;
        p->count = 1;
        p->next = NULL;
    } 
    else if (strcmp(w, p->text) == 0)
    {
        p->count++;
    }
    else
    {
        p->next = addword(p->next, w);
    }
    return p;
}

size_t main()
{
    Word* firstWord = NULL;
    char* input[N] = {"hi", "go", "go", "go", "go", "world","apple", "hi", "hi", "hiflsjafjsafsjfsdjslfjsafs"};;
    size_t inputindex = 0;
    
    // build the linked list
    for(; inputindex < N; ++inputindex)
    {
        char* currentword = input[inputindex];
        firstWord = addword(firstWord, currentword);
    }        
    wordprint(firstWord);
    
    printf("\n");
    
    // print all the words sorted by their counts from largest to smallest 
    size_t printedcount = N + 1;
    size_t maxcount = 0;
    for(Word* a = firstWord; a != NULL; a = a->next)
    {
        for(Word* b = firstWord; b != NULL; b = b->next)
        {
            if(maxcount < (b->count) && (b->count) < printedcount)
            {
                    maxcount = b->count;
            }
        }
        printedcount = maxcount;
        for(Word* c = firstWord; c != NULL; c = c->next)
        {
            if((c->count) == printedcount)
            {
                printf("%3d, %s\n", c->count, c->text);
            }
        }
        maxcount = 0;
    }
    
    //before 'main()' exiting, free all allocated memory
    for(Word* a = firstWord; a != NULL; )
    {
        Word* toFree = a;
        a = a->next;
        //free(toFree->text);
        free(toFree);
    }
    
    return 0;
}