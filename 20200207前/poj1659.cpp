/*
havel-hakimi定理
贪心的思路又错了。。。
又错了。。。。。
太难过了，逻辑我又控制不了了
*/
#include <iostream>
#include <algorithm>

#define P pair<int, int>
#define N 30
using namespace std;

int t, n;
P a[N];
int g[N][N];
bool cmp(P x, P y) {
	return x.first > y.first;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				g[i][j] = 0;
		}
		for (int i = 0; i < n; i++) {
			cin >> a[i].first;
			a[i].second = i;
		}
		
		while (true) {
			sort(a, a + n, cmp);
			if (a[0].first <= 0) break;
			for (int i = 1; i < n && a[0].first > 0; i++) {
				if (a[i].first <= 0) continue;
				a[0].first--;
				a[i].first--;
				g[a[i].second][a[0].second] = g[a[0].second][a[i].second] = 1;
			}
			if (a[0].first != 0) break;
		}
		bool flag = true;
		for (int i = 0; i < n; i++)
			if (a[i].first != 0)
				flag = false;
		if (!flag) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cout << g[i][j] << ' ';
				}
				cout << endl;
			}
		}
		cout << endl;
	}
	return 0;
}