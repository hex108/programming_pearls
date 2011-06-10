#include<stdio.h>

void reverse(int *a, int start, int end)
{
    int i = start;
    int j = end;

    while(j > i){
        int tmp = a[j];
        a[j] = a[i];
        a[i] = tmp;
        j --;
        i ++;
    }
}

void rotate(int *a, int n, int i)
{
    reverse(a, 0, i - 1);
    reverse(a, i, n - 1);
    reverse(a, 0, n - 1);
}

int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9};
    int i;

    rotate(a, 9, 4);
    
    for(i = 0; i < 9; i ++){
        printf("%d ", a[i]);
    }
    puts("");
        
	return 0;
}
