#include <bits/stdc++.h>
#define INF 987654321
#define ll long long
using namespace std;

int G, P;
int gate[100010];
int plane[100010];


int find(int n){
    if(gate[n] == n){
        gate[n]--;
        return n-1;
    } else {
        return gate[n] = find(gate[n]);
    }
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> G >> P;

    for(int i=1; i<=G; i++){
        gate[i] = i;
    }
    for(int i=1; i<=P; i++){
        cin >> plane[i];
    }

    int ans = 0;
    for(int i=1; i<=P; i++){
        if(find(plane[i]) < 0) break;
        ans++;
    }

    cout << ans;
    return 0;
}