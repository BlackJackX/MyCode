#include<bits/stdc++.h>
#define N 100010
#define M 500010
#define INF 0x7fffffff

struct edge {
    int u, v, dis, next;
};

edge e[M];
int head[N], dis[N], edge_num;
bool vis[N];
int n, m, s;

void init_graph() {
    memset(head, -1, N);
}

inline void add_edge( int u, int v, int d ) {
    e[edge_num].u = u;
    e[edge_num].dis = d;
    e[edge_num].v = v;
    e[edge_num].next = head[u];
    head[u] = edge_num;
    edge_num++;
}

struct node {
    int dis;

    int pos;
    bool operator <( const node &x )const {
        return x.dis < dis;

    }
};


std::priority_queue<node> q;

inline void dijkstra(int s, int n) {
    for(int i = 0; i < n; ++i)
        dis[i] = INF;
    dis[s] = 0;
    q.push( ( node ){0, s} );
    while( !q.empty() ) {
        node tmp = q.top();
        q.pop();
        int u = tmp.pos, d = tmp.dis;

        if( vis[u] )
            continue;
        vis[u] = 1;
        for( int i = head[u]; i>=0; i = e[i].next ) {
            int v = e[i].v;
            if( dis[v] > dis[u] + e[i].dis ) {
                dis[v] = dis[u] + e[i].dis;

                if( !vis[v] ) {
                    q.push( ( node ){dis[v], v} );
                }
            }
        }
    }
}
