#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

#define N 100005
#define INF 0x3f3f3f3f

using namespace std;

int n;
int a[N], b[N], c[N];
int f[N];
map<int, int> idx;

int LIS(int *f, int *a, int n) {
	memset(f, INF, sizeof(int) * N);
	for (int i = 0; i < n; i++) {
		f[lower_bound(f, f + n, a[i]) - f] = a[i];
	}
	
	return lower_bound(f, f + n, INF) - f;
}

int LCS(int* f, int* a, int* b, int *c, int n) {
	for (int i = 0; i < n; i++)
		idx[a[i]] = i;
	for (int i = 0; i < n; i++)
		c[i] = idx[b[i]];
	return LIS(f, c, n);
}


int main() {
	cin >> n;
	memset(f, 0, N * sizeof(int));
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];


	cout << LCS(f, a, b, c, n);
	return 0;
}