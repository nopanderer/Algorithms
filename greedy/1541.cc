/**
 * 잃어버린 괄호
 * 1541
 */
#include <iostream>
using namespace std;

int main(){
  char s[51];
  int num=0;
  int ans=0;
  bool neg=false;
  cin>>s;
  for(int i=0;s[i];i++){
    if('0' <= s[i] && s[i] <= '9'){
      num = num*10 + s[i]-'0';
    }
    else{
      if(neg){
        num *= -1;
      }
      ans += num;
      num = 0;
      if(s[i] == '-'){
        neg = true;
      }
    }
  }
  if(neg){
    num *= -1;
  }
  ans += num;
  
  cout<<ans<<'\n';

  return 0;
}
