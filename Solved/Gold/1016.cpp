#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll min_val, max_val;
ll cnt;

bool is_sq_mul[1000010];
bool primes[1000010];

void get_primes(){
    memset(primes, 1, sizeof(primes));

    for(int i=2; i<100010; i++) {
        if(!primes[i]) continue;

        for(int j=i*2; j<1000010; j+=i){
            primes[j] = false;
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> min_val >> max_val;

    get_primes();


    for(ll i=2; i<1000010; i++){
        if(!primes[i]) continue;
        else if(i*i > max_val) break;
        
        ll sq = i*i;

        ll start = sq;
        if(min_val != 1){
            start = ((min_val-1)/sq+1)*sq;
        }

        for(ll j=start; j<=max_val; j+=sq){
            if(!is_sq_mul[j-min_val]){
                is_sq_mul[j-min_val] = true;
                cnt++;
            }
        }
    }

    cout << max_val-min_val+1 - cnt;
    return 0;
}