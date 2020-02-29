/*
完全背包
物品重量为1，2，4，8
‘价值’为方案数
完全背包的核心是：
n种物品数量不限，随便拿，有一个重量限制，
且dp[i][j]依赖于dp[i-1][j]和dp[i-1][j-w[i]]

递推的方式自己好好想想！！！
没有那么复杂
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

#define N 1000010
#define INF 0x3f3f3f3f
#define MOD 1000000000
#pragma warning(disable:4996)

using namespace std;

int n, k;
int dp[N];
int a[N];

int main() {
	/*
	cin >> n;
	for (k = 0; 1 << k <= n; k++) {
		a[k] = 1 << k;
	}
	dp[0] = 1;
	for (int i = 0; i < k; i++) {
		for (int j = a[i]; j <= n; j++) {
			dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
		}
	}
	cout << dp[n] << endl;
	return 0;
	*/
	cin >> n;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1)
			dp[i] = dp[i - 1];
		else
			dp[i] = dp[i - 2] + dp[i / 2];

		dp[i] %= MOD;
	}
	cout << dp[n] << endl;
	return 0;
}
