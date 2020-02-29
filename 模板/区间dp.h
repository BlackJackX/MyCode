#include <iostream>
#include <algorithm>
#include <cstring>

#define INF 0x3f3f3f3f
#define N 105

using namespace std;

int n;
int f[N][N], num[N][N];

void range_dp(int f[N][N]) {
	//区间为左闭右开
	//区间大小2-n
	for (int k = 2; k <= n; k++) {
		//起始点
		for (int i = 0; i <= n - k; i++) {
			//中间分割点
			for (int j = i + 1; j < i + k; j++) {
				f[i][i + k] = min(f[i][i + k], f[i][j] + f[j][i + k] + num[i][j] + num[j][i + k]);
				num[i][i + k] = num[i][j] + num[j][i + k];
			}
		}
	}
}