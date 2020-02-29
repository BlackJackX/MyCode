#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

#define N 310
#define M 55000
#define INF 0x3f3f3f3f

#pragma warning(disable:4996)
using namespace std;

int m;
int g[N][N];
bool vis[N][N];


int bfs() {
	int x, y, t = 0;
	queue<int> q;
	q.push(0);
	q.push(0);
	q.push(0);

	while (!q.empty()) {
		x = q.front(); q.pop();
		y = q.front(); q.pop();
		t = q.front(); q.pop();
		if (x < 0 || y < 0 || g[x][y] <= t || vis[x][y]) continue;
		if (g[x][y] == INF) break;
		vis[x][y] = true;
		q.push(x - 1);
		q.push(y);
		q.push(t + 1);

		q.push(x + 1);
		q.push(y);
		q.push(t + 1);
		
		q.push(x);
		q.push(y - 1);
		q.push(t + 1);
		
		q.push(x);
		q.push(y + 1);
		q.push(t + 1);

	}
	if (g[x][y] == INF) return t;
	else return -1;
}

int main() {
	cin >> m;
	memset(g, INF, sizeof(int) * N * N);
	memset(vis, false, sizeof(bool) * N * N);
	for (int i = 0; i < m; i++) {
		int x, y, t;
		cin >> x >> y >> t;
		g[x][y] = min(g[x][y], t);
		if (x >= 1)
			g[x - 1][y] = min(g[x - 1][y], t);
		g[x + 1][y] = min(g[x + 1][y], t);
		if (y >= 1)
			g[x][y - 1] = min(g[x][y - 1], t);
		g[x][y + 1] = min(g[x][y + 1], t);
	}

	cout << bfs() << endl;

	return 0;
}