#include <iostream>
#include <algorithm>
using namespace std;

int maxSquare(int row, int col);

int n, m;
string ipString;
char tmp;
int dp[1010][1010];
int ip[1010][1010];
int maxNum = 0;


int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> ipString;
		for (int j = 0; j < m; j++) {
			tmp = ipString.at(j);
			ip[i][j] = (int)tmp - 48;
			dp[i][j] = -1;
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maxNum < maxSquare(i, j)) {
				maxNum = dp[i][j];
			}
		}
	}

	cout << maxNum*maxNum;

}

int maxSquare(int row, int col) {
	if (row < 0 || col < 0) {
		return 0;
	}
	if (dp[row][col] != -1) {
		return dp[row][col];
	}

	if (ip[row][col] == 0) {
		dp[row][col] = 0;
		return 0;
	}

	int ret;

	ret = min(maxSquare(row - 1, col), maxSquare(row, col - 1));
	ret = 1 + min(ret, maxSquare(row - 1, col - 1));

	dp[row][col] = ret;
	return ret;

}