#include <stdio.h>
#include <time.h>
#include <unistd.h>

const double busy = 2;
const double idle = 1000;

void foo(double percent)
{
    double start = clock() / CLOCKS_PER_SEC;

    for(;;){
        while((clock()/CLOCKS_PER_SEC - start) <= busy)
            ;

        usleep(idle);
    }
}

int main()
{
    foo(0.5);

	return 0;
}
