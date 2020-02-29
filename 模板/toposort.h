#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

#define N 550
#define M N*N
using namespace std;

int head[N],edge_num,indegree[N];
int n,m,seq[N];

struct edge
{
    int v,next;
} e[M];

void init_graph()
{
    memset(head,-1,sizeof(head));
    edge_num=0;
}

void add_edge(int u,int v)
{
    e[edge_num].v=v;
    e[edge_num].next=head[u];
    head[u]=edge_num;
    edge_num++;
}


int topo(int n)///拓扑，可做模板
{
    queue<int> q;
    int indeg[n];
    for(int i=0; i<n; i++)
    {
        indeg[i]=indegree[i];
        if(indeg[i]==0)
            q.push(i);
    }

    int k=0;
    bool res=false;
    while(!q.empty())
    {
        if(q.size() != 1) res=true;
        int u=q.front();
        q.pop();
        seq[k++]=u;
        for(int i=head[u]; i!=-1; i=e[i].next)
        {
            int v=e[i].v;
            indeg[v]--;
            if(indeg[v]==0)
                q.push(v);
        }
    }
    if(k<n)return -1;///存在有向环，总之不能进行拓扑排序
    if(!res)return 0;///可以进行拓扑排序，并且只有唯一一种方式，seq数组即是排序完好的序列
    return 1;///可以进行拓扑排序，有多种情况，seq数组是其中一种序列
}
