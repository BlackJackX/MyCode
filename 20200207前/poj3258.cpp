/*
仔细模拟，很容易过！！！
*/
#include <iostream>
#include <algorithm>

#define ll long long 
#define N 50000+10
using namespace std;

int n, m;
ll l;
ll d[N];

void read() {
	d[n + 1] = l;
	d[0] = 0;
	for (int i = 1; i <= n; i++)
		cin >> d[i];
}

bool check(int len) {
	ll l1 = d[1] - d[0];
	int num = 0;
	for (int i = 1; i <= n; i++) {
		if (l1 < len) {
			l1 += d[i + 1] - d[i];
			num++;
		}
		else
			l1 = d[i + 1] - d[i];
		if (num > m)
			break;
	}
	if (num > m)
		return false;
	else
		return true;
}

int main() {
	cin >> l;
	cin >> n >> m;
	read();
	sort(d, d + n + 2);
	if (check(l)) {
		cout << l << endl;
		return 0;
	}
	ll i = 1, j = l;
	while (true) {
		if (i == j - 1)
			break;
		ll k = (i + j) / 2;
		if (check(k))
			i = k;
		else
			j = k;
	}
	cout << i << endl;
	return 0;
}