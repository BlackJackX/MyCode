/*
没做出来, 稍后做
线段树
计算几何, 失败, 一天没做出来!!!!
重做
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

#define maxn 10010
#define lson i*2,l,m
#define rson i*2+1,m+1,r
#define PI acos(-1.0)

int d[maxn * 4], degree[maxn];
double x[maxn * 4], y[maxn * 4];

void cal(int i, int de)//计算旋转后的向量 
{
	double rad = PI * de / 180.0;
	double nx = x[i] * cos(rad) - y[i] * sin(rad);
	double ny = x[i] * sin(rad) + y[i] * cos(rad);
	x[i] = nx;
	y[i] = ny;
}

void PushUp(int i)//更新父区间 
{
	x[i] = x[i * 2] + x[i * 2 + 1];
	y[i] = y[i * 2] + y[i * 2 + 1];
}

void PushDown(int i)//更新子区间 
{
	if (d[i])
	{
		d[i * 2] += d[i];//记录转动的角度 
		d[i * 2 + 1] += d[i];
		cal(i * 2, d[i]);
		cal(i * 2 + 1, d[i]);
		d[i] = 0;//更新完子区间后，父区间转动角度还原 
	}
}

void build(int i, int l, int r)
{
	d[i] = 0;
	if (l == r)
	{
		x[i] = 0;
		scanf("%lf", &y[i]);
		return;
	}
	int m = (l + r) / 2;
	build(lson);
	build(rson);
	PushUp(i);
}

void update(int ql, int rad, int i, int l, int r)
{
	if (ql <= l)
	{
		cal(i, rad);
		d[i] += rad;//记录下当前区间转动的角度，然后也将子区间所表示的线段转动同样的角度 
		return;
	}
	PushDown(i);
	int m = (l + r) / 2;
	if (ql <= m)
		update(ql, rad, lson);
	update(ql, rad, rson);
	PushUp(i);
}

int main()
{
	int n, m, i, sign = 0;
	int ql, rad;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		if (sign)
			printf("\n");
		sign = 1;
		build(1, 1, n);
		for (i = 1; i < n; ++i)
			degree[i] = 180;//每两个相邻线段之间的初始角度都是180度 
		while (m--)
		{
			scanf("%d%d", &ql, &rad);
			update(ql + 1, rad - degree[ql], 1, 1, n);
			degree[ql] = rad;
			printf("%.2lf %.2lf\n", fabs(x[1]) < 1e-8 ? 0 : x[1], fabs(y[1]) < 1e-8 ? 0 : y[1]);
		}
	}
	return 0;
}