#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 2010;
const int MAX_M = 1e6+10;
//const int MAX_M = MAX_N * 4;

int n, m, r;
int head[MAX_N], link[MAX_N];
bool vis[MAX_N];
int edgenum;
struct edge {
    int v, next;
} e[MAX_M];

void initgh() {
    memset(head, -1, sizeof(head));
    edgenum = 0;
}

void addedge(int u, int v) {
    int &i = edgenum;
    e[i].v = v; 
    e[i].next = head[u];
    head[u] = i;
    i++;

}

void read() {
    initgh();
    int u, v;
    for(int i=0; i<r; i++) {
        scanf("%d%d", &u, &v);
        if(u>n || v>m)
            continue;
        addedge(u, v);
    }
}



bool dfs(int u) {
    if(vis[u])
        return false;
    vis[u] = true;
    for(int i=head[u]; i>=0; i=e[i].next) {
        int v = e[i].v;
        if(link[v] == 0 || dfs(link[v])) {
            link[v] = u;
            return true;
        }
    }
    return false;
}

void Hungarian() {
    int k = 0;
    memset(link, 0, sizeof(link));
    for(int i=1; i<=n; i++) {
        memset(vis, false, sizeof(vis));
        if(dfs(i))
            k++;
    }
        
    printf("%d\n", k);
}
