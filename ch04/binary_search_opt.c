#include <stdio.h>
#include <stdlib.h>

int binary_search(int *a, int num, int t)
{
    int low = -1, high = num - 1;
    
    //invariant: low < high && a[low] < t && a[high] >= t
    while(low + 1 != high){
        //printf("%d ~ %d\n", low, high);
        int middle = low + (high - low) / 2;
        if(a[middle] < t){
            low = middle;
        }else{
            high = middle;
        }
    }
    
    //assert low +1 = high && a[low] < t && a[high] >= t
    if(a[high] != t)
        return -1;
    else
        return high;
}

int int_cmp(const int *a, const int *b)
{
    return (*a - *b);
}

int main()
{
    int a[] = { 3, 3, 3, 3, 3, 11};

    int m = binary_search(a, 6, 3);
    
    printf("%d\n", m);
    
    int b = 3;
    int *n = bsearch(&b, a, 6, sizeof(int), int_cmp);
    
    printf("%d\n", n -  a);

	return 0;
}
