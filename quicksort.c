#include <stdio.h>

void Swap(int *x, int *y) {
    int tmp;

    tmp= *x;
    *x = *y;
    *y = tmp;
}

void Partition(int S[], int low, int high, int *pivotpoint)
{
    int i, j;
    int pivotitem = S[low];
    j = low;

    for(i = low + 1; i <= high; i++) {
        if(S[i] < pivotitem){
            j++;
            Swap(&S[i], &S[j]);
        }
    }
    *pivotpoint = j;
    Swap(&S[low], &S[j]);
}

void QuickSort(int S[], int low, int high)
{
    int pivotpoint;

    if (high > low)
    {
        Partition(S, low, high, &pivotpoint);
        QuickSort(S, low, pivotpoint - 1);
        QuickSort(S, pivotpoint + 1, high);
    }
}

int main(void)
{
    int S[8] = {15, 22, 13, 27, 12, 10, 20, 25};
    
    QuickSort(S, 0, 7);

    for (int i = 0; i < 8; i++)
    {
        printf("%d ", S[i]);
    }

    return 0;
}