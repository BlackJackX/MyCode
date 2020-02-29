/*
很简单的dp, 一遍过
37min
*/
#include <iostream>
#include <algorithm>

#define N (400+10)
#define M (40000+10)
using namespace std;

int n;
bool f[M];
bool bak[M];
struct block {
	int h, a, c;
	bool operator < (const block x) const {
		return a < x.a;
	}
};
block bk[N];

void read() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> bk[i].h >> bk[i].a >> bk[i].c;
	}
	sort(bk, bk + n);
}

void solve() {
	f[0] = true;
	bak[0] = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= bk[i].a; j++) {
			if (!f[j]) continue;
			for (int k = 1; k <= bk[i].c; k++) {
				if (j + k * bk[i].h > bk[i].a) break;
				bak[j + k * bk[i].h] = true;
			}
		}
		for (int j = 0; j <= bk[i].a; j++)
			f[j] = bak[j];
	}
}

void output() {
	int ans = 0;
	for (int i = 0; i < M; i++)
		if (f[i])
			ans = i;
	cout << ans << endl;
}

int main() {
	read();

	solve();

	output();

	return 0;
}