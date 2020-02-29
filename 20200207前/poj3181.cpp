/*
大数运算。。。。！！！
*/
#include <iostream>
#include <algorithm>

#define N 1000+10
using namespace std;

int n, k;
_int64 f[N];

int main() {
	cin >> n >> k;
	f[0] = 1;
	for (int i = 1; i <= k; i++) {
		for (int j = i; j <= n; j++) {
			f[j] = f[j] + f[j - i];
		}
	}
	cout << f[n] << endl;

	return 0;
}