/*
失败了!!!
二分套二分
*/
#include <iostream>
#include <algorithm>

#define ll long long
#define INF 1e12
#define N 50000+10
using namespace std;

int t, n, m;
int a[N];

ll f(int i, int j) {
	return i * i + 100000 * i + j * j - 100000 * j + i * j;
}

bool check(int x) {
	ll sum = 0;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++)
			a[i] = f(i, j);
		sum += upper_bound(a, a + n, x) - a;
	}
	sum = n * n - sum;
	return sum > m;

}


int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		ll op = -INF, ed = INF, mid;
		ll ans = 0;
		while (op <= ed) {
			mid = (op + ed) / 2;
			if (check(mid)) {
				ans = mid;
				op = mid + 1;
			}
			else
				ed = mid - 1;
		}
		cout << ans << endl;
	}
	return 0;
}