/*
第一次tle, 写成n^2了
第二次过了
注意i和j别反了
44min
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

#pragma warning(disable:4996)
#define INF (0x7fffffff)
#define N (2000+10)
using namespace std;

int a[N];
int s[N];
int f[N];
int bak[N];
int n;

void read() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		s[i] = a[i];
		f[i] = bak[i] = 0;
	}
	sort(s, s + n);
}

void solve() {
	for (int i = 0; i < n; i++) {
		int mi = INF;
		for (int j = 0; j < n; j++) {
			mi = min(mi, bak[j]);
			f[j] = mi;
			f[j] += abs(a[i] - s[j]);
		}
		for (int j = 0; j < n; j++) {
			bak[j] = f[j];
		}
	}
}

void output() {
	int ans = INF;
	for (int i = 0; i < n; i++)
		ans = min(ans, f[i]);
	printf("%d\n", ans);
}

int main() {
	read();

	solve();

	output();

	return 0;
}