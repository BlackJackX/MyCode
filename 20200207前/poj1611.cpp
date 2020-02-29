#include <iostream>
#include <algorithm>
#include <cstring>

#define N 40000

using namespace std;

int par[N], rnk[N], num[N];

void init_set() {
	for (int i = 0; i < N; i++) {
		par[i] = i;
		rnk[i] = 0;
		num[i] = 1;
	}
}

int find_set(int x) {
	if (par[x] == x)
		return x;
	else {
		par[x] = find_set(par[x]);
		return par[x];
	}
}

void union_set(int x, int y) {
	x = find_set(x);
	y = find_set(y);
	if (x == y) return;
	if (rnk[x] < rnk[y]) {
		par[x] = y;
		num[y] += num[x];
	}
	else {
		par[y] = x;
		num[x] += num[y];
		if (rnk[x] == rnk[y]) rnk[x]++;
	}
}

int main() {
	int n, m;
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		init_set();
		for (int i = 0; i < m; i++) {
			int t, x, y;
			cin >> t;
			if (t == 0) continue;
			cin >> x;
			for (int j = 1; j < t; j++) {
				cin >> y;
				union_set(x, y);
			}
		}

		cout << num[find_set(0)] << endl;
	}
	return 0;
} 