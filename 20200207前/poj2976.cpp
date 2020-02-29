/*
TLE先改cin！！！
1h
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstdio>

#pragma warning(disable:4996)
#define N 1000+10
#define ll long long
#define INF 100
using namespace std;

int n, k;
double a[N], b[N], c[N];
double maxavg;

void read() {
	for (int i = 0; i < n; i++)
		scanf("%lf", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%lf", &b[i]);
}

bool check(double x) {
	for (int i = 0; i < n; i++)
		c[i] = a[i] - b[i] * x;
	sort(c, c + n);
	double sum = 0;
	for (int i = n - 1; i >= k; i--)
		sum += c[i];
	if (sum >= 0)
		return true;
	else
		return false;
}

void solve() {
	double op = 0, ed = 1;
	while (abs(ed - op) > 1e-4) {
		double mid = (op + ed) / 2;
		if (check(mid)) op = mid;
		else ed = mid;
	}
	maxavg = op;
}

int main() {
	while (cin >> n >> k && (n || k)) {
		read();
		solve();
		printf("%.0f\n", maxavg * 100);
	}
	return 0;
}