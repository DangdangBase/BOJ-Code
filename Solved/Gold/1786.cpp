#include <bits/stdc++.h>
using namespace std;

string T, P;
vector<int> pi;
vector<int> ret;

void pre_process(string p){
    vector<int> tmp(p.size(), 0);
    pi = tmp;

    int j=0;
    for(int i=1; i<p.size(); i++){
        while(j>0 && p[i]!=p[j]){
            j = pi[j-1];
        }
        if(p[i] == p[j]){
            pi[i] = ++j;
        }
    }
}
void kmp(string t, string p){
    int j=0;
    for(int i=0; i<t.size(); i++){
        while(j>0 && t[i]!=p[j]){
            j = pi[j-1];
        }
        if(t[i] == p[j]){
            if(j == p.size()-1){
                ret.push_back(i-j+1);
                j = pi[j];
            } else {
                j++;
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    getline(cin, T);
    getline(cin, P);

    pre_process(P);
    kmp(T, P);

    cout << ret.size() << "\n";
    for(auto cur: ret){
        cout << cur << ' ';
    }

    return 0;
}