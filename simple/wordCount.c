#include <stdio.h>

#define MAX_WORDS 100
#define WORD_LENGTH 10
#define INPUT_COUNT 10

int copyWord(char* source, char* target)
{
    size_t i = 0;
    for( ; source[i] != 0; ++i)
    {
        target[i] = source[i];
    }
    return i;
}

// @Return value:
// 1 - the same
// 0 - not the same
int sameWord(char* wordA, char* wordB)
{
    size_t i = 0;
    for( ; wordA[i] != 0 && wordB[i] != 0; ++i)
    {
        if(wordA[i] != wordB[i])
        {
            return 0;
        }
    }

    if(wordA[i] == 0 && wordB[i] == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int main()
{
    char savedWords[MAX_WORDS][WORD_LENGTH] = {0};
    size_t wordCounts[MAX_WORDS] = {0};
    size_t savedWordCount = 0;

    char* inputs[INPUT_COUNT] = {"hello", "world", "apple", "hello", "orange", "earth", "orange", "hello", "hello", "apple"};

    // Build the word count table
    for(size_t inputIndex = 0; inputIndex < INPUT_COUNT; ++inputIndex)
    {
        char* currentWord = inputs[inputIndex];

        // Check whether current word is already saved
        size_t savedIndex = 0;
        for( ; savedIndex < savedWordCount; ++savedIndex)
        {
            if(sameWord(savedWords[savedIndex], currentWord)==1)
            {
                break; // found a match between current word and a saved word
            }
        }

        if(savedIndex < savedWordCount)
        {
            // found a saved one, increase the count by 1
            ++wordCounts[savedIndex];
        }
        else
        {
            // not saved yet, save it with count 1
            copyWord(currentWord, savedWords[savedWordCount]);
            wordCounts[savedWordCount] = 1;
            ++savedWordCount;
        }

    }

    // print the table as it
    printf("\n");

    // print all words sorted by their counts from largest to smallest
    for(size_t printedCount = INPUT_COUNT + 1; printedCount > 1; )
    {
        // find the max times
        size_t nextMaxCount = 0;
        
        for(size_t i = 0; i < savedWordCount; ++i)
        {
            if(wordCounts[i] < printedCount && wordCounts[i] > nextMaxCount)
            {
                nextMaxCount = wordCounts[i];
            }
        }
        
        if(nextMaxCount > 0)
        {
            // print all words that appeared exactly 'nextMaxCount' times
            for(size_t i = 0; i < savedWordCount; ++i)
            {
                if(nextMaxCount == wordCounts[i])
                {
                    printf("%d    %s\n", nextMaxCount, savedWords[i]);
                }
            }
        }

        printedCount = nextMaxCount;
    }


    return 0;
}

