/*
思路很快就想出来了，但是还是做了很久，
一方面是因为状态不好，另一方面是因为我太依赖题解和别人的测试数据了，
要自己想啊！！！
time:60min+
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <cstdio>

#define N 25500

#pragma warning(disable:4996)

using namespace std;

int n, t;
struct interval {
	int s, e;
};
interval itv[N];

bool cmp(interval x, interval y) {
	return x.s < y.s;
}

int main() {
	scanf("%d %d", &n, &t);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &itv[i].s, &itv[i].e);
	}
	sort(itv, itv + n, cmp);
	int E = 0;
	int num = 0;
	int i = 0;
	while (E < t) {
		int e = -1;
		for (; i < n && itv[i].s <= E + 1; i++) {
			e = max(e, itv[i].e);
		}
		if (e == -1) {
			num = -1;
			break;
		}
		E = e;
		num++;
	}

	printf("%d\n", num);
	return 0;
}