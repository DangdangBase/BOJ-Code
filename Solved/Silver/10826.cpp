#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N;
string fib[10010] = {"0", "1"};

string Add(string &s1, string &s2) {
    string result(max(s1.size(), s2.size()), '0');
    
    bool carry = false;
    for (int i = 0; i < result.size(); i++) {
        int temp = carry;
        carry = false;

        if (i < s1.size())
            temp += s1[s1.size() - i - 1] - '0';

        if (i < s2.size())
            temp += s2[s2.size() - i - 1] - '0';
        if (temp >= 10) {
            carry = true;
            temp -= 10;
        }
        result[result.size() - i - 1] = temp + '0';
    }

    if (carry)
        result.insert(result.begin(), '1');
    return result;
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for(int i=2; i<=N; i++){
        fib[i] = Add(fib[i-1], fib[i-2]);
    }

    cout << fib[N];
    return 0;
}