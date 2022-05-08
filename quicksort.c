#include <stdio.h>

// Swap A for B
void Swap(int *x, int *y) {
    int tmp;

    tmp= *x;
    *x = *y;
    *y = tmp;
}

// ���� �˰��� (�迭�� ����)
void Partition(int S[], int low, int high, int *pivotpoint)
{
    int i, j;
    int pivotitem = S[low];       // pivotitem���� ù ���Ҹ� ����
    j = low;                      // low�� j�� ����

    for(i = low + 1; i <= high; i++) {
        if(S[i] < pivotitem){     // ù ���ҿ� ���Ͽ� ���� ũ�Ⱑ �۴ٸ�
            j++;                  // j+1�� �Ͽ� (j�� �ʱⰪ = �迭�� ù����)
            Swap(&S[i], &S[j]);   // �񱳵� ũ�Ⱑ ���� ���ҿ� ��ȯ
        }                         
    }                             // i�� ��� ���Ҹ� �� ��ȸ�ϰ� j�� ù ���ҿ� ���Ͽ� ũ�Ⱑ ���������� 1�� �����ϰ� ��
    *pivotpoint = j;              // j�� pivotpoint�� �ڸ��� ����
    Swap(&S[low], &S[j]);         // ù ���ҿ� index j�� ��ȯ
}

// �������� �˰���
void QuickSort(int S[], int low, int high)
{
    int pivotpoint; // ������

    if (high > low)
    {
        Partition(S, low, high, &pivotpoint); // pivotitem���� ���õ� ���Ұ� ����Ǿ��ִ� index�� pivotpoint�� ����
        QuickSort(S, low, pivotpoint - 1);    // pivotpoint�� �������� low���� pivotpoint-1���� ��������(���� �� ���)
        QuickSort(S, pivotpoint + 1, high);   // pivotpoint�� �������� pivotpoint+1���� high���� ��������(���� �� ���)
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