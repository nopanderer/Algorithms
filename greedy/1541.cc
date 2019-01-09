/**
 * 잃어버린 괄호
 * 1541
 */
#include <iostream>
#include <vector>
using namespace std;

int main(){
  char s[51];
  int num=0;
  int neg=0;
  int ans=0;
  bool isPos=true;
  cin>>s;
  for(int i=0;s[i];i++){
    if(s[i] == '+'){
      if(!isPos){
        num *= -1;
      }
      ans += num;
      num = 0;
    }
    else if(s[i] == '-'){
      if(!isPos){
        num *= -1;
      }
      ans += num;
      num = 0;
      isPos = false;
    }
    else{
      num = num*10 + s[i]-'0';
    }
  }
  if(!isPos){
    num *= -1;
  }
  ans += num;
  
  cout<<ans<<'\n';

  return 0;
}
