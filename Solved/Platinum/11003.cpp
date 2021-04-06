#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
using namespace std;

int N, L;
int seq[5000010];
priority_queue<int, vector<int>, greater<int>> target;
priority_queue<int, vector<int>, greater<int>> removed;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> L;
    for(int i=1; i<=N; i++){
        cin >> seq[i];
    }

    for(int i=1; i<=N; i++){
        target.push(seq[i]);

        while(!removed.empty() && target.top()==removed.top()){
            target.pop(); 
            removed.pop();
        }

        cout << target.top() << ' ';

        if(i >= L) {
            removed.push(seq[i-L+1]);
        }
    }

    return 0;
}