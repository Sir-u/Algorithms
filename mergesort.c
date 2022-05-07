#include <stdio.h>
#define MAX_SIZE 10;

void Merge(int S[], int low, int mid, int high)
{
    int i, j, k;
    int U[high];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (S[i] < S[j])
        {
            U[k] = S[i];
            i++;
        }
        else
        {
            U[k] = S[i];
            j++;
        }
        k++;
    }

    if (i > mid)
    {
        for (int l =j; l<=mid; l++){
            U[k++] = S[i];
        }
    }
    else
    {
        for (int l = i; l <= mid; l++)
            U[k++] = S[l];
    }

    for (int l = low; l <= high; l++)
    {
        S[l] = U[l];
    }
}

void MergeSort(int S[], int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;
        MergeSort(S, low, mid);
        MergeSort(S, mid + 1, high);
        Merge(S, low, mid, high);
    }
}

int main(void)
{
    
    int S[10] = {4, 3, 5, 2, 7, 1, 9, 8, 0, 6};

    MergeSort(S, 0, 9);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", i);
    }

    return 0;
}