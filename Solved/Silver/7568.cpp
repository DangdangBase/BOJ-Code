#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int N;
vector<vector<int> > body;

int main()
{
    cin.sync_with_stdio(false);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int h, w;
        cin >> h >> w;
        vector<int> tmp;
        tmp.push_back(h);
        tmp.push_back(w);
        body.push_back(tmp);
    }

    for (int i = 0; i < N; i++)
    {
        vector<int> cur = body[i];
        int rating = 1;

        for (int j = 0; j < N; j++)
        {
            if (body[j][0] > cur[0] && body[j][1] > cur[1])
            {
                rating++;
            }
        }
        cout << rating << ' ';
    }

    return 0;
}