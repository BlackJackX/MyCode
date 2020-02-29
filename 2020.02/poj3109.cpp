/*
看懂了, 牛皮
扫描线+树状数组+坐标离散
https://blog.csdn.net/lolicon480/article/details/44183397
https://dafenghh.github.io/post/c38b5f65.html
*/
#include <cstdio>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <ctime>

#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
const ll maxn = 200010;
ll cnt = 200020;
ll bit[maxn];

void Maxi(int& a, int b) {
	if (b > a) a = b;
}

ll lowbit(ll x) {
	return x & -x;
}
ll sum(ll i) {
	ll res = 0;
	for (; i > 0; i -= lowbit(i)) res += bit[i];
	return res;
}
void add(ll i, ll x) {
	for (; i <= cnt; i += lowbit(i)) bit[i] += x;
}

struct P {
	int x, y;
	P(int x = 0, int y = 0) :x(x), y(y) {}
}a[maxn];

bool cmpx(const P& a, const P& b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}
bool cmpy(const P& a, const P& b) {
	if (a.y != b.y) return a.y < b.y;
	return a.x < b.x;
}

int mx[maxn];
bool sc[maxn]; // scope
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d", &a[i].x, &a[i].y);
	sort(a, a + n, cmpx);
	int val = 1;
	for (int i = 0; i < n; i++) {
		int temp = a[i].x;
		a[i].x = val;
		if (temp != a[i + 1].x) val++;
	}
	sort(a, a + n, cmpy);
	val = 1;
	for (int i = 0; i < n; i++) {
		int temp = a[i].y;
		a[i].y = val;
		if (temp != a[i + 1].y) val++;
	}
	for (int i = 0; i < n; i++)
		Maxi(mx[a[i].x], a[i].y);
	ll ans = 0;
	for (int i = 0; i < n - 1; i++) {
		int x = a[i].x, y = a[i].y, nx = a[i + 1].x, ny = a[i + 1].y;
		if (!sc[x] && y < mx[x]) {
			sc[x] = true;
			add(x, 1);
		}
		if (y == ny && nx > x + 1) {
			ans += sum(nx - 1) - sum(x);
		}
		if (sc[x] && y == mx[x]) {
			sc[x] = false;
			add(x, -1);
		}
	}
	ans += n;
	printf("%lld\n", ans);
}