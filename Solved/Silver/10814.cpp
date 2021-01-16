#include <bits/stdc++.h>
using namespace std;

int N, age;
string name;
vector<pair<int, string>> member;

bool cmp(pair<int, string> a, pair<int, string> b){
    return a.first < b.first;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> age >> name;
        member.emplace_back(age, name);
    }

    stable_sort(member.begin(), member.end(), cmp);

    for(int i=0; i<N; i++){
        cout << member[i].first << " " << member[i].second << "\n";
    }

    return 0;
}
