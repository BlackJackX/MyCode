/*
树状数组
终于过了
3h+
要学会造数据!!!
*/
#include <iostream>
#include <algorithm>

#define MAX_N (20000+10)
#define ll long long

using namespace std;

typedef pair<ll, ll> P;		

int n;
P cow[MAX_N];

ll nbit[MAX_N];
ll sbit[MAX_N];

ll sum(ll* bit, ll p) {
	ll res = 0;
	while (p > 0) {
		res += bit[p];
		p -= p & (-p);
	}
	return res;
}

ll sum(ll* bit, ll a, ll b) {
	return sum(bit, b) - sum(bit, a);
}


void add(ll* bit, ll p, ll x) {
	while (p < MAX_N) {
		bit[p] += x;
		p += p & (-p);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> cow[i].first >> cow[i].second;

	sort(cow, cow + n);
	ll res = 0;

	for (int i = 0; i < n; i++) {
		ll ln = sum(nbit, 0, cow[i].second);
		ll rn = sum(nbit, cow[i].second, MAX_N-1);
		ll ls = sum(sbit, 0, cow[i].second);
		ll rs = sum(sbit, cow[i].second, MAX_N-1);
		
		res += cow[i].first * ((ln * cow[i].second - ls) + (rs - rn * cow[i].second));
		
		
		add(nbit, cow[i].second, 1);
		add(sbit, cow[i].second, cow[i].second);
	}

	cout << res << endl;
	
	return 0;
}