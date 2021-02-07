#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[100010], b[100010], c[100010];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> c[i];
        }
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=0; i<n; i++){
            cin >> b[i];
        }

        int start_pos = 0, ret = 0, tmp;
        for(int i=1; i<n; i++){
            if(a[i] == b[i] || i == n-1){
                tmp = 2*(i - start_pos-1);
                if(i == n-1){
                    tmp += 2;
                }
                
                tmp += abs(a[start_pos+1] - b[start_pos+1]);
                if(i == n-1){
                    tmp += c[i]-1;
                } else {
                    tmp += c[i-1]-1;
                }

                
                if(ret < tmp){
                    ret = tmp;
                }
                start_pos = i-1;
            }
        }

        cout << ret << "\n";
    }

    return 0;
}