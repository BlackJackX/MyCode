#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

#define N 105

#pragma warning(disable:4996)
using namespace std;

int t, n;
char s1[105], s2[105], s[210];

void shuffle() {
	char ts[210];
	for (int i = 0, j = 0; i < n; i++, j += 2) {
		ts[j] = s1[i];
		ts[j + 1] = s2[i];
	}
	for (int i = 0; i < n; i++)
		s2[i] = ts[i];
	for (int i = n; i < n * 2; i++)
		s1[i-n] = ts[i];
}

char* mycat(char* s1, char* s2) {
	char ts[210];
	strcpy(ts, s1);
	strcat(ts, s2);
	cout << ts << endl;
	return ts;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> s1 >> s2 >> s;
		shuffle();
		while (strcmp(mycat(s1, s2), s) != 0) {
			shuffle();
		}
	}
	return 0;
}