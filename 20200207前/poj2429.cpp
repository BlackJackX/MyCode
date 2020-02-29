/*
没做出来
用特殊的整数分解法
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

#pragma warning(disable:4996)
#define ll  long long 
using namespace std;

ll a, b, g, l, ma;

int gcd(ll x, ll y) {
	if (y == 0)
		return x;
	return gcd(y, x % y);
}
void prime_factor(ll n) {
	for (ll i = 1; i * i < n; i++) {
		if (n % i == 0) {
			ll ta = i;
			ll tb = n / i;
			if (ta + tb < a + b) {
				a = ta;
				b = tb;
			}
		}
	}
}

int main() {
	while (~scanf("%lld %lld", &g, &l)) {
		a = (ll)1 << 31; b = 0;
		ll t = l / g;
		prime_factor(t);
		printf("%lld %lld\n", a * g, b * g);
	}
	return 0;
}