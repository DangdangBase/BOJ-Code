#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int N, M;
vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
vector<vector<int>> rep_combs;

void get_rep_combs(int remain, int idx, vector<int> & cur_rep_combs){
    if(remain == 0){
        rep_combs.push_back(cur_rep_combs);
        return;
    }

    for(int i=0; i<nums.size(); i++){
        cur_rep_combs.push_back(nums[i]);
        get_rep_combs(remain-1, i, cur_rep_combs);
        cur_rep_combs.pop_back();
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cin >> N;
    cin >> M;
    for(int i=0; i<M; i++){
        int tmp;
        cin >> tmp;

        auto iter = find(nums.begin(), nums.end(), tmp);
        nums.erase(iter);
    }

    vector<int> tmp;
    get_rep_combs(6, 0, tmp);


    int min_click = abs(N - 100);
    for(auto cur_rep_comb: rep_combs){
        int cur_val = 0, digits = 0;

        for(int i=0; i<6; i++){
            if(cur_rep_comb[i] != 0){
                digits = 6-i;
                break;
            }
        }
        for(int i=0; i<6; i++){
            cur_val += pow(10, 5-i) * cur_rep_comb[i];
        }

        min_click = min(min_click, abs(N-cur_val) + digits);
    }

    cout << min_click;


    return 0;
}