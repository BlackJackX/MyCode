#include <iostream>
#include <algorithm>
#include <cstring>

#define N 10000
#define INF 0x3f3f3f3f

using namespace std;

int n;
int a[N], b[N];
int f[N];

//a,b从1开始
int LCS(int f[N][N], int *a, int *b, int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i] == b[j])
				f[i][j] = f[i - 1][j - 1] + 1;
			else
				f[i][j] = max(f[i][j - 1], f[i-1][j]);
		}
	}
	return f[n][n];
}
//a从0开始
int LIS(int *f, int *a, int n) {
	memset(f, INF, sizeof(int) * N);
	for (int i = 0; i < n; i++) {
		f[lower_bound(f, f + n, a[i]) - f] = a[i];
	}
	
	return lower_bound(f, f + n, INF) - f;
}
//a[i],b[i]无重复，O(lgn)
int LCS(int* f, int* a, int* b, int *c, int n) {
	for (int i = 0; i < n; i++)
		idx[a[i]] = i;
	for (int i = 0; i < n; i++)
		c[i] = idx[b[i]];
	return LIS(f, c, n);
}