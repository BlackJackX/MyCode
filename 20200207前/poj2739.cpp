/*
终于过了一道尺取!!!!
30min
*/
#include <iostream>
#include <algorithm>
#include <cmath>

#define N 10000
using namespace std;

int primes[N];
int pnum = 0;

void findprime() {
	pnum = 1;
	primes[0] = 2;
	for (int i = 3; i < N; i++) {
		bool flag = true;
		for (int j = 0; j < pnum; j++) {
			if (i % primes[j] != 0)
				continue;
			flag = false;
		}
		if (flag) {
			primes[pnum] = i;
			pnum++;
		}
	}
}

int solve(int x) {
	int op = 0, ed = 0, sum = 2;
	int cnt = 0;
	while (op < pnum && ed < pnum) {
		if (primes[ed] > x) break;
		if (sum < x) {
			ed++;
			sum += primes[ed];
		}
		else if (sum > x) {
			sum -= primes[op];
			op++;
		}
		else {
			cnt++;
			ed++;
			sum += primes[ed];
		}

	}
	return cnt;
}

int main() {
	findprime();
	int x;
	while (cin >> x && x != 0) {
		cout << solve(x) << endl;
	}
	return 0;
}