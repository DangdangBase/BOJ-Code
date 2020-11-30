#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int N;
char chars[9];
vector<vector<int> > combs;

void get_combinations(int remain, int next, vector<int> &cur_comb){
    if(remain == 0){
        combs.push_back(cur_comb);
        return;
    }

    for(int i=next; i<10; i++){
        cur_comb.push_back(i);
        get_combinations(remain-1, i+1, cur_comb);
        cur_comb.pop_back();
    }
}

bool compare(char op, int a, int b){
    if(op == '<'){
        return a < b;
    } else {
        return a > b;
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> chars[i];        
    }

    vector<int> tmp;
    get_combinations(N+1, 0, tmp);


    string min_val = "9876543211", max_val = "0";


    for(auto cur_comb: combs){
        do{
            bool flag = true;
            for(int i=0; i<N; i++){
                if(!compare(chars[i], cur_comb[i], cur_comb[i+1])){
                    flag = false;
                    break;
                }
            }

            if(flag){
                string cur_val = "";
                for(int cur: cur_comb){
                    cur_val += to_string(cur);
                }
                
                min_val = stol(cur_val) > stol(min_val) ? min_val : cur_val;
                max_val = stol(cur_val) < stol(max_val) ? max_val : cur_val;
            }

        }while(next_permutation(cur_comb.begin(), cur_comb.end()));
    }


    cout << max_val << endl;
    cout << min_val << endl;


    return 0;
}