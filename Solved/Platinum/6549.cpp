#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
#define MAX 100010
using namespace std;

int N;
long arr[MAX];

long getMidArea(int lo, int hi, int mid){
  int toLeft = mid;
  int toRight = mid;

  long height = arr[mid];
  long area = arr[mid];

  while(lo<toLeft && toRight<hi){
    if(arr[toLeft-1] < arr[toRight+1]){
      toRight++;
      height = min(height, arr[toRight]);
    } else {
      toLeft--;
      height = min(height, arr[toLeft]);
    }

    area = max(area, height * (toRight - toLeft + 1));
  }

  while(toRight < hi){
    toRight++;
    height = min(height, arr[toRight]);
    area = max(area, height * (toRight - toLeft + 1));
  }
  while(lo < toLeft){
    toLeft--;
    height = min(height, arr[toLeft]);
    area = max(area, height * (toRight - toLeft + 1));
  }

  return area;
}

long getArea(int lo, int hi){
  if(lo == hi) return arr[lo];

  int mid = (lo+hi) / 2;
  long area = max(max(getArea(lo, mid), getArea(mid+1, hi)), getMidArea(lo, hi, mid));

  return area;
}

int main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N;
  while(N){
    for(int i=0; i<N; i++){
      cin >> arr[i];
    }

    cout << getArea(0, N-1) << endl;

    cin >> N;
  }

  return 0;
}