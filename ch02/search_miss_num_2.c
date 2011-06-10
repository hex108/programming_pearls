#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN 2
#define NUM ((MIN + 31)/32)
int a[NUM];
char *file[3] = {"tmp1", "tmp2", "tmp3"};

int search(char *filename, unsigned int start, unsigned int end)
{
    FILE *fp = fopen(filename,"r");

    if(fp == NULL)
        return 0;

    unsigned int i,j;

    while(fscanf(fp, "%d", &i) != EOF){
        i -= start;
        a[i/32] |= 1 << (i % 32);
    }
    
    for(i = 0; i < NUM; i ++){
        if(a[i] == -1)
            continue;

        for(j = 0;j < 32; j ++){
            if((a[i] & (1 << j)) == 0){
                fclose(fp);
                return (i * 32 + j + start);
            }
        }
    }
    fclose(fp);
    return -1;
}

int search_miss_num(unsigned int start, unsigned int end)
{
    char *filename = file[0];
    FILE *fp = fopen(filename,"r");
    char *file1 = file[1];
    FILE *fp_tmp1 = fopen(file1,"w");
    char *file2 = file[2];
    FILE *fp_tmp2 = fopen(file2,"w");

    if(fp == NULL || fp_tmp1 == NULL || fp_tmp2 == NULL){
        printf("error ,cannot open file\n");
        exit(-1);
    }

    unsigned int i;
    unsigned int count1 = 0, count2 = 0;
    unsigned int middle = (start + end) / 2;

    while(fscanf(fp, "%d", &i) != EOF){
        if(i <= middle){
            fprintf(fp_tmp1, "%d ", i);
            count1 ++;
        }else{
            fprintf(fp_tmp2, "%d ", i);
            count2 ++;
        }
    }

    fclose(fp);
    fclose(fp_tmp1);
    fclose(fp_tmp2);

    if(count1 + count2 <= MIN){
        return search(filename, start, end);
    }

    if(count1 < count2){
        file[0] = file1;
        file[1] = filename;
        return search_miss_num(start, middle);
    }
    else{
        file[0] = file2;
        file[2] = filename;
        return search_miss_num(middle + 1, end);
    }
}

void copy_file(char *dest, char *src)
{
    FILE *fp_dest = fopen(dest, "wb");
    FILE *fp_src = fopen(src, "rb");
    char buf[1000];

    if(fp_dest == NULL || fp_src == NULL){
        printf("error, cannot open file.\n");
        exit(-2);
    }

    while(!feof(fp_src)){
        int size = fread(buf, sizeof(char), 1000, fp_src);
        fwrite(buf, sizeof(char), size, fp_dest);
    }

    fclose(fp_dest);
    fclose(fp_src);
}

int main()
{
    int i;
    
    copy_file(file[0], "test.in");
    
    i = search_miss_num(1, 4290000000U);

    printf("miss num : %d \n", i);

	return 0;
}
