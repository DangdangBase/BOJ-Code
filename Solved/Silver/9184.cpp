#include <bits/stdc++.h>
using namespace std;
#define MAX_VAL 987654321

int a, b, c;
int dp[110][110][110];

int rec_func(int a, int b, int c){
    if(dp[a+50][b+50][c+50] != MAX_VAL){
        return dp[a+50][b+50][c+50];
    }

    if(a<=0 || b<=0 || c<=0){
        return dp[a+50][b+50][c+50] = 1;
    }
    else if(a>20 || b>20 || c>20){
        return dp[a+50][b+50][c+50] = rec_func(20, 20, 20);
    }
    else if(a<b && b<c){
        return dp[a+50][b+50][c+50] = rec_func(a, b, c-1) + rec_func(a, b-1, c-1) - rec_func(a, b-1, c);
    }
    else {
        return dp[a+50][b+50][c+50] = rec_func(a-1, b, c) + rec_func(a-1, b-1, c) + rec_func(a-1, b, c-1) - rec_func(a-1, b-1, c-1);
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    for(int i=0; i<110; i++){
        for(int j=0; j<110; j++){
            for(int k=0; k<110; k++){
                dp[i][j][k] = MAX_VAL;
            }
        }
    }

    while(true){
        cin >> a >> b >> c;
        if(a==-1 && b==-1 && c==-1){
            break;
        }
        printf("w(%d, %d, %d) = %d\n", a, b, c, rec_func(a, b, c));
    }


    return 0;
}