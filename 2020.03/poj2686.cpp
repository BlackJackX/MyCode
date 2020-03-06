/*
挺简单的, 好像理解dp了
float的inf也可以置为0x3f3f3f3f
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_M = 31;
const int MAX_N = 12;
const int INF = 0x3f3f3f3f;
const float FINF = 0x3f3f3f3f;

int n, m, p, a, b;
int gh[MAX_M][MAX_M];
float tk[MAX_N];
float dp[1<<MAX_N][MAX_M];

void read() {
    for(int i=0; i<MAX_M; i++)
        for(int j=0; j<MAX_M; j++)
            gh[i][j] = FINF;
    for(int i=0; i<n; i++)
        scanf("%f", &tk[i]);
    for(int i=0; i<p; i++) {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        gh[u][v] = gh[v][u] = d;
    }
}

void solve() {

    for(int j=0; j<(1<<MAX_N); j++) 
        for(int k=0; k<MAX_M; k++)
            dp[j][k] = FINF;

    dp[(1<<n)-1][a] = 0;
    float res = FINF;

    for(int T=(1<<n)-2; T>=0; T--) {
        for(int i=0; i<n; i++) {
            if((T>>i) & 1)
                continue;
            for(int v=1; v<=m; v++) {
                for(int u=1; u<=m; u++) {
                    if(gh[v][u]-FINF < 0.001 && gh[v][u]-FINF > -0.001)
                        continue;
                    dp[T][v] = min(dp[T][v], dp[T|1<<i][u]+gh[u][v]/tk[i]);
                }
            }
        }
    }
    for(int T=(1<<n)-2; T>=0; T--) 
        res = min(res, dp[T][b]);
    
    if(res-FINF < 0.001 && res-FINF > -0.001)
        printf("Impossible\n");
    else
        printf("%f\n", res);
}

int main() {
    freopen("input.txt", "r", stdin);
    while(scanf("%d%d%d%d%d", &n, &m, &p, &a, &b)==5) {
        if((n|m|p|a|b) == 0)
            break;
        read();
        solve();
    }

    return 0;
}