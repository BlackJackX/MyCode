#include <iostream>
#include <algorithm>
#include <cstring>

#define N 1005
#define V 1005
#define M 105

using namespace std;

int n, v, m;
int f[V], c[N], w[N], g[M][N];

void group_pack_main(int* f, int c[N], int w[N], int g[M][N]) {
	memset(f, 0, sizeof(int) * V);
	for (int i = 0; i < m; i++)
		for (int j = v; j >= 0; j--)
			for (int k = 1; k <= g[i][0]; k++)
				if (j >= c[g[i][k]])
					f[j] = max(f[j], f[j - c[g[i][k]]] + w[g[i][k]]);
}

int main() {
	cin >> v >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> c[i] >> w[i] >> x;
		m = max(m, x);
		g[x - 1][0]++;
		g[x - 1][g[x - 1][0]] = i;
	}
	group_pack_main(f, c, w, g);

	cout << f[v] << endl;
	return 0;
}