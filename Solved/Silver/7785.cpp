#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
using namespace std;



set<string, greater<string>> onDuty;
set<string>::iterator iter;

int n;
char tmp1[10], tmp2[10];
string name, status;


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%s %s", tmp1, tmp2);
		name = tmp1;
		status = tmp2;

		if (status == "enter") {
			onDuty.insert(name);
		}
		else {
			onDuty.erase(name);
		}
	}

	for (iter = onDuty.begin(); iter != onDuty.end(); iter++) {
		cout << *iter << '\n';
	}


}