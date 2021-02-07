#include <bits/stdc++.h>
using namespace std;

int T, N, M;
int a[100010], b[100010], c[100010];

deque<int> remain[100010];
vector<int> painted;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;
    while(T--){
        cin >> N >> M;
        for(int i=1; i<=N; i++){
            remain[i].clear();
        }
        painted.clear();

        for(int i=0; i<N; i++){
            cin >> a[i];
        }
        for(int i=0; i<N; i++){
            cin >> b[i];

            if(a[i] != b[i]){
                remain[b[i]].push_front(i);
            } else {
                remain[b[i]].push_back(i);
            }
        }
        for(int i=0; i<M; i++){
            cin >> c[i];
        }

        int last = -1;
        bool paint_yn = true;

        for(int i=M-1; i>=0; i--){
            if(!remain[c[i]].empty()){
                int cur = remain[c[i]].front(); 
                remain[c[i]].pop_front();
                painted.push_back(cur+1);

                if(last == -1){
                    last = cur;
                }
            } else {
                if(last != -1){
                    painted.push_back(last+1);
                } else {
                    paint_yn = false;
                    break;
                }
            }
        }

        for(int i=0; i<N; i++){
            if(remain[b[i]].empty()) continue;

            int cur_idx = remain[b[i]].front();
            if(a[cur_idx] != b[cur_idx]){
                paint_yn = false;
                break;
            }
        }

        if(!paint_yn){
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";

            reverse(painted.begin(), painted.end());
            for(int cur: painted){
                cout << cur << ' ';
            }
            cout << "\n";
        }
    }

    return 0;
}