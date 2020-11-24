#include <cstdio>
#include <algorithm>
using namespace std;

int R, B;

int main()
{
    scanf("%d %d", &R, &B);

    for (int i = 1; i * i <= B; i++)
    {
        int r = B % i;

        if (r != 0)
        {
            continue;
        }

        int a = i, b = B / i;

        if (2 * (a + b) + 4 == R)
        {
            printf("%d %d", max(a + 2, b + 2), min(a + 2, b + 2));
            exit(0);
        }
    }
    return 0;
}