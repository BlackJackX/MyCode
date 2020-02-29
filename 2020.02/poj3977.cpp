/*
没做完
*/
#include <iostream>
#include <algorithm>

#define SNUM (1<<20)
#define N 40
using namespace std;

struct node {
	long long v = 0;
	int num = 0;
	int mi = N;
	bool operator < (const node x) const {
		if (v < x.v)
			return true;
		else if (v > x.v)
			return false;
		else
			return mi < x.mi;
	}
	bool operator == (const node x) const {
		if (v == x.v)
			return true;
		else
			return false;
	}
};
node s[SNUM];
node mask(long long* a, int x) {
	node tmp;
	for (int i = 0; i < n; i++) {
		tmp.v += a[i] * ((x >> i) & 1);
		tmp.mi = min(i, tmp.mi);
		tmp.num++;
	}
	return tmp;
}

long long a[N];
int n, m, k;

void read() {
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
}

void divide() {
	if (n <= 20)
		m = 0;
	else
		m = n - 20;
	for (int i = (1 << m), k = 0; i < (1 << n); i++, k++)
		s[k] = mask(a, i);
	sort(s, s + k);
	k = unique(s, s + k) - s;
}


int main() {

	while (cin >> n && n != 0) {
		read();

		//solve();

		//output();
	}

	return 0;
}