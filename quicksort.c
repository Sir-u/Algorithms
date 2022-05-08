#include <stdio.h>

// Swap A for B
void Swap(int *x, int *y) {
    int tmp;

    tmp= *x;
    *x = *y;
    *y = tmp;
}

// 분할 알고리즘 (배열을 분할)
void Partition(int S[], int low, int high, int *pivotpoint)
{
    int i, j;
    int pivotitem = S[low];       // pivotitem으로 첫 원소를 선택
    j = low;                      // low를 j에 저장

    for(i = low + 1; i <= high; i++) {
        if(S[i] < pivotitem){     // 첫 원소와 비교하여 값의 크기가 작다면
            j++;                  // j+1을 하여 (j의 초기값 = 배열의 첫원소)
            Swap(&S[i], &S[j]);   // 비교된 크기가 작은 원소와 교환
        }                         
    }                             // i는 모든 원소를 다 순회하고 j는 첫 원소와 비교하여 크기가 작을때마다 1씩 증가하게 됨
    *pivotpoint = j;              // j로 pivotpoint의 자리를 설정
    Swap(&S[low], &S[j]);         // 첫 원소와 index j를 교환
}

// 빠른정렬 알고리즘
void QuickSort(int S[], int low, int high)
{
    int pivotpoint; // 기준점

    if (high > low)
    {
        Partition(S, low, high, &pivotpoint); // pivotitem으로 선택된 원소가 저장되어있는 index가 pivotpoint에 저장
        QuickSort(S, low, pivotpoint - 1);    // pivotpoint를 기준으로 low부터 pivotpoint-1까지 빠른정렬(분할 및 재귀)
        QuickSort(S, pivotpoint + 1, high);   // pivotpoint를 기준으로 pivotpoint+1부터 high까지 빠른정렬(분할 및 재귀)
    }
}

int main(void)
{
    int S[8] = {15, 22, 13, 27, 12, 10, 20, 25};
    int i;

    QuickSort(S, 0, 7);

    for (i = 0; i < 8; i++)
        printf("%d ", S[i]);

    return 0;
}