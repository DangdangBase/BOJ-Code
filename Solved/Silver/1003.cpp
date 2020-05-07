#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


int t, n;
int fibcall0[45];
int fibcall1[45];

int main() {
	fibcall0[0] = 1;
	fibcall0[1] = 0;

	fibcall1[0] = 0;
	fibcall1[1] = 1;

	for (int i = 2; i < 41; i++) {
		fibcall0[i] = fibcall0[i - 1] + fibcall0[i - 2];
		fibcall1[i] = fibcall1[i - 1] + fibcall1[i - 2];
	}

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		printf("%d %d\n", fibcall0[n], fibcall1[n]);
	}

}