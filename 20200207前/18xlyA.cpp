/*
30min
竟然把%和/弄反了！！！
*/

#include <iostream>
#include <algorithm>

using namespace std;

int y_1, m1, d1, y_2, m2, d2;
int mons[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

int days(int y, int m, int d) {
	int day = 0;
	day += (y - 1) * 365 + (y - 1) / 4 + (y - 1) / 400 - (y - 1) / 100;
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
		mons[2] = 29;
	for (int i = 1; i < m; i++) {
		day += mons[i];
	}
	day += d - 1;
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
		mons[2] = 28;
	return day;
}

int main() {
	cin >> y_1 >> m1 >> d1;
	cin >> y_2 >> m2 >> d2;
	cout << days(y_2, m2, d2) - days(y_1, m1, d1) << endl;
	return 0;
}