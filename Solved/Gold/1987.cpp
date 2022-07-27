#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
using namespace std;

int R, C;
string board[25];
bool char_code[30];

int getBoradCharCode(int i, int j){
  return int(board[i][j]) - 65;
}

int backtrack(int i, int j, int val){
  if(char_code[getBoradCharCode(i, j)]){
    return val;
  }

  int cur_val = val;
  char_code[getBoradCharCode(i, j)] = true;

  if(i > 0){
    cur_val = max(cur_val, backtrack(i-1, j, val+1));
  }
  if(i < R-1){
    cur_val = max(cur_val, backtrack(i+1, j, val+1));
  }
  if(j > 0){
    cur_val = max(cur_val, backtrack(i, j-1, val+1));
  }
  if(j < C-1){
    cur_val = max(cur_val, backtrack(i, j+1, val+1));
  }

  char_code[getBoradCharCode(i, j)] = false;

  return cur_val;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> R >> C;
    for(int i=0; i<R; i++){
      cin >> board[i];
    }

    cout << backtrack(0, 0, 0);

    return 0;
}