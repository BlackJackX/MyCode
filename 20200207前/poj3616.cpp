/*
真是英语垃圾，明明是挤奶后休息，我理解成了挤奶前准备！！！
而且忘记了判断最后截止时间
50min---
*/

#include <iostream>
#include <algorithm>
#include <cmath>

#define INF 0x3f3f3f3f
#define M 1000+10

using namespace std;

int n, m, r;
struct node {
	int st, ed, ef;
	bool operator <(const node x) const {
		return x.st > st;
	}
};
node itv[M];
int f[M];


int main() {
	cin >> n >> m >> r;
	for (int i = 1; i <= m; i++) {
		cin >> itv[i].st >> itv[i].ed >> itv[i].ef;
		itv[i].ed += r;
	}
	itv[0].st = itv[0].ed = itv[0].ef = 0;
	sort(itv + 1, itv + m + 1);
	for (int i = 1; i <= m; i++) {
		if (itv[i].ed - r > n)
			continue;
		for (int j = 0; j < i; j++) {
			if (itv[j].ed > itv[i].st)
				continue;
			f[i] = max(f[i], f[j] + itv[i].ef);
		}
	}
	int ma = 0;
	for (int i = 0; i <= m; i++)
		ma = max(ma, f[i]);
	cout << ma << endl;
	return 0;
}