/*
tle
1h5min
*/
#include <iostream>
#include <algorithm>

#define N (100000+10)
using namespace std;

int n, k;
float op = 0, ed = 0, mid = 0;
int ans[N];
struct node1 {
	float v, w;
	int p;
};
node1 a[N];
struct node2 {
	float z;
	int p;
};
node2 b[N];
void read() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i].v >> a[i].w;
		a[i].p = i + 1;
		ed = max(ed, a[i].v) + 1;
	}
}
bool cmp(node2 x, node2 y) {
	return x.z > y.z;
}

bool check() {
	for (int i = 0; i < n; i++) {
		b[i].z = a[i].v - mid * a[i].w;
		b[i].p = a[i].p;
	}
	sort(b, b + n, cmp);
	float cnt = 0;
	int i;
	for (i = 0; i < k; i++) {
		cnt += b[i].z;
		ans[i] = b[i].p;
	}
	if (cnt >= 0)
		return true;
	else
		return false;
}

void solve() {
	while (ed - op > 0.01) {
		mid = (ed + op) / 2;
		if (check())
			op = mid;
		else
			ed = mid;
	}
}

void output() {
	for (int i = 0; i < k; i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;
}

int main() {
	read();

	solve();

	output();

	return 0;
}