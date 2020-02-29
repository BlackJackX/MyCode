/*
平方分割+二分, 没做出来, 抄的答案
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>

#pragma warning(disable:4996)
using namespace std;

const int MAXN = 2 * 1e5;
const int b = 1000;

int n, m, a[MAXN], num[MAXN], l, r, k;
vector<int> bucket[MAXN / b];

int cal(int l, int r, int x) //<=x[l,r]区间中<=x元素个数
{
	int tl = l, tr = r, ans = 0;
	while (tl < tr && tl % b) if (a[tl++] <= x) ++ans;//不完整部分，枚举
	while (tl < tr && tr % b) if (a[--tr] <= x) ++ans;

	while (tl < tr)//完整部分直接二分求
	{
		int bb = tl / b;
		ans += upper_bound(bucket[bb].begin(), bucket[bb].end(), x) - bucket[bb].begin();
		tl += b;
	}
	return ans;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
		bucket[i / b].push_back(a[i]);
		num[i] = a[i];
	}
	sort(num, num + n);
	for (int i = 0; i < n / b; ++i) sort(bucket[i].begin(), bucket[i].end());

	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d%d", &l, &r, &k);//好像现把全部数据一次性读入存下来在运算AC概率更大
		--l; --r;//题目数据下标从1开始，这个程序中从0开始
		int low = 0, high = n - 1;//二分的是有序数组num的下标，而不是答案的值
		int mid;
		while (low < high)//二分
		{
			mid = (high + low) / 2;
			int x = num[mid];
			if (cal(l, r + 1, x) < k) low = mid + 1;
			else high = mid;
		}
		printf("%d\n", num[low]);
	}

	return 0;
}