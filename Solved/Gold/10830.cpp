#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

struct mat {
    int data[6][6];
    mat(){
        memset(data, 0, sizeof(data));
    }
};

bool separated_sum[45];
vector<mat> squared_mat;
ll N, B;


mat mat_mul(mat m1, mat m2){
    mat result;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                result.data[i][j] += m1.data[i][k] * m2.data[k][j];
                result.data[i][j] %= 1000;
            }
        }
    }

    return result;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> B;
    
    mat init;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> init.data[i][j];
        }
    }
    squared_mat.push_back(init);

    for(int i=0; i<40; i++){
        mat tmp = mat_mul(squared_mat[i], squared_mat[i]);
        squared_mat.push_back(tmp);
    }


    mat ret;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i == j){
                ret.data[i][j] = 1;
            }
        }
    }    

    bitset<40> b(B);
    for(int i=0; i<40; i++){
        if(b[i]){
            ret = mat_mul(ret, squared_mat[i]);
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << ret.data[i][j] << ' ';
        }
        cout << "\n";
    }
    return 0;
}