#include <bits/stdc++.h>
using namespace std;

int a, b;
string str_a="", str_b="";

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> a >> b;
    for(char c: to_string(a)){
        str_a = c + str_a;
    }
    for(char c: to_string(b)){
        str_b = c + str_b;
    }

    cout << max(stoi(str_a), stoi(str_b));
    return 0;
}