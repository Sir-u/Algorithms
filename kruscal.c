#include <stdio.h>
#define MAX 100

int aMatrix[5][5];  // 인접행렬의 값을 저장할 2차원 배열
int AMList[5][5];   // 인접행렬의 값을 출력할 2차원 배열

typedef struct edge
{
    int p, q;
    int weight;
} EDGE;             // 간선 구조체

typedef struct edgelist
{
    int n;
    EDGE data[MAX];
} EDGELIST;

EDGELIST edgeList;


// 가중치가 작은 것부터 차례대로 정렬
void sort()
{
    int i, j;
    EDGE temp;

    for (i = 0; i < edgeList.n; i++){
        for (j = 0; j < edgeList.n - 1; j++){
            if (edgeList.data[j].weight > edgeList.data[j + 1].weight)
            {
                temp = edgeList.data[j];
                edgeList.data[j] = edgeList.data[j + 1];
                edgeList.data[j + 1] = temp;
            }
        }
    }
}

// 노드를 병합하여 트리로 만들기
void merge(int member[], int v1, int v2)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if (member[i] == v2)
        {
            member[i] = v1;
        }
    }
}

// 트리에 있는지 확인
int find(int member[], int vNum)
{
    return (member[vNum]);
}

// 크루스칼 알고리즘
void kruskal()
{
    int member[MAX], i, j, vNum1, vNum2;
    edgeList.n = 0;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (aMatrix[i][j] != 0)
            {
                edgeList.data[edgeList.n].p = i;
                edgeList.data[edgeList.n].q = j;
                edgeList.data[edgeList.n].weight = aMatrix[i][j];
                edgeList.n++;
            }
        }
    }

    sort();

    for(i = 0; i < 5; i++){
        member[i] = i;
    }

    for (i = 0; i < edgeList.n; i++)
    {
        vNum1 = find(member, edgeList.data[i].p);
        vNum2 = find(member, edgeList.data[i].q);
        if (vNum1 != vNum2)
        {
            AMList[edgeList.data[i].p][edgeList.data[i].q] = edgeList.data[i].weight;
            AMList[edgeList.data[i].q][edgeList.data[i].p] = edgeList.data[i].weight;
            merge(member, vNum1, vNum2);
        }
    }

}

// Adjacent Matrix로 표현된 MST 출력
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