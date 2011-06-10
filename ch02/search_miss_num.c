#include <stdio.h>
#include <limits.h>

#define NUM (UINT_MAX/32+1)

int a[NUM];

int main()
{
    FILE *fp = fopen("test.in","r");

    if(fp == NULL)
        return 0;

    int i,j;

    a[0] = 1;  //just to exclude 0.

    while(fscanf(fp, "%d", &i) != EOF){
        a[i/32] |= 1 << (i % 32);
    }
    
    for(i = 0; i < NUM; i ++){
        if(a[i] == -1)
            continue;

        for(j = 0;j < 32; j ++){
            if((a[i] & (1 << j)) == 0){
                fclose(fp);
                printf("a miss number : %d\n", i * 32 + j);
                return 0;
            }
        }
    }
    fclose(fp);

	return 0;
}
