/*
高精度
我就不该做这个
*/
#include <iostream>
#include <algorithm>
#include <cstring>

#define N 85

using namespace std;

int n, m;
unsigned long long f[N][N];
int a[N];

void read() {
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

void solve() {
	memset(f, 0, sizeof(int) * n * n);
	for (int i = 0; i < n; i++) {
		f[i][i + 1] = a[i] * (1 << n);
	}
	for (int k = 2; k <= n; k++) {
		for (int i = 0; i < n; i++) {
			int j = i + k;
			if (j > n) break;
			unsigned long long p = 1 << (n - k + 1);
			f[i][j] = max(f[i + 1][j] + a[i] * p, f[i][j - 1] + a[j - 1] * p);
		}
	}
}

int main() {
	cin >> m;
	int sum = 0;
	cin >> n;
	while (m--) {
		read();
		solve();
		sum += f[0][n];
	}
	cout << sum << endl;
	return 0;
}