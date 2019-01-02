/**
 * 진법 변환
 * 2745
 */
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
  string n;
  int b;
  long long result=0;
  cin>>n>>b;
  int len = n.length();
  for(int i=0;i<len;i++){
    int tmp = n[len-1-i]-'0';
    if(0 <= tmp && tmp <= 9)
      result += tmp * pow(b,i);
    else
      result += (n[len-1-i]-'A'+10) * pow(b,i);
  }

  cout<<result<<endl;

  return 0;
}
