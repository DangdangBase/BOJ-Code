#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

int N, M;
string tmp;

string dic[100010];
map<string, int> m;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for(int i=1; i<=N; i++){
        cin >> dic[i];
        m[dic[i]] = i;
    }

    for(int i=0; i<M; i++){
        cin >> tmp;

        if(isdigit(tmp[0])){
            cout << dic[stoi(tmp)] << "\n";
        } else {
            cout << m[tmp] << "\n";
        }
    }

    return 0;
}