/*
tm的看错题了, 我以为n是1e12, 原来d是1e12
long long 没注意...
这玩意多tm简单啊, 第一遍的思路
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


long long solve() {
    long long ans = d;
    for(int i=n-1; i>=0; i--)
        d = d / a[i] * a[i];
    return d;
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





// #include <cstdio>
// #include <algorithm>

// using namespace std;

// int t, n;
// long long d;
// long long a[1005];

// void read() {
//     scanf("%d %lld", &n, &d);
//     for(int i=0; i<n; i++)
//         scanf("%lld", &a[i]);
// }

// bool check(long long x) {
//     for(int i=0; i<n; i++) {
//         if(x%a[i] == 0)
//             x = x/a[i];
//         else
//             x = x/a[i] + 1;
//         x *= a[i];

//         if(x > d)
//             return false;
//     }
//     return true;
// }

// long long solve() {
//     long long l = 1;
//     long long r = d + 1;
//     while(true) {
//         if(l == r-1)
//             break;
//         int mid = (l+r) / 2;
//         if(check(mid))
//             l = mid;
//         else
//             r = mid;
//     }
//     return l;
// }  

// int main() {
//     freopen("input.txt", "r", stdin);
//     scanf("%d", &t);
//     for(int ce=1; ce<=t; ce++) {
//         read();
//         printf("Case #%d: %lld\n", ce, solve());
//     }
//     return 0;
// }