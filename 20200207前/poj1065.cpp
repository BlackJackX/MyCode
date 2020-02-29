/*
根本没用dp。。。。
20min
*/

#include <iostream>
#include <algorithm>
#include <cstring>

#define P pair<int, int>
#define N 5000+10

using namespace std;

int t, n;
P wood[N];
bool vis[N];

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		memset(vis, false, sizeof(bool) * n);
		for (int i = 0; i < n; i++) {
			cin >> wood[i].first >> wood[i].second;
		}
		sort(wood, wood + n);
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (vis[i]) continue;
			vis[i] = true;
			int mi = wood[i].second;
			cnt++;
			for (int j = i + 1; j < n; j++) {
				if (mi <= wood[j].second && !vis[j]) {
					vis[j] = true;
					mi = wood[j].second;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}