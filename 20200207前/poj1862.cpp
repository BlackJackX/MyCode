/*
第一遍不知道哪里错了, 第二次改用reduce
29min
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

#define N (100+10)
using namespace std;

int n;
float a[N];

float f(float x, float y) {
	return 2 * pow(x * y, 0.5);
}

void read() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

void solve() {
	sort(a, a + n);
	reverse(a, a + n);
	for (int i = 0; i < n - 1; i++) {
		a[i + 1] = f(a[i], a[i + 1]);
	}
	printf("%.3f\n", a[n - 1]);
}

int main() {
	read();

	solve();

	return 0;
}