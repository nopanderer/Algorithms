/**
 * Z
 * 1074
 */
#include <iostream>
using namespace std;
int N,r,c;
int visit;
int go(int n){
  if(n==2){
    return visit + 2*r + c;
  }
  else{
    if(r<n/2){
      if(c<n/2){
        return go(n/2);
      }
      else{
        visit += (n/2)*(n/2);
        c-=n/2;
        return go(n/2);
      }
    }
    else{
      if(c<n/2){
        visit += (n/2)*(n/2)*2;
        r-=n/2;
        return go(n/2);
      }
      else{
        visit += (n/2)*(n/2)*3;
        r-=n/2;
        c-=n/2;
        return go(n/2);
      }
    }
  }
}
int main(){
  cin>>N>>r>>c;
  int r = 1<<N;
  // cout<<r<<endl;
  cout<<go(r)<<'\n';

  return 0;
}
