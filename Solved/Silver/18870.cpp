#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

int N;
int arr[1000010];
vector<int> sorted;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
        sorted.push_back(arr[i]);
    }

    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    for(int i=0; i<N; i++){
        cout << distance(sorted.begin(), lower_bound(sorted.begin(), sorted.end(), arr[i])) << ' ';
    }

    return 0;
}   