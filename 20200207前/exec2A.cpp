/*
16min
*/
#include <iostream>
#include <algorithm>
#include <queue>

#define N 25

using namespace std;

int n, m;
char g[N][N];
bool vis[N][N];
int sx, sy, ex, ey, len;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void read() {
	len = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> g[i][j];
			vis[i][j] = false;
			if (g[i][j] == '@') {
				sx = i; sy = j;
			}
			if (g[i][j] == '*') {
				ex = i; ey = j;
			}
		}
	}
}

bool check(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y] || g[x][y] == '#')
		return false;
	return true;
}

void bfs() {
	queue<int> q;
	q.push(sx);
	q.push(sy);
	q.push(0);
	g[sx][sy] = '.';
	while (!q.empty()) {
		int x = q.front(); q.pop();
		int y = q.front(); q.pop();
		int l = q.front(); q.pop();
		if (!check(x, y))
			continue;
		vis[x][y] = true;
		if (g[x][y] == '*') {
			len = l;
			return;
		}
		for (int i = 0; i < 4; i++) {
			q.push(x + dx[i]);
			q.push(y + dy[i]);
			q.push(l + 1);
		}
	}

}

int main() {
	while (cin >> n >> m && n != 0 && m != 0) {
		read();
		bfs();
		cout << len << endl;
	}
	return 0;
}

