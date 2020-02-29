/*
看懂题很重要，下次套模板前先看题
还有不要想当然的认为题目的要求是什么样的
总之多看几遍！！！
这里求的不是单调，不是双向单调，不是单峰，
而是中间的两个可以相等，两边单调的梯形！！！
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

#define N 1005
#define FNF 100
#define INF 0x3f3f3f3f
using namespace std;

int n;
float a[N];
int b[N], c[N];
float dp[N];


int lis(int *d) {
	for (int i = 0; i < n; i++)
		dp[i] = FNF;
	int len = 0;
	for (int i = 0; i < n; i++) {
		int idx = lower_bound(dp, dp + n, a[i]) - dp;
		dp[idx] = a[i];
		len = max(len, idx);
		d[i] = idx + 1;
	}
	return lower_bound(dp, dp + n, FNF) - dp;
}


int main() {
	cin >> n; 
	for (int i = 0; i < n; i++)
		cin >> a[i];
	lis(b);
	reverse(a, a + n);
	lis(c);

	reverse(c, c + n);
	int ma = 0;
	for (int i = 0; i < n; i++)
		ma = max(ma, b[i] + c[i] - 1);
	
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--) {
			ma = max(ma, b[i] + c[j]);
		}
	}
	cout << n - ma << endl;
	return 0;
}

