/*
中间还写了好几个bug
早就感觉int过不了, 20min
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;
int p, a;

bool isprime(ll x) {
    for(int i=2; i<sqrt(x); i++) {
        if(x % i == 0)
            return false;
    }
    return true;
}

bool check(ll p, ll a) {
    if(isprime(p))
       return false; 
    ll res = 1;
    ll base = a;
    ll pow = p;
    while(pow != 0) {
        if(pow & 1 == 1) 
            res *= base;
        res %= p;
        pow >>= 1; 
        base *= base;
        base %= p;        
    }
    if(res % p == a)
        return true;
    else
        return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    while(scanf("%lld%lld", &p, &a)!=EOF) {
        if(p+a == 0)
            break;
        if(check(p, a))
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}