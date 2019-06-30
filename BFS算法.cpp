#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define maxn 999

using namespace std;
queue<int>q;
vector<int>v[maxn];
int flag[maxn];

void bfs(int n)
{
    q.push(0);

    while(!q.empty())
    {
        int mid = q.front();
        for(int i = 0; i < v[mid].size(); i++)
        {
            int nxt = v[mid][i];
            if(flag[nxt] == 0){//是白色
                flag[nxt] = -1;//标为灰色
                q.push(nxt);
                printf("%d ", nxt);
            }
        }
        flag[mid] = 1;
        q.pop();
    }
}

int main(void)
{
    int n, m;
    int x, y;
    printf("请输入无向图的顶点数: ");;
    scanf("%d", &n);
    printf("请输入无向图的边数: ");
    scanf("%d", &m);
    memset(flag, 0, sizeof(flag));

    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }

    printf("BFS遍历的顺序是:  ");
    printf("0 ");
    bfs(n);

    return 0;
}
/*
8
11
0 1
0 2
1 2
1 3
1 4
2 4
4 5
2 6
2 7
6 7
3 4
*/
