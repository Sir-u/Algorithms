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
            U[k] = S[j];
            j++;
        }
        k++;
    }

    if (i > mid)
    {
        for (int l =j; l<=high; l++){
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
    int S[8] = {27, 10, 12, 20, 25, 13, 15, 22};

    MergeSort(S, 0, 7);

    for (int i = 0; i < 8; i++)
    {
        printf("%d ", S[i]);
    }

    return 0;
}