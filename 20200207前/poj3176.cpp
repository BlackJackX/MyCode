/*
巨简单的dp
14min
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>

#define N 355
#define INF 0x3f3f3f3f

using namespace std;

int n;
int a[N][N], dp[N][N];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> a[i][j];
		}
	}
	dp[0][0] = a[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				dp[i][j] = dp[i - 1][j] + a[i][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
		}
	}
	int ma = 0;
	for (int i = 0; i < n; i++) {
		ma = max(ma, dp[n-1][i]);
	}
	cout << ma << endl;
	return 0;
}