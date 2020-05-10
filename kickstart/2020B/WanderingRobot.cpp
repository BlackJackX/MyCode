/*
tle了
有更省的方法, 明天写

*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_LEN = 1e2+10;

int t, w, h, l, u, r, d;
float a[MAX_LEN], b[MAX_LEN];

// TLE
// float solve() {
//     a[1] = 1;
//     for(int i=2; i<=w; i++)
//         a[i] = 0;
//     for(int i=1; i<=h; i++) {
//         if(i == 1) b[0] = 1;
//         else b[0] = 0;
//         if(i == h) {
//             for(int j=1; j<=w; j++) {
//                 if(u<=i && i<=d && l<=j && j<=r)
//                     b[j] = 0;
//                 else {
//                     if(j == w)
//                         b[j] = b[j-1] + a[j];
//                     else
//                         b[j] = b[j-1] + a[j]/2;
//                 }
//             }
//         }
//         else {
//             for(int j=1; j<=w; j++) {
//                 if(u<=i && i<=d && l<=j && j<=r)
//                     b[j] = 0;
//                 else {
//                     if(j == w)
//                         b[j] = b[j-1]/2 + a[j];
//                     else
//                         b[j] = b[j-1]/2 + a[j]/2;
//                 }
//             }
//         }
//         for(int i=0; i<=w; i++)
//             a[i] = b[i];
//     }
//     return a[w];
// }

float solve() {
    if(u == 0)

}


int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &t);
    for(int ce=1; ce<=t; ce++) {
        scanf("%d%d%d%d%d%d", &w, &h, &l, &u, &r, &d);
        float ans = solve();
        printf("Case #%d: %f\n", ce, ans);
    }
    return 0;
}