#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N, solution[100010];
int ans_l=0, ans_h=INT_MAX;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> solution[i];
    sort(solution, solution+N);

    int lo=0, hi=N-1;
    while(lo != hi){
        if(abs(solution[lo]+solution[hi]) < abs(ans_l+ans_h)){
            ans_l = solution[lo];
            ans_h = solution[hi];
        }

        if(solution[lo]+solution[hi] > 0) hi--;
        else lo++;
    }

    cout << ans_l << " " << ans_h;
    return 0;
}