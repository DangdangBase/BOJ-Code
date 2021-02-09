#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

int N, M;
char a, c;

string str;
bitset<26> word[10010];
bitset<26> memorized;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> str;

        word[i].reset();
        for(char cur: str){
            word[i].set(cur - 'a');
        }
    }

    memorized.set();
    for(int i=0; i<M; i++){
        cin >> a >> c;

        if(a == '1'){
            memorized.reset(c - 'a');
        } else {
            memorized.set(c - 'a');
        }

        int cnt = 0;
        for(int i=0; i<N; i++){
            bitset<26> tmp = word[i] & memorized;
            if(word[i] == tmp){
                cnt++;
            }
        }

        cout << cnt << "\n";
    }


    return 0;
}