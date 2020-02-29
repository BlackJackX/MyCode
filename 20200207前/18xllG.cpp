#include <iostream>
#include <algorithm>
#include <queue>

#define N 210
#define INF 1e8
using namespace std;

struct node {
	int x, y;
	float dis;
	bool operator < (const node x) const {
		return x.dis < dis;
	}
};
int sx, sy, ex, ey, n, m;
node op, ed;
float dist[N];
node stop[N][N];
bool vis[N][N];

void dijkstra() {
	for (int i = 0; i <= m + 1; i++)
		dist[i] = INF;
	priority_queue<node> q;
	q.push(op);
	while (!q.empty()) {
		node tmp = q.top();
		q.pop();
		if (vis[tmp.x][tmp.y])
			continue;
		vis[tmp.x][tmp.y] = true;

	}
}

int main() {
	cin >> sx >> sy >> ex >> ey;
	op.x = sx; op.y = sy; op.dis = 0;
	ed.x = ex; ed.y = ey; op.dis = INF;
	int a, b;
	int i, j;
	for (i = 0; ; i++) {
		bool flag = false;
		for (j = 0; ; j++) {
			if (cin >> a >> b) {
				if (a == -1)
					break;
				stop[i][j].x = a;
				stop[i][j].y = b;
				stop[i][j].dis = INF;
			}
			else {
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}
	n = i; m = j;
	//dijkstra();
	cout << dist[m + 1] << endl;
	return 0;

}