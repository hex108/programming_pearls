#include <stdio.h>
#include <stdlib.h>

#define QUICK_MIN 3

void swap(int *a, int i, int j)
{
    int tmp = a[j];
    a[j] = a[i];
    a[i] = tmp;
}

void insert_sort(int *a, int n)
{
    int i,j;
    
    if(n <= 0)
        return;

    for(i = 0; i < n - 1; i ++){
        //invariant: a[0] <= a[1] <= ... <= a[i]
        //insert a[i + 1] to a[0] ~ a[i] in order to promise a[0] <= ... <= a[i + 1]
        int tmp = a[i + 1];
        int j;
        for(j = i; j >=0 && a[j] > tmp; j --){
            a[j + 1] = a[j];
        }
        a[j + 1] = tmp; 
        //invariant: a[0] <= a[1] <= ... <= a[i + 1]
    }
}

void quick_sort(int *a, int n)
{
    if(n < QUICK_MIN){
        insert_sort(a, n);
        return;
    }
    
    int tmp = rand() % n;
    printf("tmp : %d\n", tmp);
    int sentinal = a[tmp];

    swap(a, tmp, n - 1);

    int i,j;
    //invariant: a[0] ~ a[i] < sentinal, a[j + 1] ~ a[n - 1] >= sentinal 
    for(i = 0, j = n - 2; i <= j; ){
        if(a[i] >= sentinal){
            swap(a, i, j);
            j --;
        }else{
            i ++;
        }
    }
    swap(a, i, n - 1);
    quick_sort(a, i);
    quick_sort(a + i + 1, n - i - 1);
}

int main()
{
    int a[] = {2, 200, 4, 9, 7, 30, 1};
    int size = sizeof(a) / sizeof(a[0]);

    quick_sort(a, size);
    
    int i;
    for(i = 0; i < size; i ++){
        printf("%d ",a[i]);
    }
    puts("");

	return 0;
}
