#include <iostream>
#include <algorithm>
#include <cstring>

#define N 1005
#define V 1005
#define M 105

using namespace std;

int n, v, m;
int f[V], c[N], w[N], g[M][N];


void zero_one_pack_main(int* f, int* c, int* w) {
	memset(f, 0, sizeof(int) * V);
	for (int i = 0; i < n; i++) 
		zero_one_pack(f, c[i], w[i]);
}

void zero_one_pack(int* f, int c, int w) {
	for (int j = v; j >= c; j--)
		f[j] = max(f[j], f[j - c] + w);
}

void complete_pack_main(int* f, int* c, int* w) {
	memset(f, 0, sizeof(int) * V);
	for (int i = 0; i < n; i++)
		complete_pack(f, c, w);

}
void complete_pack(int* f, int c, int w) {
	for (int j = c; j <= v ; j++)
		f[j] = max(f[j], f[j - c] + w);
	
}

void muti_pack(int* f, int c, int w, int m) {
	if (c * m > v)
		complete_pack(f, c, w);
	int k = 1;
	while (k < m) {
		zero_one_pack(f, k * c, k * w);
		m = m - k;
		k = 2*k;
	}
	zero_one_pack(f, c * m, w * m);
}
void muti_pack_main(int* f, int* c, int* w, int* m) {
	memset(f, 0, sizeof(int) * V);
	for (int i = 0; i < n; i++)
		muti_pack(f, c[i], w[i], m[i]);
}



void group_pack_main(int* f, int c[N], int w[N], int g[M][N]) {
	memset(f, 0, sizeof(int) * V);
	for (int i = 0; i < m; i++)
		for (int j = v; j >= 0; j--)
			for (int k = 1; k <= g[i][0]; k++)
				if (j >= c[g[i][k]])
					f[j] = max(f[j], f[j - c[g[i][k]]] + w[g[i][k]]);
}
