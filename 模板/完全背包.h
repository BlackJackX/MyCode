#include <iostream>
#include <algorithm>

#define N 105
#define V 55500

using namespace std;

int v, n;
int f[V], c[N], w[N];

void complete_pack(int* f, int* c, int* w) {
	memset(f, 0, sizeof(int) * V);
	for (int i = 0; i < n; i++) {
		for (int j = c[i]; j <= v + 5000; j++)
			f[j] = max(f[j], f[j - c[i]] + w[i]);
	}
}