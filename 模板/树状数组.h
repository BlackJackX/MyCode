#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAX_N = 50000+1000;


int maxn;

int bit[MAX_N];

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

