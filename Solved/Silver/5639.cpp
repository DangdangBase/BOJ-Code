#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

int tmp;
vector<int> pre_order;
vector<int> post_order;

void get_post_order(int start, int end){
    if(start > end) return;
    if(start == end){
        post_order.push_back(pre_order[start]);
        return;
    }

    int idx = upper_bound(pre_order.begin()+start, pre_order.begin()+end+1, pre_order[start]) - pre_order.begin();

    get_post_order(start+1, idx-1);
    get_post_order(idx, end);
    post_order.push_back(pre_order[start]);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    while(cin >> tmp){
        pre_order.push_back(tmp);
    };

    get_post_order(0, pre_order.size()-1);

    for(int cur: post_order){
        cout << cur << "\n";
    }

    return 0;
}