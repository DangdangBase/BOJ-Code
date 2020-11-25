#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N;
string answer;

string picker[3] = {"ABC", "BABC", "CCAABB"};
string name[3] = {"Adrian", "Bruno", "Goran"};
int correct_cnt[3] = {0, 0, 0};

int main()
{
    cin.sync_with_stdio(false);
    cin >> N >> answer;

    for (int i = 0; i < N; i++)
    {
        char cur_ans = answer[i];

        for (int j = 0; j < 3; j++)
        {
            string cur_pick = picker[j];
            if (cur_pick[i % cur_pick.length()] == cur_ans)
            {
                correct_cnt[j]++;
            }
        }
    }

    int correct_max = max(max(correct_cnt[0], correct_cnt[1]), correct_cnt[2]);

    cout << correct_max << endl;
    for (int i = 0; i < 3; i++)
    {
        if (correct_cnt[i] == correct_max)
        {
            cout << name[i] << endl;
        }
    }

    return 0;
}