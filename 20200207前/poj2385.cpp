/*
先思考最优子结构！！！
把状态方程自己模拟一遍
最后再状态压缩
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <cstdio>

#define T 1005
#define W 35
#define INF 0x3f3f3f3f
#pragma warning(disable:4996)

using namespace std;

int t, w;
int f[W];
int a[T];

int main() {
	cin >> t >> w;
	int point;
	memset(f, 0, W * sizeof(int));
	for (int i = 1; i <= t; i++){
		cin >> a[i];
		a[i]--;

		f[0] = f[0] + (a[i] == 0);

		for (int j = w; j >= 1; j--) {
			f[j] = max(f[j], f[j - 1]) + (a[i] == j % 2);
		}
	}
	int ma = 0;

	for (int j = 0; j <= w; j++)
		ma = max(ma, f[j]);
	cout << ma << endl;
	return 0;

}
