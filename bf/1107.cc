/**
 * 리모컨
 * 1107
 */
#include <iostream>
using namespace std;
int N,M;
int ans;
bool c[11];
int check(int ch){
  if(ch==0){
    if(c[ch]){
      return 0;
    }
    else{
      return 1;
    }
  }
  int len = 0;
  while(ch>0){
    if(c[ch%10]){
      return 0;
    }
    len++;
    ch/=10;
  }
  return len;
}
int main(){
  cin>>N>>M;
  for(int i=0;i<M;i++){
    int ch;
    cin>>ch;
    c[ch] = true;
  }
  ans = N - 100;
  if(ans < 0){
    ans = -ans;
  }
  for(int i=0;i<=1000000;i++){
    int len = check(i);
    if(len>0){
      int tmp = N-i;
      if(tmp<0){
        tmp = -tmp;
      }
      if(ans > tmp + len){
        ans = tmp + len;
      }
    }
  }

  cout<<ans<<'\n';
  
  return 0;
}
