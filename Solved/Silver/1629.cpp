#include <bits/stdc++.h>
using namespace std;

long long A, B, C;

long long get_pow(long long b){
    if(b == 1) return A % C;

    long long tmp = get_pow(b/2) % C;
    
    if(b%2 == 0){
        return tmp * tmp % C;
    } else {
        return tmp * tmp % C * A % C;
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> A >> B >> C;

    if(A == 1){
        cout << 1;
    } else {
        cout << get_pow(B);
    }

    return 0;
}