#include <bits/stdc++.h>
using namespace std;
#define MAX 987654321

int N, M;
int a, b, c;
int cost[110][110];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i==j) cost[i][j]=0;
            else cost[i][j]=MAX;
        }
    }

    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        if(cost[a][b] > c){
            cost[a][b] = c;
        }
    }

    for(int k=1; k<=N; k++){
        for(int j=1; j<=N; j++){
            for(int i=1; i<=N; i++){
                if(cost[i][j] > cost[i][k]+cost[k][j]){
                    cost[i][j] = cost[i][k]+cost[k][j];
                }
            }
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(cost[i][j] == MAX){
                cout << 0 << ' ';
            } else {
                cout << cost[i][j] << ' ';
            }
        }
        cout << "\n";
    }

    return 0;
}