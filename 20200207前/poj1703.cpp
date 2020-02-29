#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <cstdio>

#define N 100005

#pragma warning(disable:4996)
using namespace std;

int par[N], num[N], knd[N];

int t, n, m, a, b;
char c;

void initSet(int n) {
	for (int i = 0; i < n; i++) {
		par[i] = i;
		num[i] = 1;
		knd[i] = 1;
	}
}

int findSet(int x) {
	if (x == par[x])
		return x;
	if (knd[x] == 1) {
		par[x] = findSet(par[x]);
		knd[x] = knd[par[x]];
		return par[x];
	}
	else {
		par[x] = findSet(par[x]);
		knd[x] = knd[par[x]] == 1 ? 0 : 1;
		return par[x];
	}
}

void unionSet(int x, int y) {
	int px = findSet(x);
	int py = findSet(y);
	if (px == py) return;
	if (num[px] >= num[py]) {
		par[py] = px;
		num[px] += num[py];
		knd[py] = knd[x] == knd[y] ? 0 : 1;
	}
	else {
		par[px] = py;
		num[py] += num[px];
		knd[px] = knd[x] == knd[y] ? 0 : 1;
	}
}

int main() {
	scanf("%d\n", &t);
	while (t--) {
		scanf("%d %d\n", &n, &m);
		initSet(n);
		for (int i = 0; i < m; i++) {
			scanf("%c %d %d\n", &c, &a, &b);
			a--; b--;
			if (c == 'A') {
				int pa = findSet(a);
				int pb = findSet(b);
				if (pa == pb && knd[a] == knd[b]) {
					printf("In the same gang.\n");
					continue;
				}
				else if (pa != pb)
					printf("Not sure yet.\n");
				else if (pa == pb && knd[a] != knd[b])
					printf("In different gangs.\n");
			}
			else {
				unionSet(a, b);
			}
		}
	}
	return 0;
}