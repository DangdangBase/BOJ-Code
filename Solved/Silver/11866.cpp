#include <bits/stdc++.h>
using namespace std;

int N, K, tmp;
queue<int> q;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> K;
    for(int i=1; i<=N; i++){
        q.push(i);
    }

    cout << "<";
    for(int i=0; i<K-1; i++){
        tmp = q.front();
        q.pop();
        q.push(tmp);
    }
    cout << q.front();
    q.pop();

    while(!q.empty()){
        cout << ", ";
        for(int i=0; i<K-1; i++){
            tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        cout << q.front();
        q.pop();
    }
    cout << '>';

    return 0;
}