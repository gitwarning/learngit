#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define maxn 100

using namespace std;
/*
  求出从点0到各个顶点的最短距离
*/
struct Edge
{
    int u, v, w;
    Edge(int uu, int vv, int ww):u(uu), v(vv), w(ww){}
};
struct Node
{
    int id, w;
    bool operator<(const Node &b)
        const {w>b.w;}
}mid;

vector<Edge>v[maxn];
priority_queue<Node>pq;
int dis[maxn];

void dijk(int s)
{
    pq.push(Node{s, 0});
    dis[s] = 0;
    while(!pq.empty())
    {
        mid = pq.top();
        pq.pop();
        int id = mid.id;
        //printf("%d--\n", mid.w);
        for(int i = 0; i < v[id].size(); i++)
        {
            int path = v[id][i].w;
            int nxt = v[id][i].v;
            if(dis[nxt] >= (dis[id] + path)){
                dis[nxt] = dis[id] + path;
                pq.push(Node{nxt, dis[nxt]});
            }
        }
    }
}

int main(void)
{
    int n, m;
    int x, y, z;
    printf("请输入图的顶点数: ");
    scanf("%d", &n);
    printf("请输入图的边数: ");
    scanf("%d", &m);

    memset(dis, 0x3f, sizeof(dis));
    for(int i = 0; i < n; i++)
        v[i].clear();

    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        v[x].push_back(Edge(x, y, z));
    }

    //init();

    dijk(0);

    for(int i = 1; i < n; i++){
        printf("点0到点%d的最短距离为: %d\n", i, dis[i]);
    }

    return 0;
}
/*
0 1 4
0 2 2
1 2 3
2 1 1
1 3 2
1 4 3
2 3 4
2 4 5
4 3 1
*/
