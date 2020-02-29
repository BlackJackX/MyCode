#include <iostream>
#include <algorithm>
#include <cmath>

#define INF 0x3f3f3f3f
#define N 300+5
#define M 30+5

using namespace std;

int n, m;
int f[N][M], g[N][N], a[N];

int main() {
	cin >> n >> m;
	;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int mid = (i + j) / 2;
			for (int k = i; k <= j; k++) {
				g[i][j] += abs(a[mid] - a[k]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			int mi = INF;
			for (int k = j - 1; k < i; k++) {
				mi = min(mi, f[k][j - 1] + g[k + 1][i]);
			}
			f[i][j] = mi;
		}
	}
	cout << f[n - 1][m - 1] << endl;
	return 0;
}