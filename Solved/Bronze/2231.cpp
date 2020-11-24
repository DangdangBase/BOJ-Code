#include <iostream>
using namespace std;

int N;

int dist_sum(int n)
{
    int ret = n;

    while (n > 0)
    {
        ret += n % 10;
        n /= 10;
    }

    return ret;
}

int main()
{
    scanf("%d", &N);

    for (int i = 1; i < N; i++)
    {
        if (N == dist_sum(i))
        {
            cout << i;
            return 0;
        }
    }

    cout << 0;
    return 0;
}