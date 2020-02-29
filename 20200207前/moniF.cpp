#include <iostream>
#include <algorithm>
#include <cstring>

#define INF 0x3f3f3f3f
#define N 105

using namespace std;

int n;
int f[N][N], num[N][N];

void range_dp(int f[N][N]) {
	for (int k = 2; k <= n; k++) {
		for (int i = 0; i <= n - k; i++) {
			for (int j = i + 1; j < i + k; j++) {
				f[i][i + k] = min(f[i][i + k], f[i][j] + f[j][i + k] + num[i][j] + num[j][i + k]);
				num[i][i + k] = num[i][j] + num[j][i + k];
			}
		}
	}
}

int main() {
	cin >> n;
	memset(f, INF, sizeof(int) * N * N);
	memset(num, 0, sizeof(int) * N * N);
	for (int i = 0; i < n; i++) {
		cin >> num[i][i + 1];
		f[i][i] = 0;
		f[i][i + 1] = 0;
	}
	range_dp(f);
	cout << f[0][n] << endl;
	return 0;
}