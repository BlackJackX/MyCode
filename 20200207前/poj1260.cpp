/*
题简单，做的也顺利
用时55min
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

#define N 1010
#define INF 0x3f3f3f3f

#pragma warning(disable:4996)

using namespace std;

int a[N], p[N], dp[N];
int s[N][N];
int t, c;

void read() {
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> a[i] >> p[i];
		s[i][i+1] = a[i];
	}
	for (int k = 2; k <= c; k++) {
		for (int i = 0; i < c; i++) {
			s[i][i + k] = s[i][i + k - 1] + a[i + k - 1];
		}
	}
}

int solve() {
	dp[0] = (a[0] + 10) * p[0];
	for (int i = 1; i < c; i++) {
		int mi = (s[0][i + 1] + 10) * p[i];
		for (int j = 1; j <= i; j++) {
			mi = min(mi, dp[i - j] + p[i] * (s[i - j + 1][i + 1] + 10));
		}
		dp[i] = mi;
	}
	return dp[c - 1];
}


int main() {
	cin >> t;
	while (t--) {
		read();
		cout << solve() << endl;
	}
	return 0;
}
