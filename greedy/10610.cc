/**
 * 30
 * 10610
 */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
  string s;
  cin>>s;
  sort(s.begin(), s.end());
  int sum=0;
  // 30 = 3*10
  for(int i=0;i<s.size();i++){
    sum += s[i]-'0';
  }
  if(sum%3 == 0 && s[0] == '0'){
    reverse(s.begin(),s.end());
    cout<<s<<'\n';
  }
  else{
    cout<<"-1"<<'\n';
  }

  return 0;
}
