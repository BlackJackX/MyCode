/*
42min
又忘了long long
*/
#include <iostream>
#include <algorithm>

#define _int64 long long
#define N 200000+10
using namespace std;

int n;
_int64 cnt;
int a[N], tmp[N];

void mergesort(int op, int ed) {
	if (op >= ed-1) return;

	int mid = (op + ed) / 2;
	mergesort(op, mid);
	mergesort(mid, ed);
	int i = op, j = mid, k = 0;
	while (i != mid && j != ed) {
		if (a[i] <= a[j]) {
			tmp[k] = a[i];
			i++;
			k++;
		}
		else {
			tmp[k] = a[j];
			cnt += a + mid - upper_bound(a + i, a + mid, a[j] * 2);
			j++;
			k++;
			
		}
	}
	while (i != mid) {
		tmp[k] = a[i];
		i++;
		k++;
	}
	while (j != ed) {
		tmp[k] = a[j];
		j++;
		k++;
	}
	for (int i = op, j = 0; i < ed; i++, j++) {
		a[i] = tmp[j];
	}
}


int main() {
	while(cin >> n && n != 0) {
		cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		mergesort(0, n);
		cout << cnt << endl;
	}
	return 0;
}