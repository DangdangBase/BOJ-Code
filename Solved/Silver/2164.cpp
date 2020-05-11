#include <iostream>
using namespace std;


int arr1[500010];
int arr2[500010];
int len;
bool isArr1 = true;


int main() {
	int start = 0;
	int newlen;
	int* wr, * rd;

	wr = &arr1[0];

	cin >> len;

	for (int i = 0; i < len; i++) {
		arr1[i] = i + 1;
	}

	while (len != 1) {
		if (isArr1) {
			wr = &arr2[0];
			rd = &arr1[0];
		}
		else {
			wr = &arr1[0];
			rd = &arr2[0];			
		}
		


		newlen = len / 2 + len % 2;
		start = 0;

		if (len % 2 != 0) {
			wr[0] = rd[len - 1];
			start++;
		}


		for (int i = start; i < newlen; i++) {
			wr[i] = rd[(i-start) * 2 + 1];
		}


		//for (int i = 0; i < newlen; i++) {
		//	printf("%d ", wr[i]);
		//}
		//cout << endl;


		len = newlen;
		isArr1 = (!isArr1);
	}

	cout << wr[0];

}