#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

#define N 25
#define T 10
#define INF 0x3f3f3f3f

using namespace std;

int n, m, sx, sy, mincnt, cnt;
int g[N][N];
bool vis[N][N];

void read() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> g[i][j];
			if (g[i][j] == 2) {
				sx = i;
				sy = j;
				g[i][j] = 0;
			}
		}
	}
}

void dfs(int x, int y) {
	int tx = x;
	int ty = y;
	if (cnt >= 10) return;
	cnt++;
	for (; x >= 0 && g[x][y] == 0; x--);
	if (x < 0 || y < 0 || x >= n || y >= m);
	else if (g[x][y] == 3)
		mincnt = min(cnt, mincnt);
	else if (x + 1 == tx);
	else if (g[x][y] == 1) {
		g[x][y] = 0;
		dfs(x + 1, y);
		g[x][y] = 1;
	}
	x = tx;
	for (; x < n && g[x][y] == 0; x++);
	if (x < 0 || y < 0 || x >= n || y >= m);
	else if (g[x][y] == 3)
		mincnt = min(cnt, mincnt);
	else if (x - 1 == tx);
	else if (g[x][y] == 1) {
		g[x][y] = 0;
		dfs(x - 1, y);
		g[x][y] = 1;
	}
	x = tx;
	for (; y >= 0 && g[x][y] == 0; y--);
	if (x < 0 || y < 0 || x >= n || y >= m);
	else if (g[x][y] == 3)
		mincnt = min(cnt, mincnt);
	else if (y + 1 == ty);
	else if (g[x][y] == 1) {
		g[x][y] = 0;
		dfs(x, y + 1);
		g[x][y] = 1;
	}
	y = ty;
	for (; y < m && g[x][y] == 0; y++);
	if (x < 0 || y < 0 || x >= n || y >= m);
	else if (g[x][y] == 3)
		mincnt = min(cnt, mincnt);
	else if (y - 1 == ty);
	else if (g[x][y] == 1) {
		g[x][y] = 0;
		dfs(x, y - 1);
		g[x][y] = 1;
	}
	y = ty;
	cnt--;
}

int main() {
	while (cin >> m >> n && m != 0 && n != 0) {
		read();
		mincnt = INF;
		cnt = 0;
		dfs(sx, sy);
		if (mincnt > 10)
			mincnt = -1;
		cout << mincnt << endl;
	}
	return 0;
}