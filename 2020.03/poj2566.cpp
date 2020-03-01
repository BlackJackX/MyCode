/*
上来就犯二, 不会数数看样例....
还是没思路, 看了看题解
找到好几个bug, 但还是没过....
终于过了!!!
0x3f3f3f3f运算后可能会溢出, 不是最大值
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

#define INF 0x3f3f3f3f
using namespace std;

const int MAX_N = 100000+10;
int n, k;
int a[MAX_N];
typedef pair<int, int> P;
P sums[MAX_N];
int l, r, res;

void read() {
    a[0] = 0;
    sums[0] = P(0,0);
    for(int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
        sums[i] = P(sums[i-1].first+a[i], i);
    }
    sort(sums, sums+n+1);
}

void search() {
    int t;
    scanf("%d", &t);
    int l1 = 0, r1 = 1, res1;
    int minx = INF;
    while(l <= r && r1 <= n) {
        res1 = sums[r1].first - sums[l1].first;
        if(abs(res1-t) < minx) {
            minx = abs(res1-t);
            res = res1;
            l = l1;
            r = r1;
        }      
        if(res1 < t)
            r1++;
        else if(res1 > t)
            l1++;
        else
            return;
        if(l1 == r1)
            r1++;
    }
}

void output() {
    int ridx = max(sums[l].second, sums[r].second);
    int lidx = min(sums[l].second, sums[r].second);
    cout << res << ' ' << lidx+1 << ' ' << ridx << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    while(scanf("%d %d", &n, &k) != EOF && (n!=0 || k!=0)) {
        read();
        while(k--) {
            search();
            output();
        }
    }
    return 0;
}