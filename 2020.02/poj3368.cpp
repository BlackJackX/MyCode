/*
讲题气死了, 明天调
我tm就是智障, 多组测试, 我又又又又又又又没看题
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#pragma warning(disable:4996)
using namespace std;

const int MAX_N = 100000 + 10;
const int ST_SIZE = MAX_N << 3;

int n, q;
int a[MAX_N];
struct node {
	int l, r, f, lf, rf;
} tree[ST_SIZE];

void init(node x) {
	x.l = x.r = x.f = x.lf = x.rf = 0;
}

void build(int v, int l, int r) {
	init(tree[v]);
	tree[v].l = l;
	tree[v].r = r;
	int m = (l + r) / 2;
	if (tree[v].l == tree[v].r) {
		tree[v].f = tree[v].lf = tree[v].rf = 1;
		return;
	}
	build(v * 2, l, m);
	build(v * 2 + 1, m + 1, r);
	
	tree[v].f = 0;
	if (a[m] == a[m + 1])
		tree[v].f = tree[v * 2].rf + tree[v * 2 + 1].lf;
	tree[v].f = max(tree[v].f, max(tree[v * 2].f, tree[v * 2 + 1].f));

	tree[v].lf = tree[v * 2].lf;
	tree[v].rf = tree[v * 2 + 1].rf;

	if (a[m] == a[m + 1]) {
		if (a[l] == a[m + 1])
			tree[v].lf += tree[v * 2 + 1].lf;
		if (a[m] == a[r])
			tree[v].rf += tree[v * 2].rf;
	}

/*
	if (a[m] != a[m + 1]) {
		tree[v].lf = tree[v * 2].lf;
		tree[v].rf = tree[v * 2 + 1].rf;
	}
	else {
		if (a[l] != a[m] && a[m + 1] != a[r]) {
			tree[v].lf = tree[v * 2].lf;
			tree[v].rf = tree[v * 2 + 1].rf;
		}
		else if (a[l] != a[m] && a[m + 1] == a[r]) {
			tree[v].lf = tree[v * 2].lf;
			tree[v].rf = tree[v * 2].rf + tree[v * 2 + 1].lf;
		}
		else if (a[l] == a[m] && a[m + 1] != a[r]) {
			tree[v].lf = tree[v * 2].rf + tree[v * 2 + 1].lf;
			tree[v].rf = tree[v * 2 + 1].rf;
		}
		else 
			tree[v].lf = tree[v].rf = tree[v].f;
	}
*/
}

int query(int v, int l, int r) {
	if (tree[v].l == l && tree[v].r == r)
		return tree[v].f;
	int m = (tree[v].l + tree[v].r) / 2;
	if (r <= m)
		return query(v * 2, l, r);
	else if (l >= m + 1)
		return query(v * 2 + 1, l, r);
	else {
		int lq = query(v * 2, l, m);
		int rq = query(v * 2 + 1, m + 1, r);
		int mf = 0;
		if (a[m] == a[m + 1]) {
			if (tree[v * 2].r - tree[v * 2].rf + 1 < l)
				mf += tree[v * 2].r - l + 1;
			else
				mf += tree[v * 2].rf;
			if (tree[v * 2 + 1].l + tree[v * 2 + 1].lf - 1 > r)
				mf += r - tree[v * 2 + 1].l + 1;
			else
				mf += tree[v * 2 + 1].lf;
		}
		return max(mf, max(lq, rq));
	}
}

int main() {
	while (scanf("%d %d", &n, &q) && n != 0) {
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		build(1, 1, n);
		while (q--) {
			int l, r;
			scanf("%d %d", &l, &r);
			printf("%d\n",query(1, l, r));
		}
	}



	return 0;
}