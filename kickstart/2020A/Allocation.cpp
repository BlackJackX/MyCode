#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 10;
int t, n, b;
int a[MAX_N];

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &t);
    for(int ce=1; ce<=t; ce++) {
        scanf("%d%d", &n, &b);
        for(int i=0; i<n; i++)
            scanf("%d", &a[i]);
        sort(a, a+n);
        int i = 0;
        while(i<n) {
            if(b < a[i])
                break;
            b -= a[i];
            i++;
        }

        printf("Case #%d: %d\n", ce,i);
    }
    return 0;
}