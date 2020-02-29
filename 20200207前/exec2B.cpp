/*
并查集报废，浪费30min
dfs打错一个字母，浪费5min
总1h7min
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

#define N (1000+10)
#pragma warning(disable:4996)
using namespace std;

int n, m;
int g[N][N];
int knd[N];
bool vis[N];

void init() {
	memset(g, 0, sizeof(int) * N * N);
	memset(vis, false, sizeof(bool) * N);
	memset(knd, 0, sizeof(int) * N);
}

void addedge(int a, int b, int c) {
	if (c == 0)
		g[a][b] = 1;
	else if (c == 1)
		g[a][b] = -1;
}

bool dfs(int u) {
	vis[u] = true;
	bool flag = true;
	for (int v = 0; v < n; v++) {
		if (!flag)
			return false;
		if (g[u][v] == 1) {
			if (knd[v] == 0) {
				knd[v] = knd[u];
				flag &= dfs(v);
			}
			else {
				if (knd[v] != knd[u])
					return false;
			}
		}
		else if (g[u][v] == -1) {
			if (knd[v] == 0) {
				knd[v] = knd[u] == 1 ? 2 : 1;
				flag &= dfs(v);
			}
			else {
				if (knd[v] == knd[u])
					return false;
			}
		}
	}

	return flag;
}

int main() {
	while (scanf("%d %d", &n, &m)!=EOF) {
		int a, b, c;
		init();
		while (m--) {
			scanf("%d %d %d", &a, &b, &c);
			addedge(a, b, c);
		}
		bool flag = true;
		for (int i = 0; i < n; i++) {
			if (!flag)
				break;
			if (vis[i]) continue;
			knd[i] = 1;
			if (!dfs(i))
				flag = false;
		}
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}