#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int height[9];
vector<int> picked;

void pick(int remain, int idx, int cur_sum)
{
    if (remain == 0)
    {
        if (cur_sum == 100)
        {
            sort(picked.begin(), picked.end());
            for (int cur : picked)
            {
                cout << cur << endl;
            }
            exit(0);
        }
        return;
    }

    for (int next = idx; next < 9; next++)
    {
        picked.push_back(height[next]);
        pick(remain - 1, idx + 1, cur_sum + height[next]);
        picked.pop_back();
    }
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &height[i]);
    }

    pick(7, 0, 0);

    return 0;
}