#include<stdio.h>

#define NUM 10

int num[NUM] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};

int main()
{
    int start = 0;
    int end = 0;
    int i;
    long maxsofar = 0; 
    long maxendinghere = 0;
    int maxstarthere = 0;

    for(i = 0; i < NUM; i ++){
        long tmp = maxendinghere + num[i];
        if(tmp > 0){
            maxendinghere = tmp;
        }else{
            maxstarthere = i + 1;
            maxendinghere = 0;
        }
        if(maxsofar < maxendinghere){
            start = maxstarthere;
            end = i;
            maxsofar = maxendinghere;
        }
    }

    fprintf(stderr,"start = %d , end = %d\n", start, end);

	return 0;
}
