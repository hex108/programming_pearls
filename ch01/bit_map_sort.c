#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bit_map_sort.h"

#define ARRARY_NUM INT_MAX/8

void bit_map_sort(char *file_name)
{
    char *array; 
    int num,i;
    FILE *fp;

    array = (char *)calloc(ARRARY_NUM, sizeof(char)); 

    if(array == NULL){
        fprintf(stderr, "Sorry, not enough memory.\n");
        exit(-1);
    }

    fp = fopen(file_name, "r");
    
    if(fp == NULL){
        fprintf(stderr, "Sorry, cannot find the file %s\n", file_name);
        exit(-1);
    }

    while(fscanf(fp, "%d", &num) != EOF){
        set_bit(array, num);
    }

    print_array(array, ARRARY_NUM);

    free(array);
    fclose(fp);
}

void print_array(char *array, int num)
{
    int i;

    for(i = 0; i < num; i++){
        int j,base;
        if(array[i] == 0){
            continue;
        }
        base = i * 8;
        for(j = 0; j < 8; j ++){
            if(get_bit_by_index_offset(array, i, j))
                fprintf(stdout, "%d\n", base + j);
        }
    }
}

void set_bit(char *array, int count)
{
    int index = count / 8;
    int offset = count % 8;

    array[index] |= 1 << offset;
}

int get_bit(char *array, int count)
{
    int index = count / 8;
    int offset = count % 8;

    return get_bit_by_index_offset(array, index, offset);
}

int get_bit_by_index_offset(char *array, int index, int offset)
{
    return (array[index] & (1 << offset));
}
