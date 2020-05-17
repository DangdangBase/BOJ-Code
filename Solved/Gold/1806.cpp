#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;


int n, s;
int seq[100000];
int minLength=100010, curSum=0;

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		scanf("%d", &seq[i]);
	}


	int start = 0, end = 0;
	curSum = seq[start];

	while (start < n-1) {
		if (curSum >= s || end == n-1) {
			curSum -= seq[start];
			start++;
		}
		else {
			end++;
			curSum += seq[end];
		}

		if (curSum >= s) {
			minLength = min(minLength, (end - start + 1));
		}
	}

	if (minLength == 100010) {
		minLength = 0;
	}
	cout << minLength;

}