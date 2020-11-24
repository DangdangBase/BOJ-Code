#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, ret;
vector<int> card;

int card_sum(int cur_sum, int idx, int num)
{
    if (cur_sum > M)
    {
        return -1;
    }
    else if (num == 3)
    {
        return cur_sum;
    }
    else if (idx >= N)
    {
        return -1;
    }

    return max(card_sum(cur_sum, idx + 1, num), card_sum(cur_sum + card[idx], idx + 1, num + 1));
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        int k;
        scanf("%d", &k);
        card.push_back(k);
    }

    // ret = card_sum(0, 0, 0);

    cout << card_sum(0, 0, 0);
    // cout << ret;
    return 0;
}