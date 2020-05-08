#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;


int triMax(int layer, int num);

int n;
int triangle[125260];
int dp[125260];


int main() {
	scanf("%d", &n);

	int size = n * (n + 1) / 2;


	for (int i = 0; i < size; i++) {
		scanf("%d", &triangle[i]);
		dp[i] = -1;
	}

	cout << triMax(1, 0);

}

int triMax(int layer, int num) {
	int loc = layer * (layer - 1) / 2 + num;

	if (layer == n) {
		return triangle[loc];
	}

	if (dp[loc] != -1) {
		return dp[loc];
	}
	

	int ret = triangle[loc] + max(triMax(layer + 1, num), triMax(layer + 1, num + 1));
	dp[loc] = ret;

	return ret;
}