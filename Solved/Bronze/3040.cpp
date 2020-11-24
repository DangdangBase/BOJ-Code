#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nums[9];
vector<int> cur_nums;

void find(int cur_sum, int idx, int remain)
{

    if (remain == 0)
    {
        if (cur_sum == 100)
        {
            for (int num : cur_nums)
            {
                cout << num << endl;
            }
            exit(0);
        }
        return;
    }

    for (int i = idx; i < 9; i++)
    {
        cur_nums.push_back(nums[i]);
        find(cur_sum + nums[i], i + 1, remain - 1);
        cur_nums.pop_back();
    }
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &nums[i]);
    }

    find(0, 0, 7);

    return 0;
}