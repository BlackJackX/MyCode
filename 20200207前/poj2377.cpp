/*
克鲁斯卡模板题
30min--
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>

#define N 1005
#define INF 0x3f3f3f3f
using namespace std;

struct edge {
	int a, b, c;
	edge(int na, int nb, int nc) {
		a = na; b = nb; c = nc;
	}
	bool operator < (const edge x) const {
		return x.c > c;
	}
};

int n, m;
int par[N];
priority_queue<edge> q;

int findSet(int x) {
	if (par[x] == x)
		return x;
	par[x] = findSet(par[x]);
	return par[x];
}
void unionSet(int x, int y) {
	int px = findSet(x);
	int py = findSet(y);
	if (px == py)
		return;
	par[py] = px;
}

int klsk() {
	int sum = 0;
	while (!q.empty()) {
		edge tmp = q.top();
		q.pop();
		int a = tmp.a;
		int b = tmp.b;
		int c = tmp.c;
		int pa = findSet(a);
		int pb = findSet(b);
		if (pa == pb)
			continue;
		sum += c;
		unionSet(pa, pb);
	}
	int s = findSet(1);
	for (int i = 1; i <= n; i++) {
		if (findSet(i) != s)
			return -1;
	}
	return sum;
}


int main() {
	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		q.push(edge(a, b, c));
	}
	for (int i = 0; i <= n; i++)
		par[i] = i;
	
	cout << klsk() << endl;
	return 0;
}