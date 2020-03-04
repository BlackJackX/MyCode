/*
10点ac
成功, 调了一个bug就过了
*/
/*
10 11
1 2 3 4 5 6 7 8 9 10
Q 1 10
Q 2 4
Q 4 4
C 1 10 1
C 1 5 2
C 3 5 3
C 3 4 4
C 4 4 5
Q 1 10
Q 2 4
Q 4 4
*/
#include <iostream>
#include <algorithm>
#include <cstdio>

#define ll long long
using namespace std;

const int MAX_N = 1e5+10;
int n, q;
struct node {
    int l, r;
    ll incr, sum;
} st[MAX_N<<2];

void pushup(int v) {
    st[v].sum = st[v*2].sum + st[v*2+1].sum + st[v].incr*(st[v].r-st[v].l+1);
}

void build(int v, int a, int b) {
    st[v].l = a;
    st[v].r = b;
    int mid = (a+b)/2;
    if(a == b) {
        scanf("%lld", &st[v].sum);
        return ;
    }
    build(v*2, a, mid);
    build(v*2+1, mid+1, b);
    pushup(v);
}

void change(int v, int a, int b, ll c) {
    if(st[v].l == a && st[v].r == b) {
        st[v].incr += c;
        st[v].sum += c*(b-a+1);
        return;
    }
    int mid = (st[v].l + st[v].r)/2;
    if(b <= mid)
        change(v*2, a, b, c);
    else if(mid+1 <= a)
        change(v*2+1, a, b, c);
    else {
        change(v*2, a, mid, c);
        change(v*2+1, mid+1, b, c);
    }
    pushup(v);
}

void pushdown(int v) {
    if(st[v].incr != 0) {
        st[v*2].incr += st[v].incr;
        st[v*2].sum += st[v].incr * (st[v*2].r-st[v*2].l+1);
        st[v*2+1].incr += st[v].incr;
        st[v*2+1].sum += st[v].incr * (st[v*2+1].r-st[v*2+1].l+1);
        st[v].incr = 0;
    }
}

ll query(int v, int a, int b) {
    if(st[v].l == a && st[v].r == b)
        return st[v].sum;
    int mid = (st[v].l + st[v].r)/2;
    pushdown(v);
    if(b <= mid)
        return query(v*2, a, b);
    else if(mid+1 <= a)
        return query(v*2+1, a, b);
    else {
        ll ls = query(v*2, a, mid);
        ll rs = query(v*2+1, mid+1, b);
        return ls + rs;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &q);
    build(1, 1, n);
    while(q--) {
        char t;
        while((t = getchar()) && (t != 'Q' && t != 'C')) ;
        int a, b;
        ll c;
        if(t == 'C') {
            scanf("%d %d %lld", &a, &b, &c);
            change(1, a, b, c);
        }
        else {
            scanf("%d %d", &a, &b);
            ll res = query(1, a, b);
            printf("%lld\n", res);
        }
    }
    return 0;
}