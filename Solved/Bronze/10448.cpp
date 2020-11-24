#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int triangle_nums[46];
vector<int> tc;

int find(int num, int cur_sum, int remain)
{
    if (remain == 0)
    {
        if (cur_sum == num)
        {
            return 1;
        }
        return 0;
    }

    if (cur_sum > num)
    {
        return 0;
    }

    int ret = -1;
    for (int i = 1; i < 46; i++)
    {
        ret = max(ret, find(num, cur_sum + triangle_nums[i], remain - 1));
    }
    return ret;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        tc.push_back(tmp);
    }

    for (int i = 1; i < 46; i++)
    {
        triangle_nums[i] = i * (i + 1) / 2;
    }

    for (int cur : tc)
    {
        cout << find(cur, 0, 3) << endl;
    }

    return 0;
}