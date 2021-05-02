#include <bits/stdc++.h>
#define INF 1987654321
using namespace std;


int N, len;
int arr[1000010];
int lis[1000010];
vector<int> seq;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    seq.push_back(-INF);
    for(int i=0; i<N; i++){
        cin >> arr[i];

        if(seq.back() < arr[i]){
            seq.push_back(arr[i]);
            len++;
            lis[i] = len;
        } else {
			auto idx = lower_bound(seq.begin(), seq.end(), arr[i]);
			*idx = arr[i];
            lis[i] = idx - seq.begin(); 
        }
    }


    int prev = INF;
    vector<int> ans;

    for(int i=N-1; i>=0; i--){
        if(lis[i] == len && arr[i] < prev){
            prev = arr[i];
            ans.push_back(arr[i]);
            len--;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << seq.size()-1 << '\n';
    for(int cur: ans){
        cout << cur << ' ';
    }

    return 0;
}