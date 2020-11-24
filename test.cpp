#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

vector<int> nums;

void split(string str)
{
    stringstream ss(str);
    string tmp;

    while (getline(ss, tmp, ' '))
    {
        nums.push_back(stoi(tmp));
    }
    nums.pop_back();
}

int main()
{
    cin.sync_with_stdio(false);
    string ip;
    int cnt;

    getline(cin, ip);
    while (ip != "-1")
    {
        split(ip);

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                if (nums[i] * 2 == nums[j])
                {
                    cnt++;
                }
                if (nums[i] * 2 >= nums[j])
                {
                    break;
                }
            }
        }

        cout << cnt << "\n";

        nums.clear();
        cnt = 0;
        getline(cin, ip);
    }

    return 0;
}