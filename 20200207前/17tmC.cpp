#include <iostream>
#include <algorithm>

#define N 110

using namespace std;

int n;
int g[N][N];

bool check(int i, int j) {
	if (g[i][j] > 50) return false;
	if (g[i - 1][j] <= 50 && g[i + 1][j] <= 50 && g[i][j - 1] <= 50 && g[i][j + 1] <= 50)
		return false;
	return true;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> g[i][j];
		}
	}
	for (int i = 0; i <= n; i++) {
		g[i][0] = g[i][n + 1] = 255;
		g[0][i] = g[n + 1][i] = 255;
	}
	int area = 0, len = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (g[i][j] <= 50)
				area++;
			if (check(i, j))
				len++;
		}
	}
	cout << area << ' ' << len;
	return 0;
}