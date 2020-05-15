#include <iostream>
using namespace std;

int n, iter;
string ip,op;


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		op = "";
		cin >> iter >> ip;

		for (int j = 0; j < ip.length(); j++) {
			for (int k = 0; k < iter; k++) {
				op += ip.at(j);
			}
		}

		cout << op << endl;
	}
}