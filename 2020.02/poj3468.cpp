/*
疯狂tle无法解释
我的做法明明和
https://blog.csdn.net/hurmishine/article/details/54315761
这个一样....
可能需要为每一个节点建立一个node结构
改了也不行....
*/
#include <iostream>
#include <algorithm>
#include <cstdio>

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
const int MAX_N = 100000 + 10;
const int ST_SIZE = MAX_N << 2;

int n, q;
ll a[MAX_N];


struct node {
	int l, r, m;
	ll sum, mark;
} tree[ST_SIZE];

void build(int v, int l, int r) {
	tree[v].l = l;
	tree[v].r = r;
	if (l == r) {
		tree[v].sum = a[l];
		return;
	}
	int m = (l + r) >> 1;
	tree[v].m = m;
	build(v << 1, l, m);
	build(v << 1 | 1, m + 1, r);
	tree[v].sum = tree[v << 1].sum + tree[v << 1 | 1].sum;
	tree[v].mark = 0;
}


void change(int v, int a, int b, int c) {
	int l = tree[v].l;
	int r = tree[v].r;
	if (r == a && b == l) {
		tree[v].mark += c;
		tree[v].sum += c * (r - l + 1);
		return;
	}
	int m = tree[v].m;
	if (b <= m)
		change(v << 1, a, b, c);
	else if (a >= m + 1)
		change(v << 1 | 1, a, b, c);
	else {
		change(v << 1, a, m, c);
		change(v << 1 | 1, m + 1, b, c);
	}
	tree[v].sum = tree[v << 1].sum + tree[v << 1 | 1].sum;
}

void pushdown(int v, int l, int r) {
	if (tree[v].mark != 0) {
		int m = tree[v].m;
		tree[v << 1].sum += tree[v].mark * (m - l + 1);
		tree[v << 1 | 1].sum += tree[v].mark * (r - m + 1);
		tree[v << 1].mark = tree[v].mark;
		tree[v << 1 | 1].mark = tree[v].mark;
		tree[v].mark = 0;
	}
}

ll query(int v, int a, int b) {
	int l = tree[v].l;
	int r = tree[v].r;
	if (r == a && b == l)
		return tree[v].sum;
	int m = tree[v].m;
	pushdown(v, l, r);
	if (b <= m)
		return query(v << 1, a, b);
	else if (a >= m + 1)
		return query(v << 1 | 1, a, b);
	else
		return query(v << 1, a, m) + query(v << 1 | 1, m + 1, b);
}


int main() {
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	build(1, 1, n);
	while (q--) {
		char s[2];
		scanf("%s", s);
		if (s[0] == 'Q') {
			int a, b;
			scanf("%d %d", &a, &b);
			printf("%lld\n", query(1, a, b));
		}
		else {
			int a, b;
			int c;
			scanf("%d %d %d", &a, &b, &c);
			change(1, a, b, c);
		}
	}
	return 0;
}