#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;

    cin >> t;
    while(t--){
        string str;
        cin >> str;

        for(int i=0; i<str.size(); i++){
            if(i%2 == 0){
                if(str[i] == 'a'){
                    str[i] = 'b';
                } else {
                    str[i] = 'a';
                }
            } else {
                if(str[i] == 'z'){
                    str[i] = 'y';
                } else {
                    str[i] = 'z';
                }
            }
        }

        cout << str << "\n";
    }

    return 0;
}