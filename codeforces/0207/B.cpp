#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

struct monster{
    int attack, health;
    ll damage;
};
bool operator < (monster a, monster b){
    return a.attack < b.attack;
}



int a[100010], b[100010];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        ll A, B, n;
        monster arr[100010];
        ll sum = 0;

        cin >> A >> B >> n;
        for(int i=0; i<n; i++){
            cin >> arr[i].attack;
        }
        for(int i=0; i<n; i++){
            cin >> arr[i].health;
            sum += ((arr[i].health-1)/A + 1) * arr[i].attack;
        }

        sort(arr, arr+n);

        B -= sum;


        if(B > -arr[n-1].attack){
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }



    return 0;
}