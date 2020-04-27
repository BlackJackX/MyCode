#include <cstdio>
#include <algorithm>

using namespace std;

int t;

int f() {
    char c;
    c = getchar();
    int ans = 0;
    int sn = 0;
    int sx = 1, sy = 1;
    while(c=='N' || c=='S' || c=='E' || c=='W') {
        if(c == 'N')
            sx -= 1;
        else if(c == 'S')
            sx += 1;
        else if(c == 'E')
            sy -= 1;
        else if(c == 'W')
            sy += 1;
        c = getchar();
    }
    while(c<='9' && c>='0') {
        sn *= 10;
        sn += c-'0';
        c = getchar();
    }
    if(c == '(')
        ans += f();
    else
        return sn * ans;
}


int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &t);
    getchar();
    for(int ce=1; ce<=t; ce++) {
        int ans = f();
        printf("Case #%d: %d\n", ce, ans);
    }
    return 0;
}