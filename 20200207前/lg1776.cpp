#include <iostream>
#include <algorithm>

#define N 105
#define V 100005
using namespace std;

int v, n;
int f[V], c[N], w[N], m[N];

void zero_one_pack(int* f, int c, int w) {
	for (int j = v; j >= c; j--)
		f[j] = max(f[j], f[j - c] + w);
}

void complete_pack(int* f, int c, int w) {
	for (int j = c; j <= v; j++)
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

int main() {
	cin >> n >> v;
	for (int i = 0; i < n; i++)
		cin >> w[i] >> c[i] >> m[i];
	muti_pack_main(f, c, w, m);
	int ma = 0;
	for (int i = 0; i <= v; i++)
		ma = max(ma, f[i]);
	cout << ma << endl;
	return 0;
}