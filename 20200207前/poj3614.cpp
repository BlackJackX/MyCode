/*
状态很差啊！！！
贪心的思路想错了
原来如此！！！！
greater是最小堆
改思路，一遍过！！！
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define C 2500+10
#define L 2500+10

using namespace std;

typedef pair<int, int> P;

int c, l;
P cow[C];
P ssn[L];
priority_queue<int,vector<int>, greater<int> > q;

int main() {
	cin >> c >> l;
	for (int i = 0; i < c; i++) {
		cin >> cow[i].first >> cow[i].second;
	}
	for (int i = 0; i < l; i++) {
		cin >> ssn[i].first >> ssn[i].second;
	}
	sort(cow, cow + c);
	sort(ssn, ssn + l);
	int i = 0, j = 0, cnt = 0;
	
	while (j < l) {
		int s = ssn[j].first;
		int n = ssn[j].second;
		for (; i < c && cow[i].first <= s; i++)
			q.push(cow[i].second);
		while (!q.empty() && n > 0) {
			int c = q.top();
			q.pop();
			if (c < s) continue;
			cnt++;
			n--;
		}
		ssn[j].second = n;
		j++;	
	}
	cout << cnt << endl;
	return 0;
}