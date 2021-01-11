#include <bits/stdc++.h>
using namespace std;

int a, b;
int mul;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> a >> b;

    mul = a*b;

    cout << a*(b%10) << endl;
    b /= 10;
    
    cout << a*(b%10) << endl;
    b /= 10;

    cout << a*(b%10) << endl;
    b /= 10;

    cout << mul;

    return 0;
}