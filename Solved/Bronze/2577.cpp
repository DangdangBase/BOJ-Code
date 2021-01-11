#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int mul, tmp=0;
int nums[10];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> a >> b >> c;
    mul = a*b*c;

    while(mul != 0){
        nums[mul%10]++;
        mul /= 10;
    }

    for(int cur: nums){
        cout << cur << endl;
    }

    return 0;
}