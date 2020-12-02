#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int N, M;
vector<vector<int>> map_default;
vector<vector<int>> map_copy;

vector<vector<int>> can_wall;
vector<vector<int>> wall_combs;

int ops[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
};

void get_combs(int remain, int idx, vector<int>& cur_comb){
    if(remain == 0){
        wall_combs.push_back(cur_comb);
        return;
    }

    for(int i=idx; i<can_wall.size(); i++){
        cur_comb.push_back(i);
        get_combs(remain-1, i+1, cur_comb);
        cur_comb.pop_back();
    }
}

int spread_virus(vector<int> cur_walls){
    for(int cur_idx: cur_walls){
        map_copy[can_wall[cur_idx][0]][can_wall[cur_idx][1]] = 1;
    }

    bool is_spreaded = false;

    while(!is_spreaded){
        is_spreaded = true;

    for(int i=1; i<N+1; i++){
        for(int j=1; j<M+1; j++){
            if(map_copy[i][j] == 2){
                for(int k=0; k<4; k++){
                    if(map_copy[i+ops[k][0]][j+ops[k][1]] == 0){
                        map_copy[i+ops[k][0]][j+ops[k][1]] = 2;
                        if(is_spreaded){
                            is_spreaded = false;
                        }
                    }
                }
            }
        }
    }
    }

    int ret = 0;

    for(int i=1; i<N+1; i++){
        for(int j=1; j<M+1; j++){
            if(map_copy[i][j] == 0){
                ret++;
            }
        }
    }

    return ret;
}

int main()
{
    cin.sync_with_stdio(false);
    cin >> N >> M;

    vector<int> wall_line(M+2, 1);
    map_default.push_back(wall_line);
    for(int i=0; i<N; i++){
        vector<int> row = {1};

        for(int j=0; j<M; j++){
            int tmp;
            cin >> tmp;
            row.push_back(tmp);

            if(tmp == 0){
                can_wall.push_back({i+1, j+1});
            }
        }

        row.push_back(1);
        map_default.push_back(row);
    }
    map_default.push_back(wall_line);

    vector<int> tmp_comb;
    get_combs(3, 0, tmp_comb);

    int safety_area = 0;

    for(auto cur_walls: wall_combs){
        map_copy.assign(map_default.begin(), map_default.end());
        safety_area = max(safety_area, spread_virus(cur_walls));
    }
    cout << safety_area;

    return 0;
}