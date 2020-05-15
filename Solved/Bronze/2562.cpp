#include <iostream>
using namespace std;

int num[9];
int maxVal=0, idx=0;

int main() {
	for (int i = 0; i < 9; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < 9; i++) {
		if (maxVal < num[i]) {
			maxVal = num[i];
			idx = i+1;
		}
	}
	cout << maxVal << endl;
	cout << idx;
}