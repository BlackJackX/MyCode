/*
第一次tle,因为他说第k大的,而我把所有的都派了一边序
正解clgn, 我的原解为cnlgn
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#pragma warning(disable:4996)
#define C 100000+10
#define INF 0x3f3f3f3f
using namespace std;

int n, c, mid = -1, f;

struct cow {
	int s, a;
};
cow cows[C];
int lower[C], upper[C];

bool cmp1 (cow x, cow y) {
	return x.s < y.s;
}
struct cmp2 {
	bool operator() (cow x, cow y) {
		return x.a < y.a;
	}
};


int main() {
	scanf("%d %d %lld", &n, &c, &f);
	for (int i = 0; i < c; i++) {
		scanf("%d %d", &cows[i].s, &cows[i].a);
	}
	sort(cows, cows + c, cmp1);
	priority_queue<cow, vector<cow>, cmp2> q;
	int sum = 0;
	for (int i = 0; i < c; i++) {
		lower[i] = q.size() == n / 2 ? sum : INF;
		q.push(cows[i]);
		sum += cows[i].a;
		if (q.size() > n / 2) {
			cow tmp = q.top();
			q.pop();
			sum -= tmp.a;
		}
	}
	sum = 0;
	while (!q.empty())
		q.pop();
	for (int i = c - 1; i >= 0; i--) {
		upper[i] = q.size() == n / 2 ? sum : INF;
		q.push(cows[i]);
		sum += cows[i].a;
		if (q.size() > n / 2) {
			cow tmp = q.top();
			q.pop();
			sum -= tmp.a;
		}
			
	}
	for (int i = c - 1; i >= 0; i--) {
		if (lower[i] + upper[i] + cows[i].a <= f) {
			mid = cows[i].s;
			break;
		}
	}

	printf("%d", mid);
	return 0;
}