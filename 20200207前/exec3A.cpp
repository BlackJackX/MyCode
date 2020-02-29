/*
15min
*/
#include <iostream>
#include <algorithm>

#define N 20000+10
using namespace std;

int n;
long long num;
int arr[N], tmp[N];

void read() {
	num = 0;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void mergesort(int op, int ed) {
	if (op == ed || op == ed - 1)
		return;
	int mi = (op + ed) / 2;
	mergesort(op, mi);
	mergesort(mi, ed);
	int i = op, j = mi, k = 0;
	while (i != mi && j != ed) {
		if (arr[i] <= arr[j]) {
			tmp[k] = arr[i];
			i++;
			k++;
		}
		else {
			tmp[k] = arr[j];
			num += (mi - i);
			j++;
			k++;
		}
	}
	while (i != mi) {
		tmp[k] = arr[i];
		i++;
		k++;

	}
	while (j != ed) {
		tmp[k] = arr[j];
		j++;
		k++;
	}
	for (int i = op, j = 0; i < ed; i++, j++)
		arr[i] = tmp[j];
}

int main() {
	while (cin >> n && n != 0) {
		read();
		mergesort(0, n);
		cout << num << endl;
	}
	return 0;
}