#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_N = 1e5+10;
int t, n, k;
int a[MAX_N], b[MAX_N];

bool check(int x) {
    int num = 0;
    for(int i=1; i<n; i++) {
        if(a[i] <= x)
            continue;
        num += (a[i]-1) / x;
        if(num > k)
            return false;
    }
    if(num > k)
        return false;
    else
        return true;
}

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &t);
    for(int ce=1; ce<=t; ce++) {
        scanf("%d%d", &n, &k);
        b[0] = 0;
        int itv = 0;
        for(int i=1; i<=n; i++) {
            scanf("%d", &b[i]);
            a[i-1] = b[i] - b[i-1]; 
            itv = max(itv, a[i-1]);
        }
        int l = 0, r = itv;
        int mid;
        while(true) {
            if(l == r-1)
                break;
            mid = (l+r) / 2;
            if(check(mid))
                r = mid;
            else
                l = mid;
        }
        printf("Case #%d: %d\n", ce, r);
    }

    return 0;
}