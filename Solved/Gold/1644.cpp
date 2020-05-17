#include <iostream>
#include <algorithm>
using namespace std;

int n;
int primes[4000001];

int main() {
	cin >> n;

	for (int i = 2; i < n+1; i++) {
		primes[i] = i;
	}

	for (int i = 2; i < n + 1; i++) {
		if (primes[i] == 0) { continue; }

		for (int j = i * 2; j < n + 1; j += i) {
			primes[j] = 0;
		}
	}

	int start = 2, end = 2;
	int curSum = 2;
	int count = 0;

	while (start < n+1) {
		if (curSum >= n || end == n) {
			curSum -= primes[start];
			start++;
			if (primes[start - 1] == 0) { continue; }
		}
		else {
			end++;
			curSum += primes[end];

			if (primes[end] == 0) { continue; }
		}

		if (curSum == n) {
			count++;
		}

	}

	if (n == 2) {
		count++;
	}
	cout << count;

}