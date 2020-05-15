#include <iostream>
using namespace std;

int cur, tmp;
bool nonMixed = true;
bool asc = true;

int main() {
	cin >> cur;
	if (cur != 1) {
		asc = false;
	}

	for (int i = 1; i < 8; i++) {
		tmp = cur;
		cin >> cur;

		if (abs(tmp - cur) != 1) {
			nonMixed = false;
		}

	}

	if (!nonMixed) {
		cout << "mixed";
	}
	else {
		if (asc) {
			cout << "ascending";
		}
		else {
			cout << "descending";
		}
	}
}