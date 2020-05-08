#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;


int n;
int house[1010][3];
int dp[1010][3];

int RGB_Street(int num, int color);

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &house[i][0], &house[i][1], &house[i][2]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i][j] = 1001;
		}
	}

	int tmp = min(RGB_Street(0, 0), RGB_Street(0, 1));
	int val = min(tmp, RGB_Street(0, 2));

	cout << val;

}

int RGB_Street(int num, int color) {
	if (num >= n) {
		return 0;
	}

	if (dp[num][color] != 1001) {
		return dp[num][color];
	}


	int a, b;

	if (color == 0) {
		a = 1;
		b = 2;
	}
	else if (color == 1) {
		a = 0;
		b = 2;
	}
	else {
		a = 0;
		b = 1;
	}

	int ret = house[num][color] + min(RGB_Street(num+1, a), RGB_Street(num+1, b));
	dp[num][color] = ret;

	return ret;

}
