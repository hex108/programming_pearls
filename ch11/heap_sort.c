#include <stdio.h>

void swap(int *a, int i, int j)
{
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void max_heapify(int *a, int i, int heap_size)
{
    int l, r, largest;
    l = 2 * i + 1;
    r = 2 * i + 2;

    if(l < heap_size && a[l] > a[i]){
        largest = l;
    }else{
        largest = i;
    }

    if(r < heap_size && a[r] > a[largest]){
        largest = r;
    }
    if(largest != i){
        swap(a, i, largest);
        max_heapify(a, largest, heap_size);
    }
}

void build_max_heap(int *a, int n)
{
    int i;

    for(i = (n - 2)/ 2; i >= 0; i --){
        max_heapify(a, i, n);
    }
}

void heap_sort(int *a, int n)
{
    int heap_size = n;
    int i;

    build_max_heap(a, n);

    for(i = n  - 1; i > 0; i --){
        swap(a, 0, i);
        heap_size --;
        max_heapify(a, 0, heap_size);
    }
}

int main()
{
    int a[] = {2, 200, 4, 9, 7, 30, 1, 400, 6, 10, 9};
    int size = sizeof(a) / sizeof(a[0]);

    heap_sort(a, size);
    
    int i;
    for(i = 0; i < size; i ++){
        printf("%d ",a[i]);
    }
    puts("");

	return 0;
}
