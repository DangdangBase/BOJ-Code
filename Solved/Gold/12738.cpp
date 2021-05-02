#include <bits/stdc++.h>
#define INF 1987654321
using namespace std;

int N, tmp;
vector<int> lis;

int main() {
	cin >> N;

	lis.push_back(-INF);
	for(int i=0; i<N; i++){
		cin >> tmp;

		if(lis.back() < tmp){
			lis.push_back(tmp);
		} else {
			auto idx = lower_bound(lis.begin(), lis.end(), tmp);
			*idx = tmp;
		}
	}

	cout << lis.size()-1;
}