/*
tle+wa
dfs和bfs改成老师给的就过了....
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;
const int MAX_N = 10000+10;
const int MAX_M = (100000+10)*4;
const int INF = 0x7fffffff;

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
        if(u == t)
            return true;
        for(int i=head[u]; i>=0; i=e[i].next) {
            int v = e[i].v;
            if(level[v] != 0 || e[i].cap == 0)
                continue;
            level[v] = level[u] + 1;
            q.push(v);
        }
    }
    return false;
}


int dfs(int u, int t, int bn) {
    if(u == t)
        return bn;
    
    //int flow = 0;
    int left = bn;
    for(int i=head[u]; i>=0; i=e[i].next) {
        // if(bn == 0)
        //     break;
        int v = e[i].v;
        int c = e[i].cap;
        if(c <= 0 || level[u]+1 != level[v])
            continue;
        int flow = dfs(v, t, min(left, c));
        if(flow <= 0)
            continue;
        e[i].cap -= flow;
        e[i^1].cap += flow;
        left -= flow;
        if(left==0)
            break;
        // int cur_flow = dfs(v, t, min(e[i].cap, bn));
        // flow += cur_flow;        
        // e[i].cap -= cur_flow;
        // e[i^1].cap += cur_flow;
    }
    if(left > 0)      //不加这里会tle一个
        level[u] = 0;
    return bn-left;
}

ll dinic(int s, int t) {
    ll flow = 0;
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
        printf("%lld\n", dinic(s, t));
    }

    return 0;
}