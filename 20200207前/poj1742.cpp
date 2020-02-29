/*
多重背包，int数组wa，bool数组ac
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

#define M 100000+10
#define N 105
#define INF 0x3f3f3f3f
#pragma warning(disable:4996)
using namespace std;

int n, m;
bool f[M];
int a[N], c[N];
int sum;

void read() {
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);
}
void completepack(int t) {
	for (int i = t; i <= m; i++) {
		f[i] |= f[i - t];
	}
}
void zeroonepack(int t) {
	for (int i = m; i >= t; i--) {
		f[i] |= f[i - t];
	}
}
void solve() {
	memset(f, false, M * sizeof(bool));
	f[0] = true;
	sum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] * c[i] >= m)
			completepack(a[i]);
		else {
			int k = 1;
			int num = c[i];
			while (k < num) {
				zeroonepack(k * a[i]);
				num -= k;
				k *= 2;
			}
			zeroonepack(num * a[i]);
		}
	}
	for (int i = 1; i <= m; i++)
		if (f[i] == 1)
			sum++;
}



int main() {
	while (scanf("%d %d", &n, &m) && (n != 0 || m != 0)) {
		read();
		solve();

		printf("%d\n", sum);
	}
	return 0;
}