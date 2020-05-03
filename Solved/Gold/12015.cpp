#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
	vector<int> listSeq(1);
	vector<int>::iterator idx;

	int curInput, len, lis = 0;


	scanf("%d", &len);


	for (int i = 0; i < len; i++) {
		scanf("%d", &curInput);

		if (listSeq.back() < curInput) {
			listSeq.push_back(curInput);
			lis++;
		}
		else {
			idx = lower_bound(listSeq.begin(), listSeq.end(), curInput);
			*idx = curInput;
		}
	}

	printf("%d", lis);
}