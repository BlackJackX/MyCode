/*
55min
三重bfs
一遍过！！！！
我变强了！！！！！

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

#define W 55
#define H 55
using namespace std;

int n, m;
char g[W][H];
bool vis[W][H];
vector<int> v;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool check(int x, int y) {
	if (x < 0 || y < 0 || x > n + 1 || y > m + 1 || vis[x][y])
		return false;
	return true;
}

void bfsdt(int x, int y) {
	queue<int> q;
	q.push(x);
	q.push(y);
	while (!q.empty()) {
		x = q.front();
		q.pop();
		y = q.front();
		q.pop();
		if (vis[x][y])
			continue;
		if (g[x][y] != 'X')
			continue;
		vis[x][y] = true;
		for (int i = 0; i < 4; i++) {
			if (check(x + dx[i], y + dy[i])) {
				q.push(x + dx[i]);
				q.push(y + dy[i]);
			}
		}
	}
}

void bfsde(int x, int y) {
	int c = 0;
	queue<int> q;
	q.push(x);
	q.push(y);
	while (!q.empty()) {
		x = q.front();
		q.pop();
		y = q.front();
		q.pop();
		if (vis[x][y])
			continue;
		if (g[x][y] == 'X') {
			bfsdt(x, y);
			c++;
		}
		if (g[x][y] == '.')
			continue;
		vis[x][y] = true;
		for (int i = 0; i < 4; i++) {
			if (check(x + dx[i], y + dy[i])) {
				q.push(x + dx[i]);
				q.push(y + dy[i]);
			}
		}
	}
	v.push_back(c);
}



void bfsbg(int x, int y) {
	queue<int> q;
	q.push(x);
	q.push(y);
	while (!q.empty()) {
		x = q.front();
		q.pop();
		y = q.front();
		q.pop();
		if (vis[x][y])
			continue;
		if (g[x][y] == '*' || g[x][y] == 'X')
			bfsde(x, y);
		vis[x][y] = true;
		for (int i = 0; i < 4; i++) {
			if (check(x + dx[i], y + dy[i])) {
				q.push(x + dx[i]);
				q.push(y + dy[i]);
			}
		}
	}
	return;
}


int main() {
	int cnt = 0;
	while(cin >> m >> n && m != 0 && n != 0) {
		memset(vis, false, sizeof(bool) * W * H);
		v.clear();
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> g[i][j];
			}
		}
		for (int i = 0; i <= n; i++) {
			g[i][0] = g[i][m + 1] = '.';
		}
		for (int j = 0; j <= m; j++) {
			g[0][j] = g[n + 1][j] = '.';
		}
		for (int i = 0; i <= n + 1; i++) {
			for (int j = 0; j <= m + 1; j++) {
				if(!vis[i][j])
					bfsbg(i, j);
			}
		}
		cnt++;
		cout << "Throw " << cnt << endl;
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) {
			if (v[i] > 6 || v[i] < 1)
				continue;
			cout << v[i] << ' ';
		}
		cout << endl << endl;
	}
	return 0;
}