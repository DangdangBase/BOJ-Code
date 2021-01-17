#include <bits/stdc++.h>
using namespace std;

int N, cur;
priority_queue<int> pq;

void action(int a){
    if(a != 0){
        pq.push(a);
        return;
    }

    if(pq.empty()){
        cout << 0 << "\n";
    } else {
        cout << pq.top() << "\n";
        pq.pop();
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> cur;
        action(cur);
    }

    return 0;
}