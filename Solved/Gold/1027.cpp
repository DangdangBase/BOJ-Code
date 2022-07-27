#include <bits/stdc++.h>
#define INF 1987654321
#define P pair<int, int>
#define ll long long
using namespace std;

int N;
int height[55];

float gradient[55][55];
float left_gradient, right_gradient;
int ans;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for(int i=0; i<N; i++){
      cin >> height[i];
    }

    for(int i=0; i<N; i++){
      for(int j=i+1; j<N; j++){
        gradient[i][j] = float(height[j]-height[i]) / float(j-i);
      }
    }

    for(int i=0; i<N; i++){
      int cur_ans = 0;

      for(int j=i+1; j<N; j++){
        bool flag = true;
        for(int k=i+1; k<j; k++){
          if(gradient[i][k] >= gradient[k][j]){
            flag = false;
            break;
          }
        }

        if(flag) cur_ans++;
      }

      for(int j=i-1; j>=0; j--){
        bool flag = true;
        for(int k=i-1; k>j; k--){
          if(gradient[j][k] >= gradient[k][i]){
            flag = false;
            break;
          }
        }

        if(flag) cur_ans++;
      }

      ans = max(ans, cur_ans);
    }

    cout << ans << endl;
    return 0;
}