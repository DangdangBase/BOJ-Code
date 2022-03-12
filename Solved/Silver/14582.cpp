#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a_score[10];
int b_score[10];
int sum;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    for(int i=1; i<=9; i++) cin >> a_score[i];
    for(int i=1; i<=9; i++) cin >> b_score[i];
    
    for(int i=1; i<=9; i++){
        sum += (a_score[i] - b_score[i-1]);
        if(sum > 0){
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";
    return 0;
}