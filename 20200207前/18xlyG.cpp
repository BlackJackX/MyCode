#include <iostream>
#include <algorithm>
#include <cstring>

#define N 50000+10
using namespace std;

int n, k;
int par[N], knd[N];

void initSet() {
	for (int i = 0; i < N; i++) {
		par[i] = i;
		knd[i] = 0;
	}
}

int findSet(int x) {
	if (par[x] == x) return x;
	knd[x] = findKnd(x);
	par[x] = findSet(par[x]);
	return par[x];
}

bool unionSet(int x, int y, int d) {
	int px = findSet(x);
	int py = findSet(y);
	if (px == py) {
		if (knd[x] != knd[y])
			return false;
		else
			return true;
	}
	par[py] = px;
	knd[py] = 0;

	return true;
}



int main() {
	cin >> n >> k;
	int d, a, b;
	initSet();
	int num = 0;
	while (k--) {
		cin >> d >> a >> b;
		if (a > n || b > n) {
			num++;
			continue;
		}
		if (!unionSet(a, b, d))
			num++;

	}
	cout << num << endl;
	return 0;
}