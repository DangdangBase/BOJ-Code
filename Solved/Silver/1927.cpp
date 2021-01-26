#include <bits/stdc++.h>
using namespace std;

int N, tmp;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> tmp;

        if(tmp != 0){
            pq.push(tmp);
        } else {
            if(!pq.empty()){
                cout << pq.top() << "\n";
                pq.pop();
            } else {
                cout << 0 << "\n";
            }
        }
    }


    return 0;
}