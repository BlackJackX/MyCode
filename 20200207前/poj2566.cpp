/*
尺取法
好难啊!!!
重做
*/
#include <iostream>
#include <algorithm>
#include <cmath>

#define N 100000+10
#define INF 0x7fffffff
using namespace std;

typedef  pair<int, int> P;

int n, k, t, mi, op, ed;
P a[N];

void read() {
	a[0] = P(0, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first;
		a[i].second = i;
		a[i].first = a[i - 1].first + a[i].first;
	}
	sort(a, a + n + 1);
}

void solve() {
	int op = 0, ed = 1, sum = 0;
	int miop = 0, mied = 0, misum = INF;
	while (op <= n && ed <= n) {
		sum = a[ed].first - a[op].first;
		if (abs(sum - t) < abs(misum - t)) {
			misum = sum;
			miop = a[op].second;
			mied = a[ed].second;
		}
		if (sum < t) ed++;
		else if (sum > t) op++;
		else break;

		if (op == ed) ed++;
	}
	if (miop > mied)
		swap(miop, mied);
	cout << misum << ' ' << miop + 1 << ' ' << mied << endl;
}

int main() {
	while (cin >> n >> k && n != 0 && k != 0) {
		read();
		while (k--) {
			cin >> t;
			solve();
		}
	}
	return 0;
}