/*
怮潠等﹝﹝﹝﹝
*/
#include <iostream>
#include <algorithm>

#define _int64 long long 
#define INF 5000+100
using namespace std;

int n, s;

int main() {
	cin >> n >> s;
	int pc, c, y;
	_int64 sum = 0;
	pc = INF;
	while (n--) {
		cin >> c >> y;
		if (pc + s < c)
			c = pc + s;
		sum += c * y;
		pc = c;
	}
	cout << sum << endl;
	return 0;
}