#include <bits/stdc++.h>
using namespace std;

int N, M;
int buttons[10];

int available_num(int cur_num){
    int cur_pos;
    int tot_nums = 0;

    if(cur_num == 0){
        for(int i=0; i<M; i++){
            if(buttons[i] == 0){
                return 0;
            }
        }
        tot_nums = 1;
    }

    while(cur_num > 0){
        cur_pos = cur_num % 10;
        for(int i=0; i<M; i++){
            if(buttons[i] == cur_pos){
                return 0;
            }
        }
        cur_num /= 10;
        tot_nums++;
    }

    return tot_nums;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> buttons[i];
    }

    int min_button = abs(100 - N);
    for(int i=0; i<1000000; i++){
        int cur_tot_nums = available_num(i);

        if(cur_tot_nums){
            min_button = min(min_button, abs(N - i) + cur_tot_nums);
        }
    }

    cout << min_button;
    return 0;
}

