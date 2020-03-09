/*
坑货swap
swap数组是把值全换
要用堆, 才能换指针
pre和cur可以只用一个数组, 
然后倒序生成
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_M = 21;
const int MAX_N = 25;

int *pre, *cur;
int cow[MAX_N][MAX_M+5];
int m, n;


int main() {
    pre = (int*)malloc(sizeof(int)*(1<<MAX_M));
    cur = (int*)malloc(sizeof(int)*(1<<MAX_M));

    freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++) {
        int p;
        scanf("%d", &cow[i][0]);
        int c;
        for(int j=1; j<=cow[i][0]; j++) {
            scanf("%d", &cow[i][j]);
            cow[i][j]--;
        }

    }
    pre[0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<(1<<m); j++) {
            if(pre[j] != 0) {
                for(int k=1; k<=cow[i][0]; k++) {
                    if(((j>>cow[i][k]) & 1) == 0)
                        cur[j+(1<<cow[i][k])] += pre[j];
                }
            }
            pre[j] = 0;
        }
        int *tmp = pre;
        pre = cur;
        cur = tmp;
        //swap(pre, cur);
    }
    int res = 0;
    for(int i=0; i<(1<<m); i++) {
        res += pre[i];
    }
    printf("%d\n", res);
    free(cur);
    free(pre);
    return 0;
}