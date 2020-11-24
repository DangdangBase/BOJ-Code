#include <iostream>
#include <algorithm>
using namespace std;

int N;
int nums[3];

int main()
{
    scanf("%d %d %d %d", &nums[0], &nums[1], &nums[2], &N);

    for (int i = 0; i < 301; i++)
    {
        for (int j = 0; j < 301; j++)
        {
            for (int k = 0; k < 301; k++)
            {
                int cur = nums[0] * i + nums[1] * j + nums[2] * k;
                if (cur == N)
                {
                    cout << 1;
                    exit(0);
                }
                else if (cur > N)
                {
                    break;
                }
            }
        }
    }
    cout << 0;
    return 0;
}