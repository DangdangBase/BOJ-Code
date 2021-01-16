#include <bits/stdc++.h>
using namespace std;

int T, H, W, N;
int h, w;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;
    while(T--){
        cin >> H >> W >> N;

        h = N % H;
        w = N / H + 1;

        if(h == 0){
            h = H;
            w--;
        }

        cout << h*100 + w << "\n";
    }

    return 0;
}