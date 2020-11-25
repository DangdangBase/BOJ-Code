#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int N;
vector<int> nums;

int main()
{
    cin.sync_with_stdio(false);

    cin >> N;

    if (N <= 99)
    {
        cout << N;
        exit(0);
    }

    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i + j < 10 && i + 2 * j < 10)
            {
                int cur = i * 100 + (i + j) * 10 + (i + 2 * j);
                nums.push_back(cur);
            }
            if (i - j >= 0 && i - 2 * j >= 0 && j != 0)
            {
                int cur = i * 100 + (i - j) * 10 + (i - 2 * j);
                nums.push_back(cur);
            }
        }
    }

    sort(nums.begin(), nums.end());
    int count = 99;

    for (int cur : nums)
    {
        if (cur > N)
        {
            break;
        }
        count++;
    }

    cout << count;
    return 0;
}