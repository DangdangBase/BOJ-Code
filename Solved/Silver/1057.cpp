#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int N, A, B;

int get_next(int a){
    if(a%2 == 0){
        return a/2;
    } else {
        return (a/2 + 1);
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cin >> N >> A >> B;
    if(A > B){
        swap(A, B);
    }

    int count = 1;

    while(!(A%2 == 1 && A+1 == B)){
        A = get_next(A);
        B = get_next(B);
        count++;
    }
    

    cout << count;
    return 0;
}