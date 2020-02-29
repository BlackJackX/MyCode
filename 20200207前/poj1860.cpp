#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

#define N 105
#define M 305

#define INF 0x3f3f3f3f

using namespace std;

int n, t, s, m, edge_num = 0;
float val;

int head[N];
struct edge {
	int u, v, next;
	float r, c;
};
edge e[M];

void init() {
	memset(head, -1, sizeof(int) * N);
}

void add_edge(int u, int v, float r, float c) {
	int i = edge_num;
	e[i].u = u;
	e[i].v = v;
	e[i].r = r;
	e[i].c = c;
	e[i].next = head[u];
	head[u] = i;
	edge_num++;
}

bool bf(int s) {
	float price[N];
	for (int i = 0; i < n; i++)
		price[i] = 0;
	price[s] = val;	
	m = edge_num;
	for (int i = 1; i < n; i++) {
		bool flag = false;
		for (int j = 0; j < m; j++) {
			int u = e[j].u;
			int v = e[j].v;
			float r = e[j].r;
			float c = e[j].c;
			if (price[v] < (price[u] - c) * r) {
				price[v] = (price[u] - c) * r;
				flag = true;
			}
		}
		if (!flag)
			return true;
	}
	for (int j = 0; j < m; j++) {
		int u = e[j].u;
		int v = e[j].v;
		float r = e[j].r;
		float c = e[j].c;
		if (price[v] < (price[u] - c) * r) {
			price[v] = (price[u] - c) * r;
			return false;
		}
	}
	return true;
}



int main() {
	freopen("../f.in", "r", stdin);
	cin >> n >> t >> s >> val;
	s--;
	//init();
	while (t--) {
		int u, v;
		float r, c;
		cin >> u >> v;
		u--;
		v--;
		cin >> r >> c;
		add_edge(u, v, r, c);
		cin >> r >> c;
		add_edge(v, u, r, c);
	}
	if (bf(s))
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}