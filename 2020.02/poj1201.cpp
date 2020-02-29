/*
又气死了, 没做完 
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 50000 + 10;

int n;
int num[MAX_N];
int c[MAX_N];

struct node {
	int l, r, maxn, idx;
} tree[MAX_N<<2];

void build(int v, int l, int r) {
	tree[v].l = l;
	tree[v].r = r;
	if (l == r) {
		tree[v].maxn = num[l];
		tree[v].idx = l;
		return;
	}
	int m = (l + r) / 2;
	build(v * 2, l, m);
	build(v * 2 + 1, m + 1, r);
	if (tree[v * 2].maxn < tree[v * 2 + 1].maxn) {
		tree[v].maxn = tree[v * 2 + 1].maxn;
		tree[v].idx = tree[v * 2 + 1].idx;
	}
	else {
		tree[v].maxn = tree[v * 2].maxn;
		tree[v].idx = tree[v * 2].idx;
	}
}

void update(int v, int, l, int r) {

}

int main() {
	cin >> n;
	int m = 1;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b >> c[i];
		m = max(m, b);
		for (int j = a; j <= b; j++) {
			num[j] += 1;
		}
	}

	build(1, 1, m);

	

	return 0;
}