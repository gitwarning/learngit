#include<iostream>
#include<cstdio>
#define maxn 100
#define INF 99999

using namespace std;
/*
判断x的第i位是不是1:
((x>>(i-1))&1 == 1)
*/
int c[maxn][maxn];//每条边的权值
int dp[maxn][maxn<<1];//最终结果

void init(int n)
{//从0点开始出发
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
            if(((j>>(i-1))&1) == 1)//i在集合里面，说明已经走过了
                continue;

            for(int k = 1; k < n; k++){//枚举集合里面的点，缩小问题规模
                if(((j>>(k-1))&1) == 0)//如果在集合里面
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
    printf("请输入完全图的顶点数: ");
    scanf("%d", &n);
    //printf("请输入完全图的边数: ");
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
    printf("最短的路径长: %d\n", dp[0][(1<<(n-1))-1]);

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
