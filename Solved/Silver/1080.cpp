#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M, count;
vector<vector<int>> cur_mat;
vector<vector<int>> end_mat;

void reverse_mat(int row, int col){
    count++;
    for(int i=row; i<row+3; i++){
        for(int j=col; j<col+3; j++){
            cur_mat[i][j] = !cur_mat[i][j];
        }
    }
}

int main()
{
    cin.tie(false);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for(int i=0; i<N; i++){
        vector<int> tmp;
        string cur;
        cin >> cur;
        for(int j=0; j<M; j++){
            tmp.push_back(cur[j]-'0');
        }
        cur_mat.push_back(tmp);
    }
    for(int i=0; i<N; i++){
        vector<int> tmp;
        string cur;
        cin >> cur;
        for(int j=0; j<M; j++){
            tmp.push_back(cur[j]-'0');
        }
        end_mat.push_back(tmp);
    }

    for(int i=0; i<N-2; i++){
        for(int j=0; j<M-2; j++){
            if(cur_mat[i][j] != end_mat[i][j]){
                reverse_mat(i, j);
            }
        }
    }

    if(cur_mat == end_mat){
        cout << count;
    } else {
        cout << -1;
    }

    return 0;
}
