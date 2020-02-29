/*
区间dp
27min
又没有自己想出来
*/
#include <iostream>
#include <algorithm>

#define N 105
#define INF 0x3f3f3f3f
using namespace std;

int n;
int f[N][N], a[N];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 1; i <= n - 2; i++) {
		f[i - 1][i + 1] = a[i - 1] * a[i] * a[i + 1];
	}
	for (int k = 3; k <= n - 1; k++) {
		for (int i = 0; i <= n - 1; i++) {
			int j = i + k;
			if (j > n - 1) break;
			f[i][j] = INF;
			for (int l = i + 1; l <= j - 1; l++) {
				f[i][j] = min(f[i][j], f[i][l] + f[l][j] + a[i] * a[j] * a[l]);
			}
		}
	}
	cout << f[0][n - 1] << endl;
	return 0;
}