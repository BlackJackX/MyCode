/*
堆的方向别反了。。。。
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>

#define N 120
#define INF 0x3f3f3f3f
#define P pair<int, int>
using namespace std;


int n, a, b, k;
int g[N][N];
bool vis[N];
int dist[N];

int dijkstra() {
	priority_queue<P, vector<P>, greater<P> > q;
	dist[a] = 0;
	q.push(P(0, a));
	while (!q.empty()) {
		P tmp = q.top();
		int dis = tmp.first;
		int u = tmp.second;
		q.pop();
		if (vis[u])
			continue;
		vis[u] = true;
		for (int v = 1; v <= n; v++) {
			if (dist[u] + g[u][v] >= dist[v])
				continue;
			dist[v] = dist[u] + g[u][v];
			q.push(P(g[u][v]+dist[u], v));
		}
	}
	if (dist[b] == INF)
		return -1;
	return dist[b];
}


int main() {
	cin >> n >> a >> b;
	memset(g, INF, N * N * sizeof(int));
	memset(vis, false, sizeof(bool));
	memset(dist, INF, N * sizeof(int));
	for (int i = 1; i <= n; i++) {
		cin >> k;
		int j;
		if (k == 0) continue;
		k--;
		cin >> j;
		g[i][j] = 0;
		while (k--) {
			cin >> j;
			g[i][j] = 1;
		}
	}

	cout << dijkstra() << endl;
		
		
	return 0;

}