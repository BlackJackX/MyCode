/*
很简单的gcd，一次过
49min
*/
#include <iostream>
#include <algorithm>
#include <cstring>

#define INF 0x3f3f3f3f
using namespace std;

char s[100];
int a, b;
int l, n, m;
int nom, denom;
int minnom, mindenom;

void divide() {
	char* p = s + 2;
	a = 0;
	b = 0;
	for (int i = 0; i < n; i++) {
		a *= 10;
		a += p[i] - '0';
	}
	for (int i = n; i < l; i++) {
		b *= 10;
		b += p[i] - '0';
	}
}
void merge() {
	int mnine = 0, powern = 1;
	for (int i = 0; i < m; i++) {
		mnine *= 10;
		mnine += 9;
	}
	for (int i = 0; i < n; i++)
		powern *= 10;
	nom = a * mnine + b;
	denom = powern * mnine;
}

int gcd(int x, int y) {
	if (y == 0)
		return x;
	return gcd(y, x % y);
}

void reduct() {
	int g = gcd(nom, denom);
	nom /= g;
	denom /= g;
}

int main() {
	while (cin >> s && strlen(s) != 1) {
		l = strlen(s) - 3 - 2;
		mindenom = INF;
		minnom = INF;
		for (int i = 0; i <= l - 1; i++) {
			n = i;
			m = l - n;
			divide();
			merge();
			reduct();
			if (mindenom >= denom) {
				mindenom = denom;
				minnom = nom;
			}
		}
		cout << minnom << '/' << mindenom << endl;
	}
	return 0;
}