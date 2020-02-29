/*
dijkstra模板题
41min
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>

#define N 1005
#define INF 0x3f3f3f3f

#pragma warning(disable:4996)

using namespace std;

int n, m, x;
int go[N][N], come[N][N];
int godist[N], comedist[N];
bool vis[N];

struct node {
	int p, d;
	node(int point, int dist) {
		p = point;
		d = dist;
	}
	bool operator < (node x) const {
		return d > x.d;
	}
};

void dijkstra(int x, int g[N][N], int dist[N]) {
	memset(dist, INF, N * sizeof(int));
	memset(vis, false, N * sizeof(bool));
	dist[x] = 0;
	priority_queue<node> q;
	q.push(node(x, 0));

	while (!q.empty()) {
		node tmp = q.top();
		q.pop();
		int pos = tmp.p;
		int dis = tmp.d;
		if (vis[pos])
			continue;
		vis[pos] = true;
		dist[pos] = dis;
		for (int i = 1; i <= n; i++) {
			if (g[pos][i] == 0) continue;
			if (dist[i] > dist[pos] + g[pos][i])
				dist[i] = dist[pos] + g[pos][i];
			q.push(node(i, dist[i]));
		}
	}
}


int main() {
	cin >> n >> m >> x;
	int a, b, tim;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> tim;
		go[a][b] = come[b][a] = tim;
	}
	dijkstra(x, go, godist);
	dijkstra(x, come, comedist);

	int ma = 0;
	for (int i = 1; i <= n; i++) {
		ma = max(ma, godist[i] + comedist[i]);
	}
	cout << ma << endl;
	return 0;
}

