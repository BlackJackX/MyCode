/*
线段树优化dp, 很快就写好了,
但是由于对线段树掌握不熟练,
query写错了, tle
*/
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX_N = 50000+10;
const int ST_SIZE = MAX_N << 2;

struct node {
    int l, r, min;
} st[ST_SIZE];

int n, m;

void build(int v, int a, int b) {
    st[v].l = a;
    st[v].r = b;
    if(a == b) {
        st[v].min = INF;
        return ;
    }
    int mid = (a+b)/2;
    build(v*2, a, mid);
    build(v*2+1, mid+1, b);
    st[v].min = min(st[v*2].min, st[v*2+1].min);
}

void update(int v, int p, int x) {
    if(st[v].l == st[v].r && st[v].r == p) {
        st[v].min = x;
        return ;
    }
    int mid = (st[v].l + st[v].r) /2;
    if(p <= mid) 
        update(v*2, p, x);
    else if(mid+1 <= p)
        update(v*2+1, p, x);
    st[v].min = min(st[v*2].min, st[v*2+1].min);
}

int query(int v, int a, int b) {
    if(st[v].l == a && st[v].r == b) // 这句忘了
        return st[v].min;
    if(st[v].l == st[v].r)
        return st[v].min;
    int mid = (st[v].l + st[v].r) / 2;
    if(b <= mid) 
        return query(v*2, a, b);
    else if(mid+1 <= a)
        return query(v*2+1, a, b);
    else
        return min(query(v*2, a, mid), query(v*2+1, mid+1, b));
}

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    build(1, 1, n);
    update(1, 1, 0);
    int s, t;
    while(m--) {
        scanf("%d %d", &s, &t);
        update(1, t, min(query(1, t, t), query(1, s, t)+1));
    }
    printf("%d", query(1, n, n));
    return 0;
}


