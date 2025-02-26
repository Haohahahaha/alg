/* LeetCode Question No.59
 *
 * Given a positive integer n, generate an `n x n` matrix filled with elements
 * from 1 to n2 in spiral order.
 */

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Solution {
public:
	void getSpiralMatrix(int n) {
		
		vector<vector<int>> res(n, vector<int>(n, 0));

		int loop = n / 2;

		int startx = 0;
		int starty = 0;
		int offset = 1;
		int mid = n / 2;
		
		
		int count = 1;
		int i = 0, j = 0;

		while (loop--) {
			i = startx;
			j = starty;

			for (j = starty; j < starty + n - offset; j++) {
				res[i][j] = count++;
			}

			for (i = startx; i < startx + n - offset; i++) {
				res[i][j] = count++;
			}

			for (; j > starty; j--) {
				res[i][j] = count++;
			}

			for (; i > startx; i--) {
				res[i][j] = count++;
			}
		
			startx++;
			starty++;

			offset += 2;
		}
		if (n % 2) {
			res[mid][mid] = count;
		}
		
		printMatrix(res, n);
	}	

	void printMatrix(vector<vector<int>>& res, int n) {
		int mid = n / 2;
		int wordslen = 1;
		int nsqr = n * n;
		cout << "start print" <<endl;
		while (nsqr > 0) {
			wordslen++;
			// cout << wordslen << endl;
			nsqr /= 10;
		}
		int i = 0, j = 0;
		for (; i < n; i++) {
			for (; j < n; j++) {
				if (n % 2) {
					if (i != mid || j != mid) {
						cout << left << setw(wordslen) << setfill(' ') << res[i][j] << " ";
					} else {
						cout << "\033[0;37;41m" << left << setw(wordslen) << setfill(' ') << res[i][j] << "\033[0m" << " ";
					}
				} else {
					if ((i != mid - 1 && i != mid) || (j != mid - 1 && j != mid)) {
						cout << left << setw(wordslen) << setfill(' ') << res[i][j] << " ";
					} else {
						cout << "\033[0;37;41m" << left << setw(wordslen) << setfill(' ') << res[i][j] << "\033[0m" << " ";
					}
				}
			
			}
			j = 0;
			cout << endl;
		}
	}
};

int main(int argc, char* argv[]) {
	// int layer = 0;
	// cin >> layer;
	Solution sl;
	sl.getSpiralMatrix(atoi(argv[1]));
	return 0;
}
