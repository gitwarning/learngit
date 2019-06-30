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
            if(flag[nxt] == 0){//�ǰ�ɫ
                flag[nxt] = -1;//��Ϊ��ɫ
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
    printf("����������ͼ�Ķ�����: ");;
    scanf("%d", &n);
    printf("����������ͼ�ı���: ");
    scanf("%d", &m);
    memset(flag, 0, sizeof(flag));

    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }

    printf("BFS������˳����:  ");
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
