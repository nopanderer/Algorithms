/**
 * 8진수 2진수
 * 1212
 */
#include <iostream>
#include <string>

using namespace std;

int main(){
  string s;
  cin>>s;

  for(int i=0;i<s.size();i++){
    string tmp = "000";
    int idx=2;
    int n = (int)(s[i]-'0');
    while(n != 0){
      tmp[idx--]= (char)(n%2+'0');
      n /= 2;
    }
    if(i==0){
      if(tmp[0]=='0' && tmp[1]=='0' && tmp[2]=='0')
        cout<<'0';
      else if(tmp[0]=='0' && tmp[1]=='0')
        cout<<tmp[2];
      else if(tmp[0]=='0')
        cout<<tmp[1]<<tmp[2];
      else
        cout<<tmp;
    }
    else{
      cout<<tmp;
    }
  }

  return 0;
}
