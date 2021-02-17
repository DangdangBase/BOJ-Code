#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

int t, n, tmp;
int ret, arr[3];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;
    while(t--){
        memset(arr, 0, sizeof(arr));
        ret = 0;

        cin >> n;
        for(int i=0; i<n; i++){
            cin >> tmp;
            arr[tmp%3]++;
        }

        int bal = n/3;
        int state = (arr[0]>bal) + (arr[1]>bal) + (arr[2]>bal);
        
        if(state == 1){
            int idx;
            for(int i=0; i<3; i++){
                if(arr[i] > bal){
                    idx = i;
                };
            }

            ret += (bal - arr[(idx+1)%3]);
            ret += 2*(bal - arr[(idx+2)%3]);
        } else if(state == 2){
            int idx;
            for(int i=0; i<3; i++){
                if(arr[i] < bal){
                    idx = i;
                };
            }

            ret += 2*(arr[(idx+1)%3] - bal);
            ret += (arr[(idx+2)%3] - bal);
        }

        cout << ret << "\n";
    }

    return 0;
}