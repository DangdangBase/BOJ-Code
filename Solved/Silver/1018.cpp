#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int N, M;
vector<string> board;
int color[2] = {'W', 'B'};

int paint(int y, int x){
    int first = 0, second = 0;
    
    int cur_color = 0;
    for(int i=y; i<y+8; i++){
        for(int j=x; j<x+8; j++){
            if(board[i][j] != color[cur_color]){
                first++;
            }
            else {
                second++;
            }
            cur_color = !cur_color;
        }
        cur_color = !cur_color;
    }


    return min(first, second);
}

int main()
{
    cin.sync_with_stdio(false);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        string tmp;
        cin >> tmp;
        board.push_back(tmp);
    }

    int count = 9999;
    for(int i=0; i<N-7; i++){
        for(int j=0; j<M-7; j++){
            count = min(count, paint(i, j));
        }
    }
    cout << count;


    return 0;
}