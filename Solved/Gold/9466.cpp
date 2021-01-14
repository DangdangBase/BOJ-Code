#include <bits/stdc++.h>
using namespace std;

int T, N;
int student_next[100010];
int visited[100010];
int cur_visited;
vector<int> cur_cycle;
int tot_cnt;

int dfs(int cur){
    if(visited[cur]){
        if(visited[cur] != cur_visited){
            return 0;
        }

        int team = 0, idx = cur_cycle.size()-1;

        while(idx>=0){
            team++;
            if(cur_cycle[idx] == cur){
                break;
            }

            idx--;
        }
        
        cur_cycle.clear();
        return team;
    }

    visited[cur] = cur_visited;
    cur_cycle.push_back(cur);

    return dfs(student_next[cur]);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;
    while(T--){
        cin >> N;
        for(int i=1; i<=N; i++){
            cin >> student_next[i];
        }

        tot_cnt = N;
        for(int i=1; i<=N; i++){
            if(!visited[i]){
                cur_visited++;
                visited[i] = cur_visited;
                cur_cycle.push_back(i);
                tot_cnt -= dfs(student_next[i]);
            }
        }

        cout << tot_cnt << "\n";
        memset(visited, 0, sizeof(visited));
    }

    return 0;
}