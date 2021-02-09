#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

int N, R, C;

int solve(int n, int r, int c){
    if(n == 1) return 1;

    int half = n/2;

    if(r <= half && c <= half){
        return solve(half, r, c);
    } else if(r <= half && c > half) {
        return half*half + solve(half, r, c-half);
    } else if(r > half && c <= half) {
        return half*half*2 + solve(half, r-half, c);
    } else {
        return half*half*3 + solve(half, r-half, c-half);
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> R >> C;
    cout << solve((int)round(pow(2, N)), R+1, C+1)-1;

    return 0;
}