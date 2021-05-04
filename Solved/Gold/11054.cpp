#include <bits/stdc++.h>
#define ll long long
#define P pair<int, int>
using namespace std;

int N;
int arr[1010];
int lis[1010];
int lds[1010];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    for(int i=0; i<N; i++){
        lis[i] = 1;

        for(int j=0; j<i; j++){
            if(arr[j] < arr[i]){
                lis[i] = max(lis[i], lis[j]+1);
            }
        }
    }

    for(int i=N-1; i>=0; i--){
        lds[i] = 1;

        for(int j=N-1; j>i; j--){
            if(arr[j] < arr[i]){
                lds[i] = max(lds[i], lds[j]+1);
            }
        }
    }

    int len = 0;
    for(int i=0; i<N; i++){
        len = max(len, lis[i] + lds[i] - 1);
    }

    cout << len;
}