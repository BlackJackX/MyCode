/*
双变量, 十分简单, 和之前的一样
最后又智障了,s写成t了
之前做的挺好, 就不断地测试, 根据题目要求写样例
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

#pragma warning(disable:4996)
using namespace std;

const int MAX_N = 100000 + 10;
const int BIT_SIZE = MAX_N;

struct Cow {
	int s, t, num, idx;
} cow[MAX_N];
bool cmpts(Cow x, Cow y) {
	if (x.t == y.t)
		return x.s < y.s;
	return x.t > y.t;
}
bool cmpidx(Cow x, Cow y) {
	return x.idx < y.idx;
}
int bit[BIT_SIZE];

int n;

int sum(int i) {
	int ans = 0;
	while (i != 0) {
		ans += bit[i];
		i -= i & (-i);
	}
	return ans;
}

void add(int i, int x) {
	while (i < BIT_SIZE) {
		bit[i] += x;
		i += i & (-i);
	}
}

int main() {
	while (scanf("%d", &n) != EOF && n != 0) {
		memset(bit, 0, sizeof(int) * BIT_SIZE);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &cow[i].s, &cow[i].t);
			cow[i].idx = i;
			cow[i].s++;
			cow[i].t++;
		}
		
		sort(cow, cow + n, cmpts);
		for (int i = 0; i < n; i++) {
			if (i != 0 && cow[i - 1].s == cow[i].s && cow[i - 1].t == cow[i].t)
				cow[i].num = cow[i - 1].num;
			else
				cow[i].num = sum(cow[i].s);
			add(cow[i].s, 1);
		}

		sort(cow, cow + n, cmpidx);
		for (int i = 0; i < n; i++)
			printf("%d ", cow[i].num);
		printf("\n");
	}

	return 0;
}