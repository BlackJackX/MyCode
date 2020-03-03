/*
线段树或树状数组只是用来记录这个区间有多少被取走了
终于过了!!!
一开始的思路就有问题, 排序反了
幸好比较好改
*/

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAX_N = 50000+1000;

int n;
int maxn;

struct node {
    int a, b, c;
} itv[MAX_N];

bool cmp(node x, node y) {
    return x.b < y.b;
}

int bit[MAX_N];
bool visit[MAX_N];

void add(int i, int x) {
    while(i < MAX_N) {
        bit[i] += x;
        i += i & (-i);
    }
}

int sum(int i) {
    int res = 0;
    while(i != 0) {
        res += bit[i];
        i -= i & (-i);
    }
    return res;
}

int query(int a, int b) {
    return sum(b) - sum(a-1);
}


int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d %d %d", &itv[i].a, &itv[i].b, &itv[i].c);
        maxn = max(maxn, itv[i].b);
    }
    
    sort(itv, itv+n, cmp);

    for(int i=0; i<n; i++) {
        int num = query(itv[i].a, itv[i].b);
        int need = itv[i].c - num;
        for(int j=itv[i].b, k=0; k<need; j--) {
            if(visit[j])
                continue;
            visit[j] = true;
            add(j, 1);
            k++;
        }
    }

    printf("%d\n", sum(maxn));
    return 0;
}