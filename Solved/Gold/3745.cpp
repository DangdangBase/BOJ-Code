#include <bits/stdc++.h>
#define INF 1987654321
#define P pair<int, int>
using namespace std;


int T, N, tmp;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    while(cin >> N){
        vector<int> seq;
        seq.push_back(-INF);
        int len = 0;

        for(int i=0; i<N; i++){
            cin >> tmp;
            if(seq.back() < tmp){
                seq.push_back(tmp);
                len++;
            } else {
                auto idx = lower_bound(seq.begin(), seq.end(), tmp);
                *idx = tmp;
            }
        }

        cout << len << '\n';
    }
    return 0;
}