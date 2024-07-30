#include <iostream>

using namespace std;

int ctr[20][10] = { 0 };
int main() {
	int N;
	cin >> N;
	int row = N;
	while (N--) {
		int max = 0;
		cin >> max;
		for (int i = 1; i <= max; i++) {
			for (int j = i; j != 0; j /= 10) {
				int tmp = j;
				ctr[N][tmp % 10]++;
			}
		}
	}

	for (int m = row - 1; m >= 0; m--) {
		for (int n = 0; n < 10; n++) {
			if (n < 9)
				cout << ctr[m][n] << " ";
			else
				cout << ctr[m][n];
		}
		if (m > 0) cout << endl; 
	}

	return 0;
}

