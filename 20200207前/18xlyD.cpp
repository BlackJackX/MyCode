/*
完全背包，不知道数组上界设多大
反正尽可能大就好了。。。。
1h10min
*/

#include <iostream>
#include <algorithm>
#include <cstring>

#pragma warning(disable:4996)

#define N 2500
#define INF 0x3f3f3f3f
using namespace std;

int t, n = 6;
int a[6], f[N], g[N];
float avg;
int ma;

void read() {
	int x, i = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void solve() {
	memset(f, INF, N * sizeof(int));
	f[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = a[i]; j <= 2400; j++) {
			f[j] = min(f[j - a[i]] + 1, f[j]);
		}
	}
	memset(g, INF, N * sizeof(int));
	for (int k = 1; k <= 100; k++) {
		for (int i = 0; i <= 2300; i++) {
			int j = k + i;
			g[k] = min(f[i] + f[j], g[k]);
		}
	}
}
void output() {
	avg = 0;
	ma = 0;
	for (int i = 1; i <= 100; i++) {
		avg += g[i];
		ma = max(ma, g[i]);
	}
	avg /= 100;
	printf("%.2f %d\n", avg, ma);
}

int main() {
	cin >> t;
	while (t--) {
		read();
		solve();
		output();
	}

#include <iostream>
#include <algorithm>
#include <cstring>

#pragma warning(disable:4996)

#define N 2500
#define INF 0x3f3f3f3f
	using namespace std;

	int t, n = 6;
	int a[6], f[N], g[N];
	float avg;
	int ma;

	void read() {
		int x, i = 0;
		for (int i = 0; i < n; i++)
			cin >> a[i];
	}
	void solve() {
		memset(f, INF, N * sizeof(int));
		f[0] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = a[i]; j <= 2400; j++) {
				f[j] = min(f[j - a[i]] + 1, f[j]);
			}
		}
		memset(g, INF, N * sizeof(int));
		for (int k = 1; k <= 100; k++) {
			for (int i = 0; i <= 2300; i++) {
				int j = k + i;
				g[k] = min(f[i] + f[j], g[k]);
			}
		}
	}
	void output() {
		avg = 0;
		ma = 0;
		for (int i = 1; i <= 100; i++) {
			avg += g[i];
			ma = max(ma, g[i]);
		}
		avg /= 100;
		printf("%.2f %d\n", avg, ma);
	}

	int main() {
		cin >> t;
		while (t--) {
			read();
			solve();
			output();
		}

		return 0;
	}	return 0;
}