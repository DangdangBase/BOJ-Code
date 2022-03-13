#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

int T;
string ip;
int board[11][11];
vector<P> blank;
bool checkTable[11];

void resetCheckTable(){
    memset(checkTable, 0, 11*sizeof(bool));
}

bool checkValid(){
    for(int i=1; i<=9; i++){
        resetCheckTable();
        for(int j=1; j<=9; j++){
            int curVal = board[i][j];
            if(curVal != 0){
                if(checkTable[curVal]) return false;
                else checkTable[curVal] = true;
            }
        }
    }

    for(int j=1; j<=9; j++){
        resetCheckTable();
        for(int i=1; i<=9; i++){
            int curVal = board[i][j];
            if(curVal != 0){
                if(checkTable[curVal]) return false;
                else checkTable[curVal] = true;
            }
        }
    }

    for(int bi=0; bi<3; bi++){
        for(int bj=0; bj<3; bj++){
            resetCheckTable();
            for(int i=1; i<=3; i++){
                for(int j=1; j<=3; j++){
                    int curVal = board[bi*3+i][bj*3+j];
                    if(curVal != 0){
                        if(checkTable[curVal]) return false;
                        else checkTable[curVal] = true;
                    }
                }
            }
        }
    }

    return true;
}

bool backtrack(int idx){
    if(idx == blank.size()) return true;

    for(int i=1; i<=9; i++){
        board[blank[idx].first][blank[idx].second] = i;

        if(checkValid() && backtrack(idx+1)) return true;

        board[blank[idx].first][blank[idx].second] = 0;
    }

    return false;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;

    while(T--){
      blank.clear();

      for(int i=1; i<=9; i++){
        cin >> ip;
        for(int j=1; j<=9; j++){
          board[i][j] = ip[j-1] - '0';
        }
      }

      if(!checkValid()) {
        cout << "Could not complete this grid.\n\n";
        continue;
      }

      for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
          if(board[i][j] == 0){
            blank.push_back({i, j});
          }
        }
      }

      if(backtrack(0)){
        for(int i=1; i<=9; i++){
          for(int j=1; j<=9; j++){
            cout << board[i][j];
          } cout << "\n";
        } cout << "\n";
      } else {
        cout << "Could not complete this grid.\n\n";
      }
    }
   
    return 0;
}