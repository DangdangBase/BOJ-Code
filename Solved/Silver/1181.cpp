#include <iostream>
using namespace std;

#include <algorithm>
#include <string>
#include <vector>

int n = 0;
string tmp;

bool comp(string s1, string s2)
{
    if (s1.length() == s2.length())
    {
        return s1 < s2;
    }
    else
    {
        return s1.length() < s2.length();
    }
}

int main()
{
    scanf("%d", &n);
    vector<string> ip;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        ip.push_back(tmp);
    }

    sort(ip.begin(), ip.end(), comp);

    vector<string>::iterator it = unique(ip.begin(), ip.end());
    ip.erase(it, ip.end());

    for (int i = 0; i < ip.size(); i++)
    {
        cout << ip[i] << endl;
    }
}