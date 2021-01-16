#include <bits/stdc++.h>
using namespace std;

string a, b;
int mid;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    while(true){
        cin >> a;
        if(a == "0"){
            break;
        }

        mid = a.length() / 2 + 1;
        
        if(a.length() % 2 == 0){
            b = a.substr(mid-1);
        } else {
            b = a.substr(mid);
        }
        a = a.substr(0, mid-1);
        reverse(a.begin(), a.end());

        if(a == b){
            cout << "yes" << "\n";
        } else {
            cout << "no" << "\n";
        }
    }

    return 0;
}