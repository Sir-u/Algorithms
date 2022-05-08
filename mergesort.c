#include <stdio.h>

// �պ� �˰���
void Merge(int S[], int low, int mid, int high)
{
    int i, j, k, l;
    int U[high];   // �պ��� �ʿ��� ���� �迭
    i = low;       // i�� index low ����
    j = mid + 1;   // j�� index high ����
    k = low;       // k�� index low ����

    while (i <= mid && j <= high)      // i�� j�� ���Ͽ� �� �� �� ���� ���� U�� ����
    {
        if (S[i] < S[j])
            U[k++] = S[i++];
        else
            U[k++] = S[j++];
    }

    if (i > mid)                       // i�� mid�� �Ѿ�ٸ� j���� high������ ��� ���� U�� ����
        for (l =j; l<=high; l++)
            U[k++] = S[l];
    else                               // i���� mid������ ������ �����ִٸ� i���� mid������ ��� ���� U�� ����
        for (l = i; l <= mid; l++)
            U[k++] = S[l];

    for (l = low; l <= high; l++)  // U�� ���� S�� ����
        S[l] = U[l];
}

// �պ����� �˰��� (���� + �պ�)
void MergeSort(int S[], int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;        // mid�� �迭�� �߾Ӱ�
        MergeSort(S, low, mid);        // mid�� �������� low���� mid���� �պ�����(���� �� ���)
        MergeSort(S, mid + 1, high);   // mid�� �������� mid+1���� high���� �պ�����(���� �� ���)
        Merge(S, low, mid, high);      // ���ҵ� ������ �պ� 
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