/*
调了一天....
自己的逻辑还是不太清楚,
多做题就好了,
最后还因为数组开小了wa一次, 当时真是万念俱灰
*/
/*
3
1 10 2
6
1 2 4 8 16 32
4
1 3 2 4
10
1 2 3 4 5 6 7 8 9 10
5
1 1 1 1 1
*/
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAX_N = 1e5 + 1000;
int n;
int a[MAX_N];

int pos(int x) {
    return upper_bound(a, a+n, x-1) - a;
}

bool check(int x) {
    int sump = 0;
    for(int i=0; i<n; i++) {
        int b = a[i]+x;
        int p = pos(b) - 1;

        sump += p - i;
    }
    int num = n*(n-1)/2;
    if(sump < (num+1)/2)
        return true;
    else
        return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    while(scanf("%d", &n) != EOF) {
        for(int i=0; i<n; i++)
            scanf("%d", &a[i]);
        sort(a, a+n);
        int l = 0, r = a[n-1]-a[0]+1;
        int mid = (l+r)/2;
        int num = n*(n-1)/2;
        while(r-l != 1) {
            if(check(mid))
                l = mid;
            else
                r = mid;
            mid = (l+r)/2;
        }
        printf("%d\n", l);
    }

    return 0;
}