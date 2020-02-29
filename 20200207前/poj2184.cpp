/*
完成, 01背包的负数形式处理
让人头大!!!!
1h47min
*/
#include <iostream>
#include <algorithm>

#define N (100+10)
#define M (200000+200)
#define MINF (-1*100000-10) 
#define base 100000
using namespace std;

int n;
int a[N], b[N];
int f[M];

void read() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
}

void solve() {
	for (int i = 0; i < M; i++)
		f[i] = MINF;
	f[base] = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] <= 0 && b[i] <= 0)
			continue;
		if (a[i] >= 0) {
			for (int j = 2 * base - 1; j >= a[i]; j--) {
				f[j] = max(f[j], f[j - a[i]] + b[i]);
			}
		}
		else {
			for (int j = 0; j <= 2 * base - 1 + a[i]; j++) {
				f[j] = max(f[j], f[j - a[i]] + b[i]);
			}
		}
	}
}

void output() {
	int ans = MINF;
	for (int i = base; i < base * 2; i++) {
		if (f[i] < 0) continue;
		ans = max(ans, f[i] + i - base);
	}
	if (ans < 0)
		cout << 0 << endl;
	else
		cout << ans << endl;
}

int main() {
	read();

	solve();

	output();

	return 0;
}