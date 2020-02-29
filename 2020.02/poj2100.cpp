/*
long long 类型!!!
不要偷懒, 该改就改
看清是否是多组数据
49min
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

#pragma warning(disable:4996)
using namespace std;

long long n;
long long op = 1, ed = 1;

typedef pair<int, int> P;
P a[1010];
int num = 0;

int main() {
	while (~scanf("%lld", &n)) {
		op = ed = 1;
		num = 0;
		long long cnt = 1;
		while (ed <= sqrt(n)) {
			if (cnt < n) {
				ed += 1;
				cnt += ed * ed;

			}
			else if (cnt > n) {
				cnt -= op * op;
				op += 1;
			}
			else {
				a[num].first = op;
				a[num].second = ed;
				num++;
				ed += 1;
				cnt += ed * ed;
			}
		}
		printf("%d\n", num);
		for (int i = 0; i < num; i++) {
			op = a[i].first;
			ed = a[i].second;
			printf("%d ", ed - op + 1);
			for (int i = op; i <= ed; i++)
				printf("%d ", i);
			printf("\n");
		}
	}

	return 0;
}