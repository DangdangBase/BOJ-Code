#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

int H, W;
int answer = -1;
string tmp;

vector<vector<int> > map_default;
vector<vector<int> > map_copy;

int ops[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
};


int bfs(int y, int x){
    int ret = 0;
    queue<vector<int> > q;

    vector<int> tmp;
    tmp.push_back(y);
    tmp.push_back(x);
    tmp.push_back(0);
    q.push(tmp);

    map_copy[y][x] = 0;


    while(!q.empty()){
        vector<int> cur = q.front();
        q.pop();

        ret = max(ret, cur[2]);

        for(int i=0; i<4; i++){
            int tmp_y = cur[0]+ops[i][0], tmp_x = cur[1]+ops[i][1];

            if(map_copy[tmp_y][tmp_x]){
                map_copy[tmp_y][tmp_x] = 0;

                vector<int> ip;
                ip.push_back(tmp_y);
                ip.push_back(tmp_x);
                ip.push_back(cur[2]+1);

                q.push(ip);
            }
        }
    }

    return ret;
}

int main()
{
    cin.sync_with_stdio(false);

    
    vector<int> v(52, 0);
    for(int i=0; i<52; i++){
        map_default.push_back(v);
    }

    cin >> H >> W;
    for(int i=0; i<H; i++){
        cin >> tmp;
        for(int j=0; j<W; j++){
            if(tmp[j] == 'L'){
                map_default[i+1][j+1] = 1;
            }
        }
    }


    for(int i=1; i<H+1; i++){
        for(int j=1; j<W+1; j++){
            if(map_default[i][j] == 0){
                continue;
            }

            map_copy.assign(map_default.begin(), map_default.end());
            answer = max(answer, bfs(i, j));
        }
    }


    
    cout << answer;

    return 0;
}