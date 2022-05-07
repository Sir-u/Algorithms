#include <stdio.h>

void Swap(int *x, int *y) {
    int tmp;

    tmp= *x;
    *x = *y;
    *y = tmp;
}

int Partition(int S[], int low, int high)
{
    int i, j;
    
    return 0;
}

void QuickSort(int S[], int low, int high)
{
    int pivotpoint;

    if (high > low)
    {
        pivotpoint = Partition(S, low, high);
        QuickSort(S, low, pivotpoint - 1);
        QuickSort(S, pivotpoint + 1, high);
    }
}

int main(void)
{
        
    int S[10] = {4, 3, 5, 2, 7, 1, 9, 8, 0, 6};

    QuickSort(S, 0, 9);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", i);
    }

    return 0;
}