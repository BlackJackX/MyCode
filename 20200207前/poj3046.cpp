/*
虽然自己没有想出来，不过还是顺利过了，高兴
*/

#include <iostream>
#include <algorithm>

#define N 100000+10
#define M 1000+10
#define MOD 1000000
using namespace std;

int t, n, from, to;
int f[N], a[N], b[M];


int main() {
	cin >> t >> n >> from >> to;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int head = a[0];
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == head);
		else {
			head = a[i];
			k++;
		}
		b[k]++;
	}
	f[0] = 1;
	for (int i = 0; i <= t; i++) {
		for (int j = to; j >= 0; j--) {
			for (int k = 1; k <= b[i] && j - k >= 0; k++) {
				f[j] += f[j - k];
				f[j] %= MOD;
			}
		}
	}
	int sum = 0;
	for (int i = from; i <= to; i++) {
		sum += f[i];
		sum %= MOD;
	}
	cout << sum << endl;
	return 0;
}