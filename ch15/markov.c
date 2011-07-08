#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define PER_INPUT_SIZE 5000000 * sizeof(char)
#define WORD_SIZE 1000000

char *inputchars;
long long input_size;

char *word[WORD_SIZE];

void build_markov()
{
    int i = 0;
    
    inputchars = (char *)malloc(PER_INPUT_SIZE);
    assert(inputchars != NULL);

    word[0] = &inputchars[0];
    
    while(scanf("%s", word[i]) != EOF && i < WORD_SIZE){
        word[i + 1] = word[i] + strlen(word[i]);
        //printf("%s ", word[i]);
        i ++;
    }

    printf("\n");
}

int main()
{
    build_markov();

	return 0;
}
