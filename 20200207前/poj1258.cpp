/*
克鲁斯卡, 生成树
轻松17min
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>

#define N 100+10
using namespace std;

int n;
int g[N][N];
int par[N];

struct edge {
	int u, v, len;
	bool operator > (const edge x) const {
		return len > x.len;
	}
};
priority_queue<edge, vector<edge>, greater<edge> > q;

void initset() {
	for (int i = 0; i < n; i++)
		par[i] = i;
}

int findset(int x) {
	if (par[x] == x) return x;
	par[x] = findset(par[x]);
	return par[x];
}

void unionset(int x, int y) {
	int px = findset(x);
	int py = findset(y);
	if (px == py) return;
	par[py] = px;
	return;
}

void read() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
			edge tmp;
			tmp.u = i; tmp.v = j; tmp.len = g[i][j];
			q.push(tmp);
		}
	}
}
int kruska() {
	initset();
	int l = 0;
	while (!q.empty()) {
		edge tmp = q.top();
		q.pop();
		int u = tmp.u;
		int v = tmp.v;
		int len = tmp.len;
		if (findset(u) == findset(v))
			continue;
		l += len;
		unionset(u, v);
	}
	return l;
}

int main() {
	while (cin >> n) {
		read();
		cout << kruska() << endl;
	}
	edge e1;
	e1.len = 10;
	edge e2;
	e2.len = 12;

	
	return 0;
}