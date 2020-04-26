/*
tm的看错题了, 我以为n是1e12, 原来d是1e12
*/
#include <cstdio>
#include <algorithm>

using namespace std;

int t, n;
long long d;
long long a[1005];

void read() {
    scanf("%d %lld", &n, &d);
    for(int i=0; i<n; i++)
        scanf("%lld", &a[i]);
}

bool check(int x) {
    for(int i=1; i<n; i++) {
        if(x%a[i] == 0)
            x = x/a[i];
        else
            x = x/a[i] + 1;
        x *= a[i];

        if(x > d)
            return false;
    }
    return true;
}

long long solve() {
    long long l = 1;
    long long r = d/a[0] + 1;
    while(true) {
        if(l == r-1)
            break;
        int mid = (l+r) / 2;
        if(check(mid*a[0]))
            l = mid;
        else
            r = mid;
    }
    return l * a[0];
}  

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &t);
    for(int ce=1; ce<=t; ce++) {
        read();
        printf("Case #%d: %lld\n", ce, solve());
    }
    return 0;
}