#include <stdio.h>

void insert_sort(int *a, int n)
{
    int i,j;
    
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

int main()
{
    int a[] = {2, 200, 4, 9, 7, 30, 1};
    int size = sizeof(a) / sizeof(a[0]);

    insert_sort(a, size);
    
    int i;
    for(i = 0; i < size; i ++){
        printf("%d ",a[i]);
    }
    puts("");

	return 0;
}
