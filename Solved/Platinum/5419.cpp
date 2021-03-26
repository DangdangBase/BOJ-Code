#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

int T, N;
vector<P> board;
int fwt[75010];


void update(int i){
    while(i <= N){
        fwt[i]++;
        i += (i & -i);
    }
}
int sum(int i){
    int ret = 0;
    while(i > 0){
        ret += fwt[i];
        i -= (i & -i);
    }
    return ret;
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;
    while(T--){
        cin >> N;

        board.resize(N);
        memset(fwt, 0, (N+1)*4);

        for(int i=0; i<N; i++){
            cin >> board[i].first >> board[i].second;
        }
        sort(board.begin(), board.end(), [](P &a, P &b){ return a.second < b.second; });

        int prev = board[0].second;
        board[0].second = 1;
        for(int i=1; i<N; i++){
            if(board[i].second == prev){
                board[i].second = board[i-1].second;
            } else {
                prev = board[i].second;
                board[i].second = board[i-1].second+1;
            }
        }
        sort(board.begin(), board.end(), [](P &a, P &b){
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });

        ll ans = 0;
        for(P cur: board){
            ans += sum(N) - sum(cur.second-1);
            update(cur.second);
        }

        cout << ans << '\n';
    }

    return 0;
}