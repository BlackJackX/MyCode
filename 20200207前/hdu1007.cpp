/*
重做！！！
平面最近点对
*/
#include <iostream>
#include <algorithm>
#include <cmath>

#define N 100000+10
#define P pair<float, float>

using namespace std;

int n;
P point[N];
int idx[N];

float dist(P x, P y) {
	return sqrt(pow(x.first - y.first, 2) + pow(x.second - y.second, 2));
}
bool cmp(int x, int y) {
	return point[x].second < point[y].second;
}

float mindist(int op, int ed) {
	if (op == ed) return 1e10;
	if (op == ed - 1) return dist(point[op], point[ed]);
	int mid = (op + ed) / 2;
	float tleft = mindist(op, mid);
	float tright = mindist(mid + 1, ed);
	float t = min(tleft, tright);
	int nop = op, ned = mid + 1;
	for (int i = op; i <= ed; i++) {
		if (point[mid].first - point[i].first >= t)
			nop = i;
		if (point[i].first - point[mid + 1].first < t)
			ned = i;
	}
	int k = 0;
	for (int i = op; i <= ed; i++) {
		if (abs(point[mid].first - point[i].first) <= t)
			idx[k++] = i;
	}
	sort(idx, idx + k, cmp);
	for (int i = 0; i < k; i++) {
		for (int j = i + 1; j < k && point[idx[j]].second - point[idx[i]].second < t; j++) {
			t = min(t, dist(point[idx[i]], point[idx[j]]));
		}
	}
	return t;
}

int main() {
	while (cin >> n && n != 0) {
		for (int i = 0; i < n; i++) {
			cin >> point[i].first >> point[i].second;
		}
		sort(point, point + n);
		printf("%.2f\n", mindist(0, n - 1) / 2);
	}
	return 0;
}