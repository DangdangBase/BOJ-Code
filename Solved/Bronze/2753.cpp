#include <bits/stdc++.h>
using namespace std;

int year;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> year;

    if(year % 400 == 0){
        cout << 1;
    } else if(year%4 == 0 && year%100 != 0){
        cout << 1;
    } else {
        cout << 0;
    }

    return 0;
}