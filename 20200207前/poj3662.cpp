/*
没做出来!!!!
二分求解
3h-
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>

#define N 1000+10
#define M 100000+10
#define INF 0x3f3f3f3f
using namespace std;

int n, p, k;
int op, ed;
struct edge {
	int u, v, cap, next;
};
edge e[M];
int head[N];
int num_edges = 0;
int edlen[M];

bool vis[N];
int d[N];

typedef pair<int, int> P;

void initedge() {
	memset(head, -1, N * sizeof(int));
}

void addedge(int u, int v, int cap) {
	int i = num_edges;
	e[i].u = u;
	e[i].v = v;
	e[i].cap = cap;
	e[i].next = head[u];
	head[u] = i;
	num_edges++;
}

void read() {
	initedge();
	int u, v, cap;
	for (int i = 0; i < p; i++) {
		cin >> u >> v >> cap;
		addedge(u, v, cap);
		addedge(v, u, cap);
		edlen[i + 1] = cap;
	}
	sort(edlen + 1, edlen + 1 + p);
	edlen[p + 1] = INF;
}

bool dijkstra(int mid) {
	memset(d, INF, N * sizeof(int));
	memset(vis, false, N * sizeof(bool));
	priority_queue<P, vector<P>, greater<P> > q;
	q.push(P(0, 1));
	d[1] = 0;
	while (!q.empty()) {
		P tmp = q.top();
		q.pop();
		int u = tmp.second;
		int len = tmp.first;
		int v, cap;
		if (vis[u])
			continue;
		vis[u] = true;
		for (int i = head[u]; i >= 0; i = e[i].next) {
			v = e[i].v;
			cap = e[i].cap;
			if (vis[v])
				continue;
			if (d[v] > d[u] + (cap <= mid ? 0 : 1)) {
				d[v] = d[u] + (cap <= mid ? 0 : 1);
				q.push(P(d[v], v));
			}
		}
	}
	if (d[n] <= k)
		return true;
	else
		return false;
}


void solve() {
	op = 0, ed = p + 1;
	while (op < ed) {
		int mid = edlen[(op + ed) / 2];
		if (dijkstra(mid))
			ed = (op + ed) / 2;
		else
			op = (op + ed) / 2 + 1;
	}
	if (ed == p + 1)
		cout << -1 << endl;
	else
		cout << edlen[ed] << endl;
}


int main() {
	cin >> n >> p >> k;
	read();
	solve();
	return 0;
}