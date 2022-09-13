#include <stdio.h>

int main(void)
{
    int n = 5, m = 3;

    int Available[3];
    int Max[5][3];
    int Allocation[5][3];
    int Need[5][3];
    int Work[3];

    int All[3];

    int tmpArr[3] = {0, };

    int Final[5], Ans[5], index = 0;

    freopen("input.txt", "r", stdin);

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &All[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &Allocation[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &Max[i][j]);
        }
    }

    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            tmpArr[j] += Allocation[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        Available[i] = All[i] - tmpArr[i];
    }

    for (int i = 0; i < m; i++)
    {
        Work[i] = Available[i];
    }

    /*  설정완료   */

    for (int i = 0; i < n; i++)
    {
        Final[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            Need[i][j] = Max[i][j] - Allocation[i][j];
    }

    for (int k = 0; k < 5; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (Final[i] == 0)
            {
                int check = 0;
                for (int j = 0; j < m; j++)
                {
                    if (Need[i][j] > Work[j])
                    {
                        check = 1;
                        break;
                    }
                }

                if (check == 0)
                {
                    Ans[index++] = i;
                    
                    for (int y = 0; y < m; y++)
                        Work[y] += Allocation[i][y];
                    Final[i] = 1;
                }
            }
        }
    }

    int flag = 1;

    for (int i = 0; i < n; i++)
    {
        if (Final[i] == 0)
        {
            flag = 0;
            printf("It is not the Safe Sequence");
            break;
        }
    }

    if (flag == 1)
    {

        for (int i = 0; i < n - 1; i++)
            printf("P%d -> ", Ans[i]);
        printf("P%d\n", Ans[n - 1]);

        printf("\nIt is the Safe Sequence\n");
    }

    return 0;
}