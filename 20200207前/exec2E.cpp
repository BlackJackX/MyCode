#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define N 110

int t, n, m, num;
struct edge {
	int x, y, w;
	bool operator < (const edge tmp) const {
		return tmp.w < w;
	}
	edge(int nx, int ny, int nw) {
		x = nx; y = ny; w = nw;
	}
};
priority_queue<edge> q;
int par[N];
void initSet() {
	for (int i = 0; i <= n; i++)
		par[i] = i;
}
int findSet(int x) {
	if (par[x] == x)
		return x;
	par[x] = findSet(par[x]);
	return par[x];
}
bool unionSet(int x, int y) {
	int px = findSet(x);
	int py = findSet(y);
	if (px == py) return false;
	par[py] = px;
	return true;
}

int main() {
	cin >> t;
	while (t--) {
		num = 0;
		cin >> n >> m;
		initSet();
		int x, y, w;
		while (m--) {
			cin >> x >> y >> w;
			q.push(edge(x, y, w));
		}
		bool flag = true;
		while (!q.empty()) {
			if (!flag) break;
			edge tmp = q.top(); q.pop();
			if (unionSet(tmp.x, tmp.y))
				num += tmp.w;
			if (q.empty())
				break;
			edge tmp1 = q.top();
			while (tmp1.w == tmp.w) {
				q.pop();
				int px1 = findSet(tmp.x);
				int py1 = findSet(tmp.y);
				int px2 = findSet(tmp1.x);
				int py2 = findSet(tmp1.y);
				if ((px1==px2&&py1==py2) || (px1==py2&&py1==px2)) {
					flag = false;
					break;
				}
				if (unionSet(tmp1.x, tmp1.y))
					num += tmp1.w;
				if (q.empty())
					break;
				tmp1 = q.top();
			}
		}
		if (flag)
			cout << num << endl;
		else
			cout << "Not Unique!" << endl;
	}
	return 0;
}