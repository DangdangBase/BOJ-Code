#include <bits/stdc++.h>
using namespace std;

int a, b, mul, tmp;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> a >> b;
    mul = a*b;

    if(a<b){
        swap(a, b);
    }

    while(b){
        tmp = a%b;
        a = b;
        b = tmp;
    }

    cout << a << endl;
    cout << mul/a << endl;

    return 0;
}