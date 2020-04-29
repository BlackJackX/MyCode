/*
想错了, 还想搞个在线算法, 有穷自动机...以后再说吧
终于过了...
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll MOD = 1e9;

int t;
string s;

pll solve(string s, ll l, ll r) {
    pll ans = {0, 0};

    for(ll i=l; i<r; i++) {
        ll mul = 0;
        if(s[i]<='9' && s[i]>='0') {
            int cnt = 0; 
            int j, k;
            j = i;  
            while(s[j]<='9' && s[j]>='0') {
                mul *= 10;
                mul += s[j] - '0';                    
                j++;
            }
            k = j;
            while(true) {
                if(s[k] == '(') 
                    cnt++;
                else if(s[k] == ')')
                    cnt--;
                if(cnt == 0)
                    break;
                k++;
            }
            j++;
            pll tmp = solve(s, j, k);
            ans.first += mul * tmp.first;
            ans.second += mul * tmp.second;
            i = k;
        }
        else if(s[i] == 'N')
            ans.second -= 1;
        else if(s[i] == 'S')
            ans.second += 1;
        else if(s[i] == 'W')
            ans.first -= 1;
        else if(s[i] == 'E')
            ans.first += 1;

        ans.first += MOD;
        ans.second += MOD;
        ans.first %= MOD;
        ans.second %= MOD;
    }
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &t);
    for(int ce=1; ce<=t; ce++) {
        cin >> s;
        pll ans = solve(s, 0, s.length());
        ans.first += 1;
        ans.second += 1;   
        printf("Case #%d: %lld %lld\n", ce, ans.first, ans.second);
    }
    return 0;
}