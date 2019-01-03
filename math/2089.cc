/**
 * -2진수
 * 2089
 */
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  long long N;
  string s = "";
  cin>>N;
  if(N==0)
    cout<<'0';
  while(N != 0){
    if(N > 0 || N%2 == 0){
      s += (char)(N%(-2)+'0');
      N /= (-2);
    }
    else{
      s += '1';
      N = (N-1)/(-2);
    }
  }
  reverse(s.begin(),s.end());
  cout<<s;

  return 0;
}
