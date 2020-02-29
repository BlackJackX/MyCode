/*
想的太麻烦了, 明天看题解
二位线段树, 先不做了
*/
#include <iostream>
#include <algorithm>

#define MAX_N (1000+10)
#define ST_SIZE (MAX_N<<4)
#define lu v*4-2,x1,xm,y1,ym
#define ru v*4-1,x1,xm,ym+1,y2
#define ld v*4,xm+1,x2,y1,ym
#define rd v*4+1,xm+1,x2,ym+1,y2
using namespace std;

int t, n, q;

struct node {
	int x1, x2, y1, y2;
	int mark;
	int dirty;
} tree[ST_SIZE];

void build(int v, int x1, int x2, int y1, int y2) {
	tree[v].mark = 0;
	tree[v].dirty = 0;
	tree[v].x1 = x1;
	tree[v].x2 = x2;
	tree[v].y1 = y1;
	tree[v].y2 = y2;
	if (tree[v].x1 == tree[v].x2 && tree[v].y1 == tree[v].y2)
		return;
	int xm = (x1 + x2) / 2;
	int ym = (y1 + y2) / 2;
	build(v * 2 - 2, x1, xm, y1, ym);
	build(v * 2 - 1, xm + 1, x2, y1, ym);
	build(v * 2, x1, xm, ym + 1, y2);
	build(v * 2 + 1, xm + 1, x2, ym + 1, y2);
}

void change(int v, int x1, int x2, int y1, int y2) {
	if (tree[v].dirty == 0 && tree[v].x1 == tree[v].x2 && tree[v].y1 == tree[v].y2) {
		tree[v].mark ^= 1;
		tree[v].dirty = 0;
		return;
	}
	tree[v].dirty = 1;
	int xm = (tree[v].x1 + tree[v].x2) / 2;
	int ym = (tree[v].y1 + tree[v].y2) / 2;
	int cond = 0;
	if (x2 <= xm)
		cond = 1;
	else if (x1 <= xm && x2 >= xm + 1)
		cond = 2;
	else
		cond = 3;
	if (y2 <= ym)
		cond += 0;
	else if (y1 <= ym && y2 >= ym + 1)
		cond += 3;
	else
		cond += 6;
	switch (cond) {
	case 1:
		change(v * 4 - 2, x1, x2, y1, y2);
		break;
	case 2:
		change(v * 4 - 2, x1, xm, y1, y2);
		change(v * 4 - 1, xm + 1, x2, y1, y2);
		break;
	case 3:
		change(v * 4 - 1, x1, x2, y1, y2);
		break;
	case 4:
		change(v * 4 - 2, x1, x2, y1, ym);
		change(v * 4, x1, x2, ym + 1, y2);
		break;
	case 5:

	}
}

int query(int v, int x, int y) {
	if (tree[v].dirty == 0 && tree[v].x1 <= x && tree[v].x2 >= x && tree[v].y1 <= y && tree[v].y2 >= y)
		return tree[v].mark;

	
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> q;
		build(1, 1, n, 1, n);
		while (q--) {
			char c;
			cin >> c;
			if (c == 'C') {
				int x1, y1, x2, y2;
				cin >> x1 >> y1 >> x2 >> y2;
				change(1, x1, x2, y1, y2);
			}
			else {
				int x, y;
				cin >> x >> y;
				cout << query(1, x, y) << endl;
			}
		}

	}
	return 0;
}