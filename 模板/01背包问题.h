#include <iostream>
#include <algorithm>

#define N 1100
#define V 1100

using namespace std;

int t, v, n;
int f[V], c[N], w[N];


void zop(int* f, int* c, int* w) {
	memset(f, 0, sizeof(int) * V);
	for (int i = 0; i < n; i++) {
		for (int j = v; j >= c[i]; j--)
			f[j] = max(f[j], f[j - c[i]] + w[i]);
	}
}
