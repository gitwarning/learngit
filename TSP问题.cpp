#include<iostream>
#include<cstdio>
#define maxn 100
#define INF 99999

using namespace std;
/*
�ж�x�ĵ�iλ�ǲ���1:
((x>>(i-1))&1 == 1)
*/
int c[maxn][maxn];//ÿ���ߵ�Ȩֵ
int dp[maxn][maxn<<1];//���ս��

void init(int n)
{//��0�㿪ʼ����
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < (1<<(n-1)); j++)
        {
            dp[i][j] = INF;
        }
    }


    for(int i = 0; i < n; i++)
        dp[i][0] = c[i][0];

    return;
}

void solve(int n)
{
    int set_num = 1<<(n-1);
    for(int j = 1; j < set_num; j++)
    {
        for(int i = 0; i < n; i++)
        {
            if(((j>>(i-1))&1) == 1)//i�ڼ������棬˵���Ѿ��߹���
                continue;

            for(int k = 1; k < n; k++){//ö�ټ�������ĵ㣬��С�����ģ
                if(((j>>(k-1))&1) == 0)//����ڼ�������
                    continue;

                int new_set = j^(1<<(k-1));
                if(dp[i][j] > c[i][k] + dp[k][new_set])
                    dp[i][j] = c[i][k] + dp[k][new_set];
            }
        }
    }

    return;
}

int main(void)
{
    int n, m;
    int x, y, z;
    printf("��������ȫͼ�Ķ�����: ");
    scanf("%d", &n);
    //printf("��������ȫͼ�ı���: ");
    //scanf("%d", &m);
    m = n*(n-1)/2;

    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        c[x][y] = c[y][x] = z;
    }

    init(n);
    solve(n);

    //printf("%d--\n", 1<<(n-1));
    /*
    int fin_set = (1<<(n-1));
    for(int i = 0; i < fin_set; i++)
        printf("dp[0][%d] = %d\n", i, dp[0][i]);
    */
    printf("��̵�·����: %d\n", dp[0][(1<<(n-1))-1]);

    return 0;
}
/*
5
0 1 2
0 2 2
0 3 1
0 4 4
1 2 3
1 3 2
1 4 3
2 3 2
2 4 2
3 4 4
*/
