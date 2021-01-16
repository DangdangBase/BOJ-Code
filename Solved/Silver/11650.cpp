#include <bits/stdc++.h>
using namespace std;

int N, x, y;
pair<int, int> loc[100010];

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }

    return a.first < b.first;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> loc[i].first >> loc[i].second;
    }

    // sort(loc, loc+N, cmp);
    sort(loc, loc+N);

    for(int i=0; i<N; i++){
        cout << loc[i].first << ' ' << loc[i].second << "\n";
    }

    return 0;
}