/*
tmd, 什么奇怪的题
2
0 0
0 1
答案竟然是1!!!
一条线也有面积???
要不我早做出来了
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int MAX_N = 17;
const int INF = 0x3f3f3f3f;
int n, k;
int px[MAX_N], py[MAX_N];
struct sqare {
    int pnt, area;
    int xi, yi, xj, yj;
} sq[MAX_N*(MAX_N-1)/2];
int dp[1<<MAX_N];

void read() {
    for(int i=0; i<n; i++) 
        scanf("%d%d", &px[i], &py[i]);
    k = 0;    
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int lx = px[i]-px[j]==0?1:abs(px[i]-px[j]);
            int ly = py[i]-py[j]==0?1:abs(py[i]-py[j]);
            sq[k].area = lx*ly;
            
            sq[k].xi = px[i]; sq[k].xj = px[j];
            sq[k].yi = py[i]; sq[k].yj = py[j];
            sq[k].pnt = 0;
            for(int l=0; l<n; l++) {
                if(px[l] <= px[i] && px[l] >= px[j]) ;
                else if(px[l] <= px[j] && px[l] >= px[i]) ;
                else continue;
                if(py[l] <= py[i] && py[l] >= py[j]) ;
                else if(py[l] <= py[j] && py[l] >= py[i]) ;
                else continue;               
                sq[k].pnt |= 1<<l;
            }
            k++;
        }
    }
}

void solve() {
    memset(dp, INF, sizeof(int)*(1<<n));
    dp[0] = 0;
    for(int i=0; i<k; i++) {
        for(int j=0; j<(1<<n); j++) {
            dp[j|(sq[i].pnt)] = min(dp[j|(sq[i].pnt)], dp[j]+sq[i].area);
        }
    }

    printf("%d\n", dp[(1<<n)-1]);
}


int main() {
    freopen("input.txt", "r", stdin);
    while(scanf("%d", &n)==1 && n!=0) {
        read();
        solve();
    }

    return 0;
}

