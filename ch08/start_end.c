#include<stdio.h>

#define NUM 10

int num[NUM] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
int sum[NUM][NUM];

int main()
{
    int start = 0;
    int end = 0;
    int i,j;

    long max = num[0]; 

    for(i = 0; i < NUM; i ++){
        sum[i][i] = num[i];
    }
    
    for(i = 0; i < NUM; i ++){
        for(j = i + 1; j < NUM; j++){
            sum[i][j] = sum[i][j - 1] + num[j];
            if(sum[i][j] > max){
                start = i;
                end = j;
                max = sum[i][j];
                //printf("i : %d , j : %d , max : %ld \n", i, j, max);
            }
        }
    }
    
    fprintf(stderr,"start = %d , end = %d\n", start, end);

	return 0;
}
