#include <bits/stdc++.h>
using namespace std;

int N, M;
string tmp;
string arr[500010];
vector<string> ret;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);

    for(int i=0; i<M; i++){
        cin >> tmp;
        if(binary_search(arr, arr+N, tmp)){
            ret.push_back(tmp);
        }
    }
    sort(ret.begin(), ret.end());

    cout << ret.size() << "\n";
    for(auto cur: ret){
        cout << cur << "\n";
    }

    return 0;
}
