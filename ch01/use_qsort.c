#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cmp(const void *a,const void *b)
{
    return (*(int *)a) > (*(int *)b);
}

int main()
{
    int *array = malloc(10000000 * sizeof(int));
    FILE *fp = fopen("test.txt","r");
    int num = 0,i;

    if(fp == NULL || array == NULL){
        fprintf(stderr, "error\n");
        return 0;
    }
    
    while(fscanf(fp, "%d", &array[num]) != EOF)
        num ++;

    qsort(array, num, sizeof(int), cmp);
    
    for(i = 0; i < num; i ++){
        fprintf(stdout , "%d\n", array[i]);
    }

	return 0;
}

