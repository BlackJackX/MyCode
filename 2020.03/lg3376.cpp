/*
tle+wa
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX_N = 10000+10;
const int MAX_M = (100000+10)*4;
const int INF = 0x3f3f3f3f;

int n, m, s, t;
int edgenum;
int head[MAX_N], level[MAX_N];
struct edge {
    int v, cap, next;
} e[MAX_M];

void initgh() {
    memset(head, -1, sizeof(int)*MAX_N);
    edgenum = 0;
}

void addedge(int u, int v, int c1, int c2) {
    int &i = edgenum;
    
    e[i].v = v;
    e[i].cap = c1;
    e[i].next = head[u];
    head[u] = i;
    i++;
    
    e[i].v = u;
    e[i].cap = c2;
    e[i].next = head[v];
    head[v] = i;
    i++;
}

void read() {
    initgh();
    int u, v, w;
    for(int i=0; i<m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        addedge(u, v, w, 0);
    }
}

void printgh() {
    for(int u=1; u<=n; u++) {
        printf("%d ", u);
        for(int i=head[u]; i>=0; i=e[i].next) {
            printf("%d(%d) ", e[i].v, e[i].cap);
        }
        printf("\n");
    }
    printf("\n");
}

bool bfs(int s, int t) {
    memset(level, 0, sizeof(int)*(n+1));
    queue<int> q;
    q.push(s);
    level[s] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i=head[u]; i>=0; i=e[i].next) {
            int v = e[i].v;
            if(level[v] != 0 || e[i].cap == 0)
                continue;
            level[v] = level[u] + 1;
            q.push(v);
            if(v == t)
                return true;
        }
    }
    return false;
}


int dfs(int u, int t, int bn) {
    if(u == t)
        return bn;
    int flow = 0;
    for(int i=head[u]; i>=0; i=e[i].next) {
        if(bn == 0)
            break;
        int v = e[i].v;
        if(e[i].cap == 0 || level[u]+1 != level[v])
            continue;
        int cur_flow = dfs(v, t, min(e[i].cap, bn));
        flow += cur_flow;        
        e[i].cap -= cur_flow;
        e[i^1].cap += cur_flow;
    }
    return flow;
}

int dinic(int s, int t) {
    int flow = 0;
    while(bfs(s, t)) {
        //printgh();
        flow += dfs(s, t, INF);
        //printgh();
    }
    return flow;
}


int main() {
    freopen("input.txt", "r", stdin);
    while(scanf("%d%d%d%d", &n, &m, &s, &t)==4) {
        read();
        printf("%d\n", dinic(s, t));
        break;    
    }

    return 0;
}