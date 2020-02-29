#include <iostream>
#include <cstring>
#include <cstdio>

#define N 5500
#define M 440000
#define INF 0x7fffffff

using namespace std;

struct edge {
    int u, v, dis, next;
};
edge e[M];
int head[N];
int edge_num = 0;

void add_edge(int u, int v, int dis) {
    int i = edge_num;
    e[i].u = u;
    e[i].v = v;
    e[i].dis = dis;
    e[i].next = head[u];
    head[u] = i;
    edge_num++;
}

void init_graph() {
    memset(head, -1, N*sizeof(int));
}

int prim(int n) {
    int vis[n], dis[n];
    for(int i=0; i<n; i++) {
        vis[i] = 0;
        dis[i] = INF;
    }
    dis[0] = 0;
    int u = 0;
    int res = 0;
    int num = n;
    while(num--) {
        vis[u] = 1;
        res += dis[u];
        for(int i=head[u]; i>=0; i=e[i].next) {
            int v = e[i].v;
            dis[v] = min(dis[v], e[i].dis);
        }
        u = -1;
        for(int i=0; i<n; i++) {
            if(vis[i]==0 && u==-1)
                u = i;
            else if(vis[i]==0 && dis[u]>dis[i])
                u = i;
        }
        if(u == -1) break;
    }
    if(num != 0)
        return -1;
    return res;
}


int main() {
    int n, m, u, v, dis;
    cin >> n >> m;
    init_graph();
    for(int i=0; i<m; i++) {
        cin >> u >> v >> dis;
        add_edge(u-1, v-1, dis);
        add_edge(v-1, u-1, dis);
    }
    int res = prim(n);
    if(res == -1)
        cout << "orz" << endl;
    else
        cout << res << endl;

    return 0;
}
