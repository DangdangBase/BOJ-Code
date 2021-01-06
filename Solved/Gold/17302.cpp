#include <iostream>
#include <string>
#include <vector>
using namespace std;


int n, m;
string tile[2000];

int main()
{
   cin.tie(0);
   ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> tile[i];
    }

    cout << '1' << endl;
    for(int i=0; i<n; i++){
        string tmp = "";
        for(int j=0; j<m; j++){
            bool cur = tile[i][j] == 'B' ? true : false;

            if(i == 0){
                cur = !cur;
            }
            if(i == n-1){
                cur = !cur;
            }
            if(j == 0){
                cur = !cur;
            }
            if(j == m-1){
                cur = !cur;
            }

            if(cur){
                tmp += '3';
            } else {
                tmp += '2';
            }
        }
        cout << tmp << endl;
    }

    return 0;
}
