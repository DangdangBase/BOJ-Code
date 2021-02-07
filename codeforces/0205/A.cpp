#include <bits/stdc++.h>
using namespace std;

int T, cx, cy;
int px, py;
string action;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;
    while(T--){
        cx = 0, cy = 0;
        cin >> px >> py;
        cin >> action;

        for(char c: action){
            if(c == 'R' && cx < px) cx++;
            if(c == 'L' && cx > px) cx--;

            if(c == 'U' && cy < py) cy++;
            if(c == 'D' && cy > py) cy--;
        }

        if(cx == px && cy == py){
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}