#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int t, n;
int a[105];

void read() {
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
}

int solve() {
    int cnt = 0;
    for(int i=1; i<n-1; i++) {
        if(a[i] > a[i-1] && a[i] > a[i+1])
            cnt++;
    }
    return cnt;
}

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &t);
    for(int ce=1; ce<=t; ce++) {
        read();
        printf("Case #%d: %d\n", ce, solve());
    }
    return 0;
}