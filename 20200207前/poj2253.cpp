#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdio>

#define D 1005
#define N 205
#define INF 0x3f3f3f3f

using namespace std;

int n, cnt = 0;
int coord[2 * D];
float g[N][N], dis[N];;
bool vis[N];

struct node {
	float dis;
	int pos;
	node(float d, int p) { dis = d; pos = p; }
	bool operator < (const node& x) const{
		return x.dis < dis;
	}
};

void dka(int s) {
	priority_queue<node> q;
	q.push(node(0, s));
	dis[s] = 0;
	int u;
	float d;
	while (!q.empty()) {
		node tmp = q.top();
		q.pop();
		d = tmp.dis;
		u = tmp.pos;
		if (vis[u]) continue;
		vis[u] = true;
		for (int v = 0; v < n; v++) {
			if (dis[v] > max(dis[u], g[u][v])) {
				dis[v] = max(dis[u], g[u][v]);
				
				if (!vis[v])
					q.push(node(dis[v], v));
			}
		}
	}
}

int main() {
	int x, y;
	while (cin >> n && n != 0) {
		cnt++;
		memset(coord, 0, sizeof(int) * D * 2);
		memset(g, 0, N * N * sizeof(float));
		memset(vis, false, N * sizeof(bool));
		for (int i = 0; i < n; i++)
			dis[i] = 10000;

		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			coord[i * 2] = x;
			coord[i * 2 + 1] = y;
			for (int j = 0; j < i; j++) {
				float f1 = coord[i * 2] - coord[j * 2];
				float f2 = coord[i * 2 + 1] - coord[j * 2 + 1];
				g[i][j] = g[j][i] = sqrt(pow(f1, 2) + pow(f2, 2));
			}
		}

		dka(0);
		cout << "Scenario #" << cnt << endl;
		printf("Frog Distance = %.3f\n\n", dis[1]);
	}

	return 0;
}