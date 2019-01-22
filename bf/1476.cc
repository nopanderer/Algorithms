/**
 * 날짜 계산
 * 1476
 */
#include <iostream>
using namespace std;
int e,s,m;
int E,S,M;
int ans;
int main(){
  cin>>E>>S>>M;
  e=s=m=ans=1;
  while(true){
    if(s==S && e==E && m==M) break;
    e++;
    s++;
    m++;
    if(e==16) e=1;
    if(s==29) s=1;
    if(m==20) m=1;
    ans++;
  }
  cout<<ans<<'\n';

  return 0;
}
