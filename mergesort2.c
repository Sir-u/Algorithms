#include <stdio.h>

// 합병 알고리즘
void Merge(int S[], int low, int mid, int high)
{
    int i, j, k, l;
    int U[high];   // 합병에 필요한 지역 배열
    i = low;       // i에 index low 저장
    j = mid + 1;   // j에 index high 저장
    k = low;       // k에 index low 저장

    while (i <= mid && j <= high)      // i와 j를 비교하여 둘 중 더 작은 값을 U에 저장
    {
        if (S[i] < S[j])
            U[k++] = S[i++];
        else
            U[k++] = S[j++];
    }

    if (i > mid)                       // i가 mid를 넘어섰다면 j부터 high까지의 모든 값을 U에 저장
        for (l =j; l<=high; l++)
            U[k++] = S[l];
    else                               // i부터 mid까지의 값들이 남아있다면 i부터 mid까지의 모든 값을 U에 저장
        for (l = i; l <= mid; l++)
            U[k++] = S[l];

    for (l = low; l <= high; l++)  // U의 값을 S에 저장
        S[l] = U[l];
}

// 합병정렬 알고리즘 (분할 + 합병)
void MergeSort(int S[], int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;        // mid는 배열의 중앙값
        MergeSort(S, low, mid);        // mid를 기준으로 low부터 mid까지 합병정렬(분할 및 재귀)
        MergeSort(S, mid + 1, high);   // mid를 기준으로 mid+1부터 high까지 합병정렬(분할 및 재귀)
        Merge(S, low, mid, high);      // 분할된 값들을 합병 
    }
}

int main(void)
{
    int S[8] = {27, 10, 12, 20, 25, 13, 15, 22};
    int i;

    MergeSort(S, 0, 7);

    for (i = 0; i < 8; i++)
        printf("%d ", S[i]);

    return 0;
}