#include <bits/stdc++.h>
using namespace std;

int N = 10;
int mods[42];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    for(int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        mods[tmp%42]++;
    }

    int ret = 0;
    for(int cur: mods){
        if(cur){
            ret++;
        }
    }

    cout << ret;

    return 0;
}