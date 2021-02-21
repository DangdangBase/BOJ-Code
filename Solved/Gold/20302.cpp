#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

int N, cur;
char op = '*';
int arr[100010];

void factorization(int n, bool is_mul){
    int tmp = is_mul ? 1 : -1;

	for (ll i = 2; i * i <= n; i++) {
		while (n % i == 0) {
            arr[i] += tmp;
            n /= i;
        }
	}
	if (n > 1) {
        arr[n] += tmp;
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for(int i=0; i<N; i++){
        if(i) cin >> op;
        cin >> cur;

        if(!cur){
            cout << "mint chocolate";
            return 0;
        } else {
            factorization(abs(cur), op=='*');
        }
    }



    for(int i=2; i<100010; i++){
        if(arr[i] < 0) {
            cout << "toothpaste";
            return 0;
        }
    }
    
    cout << "mint chocolate";
    return 0;
}