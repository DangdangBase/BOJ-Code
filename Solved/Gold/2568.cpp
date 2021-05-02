#include <bits/stdc++.h>
#define INF 1987654321
#define P pair<int, int>
using namespace std;


int N, s, e;
P arr[100010];
int lis[100010];
vector<int> seq;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> s >> e;
        arr[i] = {s, e};
    }

    sort(arr, arr+N);

    seq.push_back(-INF);
    int len = 0;
    for(int i=0; i<N; i++){
        if(seq.back() < arr[i].second){
            seq.push_back(arr[i].second);
            len++;
            lis[i] = len;
        } else {
            auto idx = lower_bound(seq.begin(), seq.end(), arr[i].second);
            lis[i] = idx - seq.begin();
            *idx = arr[i].second;
        }
    }




    int prev = INF;
    vector<int> ans;

    for(int i=N-1; i>=0; i--){
        if(lis[i] == len && arr[i].second < prev){
            prev = arr[i].second;
            ans.push_back(arr[i].first);
            len--;
        }
    }

    cout << N-seq.size()+1 << '\n';

    reverse(ans.begin(), ans.end());
    int idx = 0;
    for(int i=0; i<=N; i++){
        if(ans[idx] == arr[i].first) idx++;
        else cout << arr[i].first << '\n';
    }
    return 0;
}