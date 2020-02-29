/*
一个小时也没想出来
逻辑太复杂！！！
以后重想
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

#pragma warning(disable:4996)
#define N 100000+10
#define ll long long
using namespace std;

int n;
ll mid;
ll a[N];

void read() {
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
}
bool check(ll x) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += n - (lower_bound(a + i + 1, a + n, a[i] + mid) - a);
	}
	if (sum > n * (n - 1) / 2 / 2)
		return true;
	return false;
}


int main() {
	while (cin >> n) {
		read();
		sort(a, a + n);
		int i = 0, j = a[n - 1] - a[0] + 1;
		int ans = 0;
		while (i <= j) {
			mid = (i + j) / 2;
			if (check(mid)) {
				i = mid + 1;
				ans = mid;
			}
			else
				j = mid - 1;
		}
		printf("%d\n", ans);
	}

	return 0;
}