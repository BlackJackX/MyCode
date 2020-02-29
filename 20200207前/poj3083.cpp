#include <iostream>
#include <algorithm>
#include <cstring>

#define N 45
#define INF 0x3f3f3f3f

using namespace std;

int t, n, m, sx, sy, sd;
char maze[N][N];
bool vis[N][N];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void init() {
	memset(vis, false, sizeof(bool) * N * N);
	maze[sx][sy] = 'S';
}
void read() {
	for (int i = 0; i < n; i++)
		cin >> maze[i];
}
void finds(int &sx, int &sy, int &sd) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maze[i][j] == 'S') {
				sx = i; sy = j;
			}
		}
	}
	if (sx == 0)
		sd = 1;
	else if (sy == 0)
		sd = 0;
	else if (sx == n - 1)
		sd = 3;
	else if (sy == m - 1)
		sd = 2;
}

int shortestlen(int x, int y) {
	if (maze[x][y] == 'E') return 1;
	if (vis[x][y] || maze[x][y] == '#') return INF;
	vis[x][y] = true;
	int mi = INF;
	for (int i = 0; i < 4; i++) {
		if (x + dx[i] >= n || x + dx[i] < 0 || y + dy[i] >= m || y + dy[i] < 0)
			continue;
		mi = min(mi, shortestlen(x + dx[i], y + dy[i]));
	}
	return mi + 1;
}

int leftlen(int x, int y, int i) {
	if (maze[x][y] == 'E') return 1;
	int len;
	int j = (i + 3) % 4;
	while (true) {
		if (maze[x + dx[j]][y + dy[j]] == '#' && maze[x + dx[i]][y + dy[i]] != '#')
			break;
		else if (maze[x + dx[j]][y + dy[j]] == '#' && maze[x + dx[i]][y + dy[i]] == '#') {
			i = (i + 1) % 4;
		}
		else if (maze[x + dx[j]][y + dy[j]] != '#' && maze[x + dx[i]][y + dy[i]] == '#') {
			i = (i + 3) % 4;
			break;
		}
		else if (maze[x + dx[j]][y + dy[j]] != '#' && maze[x + dx[i]][y + dy[i]] != '#') {
			i = (i + 3) % 4;
			break;
		}
	}

	len = leftlen(x + dx[i], y + dy[i], i);
	if (len != INF) return len + 1;
	
	return len;
}

int rightlen(int x, int y, int i) {
	if (maze[x][y] == 'E') return 1;
	int len;
	int j = (i + 1) % 4;
	while (true) {
		if (maze[x + dx[j]][y + dy[j]] == '#' && maze[x + dx[i]][y + dy[i]] != '#')
			break;
		else if (maze[x + dx[j]][y + dy[j]] == '#' && maze[x + dx[i]][y + dy[i]] == '#') {
			i = (i + 3) % 4;
		}
		else if (maze[x + dx[j]][y + dy[j]] != '#' && maze[x + dx[i]][y + dy[i]] == '#') {
			i = (i + 1) % 4;
			break;
		}
		else if (maze[x + dx[j]][y + dy[j]] != '#' && maze[x + dx[i]][y + dy[i]] != '#') {
			i = (i + 1) % 4;
			break;
		}
	}

	len = rightlen(x + dx[i], y + dy[i], i);
	if (len != INF) return len + 1;

	return len;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> m >> n;
		read();
		finds(sx, sy, sd);
		maze[sx][sy] = '#';
		int l = leftlen(sx, sy, sd);
		int r = rightlen(sx, sy, sd);
		init();
		int s = shortestlen(sx, sy);
		printf("%d %d %d\n", l, r, s);
	}
	return 0;
}