#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int climbStairs(int pos, int cont);


int N, stair[310];
int stairMem[310][3];


int main() {
	memset(stair, 0, sizeof(stair));
	int cont = 0;

	cin >> N;
	for (int i = 1; i < N+1; i++) {
		cin >> stair[i];
	}

	for (int i = 0; i < 310; i++) {
		memset(stairMem[i], -1, sizeof(stairMem[i]));
	}


	cout << climbStairs(0, cont);


}

int climbStairs(int pos, int cont) {

	if (stairMem[pos][cont] != -1) {	// if calculated before
		return stairMem[pos][cont];
	}

	int ret = 0;

	if (pos > N) {	// out of range
		ret = 0;
		stairMem[pos][cont] = ret;
		return ret;
	}
	if (((pos == N - 1) ) && (cont == 2)) {	// can't step on the last stair condition
		ret = -999999999;
		stairMem[pos][cont] = ret;
		return ret; 
	}



	if (cont == 2) {
		ret =  climbStairs(pos + 2, 1) + stair[pos];
	}
	else {
		ret =  max(climbStairs(pos + 1, cont + 1), climbStairs(pos + 2, 1)) + stair[pos];
	}

	stairMem[pos][cont] = ret;
	return ret;
	
}