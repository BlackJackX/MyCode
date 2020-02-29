/*
素数筛+bfs, 竟然一遍过
我还以为一定会tle的
1h14min
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>

#define N (10000+10)
#define INF (0x3f3f3f3f)
using namespace std;

int t;
bool prime[N];
int pnum;
int a, b;
bool vis[N];

void findprime() {
	memset(prime, true, sizeof(bool) * N);
	for (int i = 2; i <= 100; i++) {
		if (!prime[i])
			continue;
		for (int j = 2; j * i <= 9999; j++) {
			prime[j * i] = false;
		}
	}
}

int nexta(int na, int i, int j) {
	return na / ((int)pow(10, i + 1)) * ((int)pow(10, i + 1))+ na % ((int)pow(10, i)) + j * ((int)pow(10, i));
}

int bfs(int a, int b) {
	queue<int> q;
	memset(vis, false, sizeof(bool) * N);
	int ans = 0;
	q.push(a);
	q.push(0);
	int ta;

	while (!q.empty()) {
		ta = q.front();
		q.pop();
		ans = q.front();
		q.pop();
		if (vis[ta])
			continue;
		vis[ta] = true;

		if (ta == b)
			break;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j <= 9; j++) {
				int na = nexta(ta, i, j);
				if (na < 1000 || !prime[na])
					continue;
				q.push(na);
				q.push(ans + 1);
			}
		}
	}
	if (q.empty() && ta != b)
		return -1;
	return ans;
}

int main() {
	cin >> t;
	findprime();
	
	
	
	while (t--) {
		cin >> a >> b;
		int res = bfs(a, b);
		if (res == -1)
			cout << "Impossible" << endl;
		else
			cout << res << endl;
	}
	
	return 0;
}