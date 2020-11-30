#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int N;

int main()
{
    cin.sync_with_stdio(false);
    vector<int> nums;

    cin >> N;
    for(int i=1; i<N+1; i++){
        nums.push_back(i);
    }

	do{
		for(int i=0; i<N; i++){
			cout << nums[i] << " ";
		}
		cout << '\n';

	}while(next_permutation(nums.begin(),nums.end()));

    return 0;
}