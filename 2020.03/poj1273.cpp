/*
nb!!!
EK过了!!!
开心
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int MAX_N = 200+10;
const int INF = 0x3f3f3f3f;

int n, m;
int gh[MAX_N][MAX_N];
int path[MAX_N];

void read() {
    memset(gh, 0, MAX_N*MAX_N*sizeof(int));
    int u, v, cap;
    for(int i=0; i<m; i++) {
        scanf("%d%d%d", &u, &v, &cap);
        gh[u][v] += cap;
    }
}

int bfs(int from, int to) {
    memset(path, -1, sizeof(int)*MAX_N);
    queue<int> q;
    q.push(from);
    path[from] = 0;
    int flow = INF;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v=1; v<=n; v++) {
            if(path[v] >= 0 || gh[u][v] == 0)
                continue;
            q.push(v);
            flow = min(flow, gh[u][v]);
            path[v] = u;
            if(v == to)
                return flow;
        }
    }

    return -1;
}


int EK(int from, int to) {
    int flow = 0;
    int cur_flow;
    while((cur_flow=bfs(from, to)) != -1) {
        int v = to;
        flow += cur_flow;
        while(v != from) {
            gh[path[v]][v] -= cur_flow;
            gh[v][path[v]] += cur_flow;
            v = path[v];
        }
    }
    return flow;
}


int main() {
    freopen("input.txt", "r", stdin);
    while(scanf("%d%d", &m, &n)==2) {
        read();
        printf("%d\n", EK(1, n));
    }

    return 0;
}