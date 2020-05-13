/*
tle了
有更省的方法
用log控制精度
过啦,改成2e5
*/

#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_LEN = 2e5+100;

double lg[MAX_LEN];
int t, w, h, l, u, r, d;
float a[MAX_LEN], b[MAX_LEN];

double get_one_sqare_p(int x, int y) {
    double path_num_lg = lg[x+y-2] - (lg[x-1] + lg[y-1]);
    double one_path_p = -(x+y-2);
    double tmp = pow(2, one_path_p + path_num_lg);
    return tmp;
}

double solve() {
    if(r+d == w+h)
        return 0;

    double sum = 0;

    int s = l + d;
    for(int i=d+1, j=l-1; i<=h && j>=1; i++, j--) {
        if(i == h) {
            double tmp = 0;
            for(int k=1; k<=j; k++)
                tmp += get_one_sqare_p(h-1, k);
            sum += tmp / 2;
        }
        else
            sum += get_one_sqare_p(i, j);
    }
    s = r + u;  
    for(int i=u-1, j=r+1; i>=1 && j<=w; i--, j++) {
        if(j == w) {
            double tmp = 0;
            for(int k=1; k<=i; k++)
                tmp += get_one_sqare_p(k, w-1);
            sum += tmp / 2;
        }
        else 
            sum += get_one_sqare_p(i, j);
    }
    return sum;
}


int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &t);

    lg[0] = 0;
    for(int i=1; i<MAX_LEN; i++) 
        lg[i] = lg[i-1] + log2(i);
    
    for(int ce=1; ce<=t; ce++) {
        scanf("%d%d%d%d%d%d", &w, &h, &l, &u, &r, &d);
        double ans = solve();
        printf("Case #%d: %lf\n", ce, ans);
    }
    return 0;
}


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
