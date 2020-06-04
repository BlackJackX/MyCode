/*
没有那么失败
只不过错了一个范围而已
*/
#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 2e5+10;

int t, n, k;
int a[MAX];


int solve() {
    int x = k, i = 0, ans = 0;
    while(i < n) {
        if(a[i] == x) {
            i++;
            x--;
        }
        else {
            x = k;
            if(a[i] != x)
                i++;
        }
        
        if(x == 0)
            ans++;
    }
    return ans;
}


int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &t);
    for(int ce=1; ce<=t; ce++) {
        scanf("%d%d", &n, &k);
        for(int i=0; i<n; i++)
            scanf("%d", &a[i]);
        int ans = solve();
        printf("Case #%d: %d\n", ce, ans);
    }
    return 0;
}