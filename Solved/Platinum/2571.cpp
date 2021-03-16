#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
using namespace std;

int N, tmp;
vector<P> athlete;
vector<int> fwt;
vector<int> ans;

int sum(int i){
    int ret = 0;
    while(i > 0){
        ret += fwt[i];
        i -= (i & -i);
    }
    return ret;
}
void update(int i){
    while(i < fwt.size()){
        fwt[i]++;
        i += (i & -i);
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    fwt.resize(N+1);
    ans.resize(N+1);

    for(int i=0; i<N; i++){
        cin >> tmp;
        athlete.push_back({tmp, i});
    }

    sort(athlete.begin(), athlete.end(), greater<P>());

    for(P cur: athlete){
        ans[cur.second+1] = sum(cur.second)+1;
        update(cur.second+1);
    }

    for(int i=1; i<=N; i++){
        cout << ans[i] << '\n';
    }

    return 0;
}