#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
using namespace std;

int X;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> X;

    for(int i=1; i<6000; i++){
      if(i*(i+1)/2 >= X){
        int diff = X - i*(i-1)/2;

        if(i%2){
          cout << i+1-diff << "/" << diff;
        } else {
          cout << diff << "/" << i+1-diff;
        }

        break;
      }
    }

    return 0;
}