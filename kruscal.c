#include <stdio.h>
#define MAX 100

int aMatrix[5][5];    // ��������� ���� ������ 2���� �迭
int AMList[5][5];     // ��������� ���� ����� 2���� �迭

// ���� ����ü
typedef struct edge
{
    int p, q;         // ���
    int weight;       // ���� ����ġ
} EDGE;

// ���� ����ü ����
typedef struct edgelist
{
    int n;            // ��ü ������ ��
    EDGE data[MAX];   // ��ü ������ ������ ����
} EDGELIST;

EDGELIST edgeList;


// ����ġ�� ���� �ͺ��� ���ʴ�� ����
void sort()
{
    int i, j;
    EDGE temp;   // ������ ���� �ӽ� ����

    for (i = 0; i < edgeList.n; i++){
        for (j = 0; j < edgeList.n - 1; j++){
            if (edgeList.data[j].weight > edgeList.data[j + 1].weight)   // ����� ������ ����
            {
                temp = edgeList.data[j];
                edgeList.data[j] = edgeList.data[j + 1];
                edgeList.data[j + 1] = temp;
            }
        }
    }
}

// ��带 �����Ͽ� Ʈ���� �����
void merge(int member[], int v1, int v2)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if (member[i] == v2)
        {
            member[i] = v1;  // ����� ��带 ��ü�ϸ鼭 ����
        }
    }
}

// Ʈ���� �ִ��� Ȯ��
int find(int member[], int vNum)
{
    return (member[vNum]);
}

// ũ�罺Į �˰���
void kruskal()
{
    int member[MAX], i, j, vNum1, vNum2;
    edgeList.n = 0;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (aMatrix[i][j] != 0)    // ����ġ�� 0�� �ƴ� �������� ����
            {
                edgeList.data[edgeList.n].p = i;
                edgeList.data[edgeList.n].q = j;
                edgeList.data[edgeList.n].weight = aMatrix[i][j];
                edgeList.n++;
            }
        }
    }

    sort();

    for(i = 0; i < 5; i++){ // ��带 member[]�� ����
        member[i] = i;
    }

    for (i = 0; i < edgeList.n; i++)
    {
        vNum1 = find(member, edgeList.data[i].p);  // ���1�� member[]���� ã�� vNum1�� ����
        vNum2 = find(member, edgeList.data[i].q);  // ���2�� member[]���� ã�� vNum2�� ����
        if (vNum1 != vNum2)                        // vNum1�� vNum2�� �ٸ��ٸ� ��� ������� �迭�� ����ġ�� �����ϰ� ����
        {
            AMList[edgeList.data[i].p][edgeList.data[i].q] = edgeList.data[i].weight;
            AMList[edgeList.data[i].q][edgeList.data[i].p] = edgeList.data[i].weight;
            merge(member, vNum1, vNum2);
        }
    }

}

// Adjacent Matrix�� ǥ���� MST ���
void mstPrint(){

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", AMList[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    freopen("input.txt", "r", stdin);

    // �Է� �ް� ������� ���� �迭�� �ֱ�
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &aMatrix[i][j]);
        }
    }

    kruskal();
    mstPrint();

    return 0;
}