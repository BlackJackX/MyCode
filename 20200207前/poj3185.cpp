/*
反转问题
15min
*/
#include <iostream>
#include <algorithm>

using namespace std;

int bowls[20];
int a[20];

int main() {
	for (int i = 0; i < 20; i++)
		cin >> bowls[i];
	for (int i = 0; i < 20; i++)
		a[i] = bowls[i];
	int na = 0;
	for (int i = 0; i < 19; i++) {
		if (a[i] != 1) continue;
		a[i] = !a[i];
		a[i + 1] = !a[i+1];
		a[i + 2] = !a[i + 2];
		na++;
	}
	if (a[19] == 1) na = 0x3f3f3f3f;
	int nb = 0;
	reverse(bowls, bowls + 20);
	for (int i = 0; i < 19; i++) {
		if (bowls[i] != 1) continue;
		bowls[i] = !bowls[i];
		bowls[i + 1] = !bowls[i + 1];
		bowls[i + 2] = !bowls[i + 2];
		nb++;
	}
	if (bowls[19] == 1) nb = 0x3f3f3f3f;
	cout << min(na, nb) << endl;

	return 0;
}