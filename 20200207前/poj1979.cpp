#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

#define N 25

using namespace std;

int n, m, sx, sy;
char g[N][N];
bool vis[N][N];

void init() {
	memset(vis, false, sizeof(bool) * N * N);
}

int dfs(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y] || g[x][y] != '.') return 0;
	vis[x][y] = true;
	return dfs(x + 1, y) + dfs(x - 1, y) + dfs(x, y + 1) + dfs(x, y - 1) + 1;
}

int bfs(int sx, int sy) {
	queue<int> q;
	q.push(sx);
	q.push(sy);
	int x, y;
	int num = 0;
	while (!q.empty()) {
		x = q.front(); q.pop();
		y = q.front(); q.pop();
		if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y] || g[x][y] != '.')
			continue;
		vis[x][y] = true;
		num++;
		q.push(x + 1);
		q.push(y);
		q.push(x - 1);
		q.push(y);
		q.push(x);
		q.push(y + 1);
		q.push(x);
		q.push(y - 1);
	}
	return num;
}

int main() {
	while (cin >> m >> n && m != 0 && n != 0) {
		init();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> g[i][j];
				if (g[i][j] == '@') {
					sx = i; sy = j;
					g[i][j] = '.';
				}
			}
		}
		cout << bfs(sx, sy) << endl;
	}
	
	return 0;
}