#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
#include <cstdio>

#pragma warning(disable:4996)

using namespace std;

int t, n, x, y;
char type;
priority_queue<int, vector<int>, less<int> > p;
priority_queue<int, vector<int>, greater<int> > q;

void ist(int x) {
	if (p.empty()) {
		p.push(x);
		return;
	}
	int pma = p.top();
	if (x <= pma) p.push(x);
	else q.push(x);
}

void qry() {
	printf("%d\n", p.top());
}

void dlt() {
	p.pop();
	return;
}

void cln() {
	int x;
	while (!(p.size() == q.size() || p.size() == q.size() + 1)) {
		if (p.size() < q.size()) {
			x = q.top();
			q.pop();
			p.push(x);
		}
		else {
			x = p.top();
			p.pop();
			q.push(x);
		}
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		while (!q.empty())
			q.pop();
		while (!p.empty())
			p.pop();
		while (n--) {
			//cin >> type;

			scanf("%c", &type);
			while (type <= 'A' || type >= 'Z')
				scanf("%c", &type);
			if (type == 'I') {
				scanf("%d", &x);
				ist(x);
				cln();
			}
			else if (type == 'Q')
				qry();
			else if (type == 'D') {
				dlt();
				cln();
			}
		}
	}

	return 0;
}