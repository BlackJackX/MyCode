#include <iostream>
#include <cstring>
#include <cstdio>

#define N 1000
#define M 100000
#define INF 0x3f3f3f3f

using namespace std;

struct edge{
    int u;
    int v;
    int tim;
    int next;
};
edge e[M];

int head[N];
int edge_num = 0;

void init_graph() {
    memset(head, -1, N);
    edge_num = 0;
}

void add_edge(int u, int v, int t) {
    int i = edge_num;
    e[i].u = u;
    e[i].v = v;
    e[i].tim = t;
    e[i].next = head[u];
    head[u] = i;
    edge_num++;
}

void print_graph(int n) {
    for(int u=0; u<n; u++) {
        printf("%d: ", u);
        for(int i=head[u]; i>=0; i=e[i].next) {
            printf("%d(%d)", e[i].v, e[i].tim);
        }
        cout << endl;
    }
}

//无环true，有环false
bool bellman_ford(int x, int n) {
    int dist[n];
    int m = edge_num;
    for(int i=0; i<n; i++) {
        dist[i] = INF;
    }
    dist[x] = 0;
    for(int i=1; i<n; i++) {
        bool flag = false;
        for(int j=0; j<m; j++) {
            int u = e[j].u;
            int v = e[j].v;
            int t = e[j].tim;
            if(dist[u] + t < dist[v]) {
                dist[v] = dist[u] + t;
                flag = true;
            }
        }
        if(!flag) return true;
    }
    for(int i=0; i<m; i++) {
        int u = e[i].u;
        int v = e[i].v;
        int t = e[i].tim;
        if(dist[u] + t < dist[v]) {
            return false;
        }
    }
    return true;
}
