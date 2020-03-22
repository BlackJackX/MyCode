#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int t;
int n, k, p;
int v[55][55], w[55][55];
int dp[1550], tmpdp[1550];

void read() {
    scanf("%d%d%d", &n, &k, &p);
    for(int i=0; i<n; i++) {
        v[i][0] = 0;
        w[i][0] = 0;
        for(int j=1; j<=k; j++) {
            int tmp;
            scanf("%d", &tmp);
            v[i][j] = tmp + v[i][j-1];
            w[i][j] = 1 + w[i][j-1];
        }
    }
    memset(dp, 0, sizeof(dp));
}

void solve() {
    for(int i=0; i<n; i++) {
        for(int j=1; j<=p; j++) {
            for(int l=0; l<=k; l++) {
                int tmp = tmpdp[j];
                if(j>=w[i][l]) 
                    tmpdp[j] = max(dp[j], dp[j-w[i][l]]+v[i][l]);
                else
                    tmpdp[j] = dp[j];
                tmpdp[j] = max(tmpdp[j], tmp);
            }
        }
        for(int j=0; j<=p; j++) {
            dp[j] = tmpdp[j];
            tmpdp[j] = 0;
        }
    }

}


int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &t);
    for(int ce=1; ce<=t; ce++) {
        read();
        solve();
        printf("Case #%d: %d\n", ce, dp[p]);
    }

    return 0;
}