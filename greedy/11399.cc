/**
 * ATM
 * 11399
 */
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int N;
  int p[1001];
  cin>>N;
  for(int i=0;i<N;i++)
    cin>>p[i];
  sort(p,p+N);
  int ans=0;
  for(int i=0;i<N;i++){
    ans += (N-i)*p[i];
  }
  cout<<ans<<'\n';

  return 0;
}
  
