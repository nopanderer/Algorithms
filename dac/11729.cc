/**
 * 하노이 탑 이동 순서
 * 11729
 */
#include <iostream>
using namespace std;
int N;
int K;
void move(int n,int from,int to){
  if(n == 1){
    cout<<from<<" "<<to<<'\n';
    return;
  }
  move(n-1,from,6-(from+to));
  cout<<from<<" "<<to<<'\n';
  move(n-1,6-(from+to),to);
}
int pow(int x, int n){
  int ans=1;
  for(int i=0;i<n;i++){
    ans *= x;
  }
  return ans;
}

int main(){
  cin>>N;
  cout<<pow(2,N)-1<<'\n';
  move(N,1,3);

  return 0;
}
