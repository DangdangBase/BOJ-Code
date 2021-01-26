#include <bits/stdc++.h>
using namespace std;

int N;
int in_order[100010];
int post_order[100010];
vector<int> pre_order;

void get_pre_order(int i_s, int i_e, int p_s, int p_e){
    pre_order.push_back(post_order[p_e]);
    if(i_s == i_e) return;

    int in_root, post_left_end;
    for(int i=i_s; i<=i_e; i++){
        if(in_order[i] == post_order[p_e]){
            in_root = i;
            post_left_end = p_s + in_root - i_s - 1;
            break;
        }
    }



    if(i_s <= in_root-1){
        get_pre_order(i_s, in_root-1, p_s, post_left_end);
    }
    if(in_root+1 <= i_e){
        get_pre_order(in_root+1, i_e, post_left_end+1, p_e-1);
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> in_order[i];
    }
    for(int i=0; i<N; i++){
        cin >> post_order[i];
    }

    get_pre_order(0, N-1, 0, N-1);

    for(int cur: pre_order){
        cout << cur << ' ';
    }

    return 0;
}