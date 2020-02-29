/*
智障数组开小了!!!!
1h+
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

#pragma warning(disable:4996)
#define MAX_N (50000+100)
#define ST_SIZE (MAX_N<<2)
#define INF 0x3f3f3f3f
using namespace std;

int minst[ST_SIZE], maxst[ST_SIZE];
int H[MAX_N];

int n, q;
int k;

void buildmax(int v, int l, int r) {
	if (l == r) {
		maxst[v] = H[k];
		k++;
		return;
	}
	int m = (l + r) / 2;
	buildmax(v * 2, l, m);
	buildmax(v * 2 + 1, m + 1, r);
	
	maxst[v] = max(maxst[v * 2], maxst[v * 2 + 1]);
}

void buildmin(int v, int l, int r) {
	if (l == r) {
		minst[v] = H[k];
		k++;
		return;
	}
	int m = (l + r) / 2;
	buildmin(v * 2, l, m);
	buildmin(v * 2 + 1, m + 1, r);

	minst[v] = min(minst[v * 2], minst[v * 2 + 1]);
}

int querymax(int v, int l, int r, int a, int b) {
	if (r < a || l > b)
		return 0;
	if (a <= l && r <= b)
		return maxst[v];
	int m = (l + r) / 2;

	return max(querymax(v * 2, l, m, a, b), querymax(v * 2 + 1, m + 1, r, a, b));
}

int querymin(int v, int l, int r, int a, int b) {
	if (r < a || l > b)
		return INF;
	if (a <= l && r <= b)
		return minst[v];
	int m = (l + r) / 2;

	return min(querymin(v * 2, l, m, a, b), querymin(v * 2 + 1, m + 1, r, a, b));
}


int main() {
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%d", &H[i]);
	k = 0;
	memset(maxst, 0, sizeof(int) * ST_SIZE);
	buildmax(1, 1, n);
	k = 0;
	memset(minst, INF, sizeof(int) * ST_SIZE);
	buildmin(1, 1, n);

	while (q--) {
		int a, b;
		scanf("%d %d", &a, &b);
		int maxh = querymax(1, 1, n, a, b);
		int minh = querymin(1, 1, n, a, b);
		printf("%d\n", maxh - minh);
	}

	return 0;
}

/*
int querymax(int v, int l, int r, int a, int b) {
	if (l == a && r == b)
		return maxst[v];
	int m = (l + r) / 2;
	if (b <= m)
		return querymax(v * 2, l, m, a, b);
	else if (m + 1 <= a)
		return querymax(v * 2 + 1, m + 1, r, a, b);

	return max(querymax(v * 2, l, m, a, m), querymax(v * 2 + 1, m + 1, r, m + 1, b));
}

int querymin(int v, int l, int r, int a, int b) {
	if (l == a && r == b)
		return minst[v];
	int m = (l + r) / 2;
	if (b <= m)
		return querymin(v * 2, l, m, a, b);
	else if (m + 1 <= a)
		return querymin(v * 2 + 1, m + 1, r, a, b);

	return min(querymin(v * 2, l, m, a, m), querymin(v * 2 + 1, m + 1, r, m + 1, b));
}

*/