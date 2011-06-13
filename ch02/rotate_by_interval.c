#include<stdio.h>

void rotate(int *a, int n, int i)
{
    int j,k,m,sum;

    sum = 0;
    

    for(j = 0; j < i; j ++){
        int start = j;
        int mod1 = j % n;
        int mod2 = (i + j) % n;
        int t = a[mod1];
        while(mod2 != start){
           a[mod1] = a[mod2];
           mod2 = (mod2 + i) % n;
           mod1 = (mod1 + i) % n;
           sum ++;
        }
        a[mod1] = t;
        sum ++;
        if(sum >= n)
            return;
    }
}

#define NUM 9

int main()
{
    int a[NUM] = {1,2,3,4,5,6,7,8,9};
    int i;

    rotate(a, NUM, 4);
    
    for(i = 0; i < NUM; i ++){
        printf("%d ", a[i]);
    }
    puts("");
        
	return 0;
}
