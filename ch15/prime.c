#include <stdio.h>
#include <math.h>

int is_prime(long long num)
{
    long long i;
    long long tail = sqrt(num);
    
    if(num % 2 == 0)
        return 0;

    for(i = 3; i <= tail; i += 2){
        if(num % i == 0)
            return 0;
    }

    return 1;
}

//return the successive prime after l
long long prime(long long l)
{
    long long i;
    i = l;

    if(i % 2 == 0)
        i ++;
    else
        i += 2;
    for(; ; i += 2){
        if(is_prime(i))
            return i;
    }
}

int main()
{
    long long n;
    while(scanf("%lld", &n) != EOF){
        printf(" -> %lld\n", prime(n));
    }

	return 0;
}

