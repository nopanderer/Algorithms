/**
 * 놀이 공원
 * 1561
 */
#include <iostream>
using namespace std;
int N,M;
long long l,r,m;
int a[10001];
int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin>>N>>M;
  for(int i=0;i<M;i++){
    cin>>a[i];
  }
  if(N <= M){
    cout<<N<<'\n';
    return 0;
  }
  r = 2000000000LL * 1000000LL;

  while(l<=r){
    m = (l+r)/2;
    long long begin = 0;
    long long end = M;
    for(int i=0;i<M;i++){
      end += m/a[i];
    }
    begin = end;
    for(int i=0;i<M;i++){
      if(m%a[i] == 0){
        begin -= 1;
      }
    }
    begin += 1;

    if(N < begin){
      r = m - 1;
    }
    else if(end < N){
      l = m + 1;
    }
    else{
      for(int i=0;i<M;i++){
        if(m%a[i] == 0){
          if(N == begin){
            cout<<i+1<<'\n';
            return 0;
          }
          begin+=1;
        }
      }
    }
  }

  return 0;
}
/*
 * ride \ t
 *      0   1   2   3   4   5   6   7   8
 * 1    1   6   7   9   11  14  16  19  20
 * 2    2       8       12      17      21
 * 3    3           10          18        
 * 4    4               13              22
 * 5    5                   15            
 */
