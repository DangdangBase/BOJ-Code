#include <bits/stdc++.h>
using namespace std;

int N;
char tmp;
char tree[26][2];

void pre_order(char cur){
    if(cur == '.'){
        return;
    } 

    cout << cur;
    pre_order(tree[cur - 'A'][0]);
    pre_order(tree[cur - 'A'][1]);
}

void in_order(char cur){
    if(cur == '.'){
        return;
    } 

    in_order(tree[cur - 'A'][0]);
    cout << cur;
    in_order(tree[cur - 'A'][1]);
}

void post_order(char cur){
    if(cur == '.'){
        return;
    } 

    post_order(tree[cur - 'A'][0]);
    post_order(tree[cur - 'A'][1]);
    cout << cur;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    char root, left, right;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> root >> left >> right;
        tree[root-'A'][0] = left;
        tree[root-'A'][1] = right;
    }

    pre_order('A');
    cout << "\n";
    in_order('A');
    cout << "\n";
    post_order('A');

    return 0;
}