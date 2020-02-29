/*
素数筛+快速幂
一点都不快
太不熟练了
54min
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

#define PNUM 40000
using namespace std;

long long p, a;

long long ppow(long long a, long long p) {
	long long base = a;
	long long res = 1;
	long long pp = p;
	while (pp != 0) {
		if (pp & 1) {
			res *= base;
			res %= p;

		}
		base *= base;
		base %= p;
		pp >>= 1;
	}
	return res;
}

bool primes[PNUM];

void find_prime() {
	memset(primes, true, sizeof(bool)*PNUM);
	for (int i = 2; i <= sqrt(PNUM); i++) {
		if (!primes[i])
			continue;
		for (int j = 2; j * i < PNUM; j++)
			primes[i * j] = false;
	}
}

bool is_prime(long long p) {
	for (int i = 2; i <= sqrt(p); i++) {
		if (!primes[i])
			continue;
		if (p % i == 0)
			return false;
	}
	return true;
}

int main() {
	find_prime();
	while (cin >> p >> a && p != 0 && a != 0) {
		if (is_prime(p)) {
			cout << "no" << endl;
			continue;
		}
		long long tmp = ppow(a, p);
		if (a == tmp % p)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}

	return 0;
}