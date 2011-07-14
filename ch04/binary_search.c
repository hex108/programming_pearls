#include<stdio.h>

//The program in programing pearls 9.3 is perfect!  
//while the following is just so 
int binary_search(int *a, int num, int t)
{
    int start = 0, end = num - 1;
    int p = -1;
    
    while(end >= start){
        printf("%d ~ %d\n", start, end);
        int middle = start + (end - start) / 2;
        int tmp = a[middle];
        if(tmp < t){
            start = middle + 1;
        }else if(tmp > t){
            end = middle - 1;
        }else{
            //Version 1: just return an random element that equals "t".
            return middle;

            //Version 2: find the first element that equals "t".
            //p = middle;
            //end = middle - 1;
        }
    }

    return p;
}

int main()
{
    int a[] = { 3, 3, 3, 3, 3, 11};

    int m = binary_search(a, 6, 3);

    printf("%d\n", m);

	return 0;
}
